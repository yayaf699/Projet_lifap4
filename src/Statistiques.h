#ifndef STATISTIQUES_H_INCLUDED
#define STATISTIQUES_H_INCLUDED

class Statistiques
{
public:

// COSNTRUCTEURS ET DESTRUCTEURS

    /**
     * @brief Constructeur par défaut de la classe Statistiques
     * 
     */
    Statistiques();

    /**
     * @brief Constructeur par copie de la classe Statistiques
     * 
     * @param v 
     * @param vi 
     * @param f 
     */
    Statistiques(const int &v, const int &vi, const float &f);

// ACCESSEURS ET MUTATEURS

    /**
     * @brief Accesseur: récupère la vie
     * 
     * @return const int& 
     */
    const int &getVie() const;


    /**
     * @brief Accesseur: récupère la vie
     * 
     * @return const int& 
     */
    const int &getVitesse() const;

    /**
     * @brief Accesseur: récupère la vie
     * 
     * @return const float& 
     */
    const float &getForce() const;

    /**
     * @brief Mutateur: Initialise la vie
     * 
     * @param v 
     */
    void setVie(int v);

    /**
     * @brief Mutateur: Initialise la vitesse
     * 
     * @param vi 
     */
    void setVitesse(const int &vi);

    /**
     * @brief Mutateur: Initialise la force
     * 
     * @param f 
     */
    void setForce(const float &f);

// GESTION STATS

    /**
     * @brief affiche les statistiques en mode texte
     * 
     */
    void afficherStat();


    
private:

    /**
     * @brief Les PV du personnage, entre 0 et 100
     * 
     */
    int vie; // sur 100

    /**
     * @brief La vitesse du personnage
     * 
     */
    int vitesse; // sur 100

    /**
     * @brief La force du personnage
     * 
     */
    float force; // multiplicateur
};

#endif // STATISTIQUES_H_INCLUDED
