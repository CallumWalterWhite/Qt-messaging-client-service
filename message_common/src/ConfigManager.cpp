#include <string>
#include <iostream>
#include <cstring>
#include <fstream>
#include <streambuf>
#include <cstdio>

#include "ConfigManager.h"

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/filereadstream.h"

using namespace std;
using namespace rapidjson;


static Document loadAppSettingsJsonDocument()
{
    FILE* fp = fopen("appsettings.json", "r");
    char readBuffer[65536];
    FileReadStream is(fp, readBuffer, sizeof(readBuffer));
    
    Document doc;
    doc.ParseStream(is);
    
    fclose(fp);

    return doc;
};

string ConfigManager::getClientId()
{  
    Document d = loadAppSettingsJsonDocument();
    const Value& config = d["config"];
    string clientId = config["clientId"].GetString();
    return clientId;
};

string ConfigManager::getDbUsername()
{  
    Document d = loadAppSettingsJsonDocument();
    const Value& config = d["config"];
    return config["db_login_username"].GetString();
};

string ConfigManager::getDbPassword()
{  
    Document d = loadAppSettingsJsonDocument();
    const Value& config = d["config"];
    return config["db_login_password"].GetString();
};

string ConfigManager::getDefaultAddress()
{  
    Document d = loadAppSettingsJsonDocument();
    const Value& config = d["config"];
    return config["msg_address"].GetString();
};

string ConfigManager::getDatabaseAddress()
{  
    Document d = loadAppSettingsJsonDocument();
    const Value& config = d["config"];
    return config["db_address"].GetString();
};

string ConfigManager::getClientNodePrefix()
{  
    Document d = loadAppSettingsJsonDocument();
    const Value& config = d["config"];
    return config["client_node_prefix"].GetString();
};

string ConfigManager::getClientTopicPrefix()
{  
    Document d = loadAppSettingsJsonDocument();
    const Value& config = d["config"];
    return config["client_topic_prefix"].GetString();
};

string ConfigManager::getDefaultUserImage()
{  
    Document d = loadAppSettingsJsonDocument();
    const Value& config = d["config"];
    return config["default_user_image"].GetString();
};
