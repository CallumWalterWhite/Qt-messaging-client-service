#ifndef DATABASEADAPTER_H
#define DATABASEADAPTER_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <atomic>
#include <chrono>
#include <cstring>
#include <sstream>
#include <map>
#include <vector>
#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include "Payload.h"
#include "User.h"
using namespace std;

class DatabaseAdapter
{
    private:
        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *res;
        void Log(sql::SQLException &e);
        string ExecuteQuery(string query);
        map<string, string> ExecuteQueryReturnMap(string query);
        vector<int> ExecuteQueryReturnVector(string query);
    public:
        DatabaseAdapter();
	    ~DatabaseAdapter();
        string GetClientNodeCodeById(int clientNodeId);
        string GetTopicCodeById(int topicId);
        string GetTopicCodeByClientNodeId(int clientNodeId);
        int GetAggreateTopicIdByUserId(int userId);
        int GetMessageServiceClientId();
        string GetUserNameByClientNodeId(int clientNodeId);
        string GetUserNameByUserId(int userId);
        int GetUserIdByUsernamePassword(string username, string password);
        int GetClientIdByUserId(int userId);
        map<int, string> GetUsers();
        vector<Payload> GetPayloadMessagesByUserId(int userId, int senderId);
        vector<Payload> GetPayloads();
        Payload GetPayloadById(int payloadId);
        int SavePayload(string message, string discriminator, int topicId, int userId);
        vector<int> GetUsersByEmail(string email);
        vector<int> GetUsersByUsername(string username);
        int CreateUser(string email, string username, string password);
        int CreateClientNodeWithTopic(int userId, string clientNodePrefix, string clientTopicPrefix);
        void UpdateUser(int userId, string firstName, string lastName, string email, string username, string imageURL);
        void UpdatePayloadMessage(int payloadId, string payloadMessage);
        void DeletePayload(int payloadId);
        User GetUser(int userId);
};

#endif