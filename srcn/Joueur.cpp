#include "Joueur.h"
#include <iostream>
#include <string.h>
using namespace std;


// LES CONSTRUCTEURS ET DESTRUCTEUR

void Joueur::operator=(Joueur j){
        stat = j.stat;
        inv = j.inv;
        arm = j.arm;
    }

    // CONSTRUCTEUR PAR DEFAUT
    Joueur::Joueur()
    {
        nomJoueur = "Monkey D. Nordin";


        // stat.afficherStat();
        // cout << arm.getNomArme() << endl;
        // arm.GetAttaques();


    }

    // CONSTRUCTEUR PERSONNALISÉ
    Joueur::Joueur(const string &n, const unsigned int &vi, const unsigned int &f, const unsigned int &v, const unsigned int &e, Inventaire in, const Arme &ar)
    {
            // à finir
    }


// LES ACCESSEURS ET MUTATEURS

    // ACCESSEUR NOM
    const string &Joueur::getNom() const { return nomJoueur; }

    // MUTATEUR NOM
    void Joueur::setNom(const string& n) { nomJoueur = n; }

    void Joueur::setStat(const string &s, int valeur)
    {   int v;
        if(s =="vie") v = 1;
        if(s == "force") v = 2;
        if(s == "vitesse") v = 3;

        switch(v){
            case 1:
            stat.setVie(stat.getVie() + valeur);
            break;

            case 2:
            stat.setForce(stat.getForce() + valeur);
            break;

            case 3:
            stat.setVitesse(stat.getVitesse() + valeur);
            break;

            default:
            break;

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
        inv.afficherInventaire();

        cout<<"******* ARME ******* "<<endl;
        arm.afficher();
    }

    int  Joueur::getVie()
    {
        return stat.getVie();
    }

    void Joueur::SetVie(int valeur)
    {
        stat.setVie(valeur);
    }

    Inventaire Joueur::getInv(){
        return inv;
    }

    Arme Joueur::getArme()
    {
        return arm;
    }

    int Joueur::UtiliserAttaque(int i)
    {
        return arm.UtiliserAttaque(i);
    }

    void Joueur::afficherInventaire() const
    {
        inv.afficherInventaire();
    }

    // UTILISER L'OBJET
    void Joueur::utiliserObjet(Objet o)
    {
        setStat("vie", o.getVieObjet());
        setStat("force", o.getForceObjet());
        setStat("vitesse", o.getVitesseObjet());
        inv.retirerObjetInventaire(o);
    }