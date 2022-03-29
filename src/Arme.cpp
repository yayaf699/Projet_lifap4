#include "Arme.h"
#include <iostream>

using namespace std;


// LES CONSTRUCTEURS ET DESTRUCTEURS

    // CONSTRUCTEUR
    Arme::Arme()
    {
        nomArme = "mains";
        nbAttaque = 4;
        tabAttaque = new Attaque[nbAttaque];
    }

    // CONSTRUCTEUR PAR COPIE
    Arme::Arme(const string &n, const int &nb, const Attaque &tab)
    {
        nomArme = n;
        nbAttaque = nb;

        for(int i = 0; i < nbAttaque; i++)
        {
            tabAttaque[i] = tab[i];
        }
    }

    // DESTRUCTEUR
    Arme::~Arme()
    {
        nonArme = "";
        nbAttaque = 0;

        for(int i = 0; i < nbAttaque; i++)
        {
            tabAttaque[i] = 0;
        }

        delete tabAttaque;
        tabAttaque = ptrnull; 
    }

// ACCESSEURS ET MUTATEURS

    // ACCESSEUR NOM
    const string &Arme::getNomArme() const
    {
        return nomArme;
    }

    // MUTATEUR NOM
    void Arme::setNomArme(const string &n)
    {
        nomArme = n;
    }

// GESTION ARME

    // AFFICHER LES ATTAQUES
    void Arme::afficher() const
    {
        cout<<"NOM: "<<nomArme<<endl;
        for(int i = 0; i < nbAttaque; i++)
        {  
            cout<<i+1<<". ";
            cout<<"DEGATS :"<<tabAttaque[i].getDegats()<<", ";
            cout<<"TYPE D'ATTAQUE :"<<tabAttaque[i].getTypeAttaque()<<", ";
            cout<<"NOMBRE MAX D'UTILISATION :"<<tabAttaque[i].getNombreMaxUtilisation())<<", "; 

            if(typeAttaque == "Attaque strategique")
            {
                // affiche les stats supplementaires des attaques strategiques
                
            } 
            cout<<endl;
        }
    }

    // CHOIX DE L'ATTAQUE
    const unsigned int &Arme::choixAttaque()
    {
        int i;
        afficherAttaques();
        cout<<"Quelle attaque voulez vous choisir ?"<<endl; 
        cin>>i;

        return i-1;
    }

