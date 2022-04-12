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

    //MUTATEUR STATS
    void setStat(const string &s, float valeur);

// GESTION DU JOUEUR

    // CHOIX DE L'ACTION
    int choixAction();

    // OPERATEUR << POUR AFFICHER TOUTES LES STATS
    void afficherJoueur();

    int getVie();

    void SetVie(int valeur);

    Inventaire getInv();

    Arme getArme();

    string getEtat();

    Statistiques getStats();

    Attaque Attaquer(int i);

    void afficherInventaire() const;

    void utiliserObjet(Objet o);

    Joueur &operator=(const Joueur &j);

    void ajouterJoueur(unsigned int n);

    int getNbTourEtat();
    void setNbTourEtat(int nbTour);

    void setEtat(string etat_);

private:

    string nomJoueur;
    string etat;
    int nbTourEtat;
    Statistiques stat; // les stats du joueur
    Inventaire inv; // l'inventaire d'objets du joueur
    Arme arm; // l'arme du joueur

};

#endif // JOUEUR_H_INCLUDED
