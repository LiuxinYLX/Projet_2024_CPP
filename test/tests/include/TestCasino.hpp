#ifndef TESTCASINO_HPP
#define TESTCASINO_HPP

#include <cppunit/extensions/HelperMacros.h>
#include "../include/Casino.hpp" 
#include "../include/Jeu.hpp" 

class TestCasino : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(TestCasino);
    CPPUNIT_TEST(testConstructor);
    CPPUNIT_TEST(testGetSetJeux);
    CPPUNIT_TEST_SUITE_END();

public:
    // void setUp() override; 
    // void tearDown() override; 
    
    void testConstructor();
    void testGetSetJeux();
};

#endif // TESTCASINO_HPP
