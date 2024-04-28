#include <iostream>
#include <string>
#include <sstream> 
#include "../include/Question.hpp"



//Constructeurs

Question::Question(){
    question = "Quel artiste a peint la toile La Promenade? \n 1.Paul Signac \n 2.Marc Chagall \n 3.Claude Monet \n 4.Aucun des trois \n";
    reponse = 3;
}

Question::Question(std::string q, int rep){
    question = q;
    reponse = rep;
}



//Accesseurs

std::string Question::getQuestion() const{
    return question;
}

int Question::getRep() const{
    return reponse;
}



//Mutateurs

const void Question::setQuestion(const std::string q){
    question = q;
}

const void Question::setRep(const int rep){
    reponse = rep;
}



//Méthodes

void Question::afficherQuestion(){
    std::cout << "Question : " << question << std::endl;
}



void Question::afficherErreurSaisie(){
    std::cout << "Veuillez saisir une réponse correcte (entre 1 et 4) ";
}



int Question::saisirRep() {
    int rep;
    do {
        std::cout << "Saisir le numéro de la réponse (entre 1 et 4) : ";
        std::cin >> rep;

        std::cout << rep;
        if (std::cin.fail()) {
            std::cout << "Entrée invalide. Veuillez saisir un nombre." << std::endl;
            std::cin.clear(); // 清除 std::cin 的错误标志
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清除输入缓冲区中的所有字符，直到换行符
        } else if (rep < 1 || rep > 4) {
            std::cout << "Réponse invalide. Veuillez saisir un numéro entre 1 et 4." << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清除输入缓冲区中的所有字符，直到换行符
        }
    } while (rep < 1 || rep > 4); // 重复直到输入有效为止
    return rep;
}




int Question::repQuestion(){
    int rep, res;

    afficherQuestion();
    rep = saisirRep();

    if(rep == reponse){
        res = 1;
        std::cout<<"Bonne réponse! \n";
    } else {
        res = 0;
        std::cout<<"Mauvaise réponse! \n";
    }

    return res;
}

bool Question::operator==(const Question& other) const {
    return (question == other.question && reponse == other.reponse);
}
