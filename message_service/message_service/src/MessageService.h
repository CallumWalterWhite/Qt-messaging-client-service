#include "../../../message_common/src/MessageNode.h"
#include "../../../message_common/src/Payload.h"

class MessageService : public MessageNode
{
    private:
        mqtt::token_ptr conntok;
    public:
        MessageService(int messageClientId);
        void SetupService();
        string GetTopic();
        void Disconnect();
        void DirectMessage(Payload payload);
        void SendListener(Payload payload);
};