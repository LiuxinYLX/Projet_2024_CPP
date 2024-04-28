#ifndef CENTREDESMETIERS_HPP
#define CENTREDESMETIERS_HPP

#include <string> 
#include <iostream>
#include <vector>
#include <list>
#include <chrono>
#include <ctime>
#include"Quizz.hpp"
#include"Batiment.hpp"



/**
 * @brief Classe représentant un centre des métiers.
 */

class CentreDesMetiers : public Batiment {
    
    private : 
         std::chrono::duration<double> acces; ///< Dernière date d'accès au centre des métiers
         std::chrono::duration<double> seuil = std::chrono::hours(1);
         std::list<Quizz> Quizzs;
        
    public : 
        //Constructeur - Getter - Setter
        /**
     * @brief Constructeur par défaut de la classe CentreDesMetiers.
     */
        CentreDesMetiers(const std::string& nom, const std::string& adresse);
         /**
     * @brief Getter pour la dernière date d'accès au centre des métiers.
     * @return La dernière date d'accès au centre des métiers.
     */

        std::chrono::duration<double> getAcces() const;  
      /**
     * @brief Getter pour le seuil d'accès au centre des métiers.
     * @return Le seuil d'accès au centre des métiers.
     */

        std::chrono::duration<double> getSeuil() const;  
	/**
     * @brief Setter pour la dernière date d'accès au centre des métiers.
     * @param date La dernière date d'accès au centre des métiers.
     */
        const void setAcces(const std::chrono::duration<double>);

        //Méthodes 
         /**
     * @brief Ajoute un quizz à le liste des Quizzs
     * @param q Le quizz à ajouter.
     */

        void ajouterQuizz(Quizz q);
      
         /**
     * @brief Supprime un quizz de la liste des Quizzs.
     * @param q Le quizz à supprimer.
     */
    void supprimerQuizz(Quizz q);

         /**
     * @brief Vérifie si un utilisateur peut accéder au centre des métiers dans une certaine plage horaire.
     * @param t1 Dernière date d'accès au centre des métiers.
     * @param t2 Date actuelle.
     * @return True si l'accès est autorisé, False sinon.
     */

        bool accederCDM(const std::chrono::duration<double> t1, const std::chrono::duration<double> t2);
        
         /**
     * @brief Affiche un message d'erreur si l'accès au centre des métiers est refusé.
     * @param erreur Booléen indiquant si une erreur s'est produite.
     */

        void affichErreurTemps(bool erreur);
          /**
     * @brief Permet à l'utilisateur de choisir un domaine.
     * @return Le domaine choisi.
     */

        const Domaine choisirDomaine();
      
      /**
     * @brief Permet à l'utilisateur de choisir un domaine.
     * @return Le domaine choisi.
     */

        void afficherDomaine();
            
            /**
     * @brief Permet à l'utilisateur de saisir au clavier un domaine.
     * @return Le domaine choisi.
     */
        

       const Domaine saisirDomaine();
        /**
     * @brief Lance un quizz dans le domaine spécifié.
     * @param domaine Le domaine dans lequel lancer le quizz.
     */

        int lancerQuizz(const Domaine domaine);

      /**
     * @brief Calcule le gain en fonction du nombre de bonnes réponses.
     * @param bonnesRep Le nombre de bonnes réponses.
     * @return Le gain calculé.
     */
        int calculerGain(int bonnesRep);

      /**
     * @brief Affiche le menu au joueur et charge les quizzs du centre des métiers.
     * @return Le gain calculé.
     */
        int startCDM(CentreDesMetiers centre);


      /**
     * @brief Affiche les informations du centre des métiers.
     * Affiche le nom et l'adresse du centre des métiers .
     */
    void afficherInfo() const override;

};

#endif
