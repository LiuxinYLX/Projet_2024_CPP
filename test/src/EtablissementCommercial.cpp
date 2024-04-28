#include <iostream> // 包含 iostream 以使用 std::cout 和 std::cin
#include <sstream> 
#include <limits>
#include <algorithm> // Pour std::find_if
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include "../include/Batiment.hpp"
#include "../include/EtablissementCommercial.hpp"
#include "../include/Article.hpp"
#include "../include/EtablissementCommercial.hpp"

EtablissementCommercial::EtablissementCommercial(const std::string& nom, const std::string& adresse, TypeEtablissement type)
    : Batiment(nom, adresse), type(type) {}

void EtablissementCommercial::afficherProduits() const {
    for (const auto& article : listeArticles) {
        std::cout << "Article: " << article.getNom() << ", Prix: " << article.getPrix() << std::endl;
    }
}

std::list<Article> EtablissementCommercial::choisir() {
    std::list<Article> selectionnes;
    afficherProduits(); // Afficher tous les produits en premier

    std::cout << "Veuillez entrer les numéros des articles que vous souhaitez choisir, séparés par des virgules (par exemple : 1,3,5). Appuyez sur Entrée lorsque vous avez terminé :" << std::endl;
    
    //std::cin.clear(); // Clear any error flags
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard any leftover input

    std::string input;
    std::getline(std::cin, input); // Lire la sélection de l'utilisateur à partir de l'entrée standard

    std::istringstream iss(input);
    std::string item;
    while (std::getline(iss, item, ',')) {
        try {
            int index = std::stoi(item) - 1; // Supposant que l'entrée de l'utilisateur commence à partir de 1
            if (index >= 0 && index < listeArticles.size()) {
                auto it = std::next(listeArticles.begin(), index);
                if (it->getQuantite() > 0) { // S'assurer que l'article est en stock
                    selectionnes.push_back(*it);
                } else {
                    std::cout << "L'article " << item << " est en rupture de stock. Veuillez choisir un autre article." << std::endl;
                }
            } else {
                std::cout << "Aucun article trouvé avec le numéro " << item << ". Veuillez entrer un numéro d'article valide." << std::endl;
            }
        } catch (const std::invalid_argument& e) {
            std::cout << "Entrée non reconnue : " << item << ". Assurez-vous d'entrer un nombre." << std::endl;
        } catch (const std::out_of_range& e) {
            std::cout << "Le numéro entré " << item << " est hors de la plage valide." << std::endl;
        }
    }

    return selectionnes;
}


void EtablissementCommercial::consommer(Personnage& personnage) {
    
    std::list<Article> selectionnes = choisir();
    for (auto& article : selectionnes) {
        if (article.getQuantite() > 0) { // Vérifier le stock
            double nouveauCapital = personnage.getCapital() -static_cast<double>(article.getPrix());
            int nouvelleEnergie = personnage.getEnergie() + article.getRassemblementGain(); // Supposant que la consommation d'un article augmente l'énergie
            if (nouvelleEnergie > 5){
                nouvelleEnergie = 5;
            }
            personnage.setCapital(nouveauCapital); // Mettre à jour le capital du personnage
            personnage.setEnergie(nouvelleEnergie); // Mettre à jour l'énergie du personnage

            article.setQuantite(article.getQuantite() - 1); // Réduire la quantité de l'article
        }
    }
}


void EtablissementCommercial::ajouterArticle(const Article& article) {
    listeArticles.push_back(article);
}

void EtablissementCommercial::supprimerArticle(Article& article) {
    listeArticles.remove(article);
}

std::list<Article> EtablissementCommercial::obtenirListeArticles() const {
    return listeArticles;
}

void EtablissementCommercial::definirType(TypeEtablissement type) {
    this->type = type;
}

TypeEtablissement EtablissementCommercial::obtenirType() const {
    return type;
}

void EtablissementCommercial::afficherInfo() const {
    Batiment::afficherInfo(); // Appeler la méthode de la classe de base
    std::cout << "Type d'établissement: " << (type == supermarche ? "Supermarché" : "Restaurant") << std::endl;
    afficherProduits();
}

void EtablissementCommercial::ajouterArticlesDepuisFichier(const std::string& nomFichier) {
    std::ifstream fichier(nomFichier);
    if (!fichier) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << nomFichier << std::endl;
        return;
    }

    std::string ligne;
    while (std::getline(fichier, ligne)) {
        // Utilisez un flux de chaînes pour lire les données de la ligne
        std::istringstream ss(ligne);
        
        // Déclarez des variables pour stocker les informations de l'article
        std::string nom;
        double prix;
        std::string description;
        int quantite;
        int categorie;

        // Utilisez le flux de chaînes pour extraire les informations de la ligne
        if (std::getline(ss, nom, ',') &&
            (ss >> prix).ignore() &&
            std::getline(ss, description, ',') &&
            (ss >> quantite).ignore() &&
            (ss >> categorie)) {
            // Créez un nouvel objet Article avec les informations extraites
            Article nouvelArticle(nom, prix, description, quantite, categorie);
            
            // Ajoutez l'article à la liste d'articles de l'établissement commercial
            ajouterArticle(nouvelArticle);
        } else {
            std::cerr << "Erreur lors de la lecture de la ligne : " << ligne << std::endl;
        }
    }
}

// Define a function that acts like the main logic
void EtablissementCommercial::start(Personnage& personnage) {
    // Load articles from a file
    std::string fichierArticles = "articles.txt"; // Ensure this file is in the correct location
    ajouterArticlesDepuisFichier(fichierArticles);

    // Display the initial state of the customer
    std::cout << "Bienvenue, " << personnage.getNomPrenom() << "!\n";
    std::cout << "Capital initial: " << personnage.getCapital() << " €\n";
    std::cout << "Énergie initiale: " << personnage.getEnergie() << "\n\n";

    // Display the establishment information and available products
    afficherInfo();

    // Simulate the customer buying products
    consommer(personnage);

    // Display the final state of the customer
    std::cout << "\nAprès les achats:\n";
    std::cout << "Capital restant: " << personnage.getCapital() << " €\n";
    std::cout << "Énergie restante: " << personnage.getEnergie() << "\n";
}



