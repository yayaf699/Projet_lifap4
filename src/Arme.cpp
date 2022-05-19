#include "Arme.h"
#include <iostream>

using namespace std;


// LES CONSTRUCTEURS ET DESTRUCTEURS

    // constructeur
    Arme::Arme()
    {
        nbAttaque = 4;
        tabAttaque = new Attaque[nbAttaque];
    }

    // destructeur
    Arme::~Arme()
    {
        nbAttaque = 0;
        tabAttaque = NULL;

        delete [] tabAttaque;
    }

// LES ACCESSEURS 

    // accesseur nbAttaque
    int Arme::getNbAttaque() { return nbAttaque; }

    // accesseur tabAttaque
    Attaque Arme::getTabAttaque(int i) { return tabAttaque[i]; }

// LES MUTATEURS

    // mutateur nbAttaque
    void Arme::setNbAttaque(int nb) { nbAttaque = nb; }

// GESTION ARME

    // ajouter une attaque
    void Arme::ajouterAttaque(int indice, 
                            string nomAttaque, 
                            int degats, 
                            int degatsSpeciaux, 
                            string typeDegats, 
                            string typeAttaque, 
                            string descAttaque, 
                            int nombreMaxUtilisation, 
                            int etatNombreTour)
    {
        tabAttaque[indice].setNomAttaque(nomAttaque);
        tabAttaque[indice].setDegats(degats);
        tabAttaque[indice].setDegatSp(degatsSpeciaux);
        tabAttaque[indice].setTypeDegats(typeDegats);
        tabAttaque[indice].setTypeAttaque(typeAttaque);
        tabAttaque[indice].setDescAttaque(descAttaque);
        tabAttaque[indice].setNombreMaxUtilisation(nombreMaxUtilisation);
        tabAttaque[indice].setNombreUtilisationReste(nombreMaxUtilisation);
        tabAttaque[indice].setEtatNombreTour(etatNombreTour);
    }

    // afficher les stats de toutes les attaques
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
            cout<<"NOMBRE D'UTILISATION :"<<tabAttaque[i].getNombreUtilisationReste()<<endl;
            cout<<"ETAT NOMBRE DE TOURS :"<<tabAttaque[i].getEtatNombreTour()<<endl;
        }
    }

    // MajNombreUtilisation
    void Arme::MajNombreUtilisation(int i)
    {
        tabAttaque[i].setNombreUtilisationReste(tabAttaque[i].getNombreUtilisationReste()-1);
    }
