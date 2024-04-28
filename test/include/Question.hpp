#ifndef QUESTION_HPP
#define QUESTION_HPP

#include <string> 
#include <iostream>
#include <vector>
#include <list>
#include <chrono>
#include <ctime>

/**
 * @brief Classe représentant une question.
 */

class Question{
    
    private : 
        std::string question; ///< La question
        int reponse;	///< La réponse à la question
        
    public : 
        //Constructeur - Getter - Setter
        /**
     * @brief Constructeur par défaut de la classe Question.
     */
        Question();
        
        /**
     * @brief Constructeur de la classe Question.
     * @param question La question.
     * @param reponse La réponse à la question.
     */
     
        Question(std::string question, int reponse);
	/**
     * @brief Getter pour la question.
     * @return La question.
     */
     
        std::string getQuestion() const;  
        
        /**
     * @brief Setter pour la question.
     * @param q La question.
     */
        const void setQuestion(const std::string );
	/**
     * @brief Getter pour la réponse à la question.
     * @return La réponse à la question.
     */
     
        int getRep() const;  
        
        /**
     * @brief Setter pour la réponse à la question.
     * @param rep La réponse à la question.
     */
        
        const void setRep(const int );

        //Méthodes

/**
     * @brief Affiche la question.
     */
        void afficherQuestion();
	
	/**
     * @brief Affiche un message d'erreur si la réponse saisie n'est pas valide.
     */
        void afficherErreurSaisie();
	
	/**
     * @brief Permet à l'utilisateur de saisir sa réponse à une question.
     * @return La réponse saisie.
     */
       int saisirRep();
        
	/**
     * @brief Pose une question à l'utilisateur et attend une réponse.
     * @return vrai si la réponse saisie est correcte.
     */
        int repQuestion();

        bool operator==(const Question& other) const;

};

#endif
