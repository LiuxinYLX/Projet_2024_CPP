#include <cppunit/extensions/HelperMacros.h>
#include <list>
#include "../../include/Quizz.hpp"
#include "../include/Test_Quizz.hpp"
#include "../include/Question.hpp"


void Test_Quizz::setUp() {

}

void Test_Quizz::tearDown() {

}

void Test_Quizz::testConstructeur() {
    Question q1("Question 1",1);
    Question q2("Question 2",1);
    Question q3("Question 3",4);
    std::list<Question> l1;
    std::list<Question> l2;
    l1.push_back(q1);
    l1.push_back(q2);
    l2.push_back(q3);

    Quizz q(Domaine::art,l1,l2);
    CPPUNIT_ASSERT(q.getDomaine() == Domaine::art);
    CPPUNIT_ASSERT(q.areEqual(q.getListQNonFaites(),l2));
    CPPUNIT_ASSERT(q.areEqual(q.getListQFaites(),l1));
}

void Test_Quizz::testListQ() {
    std::list<Question> l;
    l.push_back(Question("Question 1", 1));
    l.push_back(Question("Question 2", 2));

    Quizz q;
    q.setListQNonFaites(l);

    CPPUNIT_ASSERT(q.areEqual(q.getListQNonFaites(),l));
}

void Test_Quizz::testListQFaites() {
    std::list<Question> l;
    l.push_back(Question("Question 1", 1));
    l.push_back(Question("Question 2", 2));

    Quizz q;
    q.setListQFaites(l);

    CPPUNIT_ASSERT(q.areEqual(q.getListQFaites(), l));
}

void Test_Quizz::testListQVide(){
    std::list<Question> l1;
    std::list<Question> l2;
    std::string message;

    Question q1("Question 1",1);
    Question q2("Question 2",1);
    l1.push_back(q1);
    l1.push_back(q2);

    Quizz q;

    q.setListQNonFaites(l1);


    CPPUNIT_ASSERT(q.verifNonVideListQ(l1) == 1);

    CPPUNIT_ASSERT(q.verifNonVideListQ(l2) == 0);

}

// void Test_Quizz::testCalculerGain() {
//     Quizz q;
//     int bonnesRep = 5;

//     CPPUNIT_ASSERT(q.calculerGain(bonnesRep) == bonnesRep*3);

//     CPPUNIT_ASSERT(q.calculerGain(bonnesRep) != bonnesRep*6);
//     //Cela dépend de la méthode calculerGain qu'on va implémenter
// }