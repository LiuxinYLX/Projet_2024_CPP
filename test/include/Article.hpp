#ifndef ARTICLE_HPP
#define ARTICLE_HPP

#include <string>

/**
 * @brief Représente un article avec nom, prix, description, gain de rassemblement et quantité.
 */
class Article {
private:
    std::string nom;          ///< Nom de l'article.
    int prix;                 ///< Prix de l'article en unités monétaires.
    std::string description;  ///< Description de l'article.
    int rassemblementGain;    ///< Gain potentiel de rassemblement.
    int quantite;             ///< Quantité disponible.

public:
    /**
     * @brief Constructeur qui initialise un nouvel article.
     * @param nom Nom de l'article.
     * @param prix Prix de l'article.
     * @param description Description de l'article.
     * @param rassemblementGain Gain potentiel de rassemblement.
     * @param quantite Quantité disponible de l'article.
     */
    Article(const std::string& nom, int prix, const std::string& description, 
            int rassemblementGain, int quantite);

    /**
     * @brief Affiche les informations sur l'article.
     */
    void afficherInfoArticle() const;

    // Méthodes d'accès

    /**
     * @brief Obtient le nom de l'article.
     * @return Le nom de l'article.
     */
    std::string getNom() const;

    /**
     * @brief Obtient le prix de l'article.
     * @return Le prix de l'article.
     */
    int getPrix() const;

    /**
     * @brief Obtient la description de l'article.
     * @return La description de l'article.
     */
    std::string getDescription() const;

    /**
     * @brief Obtient le gain de rassemblement de l'article.
     * @return Le gain de rassemblement.
     */
    int getRassemblementGain() const;

    /**
     * @brief Obtient la quantité disponible de l'article.
     * @return La quantité disponible.
     */
    int getQuantite() const;

    // Méthodes de modification

    /**
     * @brief Définit le nom de l'article.
     * @param nom Le nouveau nom de l'article.
     */
    void setNom(const std::string& nom);

    /**
     * @brief Définit le prix de l'article.
     * @param prix Le nouveau prix de l'article.
     */
    void setPrix(int prix);

    /**
     * @brief Définit la description de l'article.
     * @param description La nouvelle description de l'article.
     */
    void setDescription(const std::string& description);

    /**
     * @brief Définit le gain de rassemblement de l'article.
     * @param rassemblementGain Le nouveau gain de rassemblement.
     */
    void setRassemblementGain(int rassemblementGain);

    /**
     * @brief Définit la quantité disponible de l'article.
     * @param quantite La nouvelle quantité disponible.
     */
    void setQuantite(int quantite);

    /**
     * @brief Surcharge de l'opérateur == pour comparer deux articles.
     * @param autre L'autre article à comparer.
     * @return True si les articles sont égaux, false sinon.
     */
    bool operator==(const Article& autre) const;
};

#endif // ARTICLE_HPP
