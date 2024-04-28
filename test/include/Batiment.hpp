#ifndef BATIMENT_HPP
#define BATIMENT_HPP

#include <string>

/**
 * @brief Représente un bâtiment avec un nom et une adresse.
 */
class Batiment {
protected:
    std::string nom;       ///< Le nom du bâtiment.
    std::string adresse;   ///< L'adresse du bâtiment.

public:
    /**
     * @brief Constructeur qui crée un bâtiment avec un nom et une adresse spécifiés.
     * @param nom Le nom du bâtiment.
     * @param adresse L'adresse du bâtiment.
     */
    Batiment(const std::string& nom, const std::string& adresse);

    /**
     * @brief Destructeur virtuel.
     */
    virtual ~Batiment();

    /**
     * @brief Affiche les informations du bâtiment.
     */
    virtual void afficherInfo() const = 0;

    /**
     * @brief Obtient le nom du bâtiment.
     * @return Retourne le nom du bâtiment.
     */
    const std::string& getNom() const;

    /**
     * @brief Définit le nom du bâtiment.
     * @param nom Le nouveau nom du bâtiment.
     */
    void setNom(const std::string& nom);

    /**
     * @brief Obtient l'adresse du bâtiment.
     * @return Retourne l'adresse du bâtiment.
     */
    const std::string& getAdresse() const;

    /**
     * @brief Définit l'adresse du bâtiment.
     * @param adresse La nouvelle adresse du bâtiment.
     */
    void setAdresse(const std::string& adresse);
};

#endif // BATIMENT_HPP
