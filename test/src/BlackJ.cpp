#include "../include/BlackJ.hpp"
#include <algorithm>
#include <random>
#include <iostream>

BlackJ::BlackJ() {}
BlackJ::BlackJ(std::string nom, Personnage personnage, std::vector<int> cartesJ, std::vector<int> cartesE) 
: Jeu(nom, personnage), cartesJ(cartesJ), cartesE(cartesE) {}

void BlackJ::distribuer() {
    if (!cartesE.empty()) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, cartesE.size() - 1);

        int indexCarte = dis(gen);
        cartesJ.push_back(cartesE[indexCarte]);
        cartesE.erase(cartesE.begin() + indexCarte);
        std::cout << "Votre carte : " << cartesJ.back() << std::endl;
    }
}

void BlackJ::continuer() {
    distribuer();
}

void BlackJ::arreter() {
    std::cout << "Fin du jeu. Calcul des gains..." << std::endl;
}

int BlackJ::calculerPrime() {
    int somme = 0;
    for (int carte : cartesJ) {
        somme += carte;
    }
    if (somme > 21) {
        std::cout << "Vous avez perdu." << std::endl;
        return 0;
    }
    std::cout << "La somme de votre cartes est: " << somme << "." << std::endl;
    if (somme == 21) return 10;
    else if (somme == 20) return 9;
    else if (somme == 19) return 5;
    else if (somme == 18) return 1;
    else if (somme < 18) return 100;
    else return 0;
}

std::vector<int> BlackJ::getCartesJoueur() const {
    return cartesJ;
}

std::vector<int> BlackJ::getCartesE() const {
    return cartesE;
}

void BlackJ::setCartesJoueur(std::vector<int> cartesJoueur) {
    cartesJ = cartesJoueur;
}

void BlackJ::setCartesE(std::vector<int> cartesEnstock) {
    cartesE = cartesEnstock;
}

void BlackJ::jouer(Personnage& Personnage) {
    int montant = choisirMontant(Personnage);

    int capJeu = Personnage.getCapital() - montant;
    Personnage.setCapital(capJeu);
    setCartesJoueur({});
    for (int i = 0; i < 4; ++i) {
        for (int val = 2; val <= 10; ++val) {
            cartesE.push_back(val);
        }
        cartesE.push_back(10); // Valet
        cartesE.push_back(10); // Reine
        cartesE.push_back(10); // Roi
        cartesE.push_back(1); // As, valeur ajustable selon les besoins
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cartesE.begin(), cartesE.end(), g);

    std::cout << "Début du jeu de Blackjack. " << std::endl;
    distribuer(); // Distribuer la première carte
    char choix = 'o';
    

    while (choix != 'n' && calculerPrime() != 0) {
        
        std::cout << "Tirer une nouvelle carte ? (o/n): ";
        std::cin >> choix;
        if (choix == 'o') {
            continuer();
        }
    }
    arreter();
    int prime = calculerPrime();
    int res = calculerLeGain(prime, montant, Personnage);
    Personnage.setCapital(res);
    if (prime > 0) {
        std::cout << "Vous avez gagner " << (prime*montant) << " ! " << std::endl;
        std::cout << "Votre capital: " << res << " ! " << std::endl;
        
    } else {
        std::cout << "Meilleure chance la prochaine fois!" << std::endl;
    }
}
