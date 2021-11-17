#include <map>
#include <string>
#include <algorithm>
#include "Chat.h"
#include <QMessageBox>
#include "../../../../message_common/src/DatabaseAdapter.h"
#include "../../../../message_common/src/ConfigManager.h"
#include "../../../../message_common/src/AlgorithmProvider.h"
#include "../MessageClient.h"
#include "Login.h"

static string QStringtoString(QString qstring)
{
    string str = qstring.toUtf8().constData();
    return str;
}

LoginRegisterMainWindow::LoginRegisterMainWindow(QWidget *parent)
{
    setupUi(this);
    
    usernameRegister->setPlaceholderText("Please Enter Username");
    passwordRegister->setPlaceholderText("Please Enter Password");
    emailAddressRegister->setPlaceholderText("Please Enter Email");
    usernameLogin->setPlaceholderText("Please Enter Username");
    passwordLogin->setPlaceholderText("Please Enter Password");

    
    connect(loginBtn, SIGNAL(clicked(bool)), this, SLOT(loginClickedSlot()));
    connect(registerBtn, SIGNAL(clicked(bool)), this, SLOT(registerClickedSlot()));
};

LoginRegisterMainWindow::~LoginRegisterMainWindow()
{
};

void LoginRegisterMainWindow::loginClickedSlot()
{
    
    string username = QStringtoString(usernameLogin->text());
    string password = QStringtoString(passwordLogin->text());

    DatabaseAdapter adapter;

    int userId = adapter.GetUserIdByUsernamePassword(username, password);

    if (userId != -1)
    {
        int clientNodeId = adapter.GetClientIdByUserId(userId);

        MessageClient messageClient(clientNodeId, userId);

        ChatMainWindow chat(&messageClient);

        messageClient.SetupClient(chat.messageArrived);
        this->hide();
        chat.show();
        chat.exec();
    }
    else
    {
        QMessageBox::information(this,"Failed login", "Username or password is incorrect.");
    }
};

void LoginRegisterMainWindow::registerClickedSlot()
{
    
    string username = QStringtoString(usernameRegister->text());
    string password = QStringtoString(passwordRegister->text());
    string email = QStringtoString(emailAddressRegister->text());

    DatabaseAdapter adapter;

    vector<int> userIdsByUsername = adapter.GetUsersByUsername(username);
    vector<int> userIdsByEmail = adapter.GetUsersByEmail(email);

    if (!(userIdsByUsername.size() > 0
        || userIdsByEmail.size() > 0))
    {
        int userId = adapter.CreateUser(email, username, password);

        string clientNodeCodePrefix = ConfigManager::getClientNodePrefix();
        string clientTopicCodePrefix = ConfigManager::getClientTopicPrefix();

        int clientNodeId = adapter.CreateClientNodeWithTopic(userId, clientNodeCodePrefix, clientTopicCodePrefix);

        QMessageBox::information(this,"User created", "You have successfully registered!");

        MessageClient messageClient(clientNodeId, userId);

        ChatMainWindow chat(&messageClient);

        messageClient.SetupClient(chat.messageArrived);
        this->hide();
        chat.show();
        chat.exec();
    }
    else
    {
        QMessageBox::information(this,"Failed register", "Username or email is already taken.");
    }
};