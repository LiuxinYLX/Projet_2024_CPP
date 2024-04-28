#ifndef TESTARTICLE_HPP
#define TESTARTICLE_HPP

#include <cppunit/extensions/HelperMacros.h>
#include "../../include/Article.hpp"

class TestArticle : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(TestArticle);
    CPPUNIT_TEST(testAccesseurs);
    CPPUNIT_TEST(testMutateurs);
    CPPUNIT_TEST(testOperateurEgalite);
    CPPUNIT_TEST(testAfficherInfoArticle);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp() override;
    void tearDown() override;
    void testConstructor();
    void testAccesseurs();
    void testMutateurs();
    void testOperateurEgalite();
    void testAfficherInfoArticle();

private:
    Article* article;
};

#endif // TESTARTICLE_HPP
