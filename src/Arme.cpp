#include "Arme.h"
#include <iostream>

using namespace std;


// LES CONSTRUCTEURS ET DESTRUCTEURS

    // CONSTRUCTEUR
    Arme::Arme()
    {
        nomArme = "Nordin equipement";
        nbAttaque = 4;
        tabAttaque = new Attaque[nbAttaque];
        tabAttaque[0].setDegats(15);
        tabAttaque[0].setNomAttaque("Pistolet");
        tabAttaque[0].setDescAttaque("Tir de pistolet, forte chance d'infliger saignement a l'adversaire");
        tabAttaque[0].setTypeDegats("saignement");
        tabAttaque[1].setDegats(40);
        tabAttaque[1].setNomAttaque("Uppercut");
        tabAttaque[1].setNombreMaxUtilisation(3);
        tabAttaque[1].setTypeDegats("Puissante");
        tabAttaque[1].setDescAttaque("Coup de poings dans le menton");
        tabAttaque[2].setDegats(0);
        tabAttaque[2].setNomAttaque("Ice Grenade");
        tabAttaque[2].setTypeDegats("gele");
        tabAttaque[2].setNombreMaxUtilisation(1);
        tabAttaque[2].setDescAttaque("Jete une grenade de glace, forte chance de geler l'adversaire");
        tabAttaque[3].setDegats(0);
        tabAttaque[3].setNomAttaque("Invincibilite");
        tabAttaque[3].setTypeDegats("invincible");
        tabAttaque[3].setNombreMaxUtilisation(1);
        tabAttaque[3].setDescAttaque("Active son bouclier pour ne subir aucun degats pendant 2 tours");
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

        tabAttaque = NULL;
        delete [] tabAttaque;
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
            cout<<"TYPE DE L'ATTAQUE :"<<tabAttaque[i].getDescAttaque()<<endl;
            cout<<"NOMBRE MAX D'UTILISATION :"<<tabAttaque[i].getNombreMaxUtilisation()<<"\n "<<endl;

            /*if(tabAttaque.getTypeAttaque() == "strategique")
            {
                // affiche les stats supplementaires des attaques strategiques

            }
            cout<<endl;
            */
        }
    }

    Attaque Arme::utiliserAttaque(int i){
        tabAttaque[i].setNombreMaxUtilisation(tabAttaque[i].getNombreMaxUtilisation()-1);
        return getAtk(i);
    }

     Attaque Arme::getAtk(int i)
    {
        return tabAttaque[i];
    }

    void Arme::ajouterAttaque(const unsigned int indice, string nom, int degats_, int nombreMaxUtilisation_)
    {
        tabAttaque[indice].setNomAttaque(nom);
        tabAttaque[indice].setDegats(degats_);
        tabAttaque[indice].setNombreMaxUtilisation(nombreMaxUtilisation_);
    }


