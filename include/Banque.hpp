#ifndef BANQUE_H
#define BANQUE_H

#include <string>
#include "Batiment.hpp"
#include "Emprunt.hpp"
#include "Personnage.hpp"

/**
 * @brief Classe représentant une banque.
 * Cette classe permet de gérer les opérations bancaires telles que les emprunts et les remboursements.
 */
class Banque : public Batiment {

private:
    std::string phraseMiniJeu; /**< La phrase utilisée pour le mini-jeu. */

public:
    /**
     * @brief Constructeur de la classe Banque.
     * @param nom Le nom de la banque.
     * @param adresse L'adresse de la banque.
     * @param phrase La phrase pour le mini-jeu.
     */
    Banque(const std::string& nom, const std::string& adresse, const std::string& phrase);

    std::string getPhrase();
    
    /**
     * @brief Affiche les informations de la banque.
     * Affiche le nom,l'adresse .
     */
    void afficherInfo() const override;

    /**
     * @brief Permet à un personnage d'emprunter de l'argent à la banque.
     * @param emprunt L'emprunt à effectuer.
     * @param perso Le personnage qui effectue l'emprunt.
     */
    void emprunter(Emprunt emprunt, Personnage& perso);

    /**
     * @brief Permet à un personnage de rembourser un emprunt à la banque.
     * @param emprunt L'emprunt à rembourser.
     * @param perso Le personnage qui effectue le remboursement.
     */
    void rembourser(Emprunt emprunt, Personnage& perso);

    /**
     * @brief Méthode pour jouer un mini-jeu de tape rapide.
     * Cette méthode lance un mini-jeu de tape rapide avec une phrase donnée.
     * @param phrase La phrase à taper rapidement.
     * @return True si le joueur a réussi, False sinon.
     */
    // bool jeuTapeRapide(const std::string phrase);
    bool jeuTapeRapide(const std::string& phrase, long long mockTime, const std::string mockInput);

    /**
     * @brief Affiche un message d'erreur lors de l'emprunt.
     * Cette méthode affiche un message d'erreur lorsque l'emprunt est impossible.
     */
    void afficherErreurEmprunt();

    /**
     * @brief Affiche un message de succès lors de l'emprunt.
     * Cette méthode affiche un message de succès lorsque l'emprunt est effectué avec succès.
     */
    void afficherSuccesEmprunt();
     /**
     * @brief Affiche un message d'erreur lors de l'emmprunt.
     * @param emprunt L'emprunt à effectuer
     * Cette méthode affiche un message d'erreur lorsque le montant demandé dépasse le montant maximal.
     */
     
     void afficherErreurEmpruntMontant(const Emprunt emprunt) ;
     /**
     * @brief Affiche un message d'erreur lors du remboursement.
     * Cette méthode affiche un message d'erreur lorsque le remboursement est impossible.
     */
    void afficherErreurRembours();
 /**
     * @brief Affiche un message de succès lors du remboursement.
     * Cette méthode affiche un message de succès lorsque le remboursement est effectué avec succès.
     */
void afficherSuccesRembours();
/**
     * @brief Affiche un message d'erreur lors du remboursement.
     * Cette méthode affiche un message d'erreur lorsque le remboursement est impossible en raison d'un manque d'argent.
     */
	void afficherErreurRemboursCapital();
/**
     * @brief Demande le montant d'emprunt souhaité.
     * Cette méthode renvoie le montant demandé.
     */
	double demanderMontantEmprunt();
/**
     * @brief Effectue le processus de l'emprunt.
     * @param perso Le personnage qui veut effectuer un emprunt
     * @param emprunt L'emprunt à effectuer
     * @param mockBoolean Paramètre de simulation pour les tests.
     * @param mockMontant Paramètre de simulation pour les tests.
     * Cette méthode renvoie l'emprunt crée (avec montant nul si l'emprunt n'a pas été effectué)
     */	
void ProcessusEmprunter(Personnage& perso, Emprunt& emprunt, bool mockBoolean, double mockMontant);
/**
     * @brief Effectue le processus du remboursement
     * @param perso Le personnage qui veut effectuer un emprunt
     * @param emprunt L'emprunt effectué
     */	
void ProcessusRembourser(Emprunt emprunt,Personnage& perso);
/**
 * @brief Obtient l'entrée de l'utilisateur.
 * @param input Référence à une chaîne de caractères pour stocker l'entrée de l'utilisateur.
 */
void getUserInput(std::string& input);
};


#endif

