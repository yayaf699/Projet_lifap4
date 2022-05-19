/**
 * @file Objet.h
 * @author 
 * @brief 
 * @version 0.1
 * @date 2022-05-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef OBJET_H_INCLUDED
#define OBJET_H_INCLUDED
#include <string>

using namespace std;


class Objet
{
public:

// LES CONSTRUCTEURS

    /**
     * @brief Constructeur par défaut de la classe Objet
     * 
     */
    Objet();

    /**
     * @brief Constructeur par copie de la classe Objet
     * 
     * @param o 
     */
    Objet(const Objet &o);

// LES ACCESEURS

    /**
     * @brief Accesseur: récupère le nom de l'objet
     * 
     * @return const string& 
     */
    const string &getNomObjet() const;

    /**
     * @brief Accesseur: récupère la vie de l'objet
     * 
     * @return const unsigned int& 
     */
    const unsigned int &getVieObjet() const;

    /**
     * @brief Accesseur: récupère la force de l'objet
     * 
     * @return const float& 
     */
    const float &getForceObjet() const;

    /**
     * @brief Accesseur: récupère la vitesse de l'objet
     * 
     * @return const unsigned int& 
     */
    const unsigned int &getVitesseObjet() const;

    /**
     * @brief 
     * 
     * @return const unsigned int& 
     */
    const unsigned int &getAttaqueUtilisation() const;


// LES MUTATEURS

    /**
     * @brief Mutateur: change le nom de l'objet
     * 
     * @param n 
     */
    void setNomObjet(const string &n);

    /**
     * @brief Mutateur: change la vie de l'objet
     * 
     * @param v 
     */
    void setVieObjet(const unsigned int &v);

    /**
     * @brief Mutateur: change la force de l'objet
     * 
     * @param f 
     */
    void setForceObjet(const  float &f);

    /**
     * @brief Mutateur: change la vitesse de l'objet
     * 
     * @param vi 
     */
    void setVitesseObjet(const unsigned int &vi);

    /**
     * @brief Mutateur: change le nombre d'utilisation de l'attaque
     * 
     * @param ut 
     */
    void setAttaqueUtilisation(const unsigned int &ut);


// GESTION DE L'OBJET

    /**
     * @brief Affiche les informations de l'objet en mode txt
     * 
     */
    void afficherObjet();

    /**
     * @brief ajoute l'objet à partir de son nom en recuperant ses stats dans un .json
     * 
     * @param nomJSON 
     */
    void ajouterObjetJSON(const string &nomJSON);


private:

    /**
     * @brief Nom de l'objet
     * 
     */
    string nom; 

    /**
     * @brief Stats de l'objet
     * 
     */
    unsigned int bonusVie, bonusVitesse, bonusAttaqueUtilisation;
    float bonusForce;
};

#endif // OBJET_H_INCLUDED
