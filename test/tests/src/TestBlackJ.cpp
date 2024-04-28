#include "../include/TestBlackJ.hpp"
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include <sstream>
#include <cppunit/ui/text/TextTestRunner.h>

CPPUNIT_TEST_SUITE_REGISTRATION(TestBlackJ);


void TestBlackJ::testDistribuer() {
    BlackJ game("Black Jack", Personnage(), {}, {1,2,3,4,5});

    // 获取初始卡片数量
    int initialCartesJSize = game.getCartesJoueur().size();
    int initialCartesESize = game.getCartesE().size();

    // 调用 distribuer() 方法
    game.distribuer();

    // 获取分发后的卡片数量
    int newCartesJSize = game.getCartesJoueur().size();
    int newCartesESize = game.getCartesE().size();

    // 验证预期的卡片数量变化
    CPPUNIT_ASSERT_EQUAL(initialCartesJSize + 1, newCartesJSize);
    CPPUNIT_ASSERT_EQUAL(initialCartesESize - 1, newCartesESize);
}

void TestBlackJ::testContinuer() {
    BlackJ game("Black Jack", Personnage(), {}, {1,2,3,4,5});

    int initialCartesJSize = game.getCartesJoueur().size();
    game.continuer();

    int newCartesJSize = game.getCartesJoueur().size();

    CPPUNIT_ASSERT_EQUAL(initialCartesJSize + 1, newCartesJSize);
    CPPUNIT_ASSERT(initialCartesJSize != newCartesJSize);
}

void TestBlackJ::testArreter() {
    BlackJ game;

    int initialCartesJSize = game.getCartesJoueur().size();
    game.arreter();

    int newCartesJSize = game.getCartesJoueur().size();

    CPPUNIT_ASSERT_EQUAL(initialCartesJSize, newCartesJSize);
    CPPUNIT_ASSERT(initialCartesJSize + 1 != newCartesJSize);
}

void TestBlackJ::testCalculerPrime() {
    BlackJ game;

    std::vector<int> vect1;
    std::vector<int> vect2;
    std::vector<int> vect3;
    std::vector<int> vect4;

    game.setCartesJoueur({10,5,6});   //somme = 21
    int prime1 = game.calculerPrime();

    game.setCartesJoueur({9,4,7});
    int prime2 = game.calculerPrime();

    game.setCartesJoueur({5,5,8,1});
    int prime3 = game.calculerPrime();
    
    game.setCartesJoueur({5,4,9});
    int prime4 = game.calculerPrime();

    CPPUNIT_ASSERT_EQUAL(10, prime1); // On initiale que la prime pour "somme = 21" est 10
    CPPUNIT_ASSERT(9 != prime1);

    CPPUNIT_ASSERT_EQUAL(9, prime2); 

    CPPUNIT_ASSERT_EQUAL(5, prime3);

    CPPUNIT_ASSERT_EQUAL(1, prime4);
}

