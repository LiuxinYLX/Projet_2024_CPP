#include <iostream>
#include <string>
#include <list> 
#include <fstream>
#include <sstream> 
#include <algorithm>
#include "../include/Quizz.hpp"
#include "../include/Question.hpp"
#include "../include/Domaine.hpp"



//Constructeurs

Quizz::Quizz(){
    std::list<Question> l1, l2;
    domaine = Domaine::sante;
    listQFaites = l1;
    listQNonFaites = l2;
}

Quizz::Quizz(Domaine d){
    domaine = d;
    std::list<Question> l1, l2;
    listQFaites = l1;
    listQNonFaites = l2;
}

Quizz::Quizz(Domaine d, std::list<Question> l1, std::list<Question> l2){
    domaine = d;
    listQFaites = l1;
    listQNonFaites = l2;
}



//Accesseurs

Domaine Quizz::getDomaine() const{
    return domaine;
}

std::list<Question> Quizz::getListQNonFaites() const{
    return listQNonFaites;
}

std::list<Question> Quizz::getListQFaites() const{
    return listQFaites;
}



//Mutateurs

const void Quizz::setDomaine(const Domaine d){
    domaine = d;
}

const void Quizz::setListQNonFaites(const std::list<Question> l){
    listQNonFaites = l;
}

const void Quizz::setListQFaites(const std::list<Question> l){
    listQFaites = l;
}




//Méthodes

int Quizz::repQuizz(){
    int res;
    res = 0;

    if (verifNonVideListQ(listQNonFaites) == true){
        for(int i=0; i<5; ++i){
  
        Question q = listQNonFaites.front(); // Obtient la première question de la liste
        res += q.repQuestion(); 

        // Ajoute la question à la liste des questions faites
        listQFaites.push_back(q);

        // Supprime la première question de la liste des questions non faites
        listQNonFaites.pop_front();
        }
    } else {
        afficheErreurListQ(verifNonVideListQ(listQNonFaites));
    }
    
    afficherRes(res);
    return res;

}

void Quizz::afficherRes(int r){
    std::cout<<"Votre score final:"<<r<<"/5 \n";
}



bool Quizz::verifNonVideListQ(std::list<Question> l){
    return !l.empty();
}


void Quizz::afficheErreurListQ(bool b){
    if (b == false){
        std::cout << "Ce domaine ne dispose plus de quizz, choisissez un autre domaine por favor!" << std::endl;
    }
}




// Méthode pour tester l'égalité entre deux listes de questions
bool Quizz::areEqual(const std::list<Question>& list1, const std::list<Question>& list2) const{
    // Vérifier si les deux listes ont la même taille
    if (list1.size() != list2.size()) {
        return false;
    }

    // Créer deux itérateurs pour parcourir les deux listes simultanément
    auto it1 = list1.begin();
    auto it2 = list2.begin();

    // Parcourir les deux listes et comparer chaque élément
    while (it1 != list1.end() && it2 != list2.end()) {
        // Utiliser l'opérateur == défini pour la classe Question
        if (!(*it1 == *it2)) {
            return false;
        }
        ++it1;
        ++it2;
    }
    return true; // Si toutes les paires d'éléments sont égales, retourner true
}
void Quizz::ajouterQuestion(Question q){
    
    listQNonFaites.push_back(q);
}

void Quizz::chargerQuizz(const std::string& nomFichier, Quizz& quizz) {
    std::ifstream fichier(nomFichier);
    if (!fichier) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << nomFichier << std::endl;
        return;
    }

    std::string ligne;
    std::list<Question> listq;
    while (std::getline(fichier, ligne)) {
        // Utilisez un flux de chaînes pour lire les données de la ligne
        std::istringstream ss(ligne);
        
        // Déclarez des variables pour stocker les informations de l'article
        std::string q;
        int rep;

        // Utilisez le flux de chaînes pour extraire les informations de la ligne
        if (std::getline(ss, q, ',') && (ss >> rep))
            {
            //std::cout<<q<<"\n"<<rep;
            // Créez un nouvel objet Article avec les informations extraites
            Question question(q,rep);
            listq.push_back(question);
        }
    }
    quizz.setListQNonFaites(listq);

}

