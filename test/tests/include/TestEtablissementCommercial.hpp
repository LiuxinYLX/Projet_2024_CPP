#ifndef TESTETABLISSEMENTCOMMERCIAL_HPP
#define TESTETABLISSEMENTCOMMERCIAL_HPP

#include <cppunit/extensions/HelperMacros.h>
#include "../../include/EtablissementCommercial.hpp"
#include "../../include/Article.hpp"
#include "../../include/Personnage.hpp"

class TestEtablissementCommercial : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(TestEtablissementCommercial);
    //CPPUNIT_TEST(testConstructor); 
    CPPUNIT_TEST(testAjouterEtSupprimerArticle);
    CPPUNIT_TEST(testObtenirListeArticles);
    CPPUNIT_TEST(testDefinirEtObtenirType);
    CPPUNIT_TEST(testChoisir);
    CPPUNIT_TEST(testConsommer);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp() override;
    void tearDown() override;

    void testAjouterEtSupprimerArticle();
    void testObtenirListeArticles();
    void testDefinirEtObtenirType();
    void testChoisir();
    void testConsommer();

private:
    EtablissementCommercial* etablissement;
};

#endif // TESTETABLISSEMENTCOMMERCIAL_HPP
