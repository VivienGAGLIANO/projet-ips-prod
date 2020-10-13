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
bool suite_TestSchrodinger_init = false;
#include "test_schrodinger.h"

static TestSchrodinger suite_TestSchrodinger;

static CxxTest::List Tests_TestSchrodinger = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestSchrodinger( "test_schrodinger.h", 8, "TestSchrodinger", suite_TestSchrodinger, Tests_TestSchrodinger );

static class TestDescription_suite_TestSchrodinger_testSchrodingerPSI : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestSchrodinger_testSchrodingerPSI() : CxxTest::RealTestDescription( Tests_TestSchrodinger, suiteDescription_TestSchrodinger, 11, "testSchrodingerPSI" ) {}
 void runTest() { suite_TestSchrodinger.testSchrodingerPSI(); }
} testDescription_suite_TestSchrodinger_testSchrodingerPSI;

static class TestDescription_suite_TestSchrodinger_testSchrodingerPSI_SECOND : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestSchrodinger_testSchrodingerPSI_SECOND() : CxxTest::RealTestDescription( Tests_TestSchrodinger, suiteDescription_TestSchrodinger, 26, "testSchrodingerPSI_SECOND" ) {}
 void runTest() { suite_TestSchrodinger.testSchrodingerPSI_SECOND(); }
} testDescription_suite_TestSchrodinger_testSchrodingerPSI_SECOND;

static class TestDescription_suite_TestSchrodinger_testSchrodingerPSI_ENERGY : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestSchrodinger_testSchrodingerPSI_ENERGY() : CxxTest::RealTestDescription( Tests_TestSchrodinger, suiteDescription_TestSchrodinger, 42, "testSchrodingerPSI_ENERGY" ) {}
 void runTest() { suite_TestSchrodinger.testSchrodingerPSI_ENERGY(); }
} testDescription_suite_TestSchrodinger_testSchrodingerPSI_ENERGY;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
