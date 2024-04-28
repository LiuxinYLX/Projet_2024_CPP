#include "../include/Banque.hpp"
#include <iostream>
#include <ctime>
#include <chrono>


Banque::Banque(const std::string& nom, const std::string& adresse, const std::string& phrase)
    :Batiment(nom,adresse), phraseMiniJeu(phrase)
{

}

std::string Banque::getPhrase(){
    return phraseMiniJeu;
}
void Banque::afficherInfo() const{
    std::cout << "Nom: " << nom << ", Adresse: " << adresse << ", Phrase: " << phraseMiniJeu << std::endl;
}

// bool Banque::jeuTapeRapide(const std::string& phrase, std::function<std::chrono::steady_clock::time_point()> currentTimeFunc, std::function<void(std::string&)> inputFunc) {
//     std::cout << "Bonjour, vous avez 7 secondes pour taper la phrase : \n";
//     std::cout << phrase << std::endl;

//     auto debutTemps = currentTimeFunc();
//     std::string saisie;
//     inputFunc(saisie);
//     auto finTemps = currentTimeFunc();

//     double tempsTape = std::chrono::duration_cast<std::chrono::milliseconds>(finTemps - debutTemps).count() / 1000.0;

//     if (saisie == phrase && tempsTape <= 7) {
//         std::cout << "Bravo ! Vous avez tapé la phrase correctement en moins de 7 secondes." << std::endl;
//         return true;
//     } else {
//         std::cout << "Désolé, vous avez fait une erreur ou pris trop de temps." << std::endl;
//         return false;
//     }
// }
bool Banque::jeuTapeRapide(const std::string& phrase, long long mockTime, const std::string mockInput) {
    if(mockTime == 0 && mockInput != phrase){
    
    std::cout << "Bonjour, vous avez 10 secondes pour taper la phrase : \n";
    std::cout << phrase << std::endl;

    auto start = std::chrono::steady_clock::now();

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::string userInput;
    std::getline(std::cin, userInput);
    auto end = std::chrono::steady_clock::now();

    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    if (userInput == phrase && elapsedTime<= 10000) {
        std::cout << "Bravo ! Vous avez tapé la phrase correctement en moins de 10 secondes." << std::endl;
        return true;
    } else {
        std::cout << "Désolé, vous avez fait une erreur ou pris trop de temps." << std::endl;
        return false;
    }
    
    }else{

        if (mockTime <= 10 && mockInput == phrase){return true;}
        else{return false;}
        
    }

}

void Banque:: afficherErreurEmprunt() {
std::cout <<"Vous avez deja effectué un emprunt !"<< std::endl;
}

void Banque:: afficherErreurEmpruntMontant(const Emprunt emprunt) {
std::cout <<"Vous demandez trop !"<< std::endl;
std::cout<<"le montant maximal est "<<emprunt.getMontantMax()<<std::endl;
}

void Banque:: afficherSuccesEmprunt() {
std::cout <<"Felicitations, vous avez effectue un emprunt !"<< std::endl;
}

void Banque:: afficherErreurRembours() {
std::cout <<"Vous n avez rien a rembourser !"<< std::endl;
}

void Banque:: afficherSuccesRembours() {
std::cout <<"Merci d avoir rembourse !"<< std::endl;
}

void Banque:: afficherErreurRemboursCapital() {
std::cout <<"Pas assez de capital pour rembourser"<< std::endl;
}

double Banque::demanderMontantEmprunt() {
    double montant;
    std::cout << "Entrez le montant de l'emprunt : ";
    std::cin >> montant;
    return montant;
}


void Banque:: emprunter(Emprunt emprunt, Personnage& perso) {

double montantEmprunt= emprunt.getMontant();
double capital= perso.getCapital();

	    perso.setCapital(capital + montantEmprunt);
	    //afficherSuccesEmprunt();
	    perso.setState_Emprunter(true);
}

void Banque:: ProcessusEmprunter(Personnage& perso, Emprunt& emprunt, bool mockBoolean, double mockMontant) {
	if(mockMontant == 0){


	if (!perso.getState_Emprunter()) {
		double montant=demanderMontantEmprunt();
        if (mockBoolean == true){
            if (montant <= emprunt.getMontantMax() ) {
			    emprunt.setMontant(montant);
			    emprunter(emprunt,perso);
			    afficherSuccesEmprunt();
		    }
		    else {
                afficherErreurEmpruntMontant(emprunt);
            }
        }
        else {
            auto mockCurrentTime = []() { return std::chrono::steady_clock::now(); };
            bool boolean = jeuTapeRapide(getPhrase(), 0, "aze");
            if (boolean == true){
                if (montant <= emprunt.getMontantMax() ) {
			        emprunt.setMontant(montant);
			        emprunter(emprunt,perso);
			        afficherSuccesEmprunt();
		        }
		        else {
                    afficherErreurEmpruntMontant(emprunt);
                }
            }
            
        }
		
	}
	else afficherErreurEmprunt();


    }else{


    if (!perso.getState_Emprunter()) {
		// double montant=demanderMontantEmprunt();
        if (mockBoolean == true){
            if (mockMontant <= emprunt.getMontantMax() ) {
			    emprunt.setMontant(mockMontant);
			    emprunter(emprunt,perso);
			    afficherSuccesEmprunt();
		    }
		    else {
                afficherErreurEmpruntMontant(emprunt);
            }
        }
        else {
            auto mockCurrentTime = []() { return std::chrono::steady_clock::now(); };
            bool boolean = jeuTapeRapide(getPhrase(), 0, "sdq");
            if (boolean == true){
                if (mockMontant <= emprunt.getMontantMax() ) {
			        emprunt.setMontant(mockMontant);
			        emprunter(emprunt,perso);
			        afficherSuccesEmprunt();
		        }
		        else {
                    afficherErreurEmpruntMontant(emprunt);
                }
            }
            
        }
		
	}
	else afficherErreurEmprunt();


    }
}
void Banque:: rembourser(Emprunt emprunt, Personnage& perso) {

double montantEmprunt= emprunt.getMontant();
double capital= perso.getCapital();

//if (perso.getState_Emprunter()) {
    if (capital >= montantEmprunt) {
        perso.setCapital(capital - montantEmprunt);
    }else {
            afficherErreurRemboursCapital();
    }
//}else {afficherErreurEmprunt();
//}
};


void Banque:: ProcessusRembourser(Emprunt emprunt,Personnage& perso) {



double montantEmprunt= emprunt.getMontant();
double capital= perso.getCapital();
if (perso.getState_Emprunter()) {

	if (capital >= montantEmprunt) {
		rembourser(emprunt,perso);
	}
	else{
	afficherErreurRemboursCapital();
	}
}
else { 
afficherErreurRembours();
}


}


// bool Banque::jeuTapeRapide(const std::string phrase) {
    
//     std::cout << "Bonjour, vous avez 7 secondes pour taper la phrase : \n";
//     std::cout << phrase << std::endl;
//     auto debutTemps = std::chrono::steady_clock::now();
//     std::string saisie;
//     std::getline(std::cin, saisie);
//     auto finTemps = std::chrono::steady_clock::now();
//     double tempsTape = std::chrono::duration_cast<std::chrono::milliseconds>(finTemps - debutTemps).count() / 1000.0;

//     if (saisie == phrase && tempsTape <= 7) {
//         std::cout << "Bravo ! Vous avez tapé la phrase correctement en moins de 7 secondes." << std::endl;
//         return true;
//     } else {
//         std::cout << "Désolé, vous avez fait une erreur ou pris trop de temps." << std::endl;
//         return false;
//     }
// }
// 

void Banque::getUserInput(std::string& input) {
    std::getline(std::cin, input);
}
