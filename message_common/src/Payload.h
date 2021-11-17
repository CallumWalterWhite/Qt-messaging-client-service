#ifndef PAYLOAD_H
#define PAYLOAD_H

#include <string>
#include <ctime>

using namespace std;

class Payload
{
private:
	int _id;
	string _payloadMessage;
	string _discriminator;
	int _clientTopicId;
	int _clientUserId;
	time_t _dateSent;
public:
	Payload(string payloadMessage, int clientTopicId, int clientUserId, string discriminator);
	~Payload();
	string Stringfy();
	string GetTopic();
	string GetUserName();
	string GetPayloadMessage();
	string GetDiscriminator();
	int GetTopicId();
	int GetUserId();
	int GetPayloadId();
	void SetId(int id);
	void SetDateSent(time_t dateSent);
	time_t GetDateSent();
	void Store();
};

class PayloadResolver
{
	public:
		static Payload resolve(string strPayload);
		static Payload create(string payloadMessage, int clientTopicId, int clientUserId, string discriminator);
};

#endif