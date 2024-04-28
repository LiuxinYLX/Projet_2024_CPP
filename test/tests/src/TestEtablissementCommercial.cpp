#include "../include/TestEtablissementCommercial.hpp"
#include "../../include/Article.hpp"
#include "../../include/Personnage.hpp"
#include <cppunit/TestAssert.h>
#include <sstream>
#include <iostream>

CPPUNIT_TEST_SUITE_REGISTRATION(TestEtablissementCommercial);

void TestEtablissementCommercial::setUp() {
    etablissement = new EtablissementCommercial("Etablissement Test", "123 Rue Test", supermarche);
}

void TestEtablissementCommercial::tearDown() {
    delete etablissement;
}

void TestEtablissementCommercial::testAjouterEtSupprimerArticle() {
    Article article("Pomme", 1, "Une pomme rouge", 0, 100);
    etablissement->ajouterArticle(article);
    auto liste = etablissement->obtenirListeArticles();
    CPPUNIT_ASSERT(liste.size() == 1);
    CPPUNIT_ASSERT(liste.front() == article);

    etablissement->supprimerArticle(article);
    liste = etablissement->obtenirListeArticles();
    CPPUNIT_ASSERT(liste.empty());
}

void TestEtablissementCommercial::testObtenirListeArticles() {
    auto liste = etablissement->obtenirListeArticles();
    CPPUNIT_ASSERT(liste.empty());

    Article article("Pomme", 2, "Une pomme rouge", 1, 2);
    etablissement->ajouterArticle(article);
    liste = etablissement->obtenirListeArticles();
    CPPUNIT_ASSERT(liste.size() == 1);
}

void TestEtablissementCommercial::testDefinirEtObtenirType() {
    etablissement->definirType(restaurant);
    CPPUNIT_ASSERT(etablissement->obtenirType() == restaurant);
}

void TestEtablissementCommercial::testConsommer() {
    Personnage personnage("Yang", "Peiwen", 100.00, 10, 10, false);
    Article article("Pomme", 1, "Une pomme vert", 1, 1);
    etablissement->ajouterArticle(article);
    etablissement->consommer(personnage);
    CPPUNIT_ASSERT(personnage.getCapital() == 100.00);
    CPPUNIT_ASSERT(personnage.getEnergie() == 10);
}

void TestEtablissementCommercial::testChoisir() {
    Article article1("Pomme", 3, "Une pomme rouge", 1, 5);
    Article article2("Banane", 4, "Une bonne banane",2, 5);
    Article article3("Pomme", 5, "Une pomme vert", 1, 5);
    etablissement->ajouterArticle(article1);
    etablissement->ajouterArticle(article2);
    etablissement->ajouterArticle(article3);
    
    std::istringstream input1("1,3");
    std::cin.rdbuf(input1.rdbuf()); // Simulate user input for choosing articles
    std::list<Article> listeChoisie = etablissement->choisir();
    CPPUNIT_ASSERT_EQUAL(2, static_cast<int>(listeChoisie.size()));
    CPPUNIT_ASSERT(listeChoisie.front().getNom() == "Pomme");
    
    // Resetting std::cin
    std::cin.rdbuf(nullptr);

    // Test case with single input
    std::istringstream input2("2");
    std::cin.rdbuf(input2.rdbuf()); 
    listeChoisie = etablissement->choisir();
    CPPUNIT_ASSERT_EQUAL(1, static_cast<int>(listeChoisie.size()));
    CPPUNIT_ASSERT(listeChoisie.front().getNom() == "Banane");

    // Resetting std::cin
    std::cin.rdbuf(nullptr);
}



