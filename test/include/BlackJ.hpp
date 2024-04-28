/**
 * @file BlackJ.hpp
 * @brief Déclaration de la classe BlackJ pour représenter une partie de Blackjack.
 * 
 * Cette classe gère les fonctionnalités spécifiques au jeu de Blackjack,
 * y compris la distribution des cartes et les règles pour calculer les gains.
 */

#ifndef BLACKJ_HPP
#define BLACKJ_HPP

#include "Jeu.hpp"
#include <vector>

using namespace std;

/**
 * @class BlackJ
 * @brief Classe représentant une partie de Blackjack.
 * 
 * Cette classe hérite de la classe Jeu et implémente les fonctionnalités spécifiques
 * au jeu de Blackjack.
 */
class BlackJ : public Jeu{
private:
    std::vector<int> cartesJ;
    std::vector<int> cartesE;
public:
    /**
     * @brief Construit un nouveau BlackJ.
     * @param nom Nom du jeu.
     * @param personnage Le personnage jouant le jeu.
     * @param cartesJ Les cartes du joueur.
     * @param cartesE Les cartes en stock.
     */
    BlackJ(std::string nom, Personnage personnage, std::vector<int> cartesJ, std::vector<int> cartesE);
    BlackJ();

    /**
     * @brief Distribue les cartes au joueur.
     */
    void distribuer();

    /**
     * @brief Appelée quand le joueur décide de tirer une carte supplémentaire.
     */
    void continuer();

    /**
     * @brief Appelée quand le joueur décide de s'arrêter.
     */
    void arreter();

    /**
     * @brief Calcule le gain(Multiplicité) du joueur en fonction des résultats de la machine à sous.
     * 
     * @return int Le multiplicité du gain calculé, le gain = multiplicité * mise.
     */
    int calculerPrime();

    /**
     * @brief Obtient les cartes du joueur.
     * 
     * @return Les cartes du joueur.
     */
    std::vector<int> getCartesJoueur() const;

    /**
     * @brief Obtient les cartes en stock.
     * 
     * @return Les cartes en stock.
     */
    std::vector<int> getCartesE() const;

    /**
     * @brief Définit les cartes du joueur.
     * 
     * @param cartesJoueur Les cartes du joueur.
     */
    void setCartesJoueur(std::vector<int> cartesJoueur);

    /**
     * @brief Définit les cartes en stock.
     * 
     * @param cartesEnstock Les cartes en stock.
     */
    void setCartesE(std::vector<int> cartesEnstock);

    void jouer(Personnage& Personnage);

};


#endif
