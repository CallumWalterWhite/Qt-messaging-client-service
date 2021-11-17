
#include <cppunit/extensions/HelperMacros.h>
#include "../../../message_common/src/AlgorithmProvider.h"
#include "../../../message_common/src/Payload.h"
#include <string>
#include <vector>

time_t ConvertStringToTime_T(const char *time_details)
{
    struct tm tm;
    strptime(time_details, "%a %b %d %H:%M:%S %Y", &tm);
    time_t t = mktime(&tm);
    return t;
};
class AlgorithmProviderTest : public CPPUNIT_NS::TestFixture
{
  CPPUNIT_TEST_SUITE( AlgorithmProviderTest );
  CPPUNIT_TEST( ConvertTimeTtoDateTimeString_Test );
  CPPUNIT_TEST( FindIndexInVector_Test );
  CPPUNIT_TEST( UniqueVectorString_Test );
  CPPUNIT_TEST( SearchUserByUsername_Test );
  CPPUNIT_TEST( SortPayloadByDate_ASC_Test );
  CPPUNIT_TEST( SortPayloadByDate_DSC_Test );
  CPPUNIT_TEST_SUITE_END();
protected:
    void ConvertTimeTtoDateTimeString_Test();
    void FindIndexInVector_Test();
    void UniqueVectorString_Test();
    void SearchUserByUsername_Test();
    void SortPayloadByDate_ASC_Test();
    void SortPayloadByDate_DSC_Test();
};
void AlgorithmProviderTest::ConvertTimeTtoDateTimeString_Test()
{
    const char *time_details = "Thu Jan 01 00:59:59 1970";
    struct tm tm;
    strptime(time_details, "%a %b %d %H:%M:%S %Y", &tm);
    time_t t = mktime(&tm);
    std::string conversion = AlgorithmProvider::ConvertTimeTtoDateTimeString(t);
    std::string str(time_details);
    CPPUNIT_ASSERT_EQUAL(conversion, str);
};
void AlgorithmProviderTest::FindIndexInVector_Test()
{
    vector<int> vectors;
    vectors.push_back(1);
    vectors.push_back(2);
    vectors.push_back(3);
    vectors.push_back(4);

    pair<bool, int> result = AlgorithmProvider::findIndexInVector(vectors, 2);

    CPPUNIT_ASSERT_EQUAL(result.second, 1);
};
void AlgorithmProviderTest::UniqueVectorString_Test()
{
    vector<string> vectors;
    vectors.push_back("test");
    vectors.push_back("test");
    vectors.push_back("testtwo");

    AlgorithmProvider::UniqueVectorString(vectors);

    CPPUNIT_ASSERT_EQUAL(static_cast<int>(vectors.size()), 2);
};
void AlgorithmProviderTest::SearchUserByUsername_Test()
{
    map<int, string> userTests;
    userTests.insert(std::make_pair(1, "callum"));
    userTests.insert(std::make_pair(2, "david"));
    userTests.insert(std::make_pair(3, "james"));
    userTests.insert(std::make_pair(4, "connor"));
    userTests.insert(std::make_pair(5, "calwhite"));

    vector<string> namesSearched = AlgorithmProvider::searchUserByUsername(userTests, 5, "cal");

    CPPUNIT_ASSERT_EQUAL(static_cast<int>(namesSearched.size()), 1);
};
void AlgorithmProviderTest::SortPayloadByDate_ASC_Test()
{
    vector<Payload> vectors;
    const char *time_details1 = "Thu Jan 01 13:45:00 2020";
    const char *time_details2 = "Thu Jan 01 14:45:00 2020";
    const char *time_details3 = "Thu Jan 01 13:30:00 2020";
    const char *time_details4 = "Thu Jan 01 14:45:30 2020";
    time_t timeT1 = ConvertStringToTime_T(time_details1);
    time_t timeT2 = ConvertStringToTime_T(time_details2);
    time_t timeT3 = ConvertStringToTime_T(time_details3);
    time_t timeT4 = ConvertStringToTime_T(time_details4);

    Payload payload1("test", 1, 1, "direct");
    Payload payload2("test", 1, 1, "direct");
    Payload payload3("test", 1, 1, "direct");
    Payload payload4("test", 1, 1, "direct");

    payload1.SetDateSent(timeT1);
    payload2.SetDateSent(timeT2);
    payload3.SetDateSent(timeT3);
    payload4.SetDateSent(timeT4);
    
    vectors.push_back(payload1);
    vectors.push_back(payload2);
    vectors.push_back(payload3);
    vectors.push_back(payload4);

    string _asc = "ASC";

    AlgorithmProvider::sortPayloadByDate(vectors, _asc);

    CPPUNIT_ASSERT_EQUAL(vectors[0].GetPayloadMessage(), payload3.GetPayloadMessage());
};
void AlgorithmProviderTest::SortPayloadByDate_DSC_Test()
{
    vector<Payload> vectors;
    const char *time_details1 = "Thu Jan 01 13:45:00 2020";
    const char *time_details2 = "Thu Jan 01 14:45:00 2020";
    const char *time_details3 = "Thu Jan 01 13:30:00 2020";
    const char *time_details4 = "Thu Jan 01 14:45:30 2020";
    time_t timeT1 = ConvertStringToTime_T(time_details1);
    time_t timeT2 = ConvertStringToTime_T(time_details2);
    time_t timeT3 = ConvertStringToTime_T(time_details3);
    time_t timeT4 = ConvertStringToTime_T(time_details4);

    Payload payload1("test1", 1, 1, "direct");
    Payload payload2("test2", 1, 1, "direct");
    Payload payload3("test3", 1, 1, "direct");
    Payload payload4("test4", 1, 1, "direct");

    payload1.SetDateSent(timeT1);
    payload2.SetDateSent(timeT2);
    payload3.SetDateSent(timeT3);
    payload4.SetDateSent(timeT4);
    
    vectors.push_back(payload1);
    vectors.push_back(payload2);
    vectors.push_back(payload3);
    vectors.push_back(payload4);

    string _dsc = "DSC";

    AlgorithmProvider::sortPayloadByDate(vectors, _dsc);

    CPPUNIT_ASSERT_EQUAL(vectors[0].GetPayloadMessage(), payload4.GetPayloadMessage());
};