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

    // CONSTRUCTEUR PAR DEFAUT
    Joueur();


// LES ACCESSEURS ET MUTATEURS

    // ACCESSEUR NOM
    const string &getNom() const;

    // MUTATEUR NOM
    void setNom(const string& n);

    // ACCESSEUR STATS
    Statistiques getStats();

    //MUTATEUR STATS
    void setStat(const string &s, float valeur);

    // ACCESSEUR VIE
    int getVie();

    // MUTATEUR VIE
    void SetVie(int valeur);

    // ACCESSEUR ARME
    Arme getArme();

    // ACCESSEUR INVENTAIRE
    Inventaire getInv();

    // ACCESSEUR ETAT
    string getEtat();

    // MUTATEUR ETAT
    void setEtat(string etat_);

    // ACCESSEUR NOMBRE DE TOURS ETAT
    int getNbTourEtat();

    // MUTATEUR NOMBRE DE TOURS ETAT
    void setNbTourEtat(int nbTour);

// GESTION DU JOUEUR

    // CHOIX DE L'ACTION
    int choixAction();

    // OPERATEUR << POUR AFFICHER TOUTES LES STATS
    void afficherJoueur();

    // ATTAQUER
    Attaque Attaquer(int i);

    // AFFICHE L'INVENTAIRE
    void afficherInventaire() const;

    // UTILISER L'OBJET
    void utiliserObjet(Objet o);

    // OPERATEUR =
    Joueur &operator=(const Joueur &j);

    // AJOUTER UN JOUEUR
    void ajouterJoueur(unsigned int n);

private:

    string nomJoueur;
    string etat;
    int nbTourEtat;
    Statistiques stat; // les stats du joueur
    Inventaire inv; // l'inventaire d'objets du joueur
    Arme arm; // l'arme du joueur

};

#endif // JOUEUR_H_INCLUDED
