#ifndef TESTMACHINES_HPP
#define TESTMACHINES_HPP

#include <cppunit/extensions/HelperMacros.h>
#include "../include/MachineS.hpp" 

class TestMachineS : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(TestMachineS);
    CPPUNIT_TEST(testRenvoyer);
    CPPUNIT_TEST(testCalculerPrime);
    CPPUNIT_TEST_SUITE_END();

public:
    // void setUp(void); 
    // void tearDown(void); 
    
    void testRenvoyer();
    void testCalculerPrime();
};

#endif // TESTMACHINES_HPP
