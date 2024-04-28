#include "../include/Personnage.hpp"

// Constructeur par défaut
Personnage::Personnage() 
    : nom(""), prenom(""), capital(0.0), rassasiement(0), energie(0), state_emprunter(false) {
}

// Constructeur avec paramètres
Personnage::Personnage(std::string nom, std::string prenom, double capital, int rassasiement, int energie, bool state_emprunter)
    : nom(nom), prenom(prenom), capital(capital), rassasiement(rassasiement), energie(energie), state_emprunter(state_emprunter) {
}

// Méthodes getter
std::string Personnage::getNomPrenom() const {
    return nom + " " + prenom;
}

double Personnage::getCapital() const {
    return capital;
}

int Personnage::getRassasiement() const {
    return rassasiement;
}

int Personnage::getEnergie() const {
    return energie;
}

bool Personnage::getState_Emprunter() const {
    return state_emprunter;
}

// Méthodes setter
void Personnage::setNomPrenom(std::string nom, std::string prenom) {
    this->nom = nom;
    this->prenom = prenom;
}

void Personnage::setCapital(const double capital) {
    this->capital = capital;
}

void Personnage::setRassasiement(const int ras) {
    rassasiement = ras;
}

void Personnage::setEnergie(const int energie) {
    this->energie = energie;
}

void Personnage::setState_Emprunter(const bool Yes_No) {
    state_emprunter = Yes_No;
}

// Autres méthodes
void Personnage::dormirDehors(int malusEnergie) {
    if(malusEnergie <= energie) {energie -= malusEnergie;}
    else {}
    
}
