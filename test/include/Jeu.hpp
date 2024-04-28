/**
 * @file jeu.hpp
 * @brief Définition de la classe Jeu représentant un jeu générique dans le casino.
 * 
 * La classe Jeu sert de base pour les différents jeux disponibles dans le casino.
 * Elle contient les attributs et méthodes communs à tous les jeux.
 */

#ifndef JEU_HPP
#define JEU_HPP

#include <string>
#include <iostream>
#include "Personnage.hpp"

using namespace std;

/**
 * @class Jeu
 * @brief Classe de base pour les jeux du casino.
 * 
 * Cette classe définit les attributs et méthodes de base partagés par tous les jeux.
 */
class Jeu {
private:
    string nom;
    Personnage personnage;
public:
    Jeu(std::string nom, Personnage personnage);
    Jeu(std::string nom);
    Jeu();
    /**
     * @brief Construit un nouveau jeu.
     * @param nom Nom du jeu.
     * @param personnage Le personnage jouant le jeu.
     */
    /**
     * @brief Permet au joueur de choisir le montant d'argent à miser.
     * @return La somme choisie par le joueur.
     */
    int choisirMontant(Personnage Personnage);

    /**
     * @brief Vérifie si le joueur a assez d'argent pour la mise.
     * @param montant La somme d'argent à vérifier.
     * @return true si le joueur a suffisamment d'argent, false sinon.
     */
    bool assezdArgent(int montant);

    /**
     * @brief Calcule le gain final du joueur après une partie, le gain = player.getCapital() - mise + mise * calculerPrime().
     * @return Le gain du joueur, qui peut être négatif en cas de perte.
     */
    int calculerLeGain(int prime, int montant, Personnage personnage);

    /**
     * @brief Obtient le nom du joueur.
     * 
     * @return Le nom du joueur.
     */
    string getNomJeu() const;

    /**
     * @brief Obtient la Personne.
     * 
     * @return La Personne.
     */
    Personnage getPersonnage() const;

    /**
     * @brief Définit le nom du jeu.
     * 
     * @param nom Le nom du jeu.
     */
    void setNomJeu(string nom);
};

#endif
