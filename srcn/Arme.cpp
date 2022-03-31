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
    Arme::Arme(const string &n, const int &nb, Attaque tab[])
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
        nomArme = "";
        nbAttaque = 0;


        if (tabAttaque != nullptr) delete tabAttaque;
        tabAttaque = NULL;
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

    void Arme::GetAttaques()
    {
        for (int i=0; i<4; i++)
        {
            cout<< i+1 << ": " << tabAttaque[i].getNomAttaque() << "\n";
        }

    }

    int Arme::UtiliserAttaque(int i)
    {
        tabAttaque[i].UtiliserAttaque();
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
            cout<<"NOMBRE MAX D'UTILISATION :"<<tabAttaque[i].getNombreMaxUtilisation()<<", ";

            /*if(tabAttaque.getTypeAttaque() == "strategique")
            {
                // affiche les stats supplementaires des attaques strategiques

            }
            cout<<endl;
            */
        }
    }

