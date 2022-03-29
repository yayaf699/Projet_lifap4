#include "Joueur.h"
#include <iostream>

using namespace std;


// LES CONSTRUCTEURS ET DESTRUCTEUR

    // CONSTRUCTEUR PAR DEFAUT
    Joueur()
    {
        nomJoueur = "Monkey D. Nordin";

        stat = new Statistique;
        inv = new Inventaire;
        arm = new Arme;
    }

    // CONSTRUCTEUR PERSONNALISÉ
    Joueur(const string &n, const unsigned int &vi, const unsigned int &f, const unsigned int &v, const unsigned int &e, const Inventaire &in, const Arme &ar)
    {
            // à finir
    }

    // DESTRUCTEUR
    ~Joueur()
    {
        nomJoueur = "";

        delete stat;
        delete inv;
        delete arm;
    }

// LES ACCESSEURS ET MUTATEURS 

    // ACCESSEUR NOM
    const string &getNom() const { return nomJoueur; }

    // MUTATEUR NOM
    void setNom(const string& n) { nomJoueur = n; }

// GESTION DU JOUEUR 

    // CHOIX DE L'ACTION
    int choixAction()
    {
        int i;

        cout<<"Que voulez-vous faire ?"<<endl;
        cout<<"1. Utiliser un Objet 2. Utiliser arme"<<endl;
        cin>>i;

        return i;
    }

    // OPERATEUR << POUR AFFICHER TOUTES LES STATS
    void operator<<()
    {
        cout<<"******* STAT DU JOUEUR ******* "<<endl;
        stat.afficherStats();

        cout<<"******* INVENTAIRE ******* "<<endl;
        inv.afficherInventaire();

        cout<<"******* ARME ******* "<<endl;
        arm.afficher();
    } 
