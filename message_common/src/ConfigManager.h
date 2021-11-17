#ifndef CONFIGMANAGER_H
#define CONFIGMANAGER_H

#include <string>

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

using namespace std;

class ConfigManager
{
    public:
        static string getClientId();
        static string getDbUsername();
        static string getDbPassword();
        static string getDefaultAddress();
        static string getDatabaseAddress();
        static string getClientNodePrefix();
        static string getClientTopicPrefix();
        static string getDefaultUserImage();
};

#endif