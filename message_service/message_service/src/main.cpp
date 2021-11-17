#include <iostream>
#include <cstdlib>
#include <string>
#include <thread>
#include <atomic>
#include <cstring>
#include <sstream>

#include "mqtt/async_client.h"
#include "MessageService.h"
#include "../../../message_common/src/DatabaseAdapter.h"
#include "../../../message_common/src/ConfigManager.h"

using namespace std;

int GetMessageServiceClientId()
{
    DatabaseAdapter adapter;
    int clientId = adapter.GetMessageServiceClientId();
    return clientId;
};

int main(int argc, char* argv[])
{
	try 
	{
		int messageServiceClientId = GetMessageServiceClientId();

		MessageService messageService(messageServiceClientId);
		
		messageService.SetupService();
		
		cout << "Message client created!" << endl;

		while (std::tolower(std::cin.get()) != 'q')
		{
		}

		messageService.Disconnect();
	}
	catch (const mqtt::exception& exc) {
        std::cerr << "\nERROR: Unable to connect to MQTT server: '"
            << "defaultAddress" << "'" << std::endl;
        exit(1);
	}

 	return 0;
}

