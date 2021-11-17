
#include <cppunit/extensions/HelperMacros.h>
#include "../../../message_common/src/AlgorithmProvider.h"
#include "../../../message_common/src/Payload.h"
#include <string>
#include <vector>

time_t ConvertStringToTime__T(const char *time_details)
{
    struct tm tm;
    strptime(time_details, "%a %b %d %H:%M:%S %Y", &tm);
    time_t t = mktime(&tm);
    return t;
};
class ReportAlgorithmTest : public CPPUNIT_NS::TestFixture
{
  CPPUNIT_TEST_SUITE( ReportAlgorithmTest );
  CPPUNIT_TEST( PayloadByDay_Test );
  CPPUNIT_TEST( PayloadByUser_Test );
  CPPUNIT_TEST_SUITE_END();
protected:
    void PayloadByDay_Test();
    void PayloadByUser_Test();
};
void ReportAlgorithmTest::PayloadByDay_Test()
{
    vector<Payload> vectors;
    const char *time_details1 = "Thu Jan 01 13:45:00 2020";
    const char *time_details2 = "Thu Jan 01 14:45:00 2020";
    const char *time_details3 = "Thu Jan 01 13:30:00 2020";
    const char *time_details4 = "Thu Jan 01 14:45:30 2020";
    time_t timeT1 = ConvertStringToTime__T(time_details1);
    time_t timeT2 = ConvertStringToTime__T(time_details2);
    time_t timeT3 = ConvertStringToTime__T(time_details3);
    time_t timeT4 = ConvertStringToTime__T(time_details4);

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
    
    vector<pair<string, int>> result = AlgorithmProvider::payloadByDay(vectors);
    
    CPPUNIT_ASSERT_EQUAL(static_cast<int>(result.size()), 1);
};
void ReportAlgorithmTest::PayloadByUser_Test()
{
    vector<Payload> vectors;
    const char *time_details1 = "Thu Jan 01 13:45:00 2020";
    const char *time_details2 = "Thu Jan 01 14:45:00 2020";
    const char *time_details3 = "Thu Jan 01 13:30:00 2020";
    const char *time_details4 = "Thu Jan 01 14:45:30 2020";
    time_t timeT1 = ConvertStringToTime__T(time_details1);
    time_t timeT2 = ConvertStringToTime__T(time_details2);
    time_t timeT3 = ConvertStringToTime__T(time_details3);
    time_t timeT4 = ConvertStringToTime__T(time_details4);

    Payload payload1("test", 2, 2, "direct");
    Payload payload2("test", 2, 2, "direct");
    Payload payload3("test", 2, 2, "direct");
    Payload payload4("test", 2, 2, "direct");

    payload1.SetDateSent(timeT1);
    payload2.SetDateSent(timeT2);
    payload3.SetDateSent(timeT3);
    payload4.SetDateSent(timeT4);
    
    vectors.push_back(payload1);
    vectors.push_back(payload2);
    vectors.push_back(payload3);
    vectors.push_back(payload4);
    
    vector<pair<string, int>> result = AlgorithmProvider::payloadByUser(vectors);
    
    CPPUNIT_ASSERT_EQUAL(static_cast<int>(result.size()), 1);
};