#ifndef TESTBLACKJ_HPP
#define TESTBLACKJ_HPP

#include <cppunit/extensions/HelperMacros.h>
#include "../include/BlackJ.hpp" 

class TestBlackJ : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(TestBlackJ);
    CPPUNIT_TEST(testDistribuer);
    CPPUNIT_TEST(testContinuer);
    CPPUNIT_TEST(testArreter);
    CPPUNIT_TEST(testCalculerPrime);
    CPPUNIT_TEST_SUITE_END();

public:
    // void setUp(void);
    // void tearDown(void); 
    
    void testDistribuer();
    void testContinuer();
    void testArreter();
    void testCalculerPrime();
};

#endif // TESTBLACKJ_HPP
