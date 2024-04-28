#include "../include/Personnage.hpp"


// Constructeur par défaut
Personnage::Personnage() 
    : nom(""), prenom(""), capital(0.0), rassasiement(0), energie(0), state_emprunter(false) {
}

Personnage::Personnage(Personnage & p){
    nom = p.nom;
    prenom = p.prenom;
    capital = p.capital;
    rassasiement = p.rassasiement;
    energie = p.energie;
    state_emprunter = p.state_emprunter;
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

void Personnage::dormirDehors(int malusEnergie) {
    if(malusEnergie <= energie) {energie -= malusEnergie;}
    else {}
    
}

void Personnage::affichPers(){
    std::cout << "Nom Prénom: " << getNomPrenom() << std::endl;
    std::cout << "Capital: " << getCapital() << std::endl;
    std::cout << "Energie: " << getEnergie() << std::endl;
    std::cout << "Rassasiement: " << getRassasiement() << std::endl;
    std::cout << "EtatEmprunt: " << getState_Emprunter() << std::endl;
}


Personnage Personnage::creationPerso() {
    std::string nom, prenom;
    int capital, rassasiement, energie;

    do {
        std::cout << "Entrez le nom du personnage : ";
        std::cin >> nom;
    } while (nom.empty()); // Vérifie que le nom n'est pas vide

    do {
        std::cout << "Entrez le prénom du personnage : ";
        std::cin >> prenom;
    } while (prenom.empty()); // Vérifie que le prénom n'est pas vide

    std::cout << "Vous avez un total de 25 unités maximales à répartir entre le captial, le niveau de rassasiement et l'énergie. "<<std::endl;

    do {
        std::cout << "Entrez le capital (entre 0 et 20) : ";
        std::cin >> capital;
    } while (capital < 0 || capital > 20); // Vérifie que le capital est entre 0 et 20

    do {
        std::cout << "Entrez le niveau de rassasiement (entre 0 et 5) : ";
        std::cin >> rassasiement;
    } while (rassasiement < 0 || rassasiement > 5); // Vérifie que le niveau de rassasiement est entre 0 et 5

    do {
        std::cout << "Entrez le niveau d'énergie (entre 0 et 5) : ";
        std::cin >> energie;
    } while (energie < 0 || energie > 5); // Vérifie que le niveau d'énergie est entre 0 et 5

    // Vérifie que la somme totale des points ne dépasse pas 25
    while (capital + rassasiement + energie > 25) {
        std::cout << "La somme totale des points ne doit pas dépasser 25. Réessayez :\n";
        std::cout << "Entrez le capital (entre 0 et 20) : ";
        std::cin >> capital;
        std::cout << "Entrez le niveau de rassasiement (entre 0 et 5) : ";
        std::cin >> rassasiement;
        std::cout << "Entrez le niveau d'énergie (entre 0 et 5) : ";
        std::cin >> energie;
    }

    state_emprunter = false;

    Personnage p(nom, prenom, capital, rassasiement, energie, state_emprunter);

    return p;
}
