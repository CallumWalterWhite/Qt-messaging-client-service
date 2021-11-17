#ifndef CHAT_H
#define CHAT_H

#include <QStringList>
#include <QtNetwork>
#include <QStandardItemModel>
#include <QHeaderView>
#include <vector>
#include <map>
#include <string>

#include "MessagePayloadMap.h"
#include "MessageArrived.h"
#include "ClickableLabel.h"
#include "../../meta/ui_chatmainwindow.h"
#include "../MessageClient.h"
#include "../../../../message_common/src/Payload.h"

using namespace std;

class ChatMainWindow: public QDialog, Ui::ChatMainWindow
{
    Q_OBJECT
    vector<MessagePayloadMap> _concurrentMessages;
    int _concurrentUserId;
    bool _concurrentUserSelected;
    string _username;
    vector<Payload> _concurrentPayloads;
    QNetworkAccessManager* _usernetwManager;
    QNetworkAccessManager* _concurrentUsernetwManager;
public:
    MessageArrived messageArrived;
    MessageClient* messageClient;
    ChatMainWindow(MessageClient* _messageClient);
    ~ChatMainWindow();
private:
    QWidget* createMessageWidget(string username, MessagePayloadMap messagePayloadMap);
    void clearLayout(QLayout *layout);
    void setUsernameText();
    void checkConcurrentUser();
    void checkConcurrentUserHistory();
    void buildMessageSortComboBox();
    string getCurrentMessageSort();
    void rebuildHistory();
    void buildUserSettings();
    void buildReports();

private slots:
    void messageSlot(const int &payloadId, const QString &text);
    void actionSlot(const int &payloadId, const QString &action);
    void listUserItemClickedSlot(QListWidgetItem* item);
    void textChangedSlot(const QString &newText);
    void sendClickedSlot();
    void settingsClickedSlot();
    void updateSettingsClickedSlot();
    void reportClickedSlot();
    void refeshConcurrentPayloadSlot();
    void userImageURLResolverSlot(QNetworkReply* reply);
    void concurrentUserImageURLResolverSlot(QNetworkReply* reply);
    void buildUserListSlot();
};

#endif 
