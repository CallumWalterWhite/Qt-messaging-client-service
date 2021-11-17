#ifndef MESSAGE_CLIENT_H
#define MESSAGE_CLIENT_H

#include "../../../message_common/src/MessageNode.h"
#include "../../../message_common/src/Payload.h"
#include "layout/MessageArrived.h"
#define OUT

class MessageClient : public MessageNode
{
    private:
        mqtt::token_ptr conntok;
    private:
        string GetTopic();
    public:
        int UserId;
        MessageClient(int messageClientId, int userId);
        void SetupClient(MessageArrived &messageArrived);
        void Disconnect();
        void DirectMessage(Payload payload);
};

#endif