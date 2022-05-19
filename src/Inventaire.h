/**
 * @file Inventaire.h
 * @author 
 * @brief 
 * @version 0.1
 * @date 2022-05-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef INVENTAIRE_H_INCLUDED
#define INVENTAIRE_H_INCLUDED
#include "Objet.h"


using namespace std;



class Inventaire
{
public:

// CONSTRUCTEUR ET DESTRUCTEUR

    /**
     * @brief Constructeur par défaut de la classe Inventaire
     * 
     */
    Inventaire();

    /**
     * @brief Destructeur de la classe Inventaire
     * 
     */
    ~Inventaire();

// ACCESSEURS

    /**
     * @brief accesseur: recupere la taille de l'inventaire
     * 
     * @return const unsigned int 
     */
    const unsigned int getTailleInventaire();

    /**
     * @brief Accesseur: récupère l'objet de l'inventaire qui correspond à l'indice en paramètre
     * 
     * @param i 
     * @return Objet 
     */
    Objet getInventaire(const unsigned int &i);

// GESTION DE L'INVENTAIRE

    /**
     * @brief Affiche l'inventaire en mode txt
     * 
     */
    void afficherInventaire() const;

    /**
     * @brief jète un objet de l'inventaire
     * 
     * @param o 
     */
    void retirerObjetInventaire(Objet &o);

    /**
     * @brief Recherche un objet de l'inventaire et retourne son indice
     * 
     * @param nomObjet 
     * @return int 
     */
    int rechercherObjetInventaire(string nomObjet) ;

    /**
     * @brief Ajoute un objet
     * 
     * @param indice 
     * @param nom 
     * @param bonusvie 
     * @param bonusvitesse 
     * @param bonusforce 
     */
    void ajouterObjet(const unsigned int indice, string nom, int bonusvie, int bonusvitesse, float bonusforce);


private:

    int taille_inventaire;
    Objet *inventaire;
};

#endif // INVENTAIRE_H_INCLUDED
