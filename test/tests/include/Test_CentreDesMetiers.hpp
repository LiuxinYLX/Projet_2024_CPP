#ifndef TEST_CENTRE_DES_METIERS_HPP
#define TEST_CENTRE_DES_METIERS_HPP

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
#include "CentreDesMetiers.hpp"
#include "../include/Quizz.hpp"

class Test_CentreDesMetiers : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(Test_CentreDesMetiers);
    CPPUNIT_TEST(testAccederCDM);
    CPPUNIT_TEST(testSaisirDomaine);
    CPPUNIT_TEST_SUITE_END();

public:
    void testAccederCDM();

    void testSaisirDomaine();
};

CPPUNIT_TEST_SUITE_REGISTRATION(Test_CentreDesMetiers);

#endif // TEST_CENTRE_DES_METIERS_HPP
