/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_TestHermit_init = false;
#include "test_hermit.h"

static TestHermit suite_TestHermit;

static CxxTest::List Tests_TestHermit = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestHermit( "test_hermit.h", 4, "TestHermit", suite_TestHermit, Tests_TestHermit );

static class TestDescription_suite_TestHermit_testHermit : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestHermit_testHermit() : CxxTest::RealTestDescription( Tests_TestHermit, suiteDescription_TestHermit, 7, "testHermit" ) {}
 void runTest() { suite_TestHermit.testHermit(); }
} testDescription_suite_TestHermit_testHermit;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
