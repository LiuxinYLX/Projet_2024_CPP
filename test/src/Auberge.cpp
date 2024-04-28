#include "../include/Auberge.hpp"
#include "../include/Personnage.hpp"
#include <thread> // Ajoutez cette ligne pour utiliser std::this_thread::sleep_for
#include <chrono> // Ajoutez cette ligne pour utiliser std::chrono::milliseconds

#include <iostream>

using namespace std;//<- Soit on écrit ça, soit on écrit std::vector

// Constructeur avec des paramètres par défaut
Auberge::Auberge(const string& nom, const string& adresse, double frais, int energieGain)
    : Batiment(nom, adresse), 
      frais(frais), 
      energieGain(energieGain) {
    // Initialisation des membres de la classe Auberge
}

// Getter pour frais
double Auberge::getFrais() const {
    return frais;
}

// Setter pour frais
void Auberge::setFrais(double nouveauFrais) {
    frais = nouveauFrais;
}

// Getter pour energieGain
int Auberge::getEnergieGain() const {
    return energieGain;
}

// Setter pour energieGain
void Auberge::setEnergieGain(int nouveauEnergieGain) {
    energieGain = nouveauEnergieGain;
}

// Méthode pour vérifier le capital
bool Auberge::verifierCapital(const Personnage& personnage) {
    return (personnage.getCapital() >= frais);
}

void Auberge::affichage(bool peutDormir, const Personnage& personnage) const {
    if (peutDormir) {
        std::cout << "Super! " << personnage.getNomPrenom() << ", vous pouvez dormir sous un toit à l'auberge ce soir. Bonne nuit!" << std::endl;
        std::cout << "Votre énergie va être restaurée. Vous allez avoir " << personnage.getEnergie() << " énergie après quelques secondes." << std::endl;
    } else {
        std::cout << "Désolé! " << personnage.getNomPrenom() << ", vous n'avez pas assez d'argent pour dormir à l'auberge." << std::endl;
    }
}

// Méthode publique pour dormir sous un toit
void Auberge::dormirSousUnToit(Personnage& personnage) {
    if (verifierCapital(personnage)){
    	affichage(true, personnage);
    	this_thread::sleep_for(chrono::milliseconds(100)); // Attendez une demi-minute
    	int energieTotale = getEnergieGain() + personnage.getEnergie();
        if (energieTotale > 5){
            energieTotale = 5;
        }
    	personnage.setEnergie(energieTotale);
    	personnage.setCapital(personnage.getCapital()- getFrais());
    } else {
    	affichage(false, personnage);
    }
}

void Auberge::afficherInfo() const {
    std::cout << "Informations sur l'auberge :" << std::endl;
    std::cout << "Nom : " << getNom() << std::endl;
    std::cout << "Adresse : " << getAdresse() << std::endl;
    std::cout << "Frais d'hébergement pour une nuit : " << frais << " euros" << std::endl;
    std::cout << "Énergie récupérée ensuite : " << energieGain << std::endl;
}


