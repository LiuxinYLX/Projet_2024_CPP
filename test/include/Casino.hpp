#ifndef CASINO_HPP
#define CASINO_HPP

#include <list>
#include <string>
#include "Jeu.hpp" 
#include "Batiment.hpp"
#include "Personnage.hpp"
#include "Roulette.hpp"
#include "MachineS.hpp"
#include "BlackJ.hpp"
#include "Roulette.hpp"

using namespace std; 

/**
 * @class Casino
 * @brief Classe représentant le bâtiment Casino
 * 
 * Cette classe hérite de la classe Bâtiment et implémente les fonctionnalités spécifiques
 * au casino.
 */
class Casino : public Batiment {
private:
    list<Jeu> jeux;

public:
    // Constructeurs
    /**
     * @brief Constructeur par défaut ou avec une liste de jeux initiale
     * @param jeux Liste des jeux disponibles dans le casino
     */
    Casino(const std::string& nom, const std::string& adresse, const std::list<Jeu>& jeux = {});


    // Méthodes
    /**
     * @brief Permet au joueur de choisir un jeu parmi la liste disponible.
     */
    int choisirJeu();

    /**
     * @brief Affiche le menu au joueur et start les jeux casino.
     */
    void start(Personnage& personnage);

    /**
     * @brief Setters: Définir la liste des jeux
     * @param nouveauxJeux La nouvelle liste de jeux
     */
    void setJeux(list<Jeu> jeux);

    list<Jeu> getJeux();

    void afficherInfo() const{};


};

#endif // CASINO_HPP
