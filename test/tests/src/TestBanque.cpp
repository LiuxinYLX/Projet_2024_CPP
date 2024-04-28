#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include <sstream>
#include <cppunit/ui/text/TextTestRunner.h>
#include "TestBanque.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(TestBanque);



    // void TestBanque::testEmprunter_casValide() {
    //     Banque banque(" "," "," ");
    //     Personnage person("John", "Doe", 1000.0, 5, 10, false);
    //     Emprunt emprunt(100, 1000, 1, 1);
    //     banque.emprunter(emprunt, person);

    //     CPPUNIT_ASSERT(person.getState_Emprunter() == true);
    //     CPPUNIT_ASSERT_EQUAL(1100.0, person.getCapital());
    // }

    // void TestBanque::testEmprunter_casLimite() {
    //     Banque banque(" "," "," ");
    //     Personnage person("John", "Doe", 1000.0, 5, 10, false);
    //     Emprunt emprunt(1000, 1000, 1, 1);
    //     banque.emprunter(emprunt, person);

    //     CPPUNIT_ASSERT(person.getState_Emprunter() == true);
    //     CPPUNIT_ASSERT_EQUAL(2000.0, person.getCapital());
    // }

// void TestBanque::testEmprunter_casNonValide1() {
//     Banque banque(" "," "," ");
//     Personnage person("John", "Doe", 1000.0, 5, 10, false);
//     Emprunt emprunt(10000, 1000, "02012024", "03012024");
//     banque.emprunter(emprunt, person);

//     CPPUNIT_ASSERT(person.getState_Emprunter() == false);
//     CPPUNIT_ASSERT_EQUAL(1000.0, person.getCapital());
// }

// void TestBanque::testEmprunter_casNonValide2() {
//     Banque banque(" "," "," ");
//     Personnage person("John", "Doe", 1000.0, 5, 10, true);
//     Emprunt emprunt(100, 1000, "02012024", "03012024");
//     banque.emprunter(emprunt, person);

//     CPPUNIT_ASSERT(person.getState_Emprunter() == true);
//     CPPUNIT_ASSERT_EQUAL(1000.0, person.getCapital());
// } emprunt的意思是只要借钱就给，因为在main里面会实现三个判断，state jeu。。

// void TestBanque::testRembourser_casValide() {
//     Banque banque(" "," "," ");
//     Personnage person("John", "Doe", 1000.0, 5, 10, true);
//     Emprunt emprunt(100, 1000, 1, 1);

//     banque.rembourser(emprunt, person);
//     CPPUNIT_ASSERT(person.getState_Emprunter() == true);
//     CPPUNIT_ASSERT_EQUAL(900.0, person.getCapital());
// }

// void TestBanque::testRembourser_casNonValide1() {
//     Banque banque(" "," "," ");
//     Personnage person("John", "Doe", 10, 5, 10, true);
//     Emprunt emprunt(100, 1000, 1, 1);

//     banque.rembourser(emprunt, person);
//     CPPUNIT_ASSERT(person.getState_Emprunter() == true);
//     CPPUNIT_ASSERT_EQUAL(10.0, person.getCapital());
// }

// void TestBanque::testRembourser_casNonValide2() {
//     Banque banque(" "," "," ");
//     Personnage person("John", "Doe", 1000, 5, 10, false);
//     Emprunt emprunt(100, 1000, 1, 1);

//     banque.rembourser(emprunt, person);
//     CPPUNIT_ASSERT(person.getState_Emprunter() == false);
//     CPPUNIT_ASSERT_EQUAL(1000.0, person.getCapital());
// }

void TestBanque::testProcessusEmprunter_casNormal(){
    Banque banque("", "", "correct_phrase");
    Personnage personnage("", "", 0, 0 , 0, false);
    Emprunt emprunt(0, 500.0, 1, 3);

    banque.ProcessusEmprunter(personnage, emprunt, true, 300.0);

    CPPUNIT_ASSERT(personnage.getState_Emprunter() == true);
    CPPUNIT_ASSERT_EQUAL(300.0, personnage.getCapital());
}
void TestBanque::testProcessusEmprunter_casErreur1(){
    Banque banque("", "", "correct_phrase");
    Personnage personnage("", "", 0, 0 , 0, true);
    Emprunt emprunt(0, 500.0, 1, 3);

    banque.ProcessusEmprunter(personnage, emprunt, true, 300.0);

    CPPUNIT_ASSERT(personnage.getState_Emprunter() == true);
    CPPUNIT_ASSERT_EQUAL(0.0, personnage.getCapital());
}
void TestBanque::testProcessusEmprunter_casErreur2(){
    Banque banque("", "", "correct_phrase");
    Personnage personnage("", "", 0, 0 , 0, false);
    Emprunt emprunt(0, 500.0, 1, 3);

    banque.ProcessusEmprunter(personnage, emprunt, true, 600.0);

    CPPUNIT_ASSERT(personnage.getState_Emprunter() == false);
    CPPUNIT_ASSERT_EQUAL(0.0, personnage.getCapital());
}
// void TestBanque::testProcessusEmprunter_casErreur3(){
//     Banque banque("", "", "correct_phrase");
//     Personnage personnage("", "", 0, 0 , 0, false);
//     Emprunt emprunt(0, 500.0, 1, 3);

//     banque.ProcessusEmprunter(personnage, emprunt, false, 300.0);

//     CPPUNIT_ASSERT(personnage.getState_Emprunter() == true);
//     CPPUNIT_ASSERT_EQUAL(300.0, personnage.getCapital());
// }
void TestBanque::testProcessusEmprunter_casLimite(){
    Banque banque("", "", "correct_phrase");
    Personnage personnage("", "", 0, 0 , 0, false);
    Emprunt emprunt(0, 500.0, 1, 3);

    banque.ProcessusEmprunter(personnage, emprunt, true, 500.0);

    CPPUNIT_ASSERT(personnage.getState_Emprunter() == true);
    CPPUNIT_ASSERT_EQUAL(500.0, personnage.getCapital());
}

void TestBanque::testProcessusRembourser_casNormal(){
    Banque banque("", "", "correct_phrase");
    Personnage personnage("", "", 1000, 0 , 0, true);
    Emprunt emprunt(500.0, 500.0, 1, 3);

    banque.ProcessusRembourser(emprunt, personnage);

    CPPUNIT_ASSERT(personnage.getState_Emprunter() == true);
    CPPUNIT_ASSERT_EQUAL(500.0, personnage.getCapital());


}
void TestBanque::testProcessusRembourser_casErreur1(){
    Banque banque("", "", "correct_phrase");
    Personnage personnage("", "", 1000, 0 , 0, false);
    Emprunt emprunt(500.0, 500.0, 1, 3);


    banque.ProcessusRembourser(emprunt, personnage);

    CPPUNIT_ASSERT(personnage.getState_Emprunter() == false);
    CPPUNIT_ASSERT_EQUAL(1000.0, personnage.getCapital());


}
void TestBanque::testProcessusRembourser_casErreur2(){
    Banque banque("", "", "correct_phrase");
    Personnage personnage("", "", 100, 0 , 0, true);
    Emprunt emprunt(500.0, 500.0, 1, 3);

    banque.ProcessusRembourser(emprunt, personnage);

    CPPUNIT_ASSERT(personnage.getState_Emprunter() == true);
    CPPUNIT_ASSERT_EQUAL(100.0, personnage.getCapital());


}
void TestBanque::testProcessusRembourser_casLimite(){
    Banque banque("", "", "correct_phrase");
    Personnage personnage("", "", 500.0, 0 , 0, true);
    Emprunt emprunt(500.0, 500.0, 1, 3);

    banque.ProcessusRembourser(emprunt, personnage);

    CPPUNIT_ASSERT(personnage.getState_Emprunter() == true);
    CPPUNIT_ASSERT_EQUAL(0.0, personnage.getCapital());


}
void TestBanque::testJeuTapeRapideCorrectEtRapide() {
    Banque banque("","","correct_phrase");
    // 模拟的当前时间

    // 调用函数并断言预期结果为 true
    CPPUNIT_ASSERT(banque.jeuTapeRapide(banque.getPhrase(), 5, banque.getPhrase()));
}

void TestBanque::testJeuTapeRapideCorrectMaisTropLent() {
    Banque banque("","","correct_phrase");


    CPPUNIT_ASSERT(!banque.jeuTapeRapide(banque.getPhrase(), 120000, banque.getPhrase()));
}

void TestBanque::testJeuTapeRapideIncorrect() {
    Banque banque("","","correct_phrase");


    CPPUNIT_ASSERT(!banque.jeuTapeRapide(banque.getPhrase(), 6, "kaze"));
}

void TestBanque::testJeuTapeRapideLimite() {
    Banque banque("","","correct_phrase");
 
    // 根据你的具体逻辑，这里可能是 true 或 false
    CPPUNIT_ASSERT(banque.jeuTapeRapide(banque.getPhrase(), 6, banque.getPhrase()));
}


CPPUNIT_TEST_SUITE_REGISTRATION(TestBanque);

