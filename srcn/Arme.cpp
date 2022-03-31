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
        tabAttaque[0].setDegats(15);
        tabAttaque[0].setNomAttaque("Pistolet");
        tabAttaque[1].setDegats(40);
        tabAttaque[1].setNomAttaque("Uppercut");
        tabAttaque[1].setNombreMaxUtilisation(10);
        tabAttaque[1].setTypeAttaque("Puissante");
        tabAttaque[2].setDegats(0);
        tabAttaque[2].setNomAttaque("Fumigene");
        tabAttaque[2].setTypeAttaque("Strategique");
        tabAttaque[2].setNombreMaxUtilisation(3);
        tabAttaque[3].setDegats(0);
        tabAttaque[3].setNomAttaque("Invincibilite");
        tabAttaque[3].setTypeAttaque("Strategique");
        tabAttaque[3].setNombreMaxUtilisation(1);
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

    if (tabAttaque != NULL) delete [] tabAttaque;
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

    void Arme::affAttaques()
    {
        for (int i=0; i<4; i++)
        {
            cout<< i+1 << ": " << tabAttaque[i].getNomAttaque() << "\n";
        }

    }


// GESTION ARME

    // AFFICHER LES ATTAQUES
    void Arme::afficher() const
    {
        cout<<"NOM DE L'ARME: "<<nomArme<<"\n"<<endl;
        for(int i = 0; i < nbAttaque; i++)
        {
            cout<<i+1<<". "<<endl;
            cout<<"NOM D'ATTAQUE : "<<tabAttaque[i].getNomAttaque()<<endl;
            cout<<"DEGATS :"<<tabAttaque[i].getDegats()<<endl;
            cout<<"TYPE D'ATTAQUE :"<<tabAttaque[i].getTypeAttaque()<<endl;
            cout<<"NOMBRE MAX D'UTILISATION :"<<tabAttaque[i].getNombreMaxUtilisation()<<"\n "<<endl;

            /*if(tabAttaque.getTypeAttaque() == "strategique")
            {
                // affiche les stats supplementaires des attaques strategiques

            }
            cout<<endl;
            */
        }
    }

    const unsigned int &Arme::utiliserAttaque(const unsigned int &i){
        return -tabAttaque[i].getDegats();
    }

