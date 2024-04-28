#include "../include/TestCasino.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(TestCasino);

void TestCasino::testConstructor() {
    std::list<Jeu> jeux;
    jeux.push_back(Jeu("Blackjack"));
    Casino casino("Casino Royale", "123 Rue de Paris", jeux);

    CPPUNIT_ASSERT_EQUAL(std::string("Casino Royale"), casino.getNom());
    CPPUNIT_ASSERT_EQUAL(std::string("123 Rue de Paris"), casino.getAdresse());
    CPPUNIT_ASSERT_EQUAL(size_t(1), casino.getJeux().size());
}

void TestCasino::testGetSetJeux() {
    Casino casino("Casino Test", "123 Test Avenue");
    std::list<Jeu> jeuxInitial;
    jeuxInitial.push_back(Jeu("BlackJack"));
    casino.setJeux(jeuxInitial);

    CPPUNIT_ASSERT_EQUAL(size_t(1), casino.getJeux().size());
}
