#include <bits/stdc++.h>
#include <list>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <netinet/in.h>

#include "testfunction.h"

using namespace CppUnit;
using namespace std;

class TestDriver : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestDriver);
    CPPUNIT_TEST(TestCustomerSunnyCase1);
    CPPUNIT_TEST(TestCustomerSunnyCase2);
    CPPUNIT_TEST(TestCustomerSunnyCase3);
    CPPUNIT_TEST(TestCustomerSunnyCase4);
    CPPUNIT_TEST(TestCustomerSunnyCase5);
    CPPUNIT_TEST(TestCustomerRainyCase1);
    CPPUNIT_TEST(TestCustomerRainyCase2);
    CPPUNIT_TEST(TestCustomerRainyCase3);
    CPPUNIT_TEST(TestCustomerRainyCase4);
    CPPUNIT_TEST(TestCustomerRainyCase5);
    CPPUNIT_TEST(TestDateSunnyCase1);
    CPPUNIT_TEST(TestDateSunnyCase2);
    CPPUNIT_TEST(TestDateSunnyCase3);
    CPPUNIT_TEST(TestDateSunnyCase4);
    CPPUNIT_TEST(TestDateSunnyCase5);
    CPPUNIT_TEST(TestDateRainyCase1);
    CPPUNIT_TEST(TestDateRainyCase2);
    CPPUNIT_TEST(TestDateRainyCase3);
    CPPUNIT_TEST(TestDateRainyCase4);
    CPPUNIT_TEST(TestDateRainyCase5);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp(void);
    void tearDown(void);

protected:
    void TestCustomerSunnyCase1(void);
    void TestCustomerSunnyCase2(void);
    void TestCustomerSunnyCase3(void);
    void TestCustomerSunnyCase4(void);
    void TestCustomerSunnyCase5(void);
    void TestCustomerRainyCase1(void);
    void TestCustomerRainyCase2(void);
    void TestCustomerRainyCase3(void);
    void TestCustomerRainyCase4(void);
    void TestCustomerRainyCase5(void);
    void TestDateSunnyCase1(void);
    void TestDateSunnyCase2(void);
    void TestDateSunnyCase3(void);
    void TestDateSunnyCase4(void);
    void TestDateSunnyCase5(void);
    void TestDateRainyCase1(void);
    void TestDateRainyCase2(void);
    void TestDateRainyCase3(void);
    void TestDateRainyCase4(void);
    void TestDateRainyCase5(void);
};

void TestDriver::TestCustomerSunnyCase1(void)
{
    CPPUNIT_ASSERT(1 == tokenizingFile("1230321|Sai|Reddy|1-190,SBI Colony,Puttur,Chittoor|9701386578|New|"));
}
void TestDriver::TestCustomerSunnyCase2(void)
{
    CPPUNIT_ASSERT(1 == tokenizingFile("1230323|Venkatesh|Gunake|302, N.G.Mill, Murarji Peth, Solapur-413001|8686661077|New|"));
}
void TestDriver::TestCustomerSunnyCase3(void)
{
    CPPUNIT_ASSERT(1 == tokenizingFile("1230325|Vedant|Ban|Shriram Colony, Sailu, Maharashtra - 431503|9420821191|New|"));
}
void TestDriver::TestCustomerSunnyCase4(void)
{
    CPPUNIT_ASSERT(1 == tokenizingFile("1230329|John|Mathews|2-2/5,Galleria Complex,Bengaluru|9441534599|Existing|"));
}
void TestDriver::TestCustomerSunnyCase5(void)
{
    CPPUNIT_ASSERT(1 == tokenizingFile("1230324|Pushpendra|Yadav|Ayodhya, Uttar Pradesh|7705888861|Existing|"));
}
void TestDriver::TestCustomerRainyCase1(void)
{
    CPPUNIT_ASSERT(0 == tokenizingFile("1230324|Pushpendra|Yadav|Ayodhya, Uttar Pradesh||Existing|"));
}
void TestDriver::TestCustomerRainyCase2(void)
{
    CPPUNIT_ASSERT(0 == tokenizingFile("1230526|Vedant|Ban||9420821191|New|"));
}
void TestDriver::TestCustomerRainyCase3(void)
{
    CPPUNIT_ASSERT(0 == tokenizingFile("||||||"));
}
void TestDriver::TestCustomerRainyCase4(void)
{
    CPPUNIT_ASSERT(0 == tokenizingFile("1230333||||9485859898|Existing|"));
}
void TestDriver::TestCustomerRainyCase5(void)
{
    CPPUNIT_ASSERT(0 == tokenizingFile("1230327|Ankur|||Sangli|New|"));
}

//--------------Date Validation------------

void TestDriver::TestDateSunnyCase1(void)
{
    CPPUNIT_ASSERT(1 == dateValidation("01/05/2002"));
}

void TestDriver::TestDateSunnyCase2(void)
{
    CPPUNIT_ASSERT(1 == dateValidation("27/07/2021"));
}
void TestDriver::TestDateSunnyCase3(void)
{
    CPPUNIT_ASSERT(1 == dateValidation("29/02/2000"));
}
void TestDriver::TestDateSunnyCase4(void)
{
    CPPUNIT_ASSERT(1 == dateValidation("15/11/2011"));
}
void TestDriver::TestDateSunnyCase5(void)
{
    CPPUNIT_ASSERT(1 == dateValidation("08/07/2022"));
}
void TestDriver::TestDateRainyCase1(void)
{
    CPPUNIT_ASSERT(0 == dateValidation("29/02/2022"));
}
void TestDriver::TestDateRainyCase2(void)
{
    CPPUNIT_ASSERT(0 == dateValidation("31/09/2015"));
}
void TestDriver::TestDateRainyCase3(void)
{
    CPPUNIT_ASSERT(0 == dateValidation("30/12/1996"));
}
void TestDriver::TestDateRainyCase4(void)
{
    CPPUNIT_ASSERT(0 == dateValidation("13/15/2010"));
}
void TestDriver::TestDateRainyCase5(void)
{
    CPPUNIT_ASSERT(0 == dateValidation("07/04/2025"));
}
void TestDriver::setUp(void)
{

}

void TestDriver::tearDown(void)
{
   
}


CPPUNIT_TEST_SUITE_REGISTRATION( TestDriver );

int main(int argc, char* argv[])
{
    // informs test-listener about testresults
    CPPUNIT_NS::TestResult testresult;

    // register listener for collecting the test-results
    CPPUNIT_NS::TestResultCollector collectedresults;
    testresult.addListener (&collectedresults);

    // register listener for per-test progress output
    CPPUNIT_NS::BriefTestProgressListener progress;
    testresult.addListener (&progress);

    // insert test-suite at test-runner by registry
    CPPUNIT_NS::TestRunner testrunner;
    testrunner.addTest (CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest ());
    testrunner.run(testresult);

    // output results in compiler-format
    CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
    compileroutputter.write ();

    // Output XML for Jenkins CPPunit plugin
    ofstream xmlFileOut("TestResults.xml");
    XmlOutputter xmlOut(&collectedresults, xmlFileOut);
    xmlOut.write();

    // return 0 if tests were successful
    return collectedresults.wasSuccessful() ? 0 : 1;
}