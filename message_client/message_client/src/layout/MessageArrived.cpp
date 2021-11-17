#include <QApplication>

#include "MessageArrived.h"

using namespace std;

MessageArrived::MessageArrived()
{
};

void MessageArrived::recieveMessage(int payloadId, string message)
{
    emit onMessageArrived(payloadId, QString::fromStdString(message));
};

void MessageArrived::recieveAction(int payloadId, string action)
{
    emit onActionArrived(payloadId, QString::fromStdString(action));
};