#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include <sstream>
#include <cppunit/ui/text/TextTestRunner.h>
#include "../include/TestPersonnage.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(TestPersonnage);

    void TestPersonnage::testDormirDehors_casValide() {
        Personnage p;
        p.setEnergie(20);
        p.dormirDehors(2);//On dit chaque fois il dimunie 2 energie.
        CPPUNIT_ASSERT_EQUAL(18, p.getEnergie());
    }

    void TestPersonnage::testDormirDehors_casNonValide() {
        Personnage p;
        p.setEnergie(1);
        p.dormirDehors(2);//On dit chaque fois il dimunie 2 energie.
        CPPUNIT_ASSERT_EQUAL(1, p.getEnergie());
    }

    


