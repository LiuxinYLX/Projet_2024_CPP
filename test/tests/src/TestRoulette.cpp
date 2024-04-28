#include "../include/TestRoulette.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(TestRoulette);
    
void TestRoulette::testChoisirI() {
    Roulette roulette;

    
    std::istringstream input("1");
    std::cin.rdbuf(input.rdbuf());
    
    int res = roulette.choisirI();
    
    CPPUNIT_ASSERT(res == 1 && res != 2 && res != 3);

    std::cin.rdbuf(nullptr);
}

void TestRoulette::testChoisirC() {
    Roulette roulette;
    
    std::istringstream input("1");
    std::cin.rdbuf(input.rdbuf());
    
    Couleur res = roulette.choisirC();
    
    CPPUNIT_ASSERT(res == Couleur::ROUGE);

    std::cin.rdbuf(nullptr);
}

void TestRoulette::testChoisirP() {
    Roulette roulette;

    std::istringstream input("1");
    std::cin.rdbuf(input.rdbuf());
    int res = roulette.choisirP();

    CPPUNIT_ASSERT(res == 1 && res != 2);
    
    std::cin.rdbuf(nullptr);
}


