#include <string>
#include <map>
#include "DatabaseAdapter.h"
#include "ConfigManager.h"
#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

DatabaseAdapter::DatabaseAdapter()
{
    driver = get_driver_instance();
    string address = ConfigManager::getDatabaseAddress();
    con = driver->connect(address, ConfigManager::getDbUsername(), ConfigManager::getDbPassword());
    string schema = ConfigManager::getClientId();
    con->setSchema(schema);
};

DatabaseAdapter::~DatabaseAdapter()
{
    if (res)
    {
        delete res;
        delete stmt;
    }
    delete con;
};

string DatabaseAdapter::ExecuteQuery(string query)
{
    string result;
    try {
        stmt = con->createStatement();
        res = stmt->executeQuery(query);
        while (res->next()) 
        {
            result = res->getString(1);
        }

    } catch (sql::SQLException &e) {
        Log(e);
    }
    return result;
};

map<string, string> DatabaseAdapter::ExecuteQueryReturnMap(string query)
{
    map<string, string> result;
    try {
        stmt = con->createStatement();
        res = stmt->executeQuery(query);
        while (res->next()) 
        {
            result[res->getString(1)] = res->getString(2);
        }

    } catch (sql::SQLException &e) {
        Log(e);
    }
    return result;
};

vector<int> DatabaseAdapter::ExecuteQueryReturnVector(string query)
{
    vector<int> results;
    try {
        stmt = con->createStatement();
        res = stmt->executeQuery(query);
        while (res->next()) 
        {
            int vectorValue = stoi(res->getString(1));
            results.push_back(vectorValue);
        }

    } catch (sql::SQLException &e) {
        Log(e);
    }
    return results;
}

string DatabaseAdapter::GetClientNodeCodeById(int clientNodeId)
{
    ostringstream oss;
    oss << "SELECT Code FROM client_node WHERE Id = '" << std::to_string(clientNodeId) << "'";
    string query = oss.str();
    return ExecuteQuery(query);
};

int DatabaseAdapter::GetClientIdByUserId(int userId)
{
    ostringstream oss;
    oss << "SELECT ClientNodeId FROM user_client_node WHERE UserId = '" << std::to_string(userId) << "'";
    string query = oss.str();
    string result = ExecuteQuery(query);
    if (result.length() > 0)
    {
        return std::stoi(result);
    }
    else
    {
        return -1;
    }
};

string DatabaseAdapter::GetTopicCodeById(int topicId)
{
    ostringstream oss;
    oss << "SELECT Value FROM topics WHERE Id = '" << std::to_string(topicId) << "'";
    string query = oss.str();
    return ExecuteQuery(query);
};

string DatabaseAdapter::GetTopicCodeByClientNodeId(int clientNodeId)
{
    ostringstream oss;
    oss << "SELECT topics.Value FROM topics join client_node_topic on client_node_topic.TopicId = topics.Id WHERE client_node_topic.ClientNodeId = " << std::to_string(clientNodeId) << "";
    string query = oss.str();
    return ExecuteQuery(query);
};

int DatabaseAdapter::GetAggreateTopicIdByUserId(int userId)
{
    ostringstream oss;
    oss << "SELECT client_node_topic.TopicId FROM client_node_topic join user_client_node on user_client_node.ClientNodeId = client_node_topic.ClientNodeId WHERE user_client_node.UserId  = " << std::to_string(userId);
    string query = oss.str();
    string result = ExecuteQuery(query);
    return std::stoi(result);
}

string DatabaseAdapter::GetUserNameByClientNodeId(int clientNodeId)
{
    ostringstream oss;
    oss << "SELECT UserName FROM user_client_node join user on user.Id = user_client_node.UserId where user_client_node.ClientNodeId = " << std::to_string(clientNodeId) << "";
    string query = oss.str();
    return ExecuteQuery(query);
};

string DatabaseAdapter::GetUserNameByUserId(int userId)
{
    ostringstream oss;
    oss << "SELECT UserName FROM user WHERE Id = " << std::to_string(userId) << "";
    string query = oss.str();
    return ExecuteQuery(query);
};

int DatabaseAdapter::GetMessageServiceClientId()
{
    string query = "SELECT Id FROM client_node WHERE MessageService = 1";
    string result = ExecuteQuery(query);
    return std::stoi(result);
};

int DatabaseAdapter::GetUserIdByUsernamePassword(string username, string password)
{
    ostringstream oss;
    oss << "SELECT Id FROM user join user_password on user_password.UserId = user.Id WHERE user.UserName = '" << username << "' and user_password.password = SHA1('" << password << "')";
    string query = oss.str();
    string result = ExecuteQuery(query);
    if (result.length() > 0)
    {
        return std::stoi(result);
    }
    else
    {
        return -1;
    }
};

map<int, string> DatabaseAdapter::GetUsers()
{
    map<int, string> result;
    string query = "SELECT Id, UserName FROM user";
    map<string, string> stringResult = ExecuteQueryReturnMap(query);
    for (const auto &iter : stringResult)
    {
        result[std::stoi(iter.first)] = iter.second;
    }
    return result;
};

vector<Payload> DatabaseAdapter::GetPayloadMessagesByUserId(int userId, int senderId)
{
    vector<Payload> payloads;
    ostringstream oss;
    oss << "SELECT payload_history.Id, payload_history.PayloadMessage, payload_history.Discriminator, payload_history.TopicId, payload_history.UserId, UNIX_TIMESTAMP(payload_history.DateSent) As DateSent FROM client_node_topic join user_client_node on user_client_node.ClientNodeId = client_node_topic.ClientNodeId join user on user.Id = user_client_node.UserId join payload_history on payload_history.TopicId = client_node_topic.TopicId WHERE (user_client_node.UserId  = " << std::to_string(userId) << " AND payload_history.UserId = " << std::to_string(senderId) << ") OR (user_client_node.UserId  = " << std::to_string(senderId) << " AND payload_history.UserId = " << std::to_string(userId) << ") order by payload_history.DateSent";
    string query = oss.str();
    
    
    stmt = con->createStatement();
    res = stmt->executeQuery(query);
    while (res->next()) 
    {
        int payloadId = res->getInt(1);
        string payloadMessage = res->getString(2);
        int clientTopicId = res->getInt(4);
        int clientUserId = res->getInt(5);
        string discriminator = res->getString(3);
        time_t dateSent =  res->getInt(6);

        Payload payload(payloadMessage, clientTopicId, clientUserId, discriminator);
    
        payload.SetDateSent(dateSent);
        payload.SetId(payloadId);

        payloads.push_back(payload);
    }

    return payloads;
};

vector<Payload> DatabaseAdapter::GetPayloads()
{
    vector<Payload> payloads;
    ostringstream oss;
    oss << "SELECT payload_history.Id, payload_history.PayloadMessage, payload_history.Discriminator, payload_history.TopicId, payload_history.UserId, UNIX_TIMESTAMP(payload_history.DateSent) As DateSent FROM payload_history";
    string query = oss.str();
    
    
    stmt = con->createStatement();
    res = stmt->executeQuery(query);
    while (res->next()) 
    {
        int payloadId = res->getInt(1);
        string payloadMessage = res->getString(2);
        int clientTopicId = res->getInt(4);
        int clientUserId = res->getInt(5);
        string discriminator = res->getString(3);
        time_t dateSent =  res->getInt(6);

        Payload payload(payloadMessage, clientTopicId, clientUserId, discriminator);
    
        payload.SetDateSent(dateSent);
        payload.SetId(payloadId);

        payloads.push_back(payload);
    }

    return payloads;
};

Payload DatabaseAdapter::GetPayloadById(int payloadId)
{
    ostringstream oss;
    oss << "SELECT payload_history.Id, payload_history.PayloadMessage, payload_history.Discriminator, payload_history.TopicId, payload_history.UserId, UNIX_TIMESTAMP(payload_history.DateSent) As DateSent FROM payload_history WHERE payload_history.Id = " << std::to_string(payloadId);
    string query = oss.str();
    
    
    stmt = con->createStatement();
    res = stmt->executeQuery(query);
    while (res->next()) 
    {
        int payloadId = res->getInt(1);
        string payloadMessage = res->getString(2);
        int clientTopicId = res->getInt(4);
        int clientUserId = res->getInt(5);
        string discriminator = res->getString(3);
        time_t dateSent =  res->getInt(6);

        Payload _payload(payloadMessage, clientTopicId, clientUserId, discriminator);
    
        _payload.SetDateSent(dateSent);
        _payload.SetId(payloadId);

        return _payload;
    }
};

int DatabaseAdapter::SavePayload(string message, string discriminator, int topicId, int userId)
{
    string result;
    con->setAutoCommit(false);
    stmt = con->createStatement();

    ostringstream oss;
    oss << "INSERT INTO payload_history (PayloadMessage, Discriminator, TopicId, UserId, DateSent) VALUES('" << message << "', '" << discriminator << "', " << std::to_string(topicId) << ", " << std::to_string(userId) << ", NOW());";
    string query = oss.str();

    stmt->execute(query);

    res = stmt->executeQuery("SELECT LAST_INSERT_ID() as Id");
    while (res->next()) 
    {
        result = res->getString(1);
    }

    con->commit();

    if (result.length() > 0)
    {
        return std::stoi(result);
    }
    else
    {
        return -1;
    }
}

int DatabaseAdapter::CreateUser(string email, string username, string password)
{
    int userId;
    con->setAutoCommit(false);
    stmt = con->createStatement();

    string imageURL = ConfigManager::getDefaultUserImage();

    ostringstream oss;
    oss << "INSERT INTO user (FirstName, LastName, Email, UserName, ImageURL) VALUES(NULL, NULL, '" << email << "', '" << username << "', '" << imageURL << "');";
    string query = oss.str();

    stmt->execute(query);
    
    res = stmt->executeQuery("SELECT LAST_INSERT_ID() as Id");
    while (res->next()) 
    {
        userId = res->getInt(1);
    }

    ostringstream oss_p;
    oss_p << "INSERT INTO user_password (UserId, password) VALUES('" << std::to_string(userId) << "', SHA1('" << password << "'));";
    query = oss_p.str();

    stmt->execute(query);

    con->commit();

    return userId;
}

int DatabaseAdapter::CreateClientNodeWithTopic(int userId, string clientNodePrefix, string clientTopicPrefix)
{
    int clientNodeId;
    int clientTopicId;
    con->setAutoCommit(false);
    stmt = con->createStatement();

    ostringstream oss_c;
    oss_c << clientNodePrefix << "_" << std::to_string(userId);
    string clientNodeCode = oss_c.str();
    
    ostringstream oss_t;
    oss_t << clientTopicPrefix << "_" << std::to_string(userId);
    string clientTopicCode = oss_c.str();

    ostringstream oss;
    oss << "INSERT INTO client_node (Code, MessageService) VALUES('" << clientNodeCode << "', 0);";
    string query = oss.str();

    stmt->execute(query);
    
    res = stmt->executeQuery("SELECT LAST_INSERT_ID() as Id");
    while (res->next()) 
    {
        clientNodeId = stoi(res->getString(1));
    }

    ostringstream oss_ts;
    oss_ts << "INSERT INTO topics (Value) VALUES('" << clientTopicCode << "');";
    query = oss_ts.str();
    
    stmt->execute(query);

    res = stmt->executeQuery("SELECT LAST_INSERT_ID() as Id");
    while (res->next()) 
    {
        clientTopicId = stoi(res->getString(1));
    }
    
    ostringstream oss_tnc;
    oss_tnc << "INSERT INTO client_node_topic (ClientNodeId, TopicId) VALUES(" << std::to_string(clientNodeId) << ", " << std::to_string(clientTopicId) << ");";
    query = oss_tnc.str();
    
    stmt->execute(query);

    ostringstream oss_ucn;
    oss_ucn << "INSERT INTO user_client_node (UserId, ClientNodeId) VALUES(" << std::to_string(userId) << ", " << std::to_string(clientNodeId) << ");";
    query = oss_ucn.str();
    
    stmt->execute(query);

    con->commit();

    return clientNodeId;
};

void DatabaseAdapter::UpdateUser(int userId, string firstName, string lastName, string email, string username, string imageURL)
{
    stmt = con->createStatement();
    ostringstream oss_ucn;
    oss_ucn << "UPDATE user SET FirstName = '" << firstName << "', LastName = '" << lastName << "', Email = '" << email << "', UserName = '" << username << "', ImageURL = '" << imageURL << "' WHERE Id = " << std::to_string(userId);
    string query = oss_ucn.str();
    
    stmt->execute(query);

    con->commit();
};

void DatabaseAdapter::UpdatePayloadMessage(int payloadId, string payloadMessage)
{
    stmt = con->createStatement();
    ostringstream oss_ucn;
    oss_ucn << "UPDATE payload_history SET PayloadMessage = '" << payloadMessage << "' WHERE Id = " << std::to_string(payloadId);
    string query = oss_ucn.str();
    
    stmt->execute(query);

    con->commit();
};

void DatabaseAdapter::DeletePayload(int payloadId)
{
    stmt = con->createStatement();
    ostringstream oss_ucn;
    oss_ucn << "DELETE FROM payload_history WHERE Id = " << std::to_string(payloadId);
    string query = oss_ucn.str();
    
    stmt->execute(query);

    con->commit();
};

vector<int> DatabaseAdapter::GetUsersByEmail(string email)
{
    ostringstream oss;
    oss << "SELECT Id FROM user WHERE Email = '" << email << "'";
    string query = oss.str();
    return ExecuteQueryReturnVector(query);
};

vector<int> DatabaseAdapter::GetUsersByUsername(string username)
{
    ostringstream oss;
    oss << "SELECT Id FROM user WHERE UserName = '" << username << "'";
    string query = oss.str();
    return ExecuteQueryReturnVector(query);
};

User DatabaseAdapter::GetUser(int userId)
{
    ostringstream oss;
    oss << "SELECT Id, FirstName, LastName, Email, UserName, ImageURL FROM user where Id = " << std::to_string(userId);
    string query = oss.str();
    
    
    stmt = con->createStatement();
    res = stmt->executeQuery(query);
    res->next();
    
    string firstName = res->getString(2);
    string lastName = res->getString(3);
    string email = res->getString(4);
    string userName = res->getString(5);
    string imageURL = res->getString(6);

    return User(userId, firstName, lastName, email, userName, imageURL);
};

void DatabaseAdapter::Log(sql::SQLException &e)
{
    cout << "# ERR: SQLException in " << __FILE__;
    cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
    cout << "# ERR: " << e.what();
    cout << " (MySQL error code: " << e.getErrorCode();
    cout << ", SQLState: " << e.getSQLState() << " )" << endl;
};