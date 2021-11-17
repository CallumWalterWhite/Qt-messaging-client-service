#ifndef MESSAGENODE_H
#define MESSAGENODE_H

#include <string>
#include "mqtt/async_client.h"

using namespace std;
using namespace mqtt;

using clientService = std::tuple<mqtt::async_client_ptr, 
                mqtt::connect_options_ptr, 
                mqtt::callback_ptr>;

class MessageNode
{
    protected:
        int _messageClientId;
        clientService _clientService;
    public:
        MessageNode(int messageClientId) : _messageClientId(messageClientId)
        {
        };
	    ~MessageNode();
        mqtt::async_client_ptr GetClient();
};

#endif