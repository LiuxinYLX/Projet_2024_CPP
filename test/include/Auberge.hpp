#ifndef AUBERGE_HPP
#define AUBERGE_HPP

#include <iostream>
#include <string>
#include "Batiment.hpp"
#include "Personnage.hpp"

using namespace std;//<- Soit on écrit ça, soit on écrit std::vector

/**
 * @class Auberge
 * @brief Classe représentant le batiment Auberge
 * 
 * Cette classe hérite de la classe Batiment et implémente les fonctionnalités spécifiques
 * à l'auberge.
 */
class Auberge : public Batiment {
private:
    double frais;
    int energieGain;

public:
    // Constructeur
    /**
     * @brief Constructeur avec des paramètres par défaut
     * @param nom Nom de l'auberge
     * @param adresse Adresse de l'auberge
     * @param frais Frais nécessaire pour l'hébergement
     * @param energieGain Energie augmenté après une nuit sous un toit
     */
    
    /**
     * @brief Constructeur sans paramètres par défaut
     */
    Auberge(const string& nom, const string& adresse, double frais, int energieGain);
    
    //Getters
    /**
     * @brief Getters: Obtenir le frais
     */
    double getFrais() const;
    
    /**
     * @brief Getters: Obtenir le EnergieGain
     */
    int getEnergieGain() const;


    //Setters
    /**
     * @brief Setters: Modifier le frais
     */
    void setFrais(double nouveauFrais);
    
    /**
     * @brief Setters: Modifier le EnergieGain
     */
    void setEnergieGain(int nouvelleEnergieGain);

    /**
     * @brief Méthode appelée quand un personnage peut dormir sous un toit
     */
    void dormirSousUnToit(Personnage& personnage);
    
    /**
     * @brief Méthode appelée dans la méthode dormirSousUnToit pour afficher de différents messages
     */
    void affichage(bool peutDormir, const Personnage& personnage) const;
    
    /**
     * @brief Méthode réécrite pour afficher les informations spécifiques du batiment Auberge
     */
    virtual void afficherInfo() const override;

    /**
     * @brief Méthode pour vérifier si un personnage avoir assez de capital pour l'auberge. Elle renvoie un bouléen
     */
    bool verifierCapital(const Personnage& personnage);
};

#endif // AUBERGE_HPP

