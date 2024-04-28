#include "../include/Jeu.hpp"


Jeu::Jeu(std::string nom, Personnage personnage)
: nom(nom), personnage(personnage) {}

Jeu::Jeu(std::string nom) 
: nom(nom), personnage(Personnage()) {} 

Jeu::Jeu() : nom(""), personnage(Personnage()) {} 

int Jeu::choisirMontant(Personnage Personnage) {
    int montant = 0;
    cout << "Entrez le montant de votre mise(>0) : ";
    while (montant <= 0) {
        cin >> montant;
        if (assezdArgent(montant) == 0) {
            cout << "Montant insuffisant. Entrez un nouveau montant : ";
        } else {
            break; // Le montant est valide et le joueur a assez d'argent
        }
    }
    
    return montant;
}

// Méthode pour vérifier si le joueur a assez d'argent
bool Jeu::assezdArgent(int montant) {
    return personnage.getCapital() >= montant;
}

// Méthode pour calculer le gain du joueur
int Jeu::calculerLeGain(int prime, int montant, Personnage Personnage) {
    double res;
    if (prime < 100){
        res = Personnage.getCapital() + prime*montant;
    }else if(prime == 100){
        res = Personnage.getCapital();
    }
    return res;
}

string Jeu::getNomJeu() const {
    return nom;
}

Personnage Jeu::getPersonnage() const {
    return personnage;
}

void Jeu::setNomJeu(string nouveauNom) {
    nom = nouveauNom;
}
