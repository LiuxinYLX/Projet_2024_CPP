#include "../../include/MachineS.hpp"
#include "../include/TestMachineS.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(TestMachineS);

void TestMachineS::testRenvoyer() {
    MachineS machine;

    int chiffre1 = machine.renvoyer();
    int chiffre2 = machine.renvoyer();
    int chiffre3 = machine.renvoyer();

    CPPUNIT_ASSERT(chiffre1 >= 0 && chiffre1 <= 9 && chiffre2 >= 0 && chiffre2 <= 9 && chiffre3 >= 0 && chiffre3 <= 9);
}

void TestMachineS::testCalculerPrime() {
        MachineS machineS;

        std::vector<int> vect1;
        std::vector<int> vect2;
        std::vector<int> vect3;
        std::vector<int> vect4;

        vect1 = {2,2,2};   //brelan
        vect2 = {1,2,3};   //quinte
        vect3 = {8,1,8};   //paire
        vect4 = {1,3,5};

        int prime1 = machineS.calculerPrime(vect1);
        int prime2 = machineS.calculerPrime(vect2);
        int prime3 = machineS.calculerPrime(vect3);
        int prime4 = machineS.calculerPrime(vect4);

        CPPUNIT_ASSERT_EQUAL(20, prime1); // On initialise que la prime pour "somme = 21" est 10
        CPPUNIT_ASSERT(19 != prime1);

        CPPUNIT_ASSERT_EQUAL(15, prime2); 

        CPPUNIT_ASSERT_EQUAL(3, prime3);

        CPPUNIT_ASSERT_EQUAL(0, prime4);
    }


