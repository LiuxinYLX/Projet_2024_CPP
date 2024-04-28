#include "include/Article.hpp"
#include "include/Auberge.hpp"
#include "include/Banque.hpp"
#include "include/Batiment.hpp"
#include "include/BlackJ.hpp"
#include "include/Casino.hpp"
#include "include/CentreDesMetiers.hpp"
#include "include/Couleur.hpp"
#include "include/Domaine.hpp"
#include "include/Emprunt.hpp"
#include "include/EtablissementCommercial.hpp"
#include "include/Jeu.hpp"
#include "include/MachineS.hpp"
#include "include/Personnage.hpp"
#include "include/Question.hpp"
#include "include/Quizz.hpp"
#include "include/Roulette.hpp"
#include <iostream>
#include <string>

int main(){

    //Création du personnage
    Personnage P;

    //Création du CDM et chargement des quizzs
    CentreDesMetiers centre("INSACHOMAGE", "90 avenue de Caen 76000 Rouen");
    Quizz q_a(Domaine::art);
    q_a.chargerQuizz("data/questions_art.txt",q_a);
    Quizz q_s(Domaine::sante);
    q_s.chargerQuizz("data/questions_sante.txt",q_s);
    Quizz q_i(Domaine::ingenierie);
    q_i.chargerQuizz("data/questions_ingenierie.txt",q_i);
    Quizz q_au(Domaine::autre);
    q_au.chargerQuizz("data/questions_autre.txt",q_au);

    centre.ajouterQuizz(q_a);
    centre.ajouterQuizz(q_au);
    centre.ajouterQuizz(q_s);
    centre.ajouterQuizz(q_i);


    //Création des établissements auberge, banque,...
    Auberge auberge("Sleepici", " 29 Avenue Maryse Bastié 76800 Saint-Étienne-du-Rouvray", 25, 5);
    Banque banque("GimmeMoney", "37 rue Jeanne D'Arc 76000 Rouen", "The weather is great!");
    Emprunt emprunt(0, 500, 1, 5);
    EtablissementCommercial etab("HungryBelly","11 avenue de la Mare aux Daims 76800 Saint-Étienne-du-Rouvray", supermarche);
    Casino casino("OCASINO", "158 Street INSA 76800 Saint-Étienne-du-Rouvray", {});


    //Chargement des articles de l'établissement commercial
    etab.ajouterArticlesDepuisFichier("data/listeArticles.txt");

    

    int Jour = 0;
    int choix0;

    
    while (true) {
        std::cout << "Bonjour et bienvenue à CityGame! \n Que souhaitez-vous faire ?" << std::endl;
        std::cout << "1. Choisir un personnage et jouer!" << std::endl;
        std::cout << "2. Quitter" << std::endl;

        int choix0;
        std::cin >> choix0;

        switch (choix0) {
            case 1:
                    P = P.creationPerso();
                            
                    while (true) {
                        if (P.getEnergie() <= 0) break;


                        // Displaying the menu
                        std::cout << "*************************************************************************** " << std::endl;
                        std::cout << "Bonjour, Jour: " << Jour << std::endl;
                        P.affichPers();
                        
                        
                        std::cout << "Où souhaitez vous aller?" << std::endl;

                        std::cout << "  ________________CityGame________________" << std::endl;
                        std::cout << " /                                         \\" << std::endl;
                        std::cout << "|        1.CDM               2.Auberge     |" << std::endl;
                        std::cout << "|       ___________         _____/\\_____   |" << std::endl;
                        std::cout << "|      |          |         |    zzzzz  |  |" << std::endl;
                        std::cout << "|      |  _    _  |         |  _    _   |  |" << std::endl;
                        std::cout << "|      | |_|  |_| |         | |_|  |_|  |  |" << std::endl;
                        std::cout << "|      |__________|         |_____/\\____|  |" << std::endl;
                        std::cout << "|                                          |" << std::endl;
                        std::cout << "|                                          |" << std::endl;
                        std::cout << "|  3.Banque     4.Établissement    5.Casino|" << std::endl;
                        std::cout << "|                commercial                |" << std::endl;
                        std::cout << "|   _____          _______           ______|" << std::endl;
                        std::cout << "|  |  £  |        |       |         |  $$  |" << std::endl;
                        std::cout << "|  |  _  |        |   _   |         |  _   |" << std::endl;
                        std::cout << "|  | |_| |        |  |_|  |         | |_|  |" << std::endl;
                        std::cout << "|  |_____|        |_______|         |______|" << std::endl;
                        std::cout << "|                                          |" << std::endl;
                        std::cout << "|                               6.Quitter  |" << std::endl;
                        std::cout << "|                                          |" << std::endl;
                        std::cout << "  __________________________________________" << std::endl;

                        std::cout << "Saisir votre choix: ";


                        int choix1;
                        std::cin >> choix1;

                        switch (choix1) {
                            case 1:
                                std::cout << "Vous avez choisi le Centre des Métiers" << std::endl;
                                if (P.getRassasiement() > 0) {
                                    centre.afficherInfo();
                                    int gain = centre.startCDM(centre); 
                                    int capCDM = P.getCapital() + gain;
                                    P.setCapital(capCDM);

                                }
                                break;

                            case 2:
                                std::cout << "Vous avez choisi l'auberge" << std::endl;
                                char choix2;
                                auberge.afficherInfo();

                                if (auberge.saisieChoix() == 'O') {
                                    int capitalIni = P.getCapital();
                                    auberge.dormirSousUnToit(P);
                                    if (capitalIni > P.getCapital()) {
                                        Jour += 1;  // Only increment day if capital has increased
                                    }
                                } else {
                                    std::cout << "bye bye" << std::endl;
                                } 

                                

                                break;

                            case 5:
                                std::cout << "Vous avez choisi le casino" << std::endl;
                                if (P.getRassasiement() > 0) {
                                    casino.afficherInfo();
                                    casino.start(P);
                                }
                                break;

                            
                            
                            case 3:
                                std::cout << "Vous avez choisi la banque'" << std::endl;
                                int choix_banque;
                                banque.afficherInfo();
                                std::cout << "Que souhaitez-vous faire? \n 1.Emprunter \n 2.Rembourser \n";
                                std::cin >> choix_banque;
                                switch(choix_banque){
                                    case 1:
                                        banque.ProcessusEmprunter(P, emprunt, false, 0);break;

                                    case 2:
                                        banque.ProcessusRembourser(emprunt, P);break;
                                }
                                break;

                            case 4:
                                std::cout << "Vous avez choisi l'établissement commercial" << std::endl;
                                etab.afficherInfo();
                                etab.start(P);

                                break;

                            case 6:
                                break;
                        }

                        if (choix1 == 6) {
                            break;
                        }
                    }


            case 2:
                std::cout << "Au revoir !" << std::endl;
                return 0;
            default:
                std::cout << "Choix non valide. Veuillez saisir un numéro valide." << std::endl;
                break;
        }
    }

    return 0;
}






