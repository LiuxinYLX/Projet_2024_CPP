#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <string>
#include <iostream>

/**
 * @brief Classe représentant un personnage.
 * 
 * Cette classe permet de gérer les détails d'un personnage, tels que son nom, son capital, son niveau de rassasiement et son niveau d'énergie.
 */
class Personnage {

private:
    std::string nom; /**< Le nom du personnage. */
    std::string prenom; /**< Le prénom du personnage. */
    double capital; /**< Le capital du personnage. */
    int rassasiement; /**< Le niveau de rassasiement du personnage. */
    int energie; /**< Le niveau d'énergie du personnage. */
    bool state_emprunter; /**< Le statut d'emprunt du personnage. */

public:
    /**
     * @brief Constructeur par défaut de la classe Personnage.
     */
    Personnage();

     /**
     * @brief Constructeur par recopie.
     */
    Personnage(Personnage &);

    /**
     * @brief Constructeur de la classe Personnage.
     * 
     * @param nom Le nom du personnage.
     * @param prenom Le prénom du personnage.
     * @param capital Le capital du personnage.
     * @param rassasiement Le niveau de rassasiement du personnage.
     * @param energie Le niveau d'énergie du personnage.
     * @param state_emprunter Le statut d'emprunt du personnage.
     */
    Personnage(std::string nom, std::string prenom, double capital, int rassasiement, int energie, bool state_emprunter);

    // Méthodes pour manipuler les détails du personnage

    /**
     * @brief Obtient le nom complet du personnage.
     * 
     * @return Le nom complet du personnage.
     */
    std::string getNomPrenom() const;

    /**
     * @brief Obtient le capital du personnage.
     * 
     * @return Le capital du personnage.
     */
    double getCapital() const;

    /**
     * @brief Obtient le niveau de rassasiement du personnage.
     * 
     * @return Le niveau de rassasiement du personnage.
     */
    int getRassasiement() const;

    /**
     * @brief Obtient le niveau d'énergie du personnage.
     * 
     * @return Le niveau d'énergie du personnage.
     */
    int getEnergie() const;

    /**
     * @brief Obtient le statut d'emprunt du personnage.
     * 
     * @return Le statut d'emprunt du personnage.
     */
    bool getEmprunter() const;

    /**
     * @brief Définit le nom et le prénom du personnage.
     * 
     * @param nom Le nouveau nom du personnage.
     * @param prenom Le nouveau prénom du personnage.
     */
    void setNomPrenom(std::string nom, std::string prenom);

    /**
     * @brief Définit le capital du personnage.
     * 
     * @param capital Le nouveau capital du personnage.
     */
    void setCapital(const double capital);

    /**
     * @brief Définit le niveau de rassasiement du personnage.
     * 
     * @param ras Le nouveau niveau de rassasiement du personnage.
     */
    void setRassasiement(const int ras);

    /**
     * @brief Définit le niveau d'énergie du personnage.
     * 
     * @param energie Le nouveau niveau d'énergie du personnage.
     */
    void setEnergie(const int energie);

    /**
     * @brief Fait dormir le personnage dehors.
     */
    void dormirDehors(int malusEnergie);

    /**
     * @brief Obtient le statut d'emprunt du personnage.
     * 
     * @return Le statut d'emprunt du personnage.
     */
    bool getState_Emprunter() const;

    /**
     * @brief Définit le statut d'emprunt du personnage.
     * 
     * @param Yes_No Le nouveau statut d'emprunt du personnage.
     */
    void setState_Emprunter(const bool Yes_No);

    /**
     * @brief Affiche les infos du personnage.
     */
    void affichPers();

    /**
     * @brief Création du personnage par l'utilisateur
     * 
     * @return Le personnage créé
     */
    Personnage creationPerso();

};

#endif 

