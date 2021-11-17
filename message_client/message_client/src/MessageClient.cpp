#include "MessageClient.h"
#include "../../../message_common/src/ConfigManager.h"
#include "../../../message_common/src/DatabaseAdapter.h"

using namespace std;

const char* LWT_PAYLOAD = "CLIENT.";

const int  QOS = 1;

const auto TIMEOUT = std::chrono::seconds(10);

const int	N_RETRY_ATTEMPTS = 5;

string GetMessageServiceClientTopicCode()
{
    DatabaseAdapter adapter;
    int clientId = adapter.GetMessageServiceClientId();
    string messageClientCode = adapter.GetTopicCodeByClientNodeId(clientId);
    return messageClientCode;
};


class ActionListener : public virtual mqtt::iaction_listener
{
    std::string name_;

    void on_failure(const mqtt::token& tok) override {
    };

    void on_success(const mqtt::token& tok) override {
    }

    public:
        ActionListener(const std::string& name) : name_(name) {}
};


class MessageClientCallback : public virtual mqtt::callback,
					public virtual mqtt::iaction_listener

{
	int nretry_;
	mqtt::async_client_ptr cli_;
	mqtt::connect_options& connOpts_;
	ActionListener subListener_;
    string topicClient_;
    MessageArrived &messageArrived_;

	void reconnect() {
		std::this_thread::sleep_for(std::chrono::milliseconds(2500));
		try 
        {
			cli_->connect(connOpts_, nullptr, *this);
		}
		catch (const mqtt::exception& exc) {
			std::cerr << "Error: " << exc.what() << std::endl;
			exit(1);
		}
	};

	void on_failure(const mqtt::token& tok) override {
		if (++nretry_ > N_RETRY_ATTEMPTS)
			exit(1);
		reconnect();
	};

	void on_success(const mqtt::token& tok) override {
    };

	void connected(const std::string& cause) override 
	{
		cli_->subscribe(topicClient_, QOS, nullptr, subListener_);
	};

	void connection_lost(const std::string& cause) override {
		nretry_ = 0;
		reconnect();
	};

	void message_arrived(mqtt::const_message_ptr msg) override {
		std::cout << "Message arrived" << std::endl;
		std::cout << "\ttopic: '" << msg->get_topic() << "'" << std::endl;
		std::cout << "\tpayload: '" << msg->to_string() << "'\n" << std::endl;

        string payloadMsg = msg->to_string();

        Payload payload = PayloadResolver::resolve(payloadMsg);

        string discriminator = payload.GetDiscriminator();
				
        if (discriminator == "update")
        {
            int payloadId = payload.GetPayloadId();
            
            messageArrived_.recieveAction(payloadId, "update");
        }
        else
        {
            string textMessage = payload.GetPayloadMessage();
            int payloadId = payload.GetPayloadId();

            messageArrived_.recieveMessage(payloadId, textMessage);
        }
	};

	void delivery_complete(mqtt::delivery_token_ptr token) override {
    };

public:
	MessageClientCallback(mqtt::async_client_ptr cli, mqtt::connect_options& connOpts, string topicClient, MessageArrived &messageArrived)
				: nretry_(0), cli_(cli), connOpts_(connOpts), subListener_(topicClient), topicClient_(topicClient), messageArrived_(messageArrived) {}
};

MessageClient::MessageClient(int messageClientId, int userId) : MessageNode(messageClientId), UserId(userId)
{
};

void MessageClient::SetupClient(MessageArrived &messageArrived)
{    
	auto connOpts = std::make_shared<mqtt::connect_options>();
    connOpts->set_keep_alive_interval(20);
    connOpts->set_clean_session(true);

    DatabaseAdapter adapter;
    string messageClientCode = adapter.GetClientNodeCodeById(_messageClientId);

    string defaultAddress = ConfigManager::getDefaultAddress();
	auto client = std::make_shared<mqtt::async_client>(defaultAddress, messageClientCode);
    string topicClient = GetTopic();
    
    MessageClientCallback msgcb(client, *connOpts, topicClient, messageArrived);
    auto messageCallback = std::make_shared<MessageClientCallback>(msgcb);
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

void MessageClient::DirectMessage(Payload payload)
{
    auto client = GetClient();
    string messageServiceBusCode = GetMessageServiceClientTopicCode();
	mqtt::message_ptr pubmsg = mqtt::make_message(messageServiceBusCode, payload.Stringfy());
	pubmsg->set_qos(QOS);
	client->publish(pubmsg)->wait_for(TIMEOUT);
};

string MessageClient::GetTopic()
{
    DatabaseAdapter adapter;
    return adapter.GetTopicCodeByClientNodeId(_messageClientId);
};

void MessageClient::Disconnect() 
{  
    auto client = GetClient();
    cout << "\nDisconnecting..." << endl;
    client->disconnect();
    cout << "Disconnected" << endl;
};