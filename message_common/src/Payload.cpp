#include <string>

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/filereadstream.h"
#include "Payload.h"
#include "DatabaseAdapter.h"
#define RAPIDJSON_HAS_STDSTRING 1

using namespace std;
using namespace rapidjson;

Payload::Payload(string payloadMessage, int clientTopicId, int clientUserId, string discriminator)
{
    _payloadMessage = payloadMessage;
    _clientTopicId = clientTopicId;
    _clientUserId = clientUserId;
    _discriminator = discriminator;
};

Payload::~Payload()
{
};

string Payload::Stringfy()
{
    Document doc;
    doc.SetObject();
    
	rapidjson::Document::AllocatorType& allocator = doc.GetAllocator();
    
	doc.AddMember("id", _id, allocator);
    Value nPayloadMessage(_payloadMessage.c_str(), allocator);
	doc.AddMember("message", nPayloadMessage, allocator);
	doc.AddMember("clientTopicId", _clientTopicId, allocator);
	doc.AddMember("clientUserId", _clientUserId, allocator);
    Value nDiscriminator(_discriminator.c_str(), allocator);
    doc.AddMember("discriminator", nDiscriminator, allocator);
    
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    doc.Accept(writer);

    return buffer.GetString();
};

string Payload::GetTopic()
{
    DatabaseAdapter adapter;
    string topicStr = adapter.GetTopicCodeById(_clientTopicId);
    return topicStr;
};

int Payload::GetTopicId()
{
    return _clientTopicId;
};

string Payload::GetUserName()
{
    DatabaseAdapter adapter;
    string userName = adapter.GetUserNameByUserId(_clientUserId);
    return userName;
};

string Payload::GetPayloadMessage()
{
    return _payloadMessage;
};

int Payload::GetPayloadId()
{
    return _id;
};

int Payload::GetUserId()
{
    return _clientUserId;
}

void Payload::SetId(int id)
{
    _id = id;
};

void Payload::SetDateSent(time_t dateSent){
    _dateSent = dateSent;
};

string Payload::GetDiscriminator()
{
    return _discriminator;
};

time_t Payload::GetDateSent(){
    return _dateSent;
};

Payload PayloadResolver::resolve(string strPayload)
{
    Document doc;

    doc.Parse<0>(strPayload.c_str());

    int payloadId;
    string payloadMessage;
    int clientTopicId;
    int clientUserId;
    string discriminator;

    const Value& payloadIdJson = doc["id"];
    payloadId = payloadIdJson.GetInt();
    
    const Value& payloadMessageJson = doc["message"];
    payloadMessage = payloadMessageJson.GetString();
    
    const Value& clientTopicIdJson = doc["clientTopicId"];
    clientTopicId = clientTopicIdJson.GetInt();
    
    const Value& clientUserIdJson = doc["clientUserId"];
    clientUserId = clientUserIdJson.GetInt();
    
    const Value& discriminatorJson = doc["discriminator"];
    discriminator = discriminatorJson.GetString();

    Payload payload(payloadMessage, clientTopicId, clientUserId, discriminator);

    payload.SetId(payloadId);

    return payload;
};

void Payload::Store()
{
    DatabaseAdapter adapter;
    int id = adapter.SavePayload(_payloadMessage, _discriminator, _clientTopicId, _clientUserId);
    SetId(id);
};

Payload PayloadResolver::create(string payloadMessage, int clientTopicId, int clientUserId, string discriminator)
{
    return Payload(payloadMessage, clientTopicId, clientUserId, discriminator);
};