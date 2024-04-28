// Article.cpp
#include "../include/Article.hpp"
#include <iostream>

// Constructeur
Article::Article(const std::string& nom, int prix, const std::string& description, 
                 int rassemblementGain, int quantite)
    : nom(nom), prix(prix), description(description),
      rassemblementGain(rassemblementGain), quantite(quantite) {}

// Afficher les informations sur l'article
void Article::afficherInfoArticle() const {
    std::cout << "Nom: " << getNom() << std::endl;
    std::cout << "Prix: " << getPrix() << std::endl;
    std::cout << "Description: " << getDescription() << std::endl;
    std::cout << "Gain de rassemblement: " << getRassemblementGain() << std::endl;
    std::cout << "Quantité disponible: " << getQuantite() << std::endl;
}

// Méthodes d'accès
std::string Article::getNom() const { return nom; }
int Article::getPrix() const { return prix; }
std::string Article::getDescription() const { return description; }
int Article::getRassemblementGain() const { return rassemblementGain; }
int Article::getQuantite() const { return quantite; }

// Méthodes de modification
void Article::setNom(const std::string& nouveauNom) { nom = nouveauNom; }
void Article::setPrix(int nouveauPrix) { prix = nouveauPrix; }
void Article::setDescription(const std::string& nouvelleDescription) { description = nouvelleDescription; }
void Article::setRassemblementGain(int nouveauGain) { rassemblementGain = nouveauGain; }
void Article::setQuantite(int nouvelleQuantite) { quantite = nouvelleQuantite; }

// Surcharge de l'opérateur ==
bool Article::operator==(const Article& autre) const {
    return nom == autre.nom && prix == autre.prix && 
           description == autre.description && 
           rassemblementGain == autre.rassemblementGain && 
           quantite == autre.quantite;
}
