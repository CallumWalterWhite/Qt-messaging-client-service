#include "AlgorithmProvider.h"

using namespace std;

struct ComparePayloadDatesAsc {
    bool operator()(Payload& po, Payload& pt) const {
         return po.GetDateSent() < pt.GetDateSent();
    }
};

struct ComparePayloadDatesDsc {
    bool operator()(Payload& po, Payload& pt) const {
         return po.GetDateSent() > pt.GetDateSent();
    }
};

struct tm * timeinfo;

string AlgorithmProvider::ConvertTimeTtoDateString(time_t time)
{
    char buffer[80];
    timeinfo = localtime(&time);
    strftime(buffer,sizeof(buffer),"%d-%m-%Y",timeinfo);
    string dateStr(buffer);
    return dateStr;
};

string AlgorithmProvider::ConvertTimeTtoDateTimeString(time_t time)
{
    char buffer[80];
    timeinfo = localtime(&time);
    strftime(buffer,sizeof(buffer),"%a %b %d %H:%M:%S %Y",timeinfo);
    string dateStr(buffer);
    return dateStr;
};

void AlgorithmProvider::UniqueVectorString(vector<string> &v)
{
    sort( v.begin(), v.end() );
    v.erase( unique( v.begin(), v.end() ), v.end() );
};

pair<bool, int> AlgorithmProvider::findIndexInVector(const vector<int> &vlist, const int &value)
{
    std::pair<bool, int > result;
    auto it = std::find(vlist.begin(), vlist.end(), value);
    if (it != vlist.end())
    {
        result.second = distance(vlist.begin(), it);
        result.first = true;
    }
    else
    {
        result.first = false;
        result.second = -1;
    }
    return result;
};

void AlgorithmProvider::sortPayloadByDate(vector<Payload> &payloads, string &sortDesc)
{
    if (sortDesc == "DSC")
    {
        sort(payloads.begin(), payloads.end(), ComparePayloadDatesDsc());
    }
    else
    {
        sort(payloads.begin(), payloads.end(), ComparePayloadDatesAsc());
    }
};

vector<pair<string, int>> AlgorithmProvider::payloadByDay(vector<Payload> &payloads)
{
    vector<pair<string, int>> result;
    vector<string> vectorDateStr;
    unsigned size = payloads.size();
    for( unsigned i = 0; i < size; ++i )
    {
        time_t date = payloads[i].GetDateSent();
        string dateStr = AlgorithmProvider::ConvertTimeTtoDateString(date);
        vectorDateStr.push_back(dateStr);
    }
    UniqueVectorString(vectorDateStr);
    for ( unsigned i = 0; i < vectorDateStr.size(); i++)
    {
        string date = vectorDateStr[i];
        int sumPayloadMessages = 0;
        for ( unsigned x = 0; x < payloads.size(); x++)
        {
            time_t time = payloads[x].GetDateSent();
            string dateStr = AlgorithmProvider::ConvertTimeTtoDateString(time);
            if (dateStr == date)
            {
                sumPayloadMessages++;
            }
        }
        pair<string, int> payloadSums;
        payloadSums.second = sumPayloadMessages;
        payloadSums.first = date;
        result.push_back(payloadSums);
    }
    return result;
};

vector<pair<string, int>> AlgorithmProvider::payloadByUser(vector<Payload> &payloads)
{
    vector<pair<string, int>> result;
    vector<string> vectorUsers;
    unsigned size = payloads.size();
    for( unsigned i = 0; i < size; ++i )
    {
        string userName = payloads[i].GetUserName();
        vectorUsers.push_back(userName);
    }
    UniqueVectorString(vectorUsers);
    for ( unsigned i = 0; i < vectorUsers.size(); i++)
    {
        string userName = vectorUsers[i];
        int sumPayloadMessages = 0;
        for ( unsigned x = 0; x < payloads.size(); x++)
        {
            string payloadUsername = payloads[x].GetUserName();
            if (payloadUsername == userName)
            {
                sumPayloadMessages++;
            }
        }
        pair<string, int> payloadSums;
        payloadSums.second = sumPayloadMessages;
        payloadSums.first = userName;
        result.push_back(payloadSums);
    }
    return result;
};

vector<string> AlgorithmProvider::searchUserByUsername(map<int, string> &users, int excludeId, string search)
{
    vector<string> vectorUsers;
    if (search.empty())
    {
        unsigned size = users.size();
        for (const auto &iter : users)
        {
            if (iter.first != excludeId)
            {    
                vectorUsers.push_back(iter.second);
            }
        }
        return vectorUsers;
    }
    unsigned size = users.size();
    for (const auto &iter : users)
    {
        if (iter.first != excludeId)
        {    
            if (iter.second.find(search) != string::npos) 
            {
                vectorUsers.push_back(iter.second);
            }
        }
    }
    return vectorUsers;
};