/**
 * @file machineS.hpp
 * @brief Définition de la classe MachineS pour le jeu de machine à sous.
 * 
 * Cette classe hérite de Jeu et implémente les spécificités du jeu de machine à sous.
 */

#ifndef MACHINES_HPP
#define MACHINES_HPP

#include "Jeu.hpp"
#include <iostream>
#include <vector>

using namespace std;
/**
 * @class MachineS
 * @brief Classe représentant une machine à sous.
 * 
 * Cette classe hérite de la classe Jeu et implémente les méthodes spécifiques pour jouer à une machine à sous.
 */
class MachineS : public Jeu {
private:
    std::vector<int> resultat; ///< Résultats du tirage des nombres.

public:
    /**
     * @brief Construit un nouveau BlackJ.
     * @param nom Nom du jeu.
     * @param personnage Le personnage jouant le jeu.
     * @param resultat Le resultat de machine sous.
     */
    MachineS(std::string nom, Personnage personnage, std::vector<int> resultat);
    MachineS();

    /**
     * @brief Renvoie un chiffre aléatoire entre 0 et 9.
     * 
     * Cette méthode simule le tirage d'un chiffre sur un rouleau de la machine à sous.
     * 
     * @return int Un chiffre aléatoire entre 0 et 9.
     */
    int renvoyer();

    /**
     * @brief Calcule le gain(Multiplicité) du joueur en fonction des résultats de la machine à sous.
     * 
     * @return int Le multiplicité du gain calculé, le gain = multiplicité * mise.
     */
    int calculerPrime(vector<int> res);

        /**
     * @brief Obtient le resultat qui est un vecteur contiant 3 chiffres.
     * 
     * @return Le vecteur de 3 chiffres.
     */
    std::vector<int> getResultat() const;

    /**
     * @brief Définit un vecteur comme le resultat.
     * 
     * @param resultat Le resultat.
     */
    void setResultat(std::vector<int> resultat);

    void lancer();

    void jouer(Personnage& Personnage);
};

#endif // MACHINES_HPP
