#include "../include/Roulette.hpp"
#include <iostream>
#include <random>
#include <ctime>

Roulette::Roulette(std::string nom, Personnage personnage, Couleur couleur, int intervalle, int parite)
    : Jeu(nom, personnage), // Appel au constructeur de la classe de base Jeu
      couleur(couleur), // Initialisation de la couleur
      intervalle(intervalle), // Initialisation de l'intervalle
      parite(parite) {}

Roulette::Roulette()
    :
    couleur(Couleur::ROUGE),
    intervalle(1),
    parite(1)
    {}

Couleur Roulette::choisirC() {
    std::cout << "Choisissez une couleur (1 pour ROUGE, 2 pour NOIR): ";
    int choix;
    std::cin >> choix;
    if (choix == 1) {
        return Couleur::ROUGE;
    } else {
        return Couleur::NOIR;
    }
}

int Roulette::choisirI() {
    std::cout << "Choisissez un intervalle (1 pour [1,12], 2 pour [13,24], 3 pour [25,36]): ";
    int choix;
    std::cin >> choix;
    return choix;
}

int Roulette::choisirP() {
    std::cout << "Choisissez la parité (1 pour Impaire, 2 pour Paire): ";
    int choix;
    std::cin >> choix;
    return choix;
}

void Roulette::afficher() {

    int numero = std::rand() % 36 + 1; 
    couleur = (std::rand() % 2 == 0) ? Couleur::NOIR : Couleur::ROUGE;
    parite = (numero % 2 == 0) ? 2 : 1;
    intervalle = (numero <= 12) ? 1 : (numero <= 24) ? 2 : 3;

    std::cout << "Résultat de la roulette:" << std::endl;
    std::cout << "Numéro: " << numero << std::endl;
    std::cout << "Couleur: " << (couleur == Couleur::ROUGE ? "Rouge" : "Noir") << std::endl;
    std::cout << "Parité: " << parite << std::endl;
    std::cout << "Intervalle: " << (intervalle == 1 ? "[1,12]": intervalle == 2 ? "[13,24]": "[25,36]") << std::endl;
}

int Roulette::calculerPrime(Couleur couleurChoisie, int intervalleChoisi, int pariteChoisi) {
    Roulette::afficher();

    int score = 0;

    // Vérifier l'intervalle
    if (intervalle == intervalleChoisi) {
        score = score + 2;
    }

    // Vérifier la couleur
    if (couleur == couleurChoisie) {
        score++;
    }

    // Vérifier la parité
    if (parite == pariteChoisi) {
        score++;
    }

    // Attribuer le prix en fonction du score
    switch (score) {
        case 4: // Gagne le plus grand prix
            return 7;
        case 3: // Gagne le deuxième prix
            return 3;
        case 2: // Gagne le troisième ou quatrième prix
            return 2;
        case 1:
            return 1;
        default: // Ne gagne rien
            return 0;
    }
}

void Roulette::jouer(Personnage& Personnage) {
    int montant = choisirMontant(Personnage);

    int capJeu = Personnage.getCapital() - montant;
    Personnage.setCapital(capJeu);
    std::cout << "Bienvenue dans le jeu Roulette! " << std::endl;
    std::cout << "Veuillez faire votre choix:  " << std::endl;

    Couleur couleurChoisie = choisirC();
    int intervalleChoisi = choisirI();
    int pariteChoisi = choisirP();

    int prime = calculerPrime(couleurChoisie, intervalleChoisi, pariteChoisi);
    int res = calculerLeGain(prime, montant, Personnage);
    Personnage.setCapital(res);
    if (prime > 0) {
        std::cout << "Vous avez gagner " << (prime*montant) << " ! " << std::endl;
        std::cout << "Votre capital: " << res << " ! " << std::endl;

    } else {
        std::cout << "Meilleure chance la prochaine fois!" << std::endl;
    }
}





