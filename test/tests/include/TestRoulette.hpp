#ifndef TESTROULETTE_HPP
#define TESTROULETTE_HPP

#include <cppunit/extensions/HelperMacros.h>
#include "../include/Roulette.hpp"
#include "../include/Couleur.hpp"

class TestRoulette : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(TestRoulette);
    CPPUNIT_TEST(testChoisirI);
    CPPUNIT_TEST(testChoisirC);
    CPPUNIT_TEST(testChoisirP);
    CPPUNIT_TEST_SUITE_END();

public:
    // void setUp(void); 
    // void tearDown(void); 

    void testChoisirI();
    void testChoisirC();
    void testChoisirP();
};

#endif // TESTROULETTE_HPP
