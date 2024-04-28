
#include "../include/TestJeu.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(TestJeu);

void TestJeu::testChoisirMontant() {
    Personnage player("Nom", "Prenom", 100, 10, 10, false);
    Jeu game("nomJeu", player);
    int montant = game.choisirMontant(player);

    std::istringstream input("1");
    std::cin.rdbuf(input.rdbuf());

    CPPUNIT_ASSERT(player.getCapital() == 100);

    std::cin.rdbuf(nullptr);
}

void TestJeu::testAssezdArgent() {
    Personnage playerBlackjack("Nom", "Prenom", 100, 10, 10, false);
    Jeu game("nomJeu", playerBlackjack);
    int enjeu = 101;
    bool assezdArgent = game.assezdArgent(enjeu);
    
    CPPUNIT_ASSERT_EQUAL(false, assezdArgent);
}

CPPUNIT_TEST_SUITE_REGISTRATION(TestJeu);
