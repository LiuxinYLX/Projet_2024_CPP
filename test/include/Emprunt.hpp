#ifndef EMPRUNT_H
#define EMPRUNT_H

#include <string> 

/**
 * @brief Classe représentant un emprunt.
 * 
 * Cette classe permet de gérer les détails d'un emprunt, tels que le montant emprunté, les dates d'emprunt et de remboursement.
 */
class Emprunt {
private:
    double montant; /**< Le montant de l'emprunt. */
    const double montantMax; /**< Le montant maximal autorisé pour l'emprunt. */
    int dateEmprunt; /**< La date de l'emprunt. */
    int dateRemboursement; /**< La date de remboursement prévue. */

public:
    /**
     * @brief Constructeur de la classe Emprunt.
     * 
     * @param montant Le montant de l'emprunt.
     * @param montantMax Le montant maximal autorisé pour l'emprunt.
     * @param dateEmprunt La date de l'emprunt.
     * @param dateRemboursement La date de remboursement prévue.
     */
    Emprunt(double montant, double montantMax, int dateEmprunt, int dateRemboursement);

    /**
     * @brief Obtient le montant de l'emprunt.
     * 
     * @return Le montant de l'emprunt.
     */
    double getMontant() const;

    /**
     * @brief Obtient le montant maximal autorisé pour l'emprunt.
     * 
     * @return Le montant maximal autorisé pour l'emprunt.
     */
    double getMontantMax() const;

    /**
     * @brief Obtient la date de l'emprunt.
     * 
     * @return La date de l'emprunt.
     */
    int getDateEmprunt() const;

    /**
     * @brief Obtient la date de remboursement prévue.
     * 
     * @return La date de remboursement prévue.
     */
    int getDateRemboursement() const;

    /**
     * @brief Définit le montant de l'emprunt.
     * 
     * @param montant Le nouveau montant de l'emprunt.
     */
    void setMontant(double montant);

    /**
     * @brief Définit la date de l'emprunt.
     * 
     * @param date La nouvelle date de l'emprunt.
     */
    void setDateEmprunt(int date);

    /**
     * @brief Définit la date de remboursement prévue.
     * 
     * @param date La nouvelle date de remboursement prévue.
     */
    void setDateRemboursement(int date);

    //bool condition_Emprunt(double montant, Emprunt emprunt);
	
    //Emprunt creerEmprunt(double montantMax, int day);
}; 


#endif
