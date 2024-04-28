#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <iostream>
#include <string>
#include <sstream> 
#include "Question.hpp"
#include "Test_Question.hpp"


//void Test_Question::setUp(void);
//void Test_Question::tearDown(void);
Test_Question::Test_Question() {
}


Test_Question::~Test_Question() {

}
void Test_Question::setUp() {

}

void Test_Question::tearDown() {

}

void Test_Question::testConstructeur() {
    Question q("Quel artiste a peint la toile La Promenade? \n 1.Paul Signac \n 2.Marc Chagall \n 3.Claude Monet \n 4.Aucun des trois \n ", 3);
    CPPUNIT_ASSERT(q.getQuestion() == "Quel artiste a peint la toile La Promenade? \n 1.Paul Signac \n 2.Marc Chagall \n 3.Claude Monet \n 4.Aucun des trois \n ");
    CPPUNIT_ASSERT(q.getRep() == 3);
}

// void Test_Question::testRepQuestion_nominal() {
//     Question q("Quel langage de programmation est principalement utilisé pour le développement d'applications Android ? \n 1.Java \n 2.C++ \n 3.Python \n 4.Aucun des trois \n", 1);
        
//     // Cas nominal : saisie de la bonne réponse
    
//     // On simule l'entrée utilisateur à 1, qu'on va ensuite rediriger vers notre std::istringstream
//     // On utilise std::cin pour simuler l'entrée utilisateur.

//     std::cin.clear();
//     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

//     std::istringstream input("1");
//     std::cin.rdbuf(input.rdbuf());
//     CPPUNIT_ASSERT(q.repQuestion() == true); 
//     // Rétablir std::cin
//     std::cin.rdbuf(nullptr);

// }


// void Test_Question::testRepQuestion_erreur() {
//     Question q("Quel langage de programmation est principalement utilisé pour le développement d'applications Android ? \n 1.Java \n 2.C++ \n 3.Python \n 4.Aucun des trois \n", 1);
    
    
//     // std::cin.clear();
//     // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//     // Cas d'erreur : saisie d'une réponse incorrecte
    
//     std::istringstream input("3");
//     std::cin.rdbuf(input.rdbuf());
//     CPPUNIT_ASSERT(q.repQuestion() == false); 
//     // Rétablir std::cin
//     std::cin.rdbuf(nullptr);
    
// }


// void Test_Question::testRepQuestion_lim() {
//     Question q("Quel langage de programmation est principalement utilisé pour le développement d'applications Android ? \n 1.Java \n 2.C++ \n 3.Python \n 4.Aucun des trois \n", 1);
        
    
//     // std::cin.clear();
//     // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//     // Cas limite : saisie en dehors des options possibles
    
//     std::istringstream input("6");
//     std::cin.rdbuf(input.rdbuf());
//     CPPUNIT_ASSERT(q.repQuestion() == false); 
//     std::cin.rdbuf(nullptr);
// }


