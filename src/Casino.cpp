#include "../include/Casino.hpp"
#include <iostream>


Casino::Casino(const std::string& nom, const std::string& adresse, const std::list<Jeu>& jeux)
: Batiment(nom, adresse), jeux(jeux) {}

int Casino::choisirJeu() {
    cout << "Choisissez un jeu parmi les suivants :" << endl;
    cout << "1. Roulette :" << endl;
    cout << "2. Black Jack :" << endl;
    cout << "3. Machine à Sous :" << endl;
    
    int choix;

    cout << "Entrez le numéro du jeu : ";
    cin >> choix;
    return choix;
}


void Casino::setJeux(list<Jeu> jeux) {
    this->jeux = jeux;
}

list<Jeu> Casino::getJeux(){ 
    return jeux;
}

void Casino::start(Personnage& personnage) {

    Roulette roulette("ROULETTE", personnage, Couleur::NOIR, 1, 1);
    BlackJ blackJ("BLACK JACK", personnage, {}, {});
    MachineS machineS("MACHINE à SOUS", personnage, {});
    setJeux({roulette, blackJ, machineS});

    cout << "Bienvenue au " << getNom() << "!" << endl;
    
    int choix = 0;
    do {
        cout << "1. Veuillez choisir un jeu" << endl;
        cout << "2. Quitter" << endl;

        cout << "Entrez votre choix : ";
        cin >> choix;

        switch (choix) {
            case 1: {
                int choixJeu = choisirJeu();
                switch (choixJeu) {
                    case 1:
                        roulette.jouer(personnage);
                        break;
                    case 2:
                        blackJ.jouer(personnage);
                        break;
                    case 3:{
                        machineS.jouer(personnage);
                        break;
                    }
                    default:
                        cout << "Choix de jeu invalide. Veuillez réessayer." << endl;
                        break;
                }
                break;
            }
            case 2:
                cout << "Merci de votre visite!" << endl;
                break;
            default:
                cout << "Choix invalide. Veuillez réessayer." << endl;
                break;
        }
    } while (choix != 2); 

}

