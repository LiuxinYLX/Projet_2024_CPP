#ifndef TEST_QUIZZ_HPP
#define TEST_QUIZZ_HPP

#include <cppunit/extensions/HelperMacros.h>
#include <list>
#include "Quizz.hpp"
#include "../include/Question.hpp"

class Test_Quizz : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(Test_Quizz);
    CPPUNIT_TEST(testConstructeur);
    CPPUNIT_TEST(testListQ);
    CPPUNIT_TEST(testListQFaites);
    CPPUNIT_TEST(testListQVide);
    // CPPUNIT_TEST(testCalculerGain);
    CPPUNIT_TEST_SUITE_END();

private:
    Quizz qui;

public:
    void setUp(void);
    void tearDown(void);

    void testConstructeur();

    void testListQ();

    void testListQFaites();

    void testListQVide();

    // void testCalculerGain();
};

CPPUNIT_TEST_SUITE_REGISTRATION(Test_Quizz);

#endif // TEST_QUIZZ_HPP
