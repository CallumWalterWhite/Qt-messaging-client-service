#include "MessageNode.h"
#include "DatabaseAdapter.h"
#include "ConfigManager.h"
#include "mqtt/async_client.h"

using namespace std;

mqtt::async_client_ptr MessageNode::GetClient()
{
    auto client = std::get<0>(_clientService);
    return client;
};

MessageNode::~MessageNode()
{
};
