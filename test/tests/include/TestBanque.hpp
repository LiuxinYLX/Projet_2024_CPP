#ifndef TEST_BANQUE_HPP
#define TEST_BANQUE_HPP

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include "Personnage.hpp"
#include "Emprunt.hpp"
#include "Banque.hpp"
#include "Batiment.hpp"

class TestBanque : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(TestBanque);
    // CPPUNIT_TEST(testEmprunter_casValide);
    // CPPUNIT_TEST(testEmprunter_casLimite);
    // CPPUNIT_TEST(testEmprunter_casNonValide1);
    // // CPPUNIT_TEST(testEmprunter_casNonValide2);
    // CPPUNIT_TEST(testRembourser_casValide);
    // CPPUNIT_TEST(testRembourser_casNonValide1);
    // CPPUNIT_TEST(testRembourser_casNonValide2);
    CPPUNIT_TEST(testProcessusEmprunter_casNormal);
    CPPUNIT_TEST(testProcessusEmprunter_casErreur1);
    CPPUNIT_TEST(testProcessusEmprunter_casErreur2);
    CPPUNIT_TEST(testProcessusEmprunter_casLimite);
    CPPUNIT_TEST(testProcessusRembourser_casNormal);
    CPPUNIT_TEST(testProcessusRembourser_casErreur1);
    CPPUNIT_TEST(testProcessusRembourser_casErreur2);
    CPPUNIT_TEST(testProcessusRembourser_casLimite);
    CPPUNIT_TEST(testJeuTapeRapideLimite);
    CPPUNIT_TEST(testJeuTapeRapideCorrectEtRapide);
    CPPUNIT_TEST(testJeuTapeRapideCorrectMaisTropLent);
    CPPUNIT_TEST(testJeuTapeRapideIncorrect);
    CPPUNIT_TEST_SUITE_END();

public:
    // void testEmprunter_casValide();
    // void testEmprunter_casLimite();
    // void testEmprunter_casNonValide1();
    // void testEmprunter_casNonValide2();
    // void testRembourser_casValide();
    // void testRembourser_casNonValide1();
    // void testRembourser_casNonValide2();
    void testProcessusEmprunter_casNormal();
    void testProcessusEmprunter_casErreur1();
    void testProcessusEmprunter_casErreur2();
    void testProcessusEmprunter_casLimite();
    void testProcessusRembourser_casNormal();
    void testProcessusRembourser_casErreur1();
    void testProcessusRembourser_casErreur2();
    void testProcessusRembourser_casLimite();
    void testJeuTapeRapideLimite();
    void testJeuTapeRapideCorrectEtRapide();
    void testJeuTapeRapideCorrectMaisTropLent();
    void testJeuTapeRapideIncorrect();

};

#endif // TEST_BANQUE_HPP
