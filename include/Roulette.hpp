/**
 * @file roulette.hpp
 * @brief Déclaration de la classe Roulette pour représenter le jeu de roulette.
 * 
 * Cette classe gère les fonctionnalités spécifiques à la roulette, y compris les paris
 * sur les numéros, les couleurs et les intervalles.
 */

#ifndef ROULETTE_HPP
#define ROULETTE_HPP

#include "Jeu.hpp" 
#include "Couleur.hpp" 
#include<iostream>
#include<vector>

using namespace std;

/**
 * @class Roulette
 * @brief Classe représentant le jeu de roulette.
 * 
 * Cette classe hérite de la classe Jeu et permet au joueur de faire des paris
 * sur le résultat d'un lancer de bille sur la roulette.
 */
class Roulette : public Jeu {
public:
    Couleur couleur;
    int intervalle;
    int parite;
public:
    /**
     * @brief Construit un nouveau BlackJ.
     * @param nom Nom du jeu.
     * @param personnage Le personnage jouant le jeu.
     * @param couleur Le resultat de la couleur.
     * @param intervalle Le resultat de l'intervalle.
     * @param parite Le resultat de la parite.
     */
    Roulette(std::string nom, Personnage personnage, Couleur couleur, int intervalle, int parite);
    Roulette();

    /**
     * @brief Permet au joueur de choisir une couleur.
     * @return Le couleur choisi(ROUGE ou NOIR)
     */
    Couleur choisirC();

    /**
     * @brief Permet au joueur de choisir un intervalle de nombres.
     * 
     * @return int L'intervalle choisi, 1 --> [1,12]; 2 --> [13,24]; 3 --> [25,36]
     */
    int choisirI();

    /**
     * @brief Permet au joueur de choisir la parite.
     * 
     * @return Un int qui represente la parite, 1 --> Impaire, 2 --> Paire.
     */
    int choisirP();

    /**
     * @brief Affiche les résultats de la roulette.
     */
    void afficher();

    /**
     * @brief Calcule le gain(Multiplicité) du joueur en fonction des résultats de la machine à sous.
     * 
     * @return int Le multiplicité du gain calculé, le gain = multiplicité * mise.
     */
    int calculerPrime(Couleur c, int i, int p);

    void jouer(Personnage &Personnage);
};

#endif
