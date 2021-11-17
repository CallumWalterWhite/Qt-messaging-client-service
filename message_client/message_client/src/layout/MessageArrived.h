#ifndef MESSAGE_ARRIVED_H
#define MESSAGE_ARRIVED_H

#include <QStringList>
#include "../../meta/ui_chatmainwindow.h"
#include "../../meta/ui_chatloginregister.h"

using namespace std;

class MessageArrived: public QDialog
{
    Q_OBJECT
public:
    MessageArrived();
    void recieveMessage(int payloadId, string message);
    void recieveAction(int payloadId, string action);
signals:
    void onMessageArrived(int payloadId, QString text);
    void onActionArrived(int payloadId, QString action);
};

#endif