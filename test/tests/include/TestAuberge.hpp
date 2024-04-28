#ifndef TESTAUBERGE_HPP
#define TESTAUBERGE_HPP

#include <cppunit/extensions/HelperMacros.h>
#include "../../include/Auberge.hpp"


class TestAuberge : public CppUnit::TestCase {
    CPPUNIT_TEST_SUITE(TestAuberge);
    CPPUNIT_TEST(testConstruction);
    CPPUNIT_TEST(testDormirSousUnToit);
    CPPUNIT_TEST(testVerfierCapital);
    CPPUNIT_TEST_SUITE_END();
    
public:

    void setUp();
    void tearDown();
    void testConstruction();
    void testDormirSousUnToit();
    void testVerfierCapital();
    
private: 
    Auberge* auberge1;
    Auberge* auberge2;
    
};

#endif // TESTAUBERGE_HPP
