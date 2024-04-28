#ifndef QUIZZ_HPP
#define QUIZZ_HPP

#include <string> 
#include <iostream>
#include <vector>
#include <list>
#include "Question.hpp"
#include "Domaine.hpp"

/**
 * @brief Classe représentant un quizz.
 */
class Quizz{
    
private:
    Domaine domaine; ///< Le domaine du quizz
    std::list<Question> listQNonFaites; ///< Liste des questions non posées du quizz
    std::list<Question> listQFaites; ///< Liste des questions déjà posées dans le quizz
    
public:
    //Constructeur - Getter - Setter
    
    /**
     * @brief Constructeur par défaut de la classe Quizz.
     */
    Quizz();
    
    /**
     * @brief Constructeur de la classe Quizz.
     * @param domaine Le domaine du quizz.
     */
    Quizz(Domaine d);
    
    /**
     * @brief Constructeur de la classe Quizz.
     * @param domaine Le domaine du quizz.
     * @param l1 Liste des questions non posées du quizz.
     * @param l2 Liste des questions déjà posées dans le quizz.
     */
    Quizz(Domaine domaine, std::list<Question> l1, std::list<Question> l2);

    /**
     * @brief Getter pour le domaine du quizz.
     * @return Le domaine du quizz.
     */
    Domaine getDomaine() const;  
    
    /**
     * @brief Setter pour le domaine du quizz.
     * @param domain Le domaine du quizz.
     */
    const void setDomaine(const Domaine d);

    /**
     * @brief Getter pour la liste des questions non posées du quizz.
     * @return La liste des questions non posées du quizz.
     */
    std::list<Question> getListQNonFaites() const;  
    
    /**
     * @brief Setter pour la liste des questions non posées du quizz.
     * @param l La liste des questions non posées du quizz.
     */
    const void setListQNonFaites(const std::list<Question> l);

    /**
     * @brief Getter pour la liste des questions déjà posées dans le quizz.
     * @return La liste des questions déjà posées dans le quizz.
     */
    std::list<Question> getListQFaites() const;  
    
    /**
     * @brief Setter pour la liste des questions déjà posées dans le quizz.
     * @param l La liste des questions déjà posées dans le quizz.
     */
    const void setListQFaites(const std::list<Question> l);

    //Méthodes

    /**
     * @brief Lance le quizz en posant des questions et en demandant des réponses à l'utilisateur.
     * @return Le nombre de bonnes réponses.
     */
     int repQuizz();

    /**
     * @brief Vérifie si une liste de questions n'est pas vide.
     * @param l La liste de questions à vérifier.
     * @return True si la liste n'est pas vide, False sinon.
     */
    bool verifNonVideListQ(std::list<Question> l);

    /**
     * @brief Affiche un message d'erreur si la liste de questions est vide.
     * @param b Booléen indiquant si la liste est vide.
     */
    void afficheErreurListQ(bool b);

    
     

    bool areEqual(const std::list<Question>& list1, const std::list<Question>& list2) const ;

    void chargerQuizz(const std::string& nomFichier, Quizz& q);

    void ajouterQuestion(Question q);

    void supprimerQuestion(Question q);

    void afficherRes(int r);
};

#endif

