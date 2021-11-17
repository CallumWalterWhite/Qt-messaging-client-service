#include "MessageService.h"
#include "../../../message_common/src/ConfigManager.h"
#include "../../../message_common/src/DatabaseAdapter.h"

using namespace std;

const char* LWT_PAYLOAD = "CLIENT.";

const int  QOS = 1;

const auto TOKEN_TIMEOUT = chrono::seconds(10);

const int	N_RETRY_ATTEMPTS = 5;

class ActionListener : public virtual mqtt::iaction_listener
{
public:
	void on_failure(const mqtt::token& tok) override {
		cout << "\tListener failure for token: "
			<< tok.get_message_id() << endl;
	}

	void on_success(const mqtt::token& tok) override {
		cout << "\tListener success for token: "
			<< tok.get_message_id() << endl;
	}
};


class MessageServiceCallback : public virtual mqtt::callback,
					public virtual mqtt::iaction_listener

{
	int retry;
	MessageService* messageService_;
	mqtt::async_client_ptr client_;
	mqtt::connect_options& connOpts_;
	ActionListener subListener_;
    string topicClient_;

	void reconnect() {
		std::this_thread::sleep_for(std::chrono::milliseconds(2500));
		try {
			client_->connect(connOpts_, nullptr, *this);
		}
		catch (const mqtt::exception& exc) {
			std::cerr << "Error: " << exc.what() << std::endl;
			exit(1);
		}
	}

	// Re-connection failure
	void on_failure(const mqtt::token& tok) override {
		if (++retry > N_RETRY_ATTEMPTS)
			exit(1);
		reconnect();
	}

	void on_success(const mqtt::token& tok) override {}


	void connected(const std::string& cause) override {
        string clientId = client_->get_client_id();
		std::cout << "\nConnection success" << std::endl;
		std::cout << "\nSubscribing to topic '" << topicClient_ << "'\n"
			<< "\tfor client " << clientId
			<< " using QoS" << QOS << "\n"
			<< "\nPress Q<Enter> to quit\n" << std::endl;

		client_->subscribe(topicClient_, QOS, nullptr, subListener_);
	}

	void connection_lost(const std::string& cause) override {
		retry = 0;
		reconnect();
	}

	void message_arrived(mqtt::const_message_ptr msg) override {
		string payloadJson = msg->to_string();

		if (payloadJson != LWT_PAYLOAD)
		{
			Payload payload = PayloadResolver::resolve(payloadJson);

			string discriminator = payload.GetDiscriminator();
				
			if (discriminator == "update")
			{
				messageService_->DirectMessage(payload);
			}
			else
			{
				payload.Store();

				messageService_->SendListener(payload);
			}
		}
	}

	void delivery_complete(mqtt::delivery_token_ptr token) override {}

public:
	MessageServiceCallback(mqtt::async_client_ptr cli, mqtt::connect_options& connOpts, MessageService *messageService, string topicClient)
				: retry(0), client_(cli), connOpts_(connOpts), subListener_(), messageService_(messageService), topicClient_(topicClient) {}
};

MessageService::MessageService(int messageClientId) : MessageNode(messageClientId) 
{
};

void MessageService::SetupService()
{    
	auto connOpts = std::make_shared<mqtt::connect_options>();
    connOpts->set_keep_alive_interval(20);
    connOpts->set_clean_session(true);

    DatabaseAdapter adapter;
    string messageClientCode = adapter.GetClientNodeCodeById(_messageClientId);

    string defaultAddress = ConfigManager::getDefaultAddress();
	auto client = std::make_shared<mqtt::async_client>(defaultAddress, messageClientCode);
    string topicClient = GetTopic();
    
    MessageServiceCallback msgcb(client, *connOpts, this, topicClient);
    auto messageCallback = std::make_shared<MessageServiceCallback>(msgcb);
    client->set_callback(*messageCallback);
    try 
    {
        client->connect(*connOpts, nullptr, *messageCallback);
    }
    catch (const mqtt::exception&) {
        std::cerr << "\nERROR: Unable to connect to MQTT server: '"
            << defaultAddress << "'" << std::endl;
        exit(1);
    }

    _clientService = std::make_tuple(client, connOpts, messageCallback);
};

void MessageService::DirectMessage(Payload payload)
{
	auto client = GetClient();
	string topic = payload.GetTopic();
	mqtt::message_ptr pubmsg = mqtt::make_message(topic, payload.Stringfy());
	pubmsg->set_qos(QOS);
	client->publish(pubmsg);
};

void MessageService::SendListener(Payload payload)
{
	auto client = GetClient();
	string topic = payload.GetTopic();
	mqtt::delivery_token_ptr pubtok;
	string payloadMessage = payload.Stringfy();
    char payload_array[payloadMessage.length() + 1];
    strcpy(payload_array, payloadMessage.c_str());
	pubtok = client->publish(topic, payload_array, strlen(payload_array), QOS, false);
	pubtok->wait_for(TOKEN_TIMEOUT);
};

string MessageService::GetTopic()
{
    DatabaseAdapter adapter;
    return adapter.GetTopicCodeByClientNodeId(_messageClientId);
};

void MessageService::Disconnect() 
{  
    auto client = GetClient();
    cout << "\nDisconnecting..." << endl;
    client->disconnect();
    cout << "Disconnected" << endl;
};