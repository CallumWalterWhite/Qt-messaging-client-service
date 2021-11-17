#ifndef ALGORITHPROVIDER_H
#define ALGORITHPROVIDER_H

#include <vector>
#include <algorithm>
#include <map>
#include <ctime>
#include <sstream>
#include <iostream>
#include "Payload.h"

using namespace std;

class AlgorithmProvider {
    private:
        static string ConvertTimeTtoDateString(time_t time);
    public:
        static void UniqueVectorString(vector<string> &v);
        static pair<bool, int> findIndexInVector(const vector<int> &vlist, const int &value);
        static void sortPayloadByDate(vector<Payload> &payloads, string &sort);
        static vector<pair<string, int>> payloadByDay(vector<Payload> &payloads);
        static vector<pair<string, int>> payloadByUser(vector<Payload> &payloads);
        static vector<string> searchUserByUsername(map<int, string> &users, int excludeId, string search);
        static string ConvertTimeTtoDateTimeString(time_t time);
};

#endif