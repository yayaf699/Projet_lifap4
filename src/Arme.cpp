#include "Arme.h"
#include <iostream>

using namespace std;


// LES CONSTRUCTEURS ET DESTRUCTEURS

    // CONSTRUCTEUR
    Arme::Arme()
    {
        nbAttaque = 4;
        tabAttaque = new Attaque[nbAttaque];
    }

    // DESTRUCTEUR
    Arme::~Arme()
    {
        nbAttaque = 0;
        tabAttaque = NULL;

        delete [] tabAttaque;
    }

// ACCESSEURS ET MUTATEURS

    // ACCESSEUR NOMBRE D'ATTAQUE
    int Arme::getNbAttaque() { return nbAttaque; }

    // ACCESSEUR ATTAQUE
    string Arme::getNomAttaque(int i) { return tabAttaque[i].getNomAttaque(); }

    // MUTATEUR ATTAQUE
    void Arme::setNomAttaque(const unsigned int &i, const string &n) { tabAttaque[i].setNomAttaque(n); }

// GESTION ARME

    // AJOUTER ATTAQUE
    void Arme::ajouterAttaque(int indice, string nomAttaque, int degats, int degatsSpeciaux, string typeDegats, string typeAttaque, string descAttaque, int nombreMaxUtilisation, int etatNombreTour)
    {
        tabAttaque[indice].setNomAttaque(nomAttaque);
        tabAttaque[indice].setDegats(degats);
        tabAttaque[indice].setDegatSp(degatsSpeciaux);
        tabAttaque[indice].setTypeDegats(typeDegats);
        tabAttaque[indice].setTypeAttaque(typeAttaque);
        tabAttaque[indice].setDescAttaque(descAttaque);
        tabAttaque[indice].setNombreMaxUtilisation(nombreMaxUtilisation);
        tabAttaque[indice].setEtatNombreTour(etatNombreTour);
    }


    // RETOURNE I-EME ATTAQUE
    Attaque Arme::retourneAttaqueArme(const unsigned int &i)
    {
        return tabAttaque[i];
    }

    // AFFICHER LES STATS DE TOUTES LES ATTAQUES
    void Arme::afficherStat()
    {
        for(int i = 0; i < nbAttaque; i++)
        {
            cout<<i+1<<". "<<endl;
            cout<<"NOM D'ATTAQUE : "<<tabAttaque[i].getNomAttaque()<<endl;
            cout<<"DEGATS :"<<tabAttaque[i].getDegats()<<endl;
            cout<<"DEGATS SPECIAUX :"<<tabAttaque[i].getDegatSp()<<endl;
            cout<<"TYPE DE DEGATS :"<<tabAttaque[i].getTypeDegats()<<endl;
            cout<<"TYPE DE L'ATTAQUE :"<<tabAttaque[i].getTypeAttaque()<<endl;
            cout<<"DESCRIPTION D'ATTAQUE :"<<tabAttaque[i].getDescAttaque()<<endl;
            cout<<"NOMBRE MAX D'UTILISATION :"<<tabAttaque[i].getNombreMaxUtilisation()<<endl;
            cout<<"ETAT NOMBRE DE TOURS :"<<tabAttaque[i].getEtatNombreTour()<<endl;
        }
    }

    // L'UTILISATION DE L'ATTAQUE
    Attaque Arme::utiliserAttaque(int i)
    {
        tabAttaque[i].setNombreMaxUtilisation(tabAttaque[i].getNombreMaxUtilisation()-1);
        return retourneAttaqueArme(i);
    }
