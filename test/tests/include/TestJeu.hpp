#ifndef TESTJEU_HPP
#define TESTJEU_HPP

#include <cppunit/extensions/HelperMacros.h>
#include "../include/Jeu.hpp"  // 包含要测试的类的头文件
#include "../include/Personnage.hpp"  // 如果需要使用 Personnage 类，也需要包含其头文件

class TestJeu : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(TestJeu);
    CPPUNIT_TEST(testChoisirMontant);
    CPPUNIT_TEST(testAssezdArgent);
    CPPUNIT_TEST_SUITE_END();

public:
    // void setUp() override;
    // void tearDown() override;

    void testChoisirMontant();
    void testAssezdArgent();
};

#endif // TESTJEU_HPP
