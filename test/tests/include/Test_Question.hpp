#ifndef TEST_QUESTION_HPP
#define TEST_QUESTION_HPP

#include <cppunit/extensions/HelperMacros.h>
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
#include <iostream>
#include <string>
#include <sstream> 
#include "Question.hpp"

class Test_Question : public CppUnit::TestFixture {
    public:
    Test_Question(); 
    ~Test_Question(); 

    // La liste de tests qu'on va réaliser
    CPPUNIT_TEST_SUITE(Test_Question);
    CPPUNIT_TEST(testConstructeur);
    // CPPUNIT_TEST(testRepQuestion_nominal);
    // CPPUNIT_TEST(testRepQuestion_erreur);
    // CPPUNIT_TEST(testRepQuestion_lim);
    CPPUNIT_TEST_SUITE_END();

private:
    Question q;

public:
    void setUp(void);
    void tearDown(void);

    void testConstructeur();
    // void testRepQuestion_nominal();
    // void testRepQuestion_erreur();
    // void testRepQuestion_lim();
};

CPPUNIT_TEST_SUITE_REGISTRATION(Test_Question);
#endif 
