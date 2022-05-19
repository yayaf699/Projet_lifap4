/**
 * @file Joueur.h
 * @author 
 * @brief 
 * @version 0.1
 * @date 2022-05-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED
#include <string>
#include "Arme.h"
#include "Statistiques.h"
#include "Inventaire.h"
#include "Objet.h"
#include "Attaque.h"

using namespace std;

class Joueur{
public:

// LE CONSTRUCTEUR

    /**
     * @brief Construct par défaut de la classe joueur
     * 
     */
    Joueur();


// LES ACCESSEURS

    /**
     * @brief Accesseur: récupère le nom du joueur
     * 
     * @return const string& 
     */
    const string &getNom() const;

    /**
     * @brief Accesseur: récupère l'etat du joueur
     * 
     * @return string 
     */
    string getEtat();

    /**
     * @brief Accesseur: récupère le nombre de tour passé du joueur
     * 
     * @return int 
     */
    int getNbTourEtat();

    /**
     * @brief Accesseur: récupère les stats du joueur
     * 
     * @return Statistiques 
     */
    Statistiques getStats();

    /**
     * @brief Accesseur: récupère l'inventaire du joueur
     * 
     * @return Inventaire 
     */
    Inventaire getInv();

    /**
     * @brief Accesseur: récupère l'arme du joueur
     * 
     * @return Arme 
     */
    Arme getArme();

    /**
     * @brief Accesseur: récupère le nombre de pièces du joueur
     * 
     * @return int 
     */
    int getPiece();

// LES MUTATEURS

    /**
     * @brief Mutateur: initialise le nom du joueur
     * 
     * @param n 
     */
    void setNom(const string& n);

    /**
     * @brief Mutateur: initialise l'etat du joueur
     * 
     * @param e 
     */
    void setEtat(string e);

    /**
     * @brief Mutateur: initialise le nombre de tour passés du joueur
     * 
     * @param nb 
     */
    void setNbTourEtat(int nb);

    /**
     * @brief Mutateur: initialise le nombre de pièces du joueur
     * 
     * @param p 
     */
    void setPiece(int p);

// GESTION DU JOUEUR

    /**
     * @brief indique le choix de l'action qui va etre fait
     * 
     * @return int 
     */
    int choixAction();

    /**
     * @brief Affiche les infos du joueur en mode txt
     * 
     */
    void afficherJoueur();

    /**
     * @brief réalise une attaque
     * 
     * @param i 
     * @return Attaque 
     */
    Attaque Attaquer(int i);

    /**
     * @brief Affiche l'inventaire en mode txt
     * 
     */
    void afficherInventaire() const;

    /**
     * @brief Utilise un objet
     * 
     * @param o 
     */
    void utiliserObjet(Objet o);

    /**
     * @brief opérateur =
     * 
     * @param j 
     * @return Joueur& 
     */
    Joueur &operator=(const Joueur &j);

    /**
     * @brief Ajoute un joueur
     * 
     * @param n 
     */
    void ajouterJoueur(unsigned int n);


    /**
     * @brief Actualise la vie
     * 
     * @param degatsRecu 
     */
    void MajVieJoueur(int degatsRecu);

    /**
     * @brief Achète un objet
     * 
     * @param o 
     * @param prix 
     */
    void acheterObjet(string nom_Objet, int prix);

private:

    string nomJoueur;
    string etat;
    int nbTourEtat;
    Statistiques stat; // les stats du joueur
    Inventaire inv; // l'inventaire d'objets du joueur
    Arme arm; // l'arme du joueur
    int piece; // la monnaie du joueur

};

#endif // JOUEUR_H_INCLUDED
