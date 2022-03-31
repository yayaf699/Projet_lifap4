#include "Joueur.h"
#include <iostream>
#include "Statistiques.h"
using namespace std;


// LES CONSTRUCTEURS ET DESTRUCTEUR

    // CONSTRUCTEUR PAR DEFAUT
    Joueur::Joueur()
    {
        nomJoueur = "Monkey D. Nordin";

        Statistiques *stat = new Statistiques(100,50,1.1);
        Inventaire *inv = new Inventaire;
        Arme *arm = new Arme;
    }

    // CONSTRUCTEUR PERSONNALISÉ
    Joueur::Joueur(const string &n, const unsigned int &vi, const unsigned int &f, const unsigned int &v, const unsigned int &e, const Inventaire &in, const Arme &ar)
    {
            // à finir
    }

    // DESTRUCTEUR
    Joueur::~Joueur()
    {
        nomJoueur = "";

        delete stat;
        delete inv;
        delete arm;
    }

// LES ACCESSEURS ET MUTATEURS

    // ACCESSEUR NOM
    const string &Joueur::getNom() const { return nomJoueur; }

    // MUTATEUR NOM
    void Joueur::setNom(const string& n) { nomJoueur = n; }

    void Joueur::setStat(const string &s, int valeur)
    {
        if(s == "vie")
        {
            stat->setVie(valeur);
        }
    }

// GESTION DU JOUEUR

    // CHOIX DE L'ACTION
    int Joueur::choixAction()
    {
        int i;

        cout<<"Que voulez-vous faire ?"<<endl;
        cout<<"1. Utiliser un Objet 2. Utiliser arme"<<endl;
        cin>>i;

        return i;
    }

    // OPERATEUR << POUR AFFICHER TOUTES LES STATS
    void Joueur::afficherJoueur()
    {
        // cout<<"******* STAT DU JOUEUR ******* "<<endl;
        // stat.afficherStats();

        cout<<"******* INVENTAIRE ******* "<<endl;
        inv->afficherInventaire();

        cout<<"******* ARME ******* "<<endl;
        arm->afficher();
    }

    int  Joueur::getVie()
    {
        return stat->getVie();
    }

    void Joueur::SetVie(int valeur)
    {
        stat->setVie(valeur);
    }

    void Joueur::GetAttaques()
    {
        arm->GetAttaques();
    }

    int Joueur::UtiliserAttaque(int i)
    {
        return arm->UtiliserAttaque(i);
    }

    void Joueur::afficherInventaire() const
    {
        inv->afficherInventaire();
    }

    int* Joueur::utiliserObjet(int choix)
    {
        return inv->utiliserObjet(choix);
    }
