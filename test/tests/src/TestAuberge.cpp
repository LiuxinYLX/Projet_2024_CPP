#include <cppunit/extensions/HelperMacros.h>
#include "../include/TestAuberge.hpp"
#include "../../include/Auberge.hpp"
#include "../../include/Personnage.hpp"


CPPUNIT_TEST_SUITE_REGISTRATION(TestAuberge);



void TestAuberge::setUp() {
    auberge1 = new Auberge("Madrillet", "11 avenue de la mare aux daims", 50.0, 5);
    auberge2 = new Auberge("Madrillet", "11 avenue de la mare aux daims", 50.0, 3);
}

void TestAuberge::tearDown() {
    delete auberge1;
    auberge1 = nullptr;
    delete auberge2;
    auberge2 = nullptr;
}

/**
* @brief Test des constructeurs
*/
void TestAuberge::testConstruction() {
    // Test de construction avec des valeurs par défaut
    CPPUNIT_ASSERT_EQUAL(50.0, auberge1->getFrais());
    CPPUNIT_ASSERT_EQUAL(5, auberge1->getEnergieGain());
}

    
void TestAuberge::testDormirSousUnToit() {
    Personnage personnage("Yang","Liuxin",100.0, 5, 2,false);
    auberge2->dormirSousUnToit(personnage);

    /**
        * @brief Vérification que l'énergie du personnage a augmenté après avoir dormi sous un toit
    */
    CPPUNIT_ASSERT(personnage.getEnergie() == 5);
    CPPUNIT_ASSERT(personnage.getEnergie() != 15);
}
    
    
void TestAuberge::testVerfierCapital() {
    // Création d'un objet Personnage
    // Personnage(nom, prenom, capital, rassasiement, energie)
    Personnage personnage("Yang","Liuxin",100.0, 5, 2,false);

    // Exécution de la méthode affichage avec différentes valeurs
    // On peut dormir
    CPPUNIT_ASSERT_EQUAL(true, auberge2->verifierCapital(personnage));
        
    // On ne peut pas dormir
    personnage.setCapital(10.0);
    CPPUNIT_ASSERT_EQUAL(false, auberge2->verifierCapital(personnage));
}

