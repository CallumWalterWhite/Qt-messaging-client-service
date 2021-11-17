#include <iostream>
#include <cstdlib>
#include <string>
#include <thread>
#include <atomic>
#include <cstring>
#include <sstream>

#include <QApplication>

#include "layout/MessageArrived.h"
#include "layout/Login.h"

using namespace std;
int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	try 
	{		
		LoginRegisterMainWindow loginChat;

		loginChat.show();

		app.exec();
	}
	catch (const mqtt::exception& exc) {
        std::cerr << "\nERROR: Unable to connect to MQTT server: '"
            << "defaultAddress" << "'" << std::endl;
        exit(1);
	}

 	return 0;
}

