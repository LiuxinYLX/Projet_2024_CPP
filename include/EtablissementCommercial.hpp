#ifndef ETABLISSEMENTCOMMERCIAL_HPP
#define ETABLISSEMENTCOMMERCIAL_HPP
#include "Personnage.hpp"
#include "Batiment.hpp"
#include <list>
#include <string>

enum TypeEtablissement { supermarche, restaurant };

class Article;

/**
 * @brief Représente un établissement commercial comme un supermarché ou un restaurant.
 */
class EtablissementCommercial : public Batiment {
private:
    TypeEtablissement type; ///< Type de l'établissement: supermarché ou restaurant.
    std::list<Article> listeArticles; ///< Liste des articles disponibles.

public:
    /**
     * @brief Constructeur de l'établissement commercial.
     * @param nom Nom de l'établissement.
     * @param adresse Adresse de l'établissement.
     * @param type Type de l'établissement (supermarché ou restaurant).
     */
    EtablissementCommercial(const std::string& nom, const std::string& adresse, TypeEtablissement type);

    /**
     * @brief Afficher la liste des produits disponibles.
     */
    void afficherProduits() const;

    /**
     * @brief Permettre l'utilisateur de choisir plusieurs articles
     */
    std::list<Article> choisir();
    
    /**
     * @brief Permettre l'utilisateur de consommer un article choisi
     */
    void consommer(Personnage& personnage);

    /**
     * @brief Ajouter un article à la liste des produits disponibles.
     * @param article L'article à ajouter.
     */
    void ajouterArticle(const Article& article);

    /**
     * @brief Supprime un article de la liste des produits disponibles.
     * @param article L'article à supprimer.
     */
    void supprimerArticle(Article& article);

    /**
     * @brief Obtient la liste des articles disponibles dans l'établissement.
     * @return La liste des articles.
     */
    std::list<Article> obtenirListeArticles() const;

    /**
     * @brief Définit le type de l'établissement commercial.
     * @param type Le nouveau type de l'établissement.
     */
    void definirType(TypeEtablissement type);

    /**
     * @brief Obtient le type de l'établissement commercial.
     * @return Le type de l'établissement.
     */
    TypeEtablissement obtenirType() const;

    /**
     * @brief Méthode réécrite pour afficher les informations spécifiques du batiment Etablissement commercial
     */
    virtual void afficherInfo() const override;

    /**
     * @brief Lire un fichier texte pour enregister les articles comme objets
     */
    void ajouterArticlesDepuisFichier(const std::string& nomFichier);

    /**
     * @brief Lire un fichier texte pour enregister les articles comme objets
     */
    void start(Personnage& personnage);



};
#endif // ETABLISSEMENTCOMMERCIAL_HPP
