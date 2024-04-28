#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/CompilerOutputter.h>
#include "../include/TestArticle.hpp"
#include "../include/TestAuberge.hpp"
#include "../include/TestBanque.hpp" 
#include "../include/Test_CentreDesMetiers.hpp"
#include "../include/TestEtablissementCommercial.hpp"
#include "../include/TestPersonnage.hpp"
#include "../include/Test_Question.hpp"
#include "../include/Test_Quizz.hpp"
#include "../include/TestJeu.hpp"
#include "../include/TestCasino.hpp"
#include "../include/TestMachineS.hpp"
#include "../include/TestBlackJ.hpp"
#include "../include/TestRoulette.hpp"


int main() {
    CppUnit::TextTestRunner runner;
    
    runner.addTest(TestArticle::suite());
    runner.addTest(TestAuberge::suite());
    runner.addTest(TestBanque::suite());
    runner.addTest(TestBlackJ::suite());
    runner.addTest(TestCasino::suite());
    runner.addTest(Test_CentreDesMetiers::suite());
    runner.addTest(TestEtablissementCommercial::suite());
    runner.addTest(TestJeu::suite());
    runner.addTest(TestMachineS::suite());
    runner.addTest(TestPersonnage::suite());
    runner.addTest(Test_Question::suite());
    runner.addTest(Test_Quizz::suite());
    runner.addTest(TestRoulette::suite());
    
    bool wasSuccessful = runner.run("", false);
    return wasSuccessful ? 0 : 1;
}
