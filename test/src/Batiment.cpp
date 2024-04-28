#include "../include/Batiment.hpp"
#include <iostream>

// Constructeur
Batiment::Batiment(const std::string& nom, const std::string& adresse)
    : nom(nom), adresse(adresse) {
}

// Destructeur virtuel
Batiment::~Batiment() {
}

// afficherInfo: implémentation de base pour permettre la compilation. 
// Doit être surchargée dans les classes dérivées.
void Batiment::afficherInfo() const {
    std::cout << "Nom: " << nom << "\nAdresse: " << adresse << std::endl;
}

// Retourne le nom du bâtiment
const std::string& Batiment::getNom() const {
    return nom;
}

// Définit le nom du bâtiment
void Batiment::setNom(const std::string& nom) {
    this->nom = nom;
}

// Retourne l'adresse du bâtiment
const std::string& Batiment::getAdresse() const {
    return adresse;
}

// Définit l'adresse du bâtiment
void Batiment::setAdresse(const std::string& adresse) {
    this->adresse = adresse;
}
