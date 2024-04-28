#include"../include/CentreDesMetiers.hpp"

#include<iostream>
#include<chrono>
#include<list>
#include <random>
#include <algorithm>

using namespace std;
CentreDesMetiers::CentreDesMetiers(const string& nom, const string& adresse) :Batiment(nom,adresse) {
}


chrono::duration<double> CentreDesMetiers::getAcces() const {
    return acces;
}


chrono::duration<double> CentreDesMetiers::getSeuil() const {
    return seuil;
}


const void CentreDesMetiers::setAcces(const chrono::duration<double> date) {
    acces = date;
}


bool CentreDesMetiers::accederCDM(const chrono::duration<double> t1, const chrono::duration<double> t2) {
    if((t2-t1)<= seuil){
        return false;
    }
    else{
        return true;
    }
}


void CentreDesMetiers::affichErreurTemps(bool erreur) {
    cout<< "Vous devez revenir apres."<< endl;
}


/*const string CentreDesMetiers::choisirDomaine() {
    string domaine;
    cout<< "Choisir un domaine."<< std:: endl;
    cin>>domaine;
    return domaine;

}*/


void CentreDesMetiers::afficherDomaine() {
    cout<< "Voici les différents domaines: sante, art, ingenierie, autre. \n";
}


const Domaine CentreDesMetiers::saisirDomaine() {
    Domaine domaine;
    string input;
    bool valide = false;

    while (!valide) {
        std::cout << "Veuillez choisir un domaine: "<< endl;
        std::cin >> input;

        if (input == "sante") {
            domaine = Domaine::sante;
            valide = true;
        } else if (input == "art") {
            domaine = Domaine::art;
            valide = true;
        } else if (input == "ingenierie") {
            domaine = Domaine::ingenierie;
            valide = true;
        } else if (input == "autre") {
            domaine = Domaine::autre;
            valide = true;
        } else {
            cerr << "Domaine invalide. Veuillez réessayer." << endl;
        }
    }
    return domaine;
}


int CentreDesMetiers::lancerQuizz(const Domaine domaine) {
    
    for (auto it = Quizzs.begin(); it != Quizzs.end(); it++ ){
        if (domaine == it->getDomaine()) {
            return it->repQuizz();
        }
            
    }

    return -1;
}

int CentreDesMetiers::calculerGain(int bonnesrep){
    return bonnesrep * 3;
}

void CentreDesMetiers::ajouterQuizz(Quizz q){
    Quizzs.push_back(q);
}

int CentreDesMetiers::startCDM(CentreDesMetiers centre){

    Domaine domaine;
    int score;

    centre.afficherDomaine();
    domaine = centre.saisirDomaine();
    score = centre.lancerQuizz(domaine);
    std::cout << "Bravo! Vous avez gagné " << centre.calculerGain(score) <<" euro!" << std::endl;
    return centre.calculerGain(score);
}

void CentreDesMetiers::afficherInfo() const{
    std::cout << "Nom: " << nom << ", Adresse: " << adresse <<  std::endl;
}