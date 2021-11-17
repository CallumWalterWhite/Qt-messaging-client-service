#include <map>
#include <string>
#include <algorithm>
#include <ctime>
#include <QApplication>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QtNetwork>
#include "Chat.h"
#include "../../../../message_common/src/DatabaseAdapter.h"
#include "../../../../message_common/src/ConfigManager.h"
#include "../../../../message_common/src/AlgorithmProvider.h"
#include "../MessageClient.h"

using namespace std;

static string QStringtoString(QString qstring)
{
    string str = qstring.toUtf8().constData();
    return str;
}

ChatMainWindow::ChatMainWindow(MessageClient* _messageClient)
{
    setupUi(this);
    messageClient = _messageClient;
    sendButton->setEnabled(false);

    _concurrentUserSelected = false;
    connect(messageLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(textChangedSlot(QString)));
    connect(sendButton, SIGNAL(clicked(bool)), this, SLOT(sendClickedSlot()));
    connect(settingsButton, SIGNAL(clicked(bool)), this, SLOT(settingsClickedSlot()));
    connect(updateSettings, SIGNAL(clicked(bool)), this, SLOT(updateSettingsClickedSlot()));
    connect(reportButton, SIGNAL(clicked(bool)), this, SLOT(reportClickedSlot()));
    connect(userListSearch_button, SIGNAL(clicked(bool)), this, SLOT(buildUserListSlot()));

    connect(&messageArrived,SIGNAL(onMessageArrived(int,QString)),this,SLOT(messageSlot(int,QString)));
    connect(&messageArrived,SIGNAL(onActionArrived(int,QString)),this,SLOT(actionSlot(int,QString)));
    connect(messageSortComboBox,SIGNAL(currentIndexChanged(const QString&)),
        this,SLOT(refeshConcurrentPayloadSlot()));

    
    connect(userList, SIGNAL(itemClicked(QListWidgetItem*)), 
            this, SLOT(listUserItemClickedSlot(QListWidgetItem*)));

    
    DatabaseAdapter adapter;
    User user = adapter.GetUser(messageClient->UserId);
    _username = user.UserName;

    QVBoxLayout *qvBoxLayout = new QVBoxLayout(messageScrollArea_widget);
    this->messageScrollArea_widget->setLayout(qvBoxLayout);

    _usernetwManager = new QNetworkAccessManager(this);
    _concurrentUsernetwManager = new QNetworkAccessManager(this);
    connect(_usernetwManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(userImageURLResolverSlot(QNetworkReply*)));
    connect(_concurrentUsernetwManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(concurrentUserImageURLResolverSlot(QNetworkReply*)));

    QUrl url(QString::fromStdString(user.ImageURL));
    QNetworkRequest request(url);
    _usernetwManager->get(request);

    setUsernameText();
    buildUserListSlot();
    checkConcurrentUser();
    buildMessageSortComboBox();
    settingPorfileWidget->hide();
    reportWidget->hide();
}

ChatMainWindow::~ChatMainWindow()
{
    delete messageClient;
};

QWidget* ChatMainWindow::createMessageWidget(string username, MessagePayloadMap messagePayloadMap)
{
    QWidget *messageWidget = new QWidget();
    messageWidget->resize(messageWidget->width(), 80);
    QVBoxLayout *msgLayout = new QVBoxLayout(messageWidget);
    ClickableLabel *label = new ClickableLabel(messageArrived);
    QString msg(QLatin1String("<%1 - %2> %3"));
    string payloadMessage = QStringtoString(messagePayloadMap.Message);
    string dateTimeStr = AlgorithmProvider::ConvertTimeTtoDateTimeString(messagePayloadMap.DateSent);
    msg = msg.arg(QString::fromStdString(dateTimeStr), QString::fromStdString(username), messagePayloadMap.Message);
    label->setText(msg);
    label->Setup(messagePayloadMap.PayloadId, messageClient);
    msgLayout->addWidget(label);
    return messageWidget;
};

void ChatMainWindow::rebuildHistory()
{
    clearLayout(this->messageScrollArea_widget->layout());
    DatabaseAdapter adapter;
    string username = adapter.GetUserNameByUserId(_concurrentUserId);
    for (MessagePayloadMap messagePayloadMap : _concurrentMessages)
    {
        int payloadId = messagePayloadMap.PayloadId;
        
        string messageUsername = username;
        if (payloadId > -1)
        {
            auto it = find_if(_concurrentPayloads.begin(), _concurrentPayloads.end(), [&payloadId](Payload obj) {return obj.GetPayloadId() == payloadId;});
            if (it != _concurrentPayloads.end())
            {
                auto index = std::distance(_concurrentPayloads.begin(), it);
                Payload payload = _concurrentPayloads[index];
                if (payload.GetUserId() == messageClient->UserId)
                {
                    messageUsername = _username;
                }
            }
        }
        else
        {
            messageUsername = _username;
        }
        QWidget *messageWidget = createMessageWidget(messageUsername, messagePayloadMap);
        this->messageScrollArea_widget->layout()->addWidget(messageWidget);
    }
};

void ChatMainWindow::clearLayout(QLayout *layout) 
{
    QLayoutItem *item;
    while((item = layout->takeAt(0))) 
    {
        if (item->layout()) 
        {
            clearLayout(item->layout());
            delete item->layout();
        }
        if (item->widget()) {
           delete item->widget();
        }
        delete item;
    }
}

void ChatMainWindow::buildMessageSortComboBox()
{
    messageSortComboBox->addItem(tr("ASC"));
    messageSortComboBox->addItem(tr("DSC"));
};

string ChatMainWindow::getCurrentMessageSort()
{
    return QStringtoString(messageSortComboBox->currentText());
};

void ChatMainWindow::buildUserListSlot()
{
    userList->clear();
    DatabaseAdapter adapter;
    map<int, string> users = adapter.GetUsers();

    string search = QStringtoString(userListSearch->text());

    vector<string> usernames = AlgorithmProvider::searchUserByUsername(users, messageClient->UserId, search);

    for( unsigned i = 0; i < usernames.size(); ++i )
    {
        userList->addItem(QString::fromStdString(usernames[i]));
    }
};

void ChatMainWindow::buildReports()
{
    DatabaseAdapter adapter;
    vector<Payload> payloads = adapter.GetPayloads();

    vector<pair<string, int>> resultDate = AlgorithmProvider::payloadByDay(payloads);
    vector<pair<string, int>> resultUsers = AlgorithmProvider::payloadByUser(payloads);
    auto modelDate = new QStandardItemModel();
    auto modelUser = new QStandardItemModel();
    report_messagePerDay_Table->setModel(modelDate);
    report_mostSentMessages_Table->setModel(modelUser);

    modelDate->setHorizontalHeaderItem(0, new QStandardItem("Date"));
    modelDate->setHorizontalHeaderItem(1, new QStandardItem("Amount of messages"));
    
    modelUser->setHorizontalHeaderItem(0, new QStandardItem("User"));
    modelUser->setHorizontalHeaderItem(1, new QStandardItem("Amount of messages"));

    QList<QStandardItem*> rowData;
    Q_FOREACH(const auto &item, resultDate)
    {
        rowData.clear();
        rowData << new QStandardItem(QString::fromStdString(item.first));
        rowData << new QStandardItem(QString::fromStdString(to_string(item.second)));
        modelDate->appendRow(rowData);
    }
    
    Q_FOREACH(const auto &item, resultUsers)
    {
        rowData.clear();
        rowData << new QStandardItem(QString::fromStdString(item.first));
        rowData << new QStandardItem(QString::fromStdString(to_string(item.second)));
        modelUser->appendRow(rowData);
    }
};

void ChatMainWindow::buildUserSettings()
{
    DatabaseAdapter adapter;
    User user = adapter.GetUser(messageClient->UserId);

    usernameSettings->setText(QString::fromStdString(user.UserName));
    firstnameSettings->setText(QString::fromStdString(user.FirstName));
    lastnameSettings->setText(QString::fromStdString(user.LastName));
    emailaddressSettings->setText(QString::fromStdString(user.Email));
    imageURLSettings->setText(QString::fromStdString(user.ImageURL));
};


void ChatMainWindow::checkConcurrentUser()
{
    if (_concurrentUserSelected)
    {
        messageWindow->show();
        settingPorfileWidget->hide();
        reportWidget->hide();
        
    
        DatabaseAdapter adapter;
        User user = adapter.GetUser(_concurrentUserId);
        string username = user.UserName;
        concurrentUsername->setText(QString::fromStdString(username));
        
        QUrl url(QString::fromStdString(user.ImageURL));
        QNetworkRequest request(url);
        _concurrentUsernetwManager->get(request);
        
        checkConcurrentUserHistory();
    }
    else
    {
        messageWindow->hide();
    }
}

void ChatMainWindow::checkConcurrentUserHistory()
{
    if (_concurrentUserSelected)
    {
        messageWindow->show();
        DatabaseAdapter adapter;
        _concurrentPayloads = adapter.GetPayloadMessagesByUserId(messageClient->UserId, _concurrentUserId);
        refeshConcurrentPayloadSlot();
    }
}

void ChatMainWindow::refeshConcurrentPayloadSlot()
{
    _concurrentMessages.clear();
    string sort = getCurrentMessageSort();
    AlgorithmProvider::sortPayloadByDate(_concurrentPayloads, sort);
    for(size_t i=0; i<_concurrentPayloads.size(); ++i)
    {
        Payload payload = _concurrentPayloads[i];
        int senderUserId = payload.GetUserId();
        QString qpayloadMsg = QString::fromStdString(payload.GetPayloadMessage());
        int payloadId = payload.GetPayloadId();
        time_t dateSent = payload.GetDateSent();
        MessagePayloadMap messagePayloadMap(payloadId, dateSent, qpayloadMsg);
        _concurrentMessages.push_back(messagePayloadMap);
    }
    rebuildHistory();
}

void ChatMainWindow::setUsernameText()
{
    loggedInUsername->setText(QString::fromStdString(_username));
}

void ChatMainWindow::listUserItemClickedSlot(QListWidgetItem* item)
{
    DatabaseAdapter adapter;
    map<int, string> users = adapter.GetUsers();

    for (const auto &iter : users)
    {
        if (iter.second == QStringtoString(item->text()))
        {
            
            _concurrentUserId = iter.first;
            _concurrentUserSelected = true;
            checkConcurrentUser();
            break;
        }
    }
}

void ChatMainWindow::messageSlot(const int &payloadId, const QString &text)
{
    if (payloadId > -1)
    {
        auto it = find_if(_concurrentPayloads.begin(), _concurrentPayloads.end(), [&payloadId](Payload& obj) {return obj.GetPayloadId() == payloadId;});
        if (it != _concurrentPayloads.end())
        {
            return;
        }
    }
    time_t t = time(0);
    MessagePayloadMap messagePayloadMap(payloadId, t, text);
    _concurrentMessages.push_back(messagePayloadMap);
    rebuildHistory();
};

void ChatMainWindow::actionSlot(const int &payloadId, const QString &action)
{
    cout << QStringtoString(action) << endl;
    if (QStringtoString(action) == "update")
    {
        checkConcurrentUserHistory();
    }
};

void ChatMainWindow::textChangedSlot(const QString &newText)
{
    sendButton->setEnabled(!newText.isEmpty());
}

void ChatMainWindow::sendClickedSlot()
{
    DatabaseAdapter adapter;
    int concurrentUserTopicId = adapter.GetAggreateTopicIdByUserId(_concurrentUserId);
    QString qsMessage = messageLineEdit->text();
    string textMessage = QStringtoString(qsMessage);
    Payload playload(textMessage, concurrentUserTopicId, messageClient->UserId, "direct"); 
    messageClient->DirectMessage(playload);
    messageLineEdit->setText(QString());
    int prePayloadId = -1;
    messageSlot(prePayloadId, qsMessage);
};

void ChatMainWindow::settingsClickedSlot()
{
    settingPorfileWidget->show();
    reportWidget->hide();
    messageWindow->hide();
    buildUserSettings();
};

void ChatMainWindow::reportClickedSlot()
{
    settingPorfileWidget->hide();
    messageWindow->hide();
    reportWidget->show();
    buildReports();
};

void ChatMainWindow::updateSettingsClickedSlot()
{
    string username = QStringtoString(usernameSettings->text());
    string firstname = QStringtoString(firstnameSettings->text());
    string lastname = QStringtoString(lastnameSettings->text());
    string emailAddress = QStringtoString(emailaddressSettings->text());
    string imageURL = QStringtoString(imageURLSettings->text());

    DatabaseAdapter adapter;
    
    vector<int> userIdsByUsername = adapter.GetUsersByUsername(username);
    vector<int> userIdsByEmail = adapter.GetUsersByEmail(emailAddress);

    std::pair<bool, int> usernameResult = AlgorithmProvider::findIndexInVector(userIdsByUsername, messageClient->UserId);
    std::pair<bool, int> emailResult = AlgorithmProvider::findIndexInVector(userIdsByEmail, messageClient->UserId);
    
    if (userIdsByUsername.size() > 0 && !usernameResult.first){
        QMessageBox::information(this,"Username exist", "That username is already taken.");
    }
    else if (userIdsByEmail.size() > 0 && !emailResult.first){
        QMessageBox::information(this,"Email exist", "That email is already taken.");
    }
    else
    {
        adapter.UpdateUser(messageClient->UserId, firstname, lastname, emailAddress, username, imageURL);
        _username = username;
        QMessageBox::information(this,"User updated", "User updated.");
        setUsernameText();
        QUrl url(QString::fromStdString(imageURL));
        QNetworkRequest request(url);
        _usernetwManager->get(request);
    }
};

void ChatMainWindow::userImageURLResolverSlot(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError) {
    qDebug() << "Error in" << reply->url() << ":" << reply->errorString();
    return;
    }
    
    QByteArray jpegData = reply->readAll();
    QPixmap pixmap;
    pixmap.loadFromData(jpegData);
    userImageURL_label->setPixmap(pixmap); 
    userImageURL_label->setScaledContents(true);

}

void ChatMainWindow::concurrentUserImageURLResolverSlot(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError) {
    qDebug() << "Error in" << reply->url() << ":" << reply->errorString();
    return;
    }
    
    QByteArray jpegData = reply->readAll();
    QPixmap pixmap;
    pixmap.loadFromData(jpegData);
    concurrentUserImageURL_label->setPixmap(pixmap); 
    concurrentUserImageURL_label->setScaledContents(true);

}
