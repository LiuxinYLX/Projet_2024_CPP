#include "../include/MachineS.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

// Assuming Jeu and Personnage classes are defined elsewhere

MachineS::MachineS(std::string nom, Personnage personnage, std::vector<int> resultat) 
: Jeu(nom, personnage), 
  resultat(resultat) {}

MachineS::MachineS()
    : Jeu("Default Name", Personnage()), // 假设Personnage有一个默认构造函数
      resultat() {  // 这将初始化resultat为一个空的vector
    // 构造函数体可以留空
}

int MachineS::renvoyer() 
{
    return std::rand() % 10; // Returns a random number between 0 and 9
}

int MachineS::calculerPrime(std::vector<int> res) 
{
    if (res[0] == res[1] && res[1] == res[2]) {
        return 20; // Highest prize
    }

    else if ((res[0] + 1 == res[1] && res[1] + 1 == res[2]) || (res[0] - 1 == res[1] && res[1] - 1 == res[2])) 
    {
        return 15; // Second prize
    }
    
    else if (res[0] == res[1] || res[1] == res[2] || res[0] == res[2]) {
        return 3; // Third prize
    }

    else return 0; // No prize
}

void MachineS::lancer(){
    std::cout << "Tapez Entrer pour lancer! \n";
    for (int i = 0; i < 3; ++i) {
        std::cin.get(); // Wait for user to press Enter
        int number = renvoyer();
        resultat.push_back(number);
        std::cout << number << " ";
    }
    std::cout << "\n";
}

void MachineS::jouer(Personnage& Personnage) {
    std::cout << "Bienvenue dans le jeu Machine à Sous!" << std::endl;
    int montant = choisirMontant(Personnage);

    int capJeu = Personnage.getCapital() - montant;
    Personnage.setCapital(capJeu);

    resultat.clear(); // Clear previous results
    lancer();

    int prime = calculerPrime(resultat);
    int res = calculerLeGain(prime, montant, Personnage);
    Personnage.setCapital(res);
    if (prime > 0 && prime != 100) {
        std::cout << "Vous avez gagner " << (prime*montant) << " ! " << std::endl;
        std::cout << "Votre capital: " << res << " ! " << std::endl;

    } else {
        std::cout << "Meilleure chance la prochaine fois!" << std::endl;
    }
}

std::vector<int> MachineS::getResultat() const {
    return resultat;
}

void MachineS::setResultat(std::vector<int> resultat) {
    this->resultat = resultat;
}
