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
#include <chrono>
#include <sstream>
#include"CentreDesMetiers.hpp"
#include"Test_CentreDesMetiers.hpp"
#include"../include/Quizz.hpp"


using namespace std;



void Test_CentreDesMetiers::testAccederCDM(){

    CentreDesMetiers cdm("","");
    std::chrono::duration<double> t1;
    std::chrono::duration<double> t2;
    std::chrono::duration<double> t3;
    std::chrono::duration<double> t4;

    t1 = std::chrono::hours(1);
    t2 = std::chrono::hours(1) + std::chrono::minutes(30);
    t3 = std::chrono::hours(1);
    t4 = std::chrono::hours(2) + std::chrono::minutes(45);

    CPPUNIT_ASSERT(cdm.accederCDM(t1,t2) == 0);
    CPPUNIT_ASSERT(cdm.accederCDM(t1,t3) == 0);
    CPPUNIT_ASSERT(cdm.accederCDM(t1,t4) == 1);

}

void Test_CentreDesMetiers::testSaisirDomaine() {
    CentreDesMetiers cdm("", "");


    std::istringstream iss("art");
    std::cin.rdbuf(iss.rdbuf());

    Domaine saisie_utilisateur = cdm.saisirDomaine();
    CPPUNIT_ASSERT_EQUAL(Domaine::art, saisie_utilisateur);
}
