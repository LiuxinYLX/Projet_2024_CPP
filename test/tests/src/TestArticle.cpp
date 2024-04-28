#include "../include/TestArticle.hpp"
#include <cppunit/TestAssert.h> // For CPPUNIT_ASSERT
#include <sstream>
#include <iostream>

CPPUNIT_TEST_SUITE_REGISTRATION(TestArticle);

void TestArticle::setUp() {
    article = new Article("Test", 100, "Description test", 10, 5);
}

void TestArticle::tearDown() {
    delete article;
}

void TestArticle::testConstructor() {
    CPPUNIT_ASSERT_EQUAL(std::string("Test"), article->getNom());
    CPPUNIT_ASSERT_EQUAL(100, article->getPrix());
    CPPUNIT_ASSERT_EQUAL(std::string("Description test"), article->getDescription());
    CPPUNIT_ASSERT_EQUAL(10, article->getRassemblementGain());
    CPPUNIT_ASSERT_EQUAL(5, article->getQuantite());
}

void TestArticle::testAccesseurs() {
    // Initialiser un Article pour le test
    Article* article = new Article("Test", 100, "Description Test", 10, 5);

    // Vérifier le nom
    CPPUNIT_ASSERT_EQUAL(std::string("Test"), article->getNom());

    // Vérifier le prix
    CPPUNIT_ASSERT_EQUAL(100, article->getPrix());

    // Vérifier la description
    CPPUNIT_ASSERT_EQUAL(std::string("Description Test"), article->getDescription());

    // Vérifier le gain de rassemblement
    CPPUNIT_ASSERT_EQUAL(10, article->getRassemblementGain());

    // Vérifier la quantité
    CPPUNIT_ASSERT_EQUAL(5, article->getQuantite());

    // Libérer l'objet Article après le test
    delete article;
}


void TestArticle::testMutateurs() {
    // Changer le nom et vérifier
    article->setNom("Test2");
    CPPUNIT_ASSERT_EQUAL(std::string("Test2"), article->getNom());

    // Changer le prix et vérifier
    article->setPrix(200);
    CPPUNIT_ASSERT_EQUAL(200, article->getPrix());

    // Changer la description et vérifier
    article->setDescription("Nouvelle description");
    CPPUNIT_ASSERT_EQUAL(std::string("Nouvelle description"), article->getDescription());

    // Changer le gain de rassemblement et vérifier
    article->setRassemblementGain(15);
    CPPUNIT_ASSERT_EQUAL(15, article->getRassemblementGain());

    // Changer la quantité et vérifier
    article->setQuantite(10);
    CPPUNIT_ASSERT_EQUAL(10, article->getQuantite());
}


void TestArticle::testOperateurEgalite() {
    Article autreArticle("Test", 100, "Description test", 10, 5);
    CPPUNIT_ASSERT(*article == autreArticle);

    Article differentArticle("Test3", 300, "Description différente", 20, 10);
    CPPUNIT_ASSERT(!(*article == differentArticle));
}

void TestArticle::testAfficherInfoArticle() {
    // Sauvegarder l'ancien buffer de cout
    std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    // Créer un objet ostringstream
    std::ostringstream strCout;
    // Rediriger cout vers le nouveau streambuf
    std::cout.rdbuf(strCout.rdbuf());

    // Appeler afficherInfoArticle(), la sortie sera redirigée vers strCout
    article->afficherInfoArticle();

    // Restaurer l'ancien buffer de cout, rétablissant la sortie standard
    std::cout.rdbuf(oldCoutStreamBuf);

    // Construire la chaîne de caractères attendue
    std::string expectedOutput = 
        "Nom: Test\n"
        "Prix: 100\n"
        "Description: Description test\n"
        "Gain de rassemblement: 10\n"
        "Quantité disponible: 5\n";
    
    // Comparer la sortie attendue avec la sortie réelle
    CPPUNIT_ASSERT_EQUAL(expectedOutput, strCout.str());
}
