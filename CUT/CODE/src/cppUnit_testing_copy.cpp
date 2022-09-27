#include <iostream>
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
#include <netinet/in.h>
#include <string>
#include "alumni_class.cpp"
#include "student_class.cpp"
//#include "validation.cpp"


using namespace CppUnit;
using namespace std;

class test: public CppUnit::TestFixture
{	
	CPPUNIT_TEST_SUITE(test);
	CPPUNIT_TEST(test_Email_check);
        CPPUNIT_TEST(test_check_alumni_register_number);
        CPPUNIT_TEST(test_alumni_get_data);
	CPPUNIT_TEST(test_Edit_Info);
	CPPUNIT_TEST_SUITE_END();
	
	public:
		void setUp(void);
		void tearDown(void);
	protected:
          void test_Email_check(void);
          void test_check_alumni_register_number(void);
          void test_alumni_get_data(void);
          void test_Edit_Info(void);
	private:
		Alumni  *myobj1;
		student *myobj2;
        	validations *myobj3;
};

void test:: test_Email_check(void)
{
	CPPUNIT_ASSERT(false==myobj3->Email_check("rehanappm@gmail.com"));
}


void test:: test_check_alumni_register_number(void)
{
        CPPUNIT_ASSERT(0==myobj3->check_alumni_register_number("UA1000"));
}

void test:: test_alumni_get_data(void)
{
        CPPUNIT_ASSERT(1==myobj1->alumni_get_data());
}


void test::test_Edit_Info(void)
{
	CPPUNIT_ASSERT(0==myobj2->Edit_Info("1000"));
}

void test::setUp(void)
{
	myobj1=new Alumni();
	myobj2=new student();
        myobj3=new validations();
}

void test::tearDown(void)
{
	delete myobj1;
	delete myobj2;
        delete myobj3;
}

CPPUNIT_TEST_SUITE_REGISTRATION(test);

int main(int argc,char* argv[])
{
	CPPUNIT_NS::TestResult testresult;
	CPPUNIT_NS::TestResultCollector collectedresults;
	testresult.addListener(&collectedresults);
	CPPUNIT_NS::BriefTestProgressListener progress;
	testresult.addListener(&progress);
	CPPUNIT_NS::TestRunner testrunner;
	testrunner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
	testrunner.run(testresult);
	CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults,std::cerr);
	compileroutputter.write();
	return collectedresults.wasSuccessful()?0:1;

}


