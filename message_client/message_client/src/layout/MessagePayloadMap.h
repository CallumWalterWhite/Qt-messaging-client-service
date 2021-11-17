#ifndef MESSAGEPAYLOAD_MAP_H
#define MESSAGEPAYLOAD_MAP_H

#include <QStringList>
#include <string>
#include <ctime>
using namespace std;

class MessagePayloadMap 
{
    public:
        MessagePayloadMap(int payloadId, time_t dateSent, QString message) : PayloadId(payloadId), DateSent(dateSent), Message(message)
        {

        };
        int PayloadId;
        time_t DateSent;
        QString Message;

};

#endif