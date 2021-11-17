 #include <cppunit/extensions/TestFactoryRegistry.h>
 #include <cppunit/CompilerOutputter.h>
 #include <cppunit/TestResult.h>
 #include <cppunit/TestResultCollector.h>
 #include <cppunit/TestRunner.h>
 #include <cppunit/TextTestProgressListener.h>

#include "AlgorithmProviderTest.cpp"
#include "ReportAlgorithmTest.cpp"

class MyCustomProgressTestListener : public CppUnit::TextTestProgressListener {
 public:
     virtual void startTest(CppUnit::Test *test) {
         fprintf(stderr, "starting test %s\n", test->getName().c_str());
     }
};

int main( int ac, char **av )
{

  CppUnit::TestResult controller;
  CppUnit::TestResultCollector result;
  controller.addListener( &result );        
 
   // Add a listener that print test run.
  MyCustomProgressTestListener progress;
  controller.addListener( &progress );      

   // Add the top suite to the test runner
  CppUnit::TestRunner runner;
  runner.addTest( AlgorithmProviderTest::suite() );
  runner.addTest( ReportAlgorithmTest::suite() );
  //runner.setOutputter( );
  try
  {
    std::cout << "Running tests"  <<  std::endl;
    runner.run( controller );
 
    std::cerr << std::endl;
 
    CppUnit::CompilerOutputter outputter( &result, std::cerr );
    outputter.write();                      
  }
  catch ( std::invalid_argument &e ) 
  {
    return 0;
  }
 
   return result.wasSuccessful() ? 0 : 1;
}