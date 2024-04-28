#ifndef TEST_PERSONNAGE_HPP
#define TEST_PERSONNAGE_HPP

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../../include/Personnage.hpp"

class TestPersonnage : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(TestPersonnage);
    CPPUNIT_TEST(testDormirDehors_casValide);
    CPPUNIT_TEST(testDormirDehors_casNonValide);

    CPPUNIT_TEST_SUITE_END();

public:

    void testDormirDehors_casValide();
    void testDormirDehors_casNonValide();

};

#endif // TEST_BANQUE_HPP
