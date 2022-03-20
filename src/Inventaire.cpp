#include <iostream>
#include <string>
#include <cassert>
#include "Inventaire.h"

using namespace std;

// CONSTRUCTEURS

    // CONSTRUCTEUR
    Inventaire::Inventaire()
    {
        inv = new Objet[taille_inventaire];  
    }

    // CONSTRUCTEUR PAR COPIE
    Inventaire::Inventaire(const Inventaire &in)
    {
        inv = new Objet[in.taille_inventaire];
        for(unsigned char i = 0; i < taille_inventaire; i++)
        {
            inv[i].setNomObjet(in.inv[i].getNomObjet());
            inv[i].setVieObjet(in.inv[i].getVieObjet());
            inv[i].setForceObjet(in.inv[i].getForceObjet());
            inv[i].setVitesseObjet(in.inv[i].getVitesseObjet());
            inv[i].setEnduranceObjet(in.inv[i].getEnduranceObjet());

        } 
    }

// GESTION DE L'INVENTAIRE 

    // AFFICHER I-EME OBJET
    void Inventaire::afficherObjetInventaire(const unsigned char &i) const
    {
        assert(i > 0);
        assert(i < taille_inventaire);

        cout<<inv[i].getNomObjet()<<" ";
        cout<<"Bonus vie: +"<<inv[i].getVieObjet()<<" ";
        cout<<"Bonus vitesse: +"<<inv[i].getVitesseObjet()<<" ";
        cout<<"Bonus force: +"<<inv[i].getForceObjet()<<" ";
        cout<<"Bonus endurance: +"<<inv[i].getEnduranceObjet()<<" ";  
    }

    // AFFICHER INVENTAIRE
    void Inventaire::afficherInventaire() const
    {
        for(int i = 0; i < taille_inventaire; i++)
        {
            if(inv[i].getNomObjet() == "emplacement vide")
            {
                cout<<inv[i].getNomObjet()<<endl;
            }
            else
            {
                cout<<i+1<<". ";
                afficherObjetInventaire(i);
                cout<<endl;
            }
        }
    }

    // JETER UN OBJET
    void Inventaire::jeterObjetInventaire(const unsigned char &i)
    {
       assert(i > 0);
        assert(i < taille_inventaire);

        if(i != taille_inventaire-1)
        {
            for(int j = i; j < taille_inventaire-1; j++)
            {
                inv[j].setNomObjet(inv[j+1].getNomObjet());
                inv[j].setVieObjet(inv[j+1].getVieObjet());
                inv[j].setVitesseObjet(inv[j+1].getVitesseObjet());
                inv[j].setForceObjet(inv[j+1].getForceObjet());
                inv[j].setEnduranceObjet(inv[j+1].getEnduranceObjet());

            }
        }
        
        inv[taille_inventaire-1].setNomObjet("emplacement vide");
        inv[taille_inventaire-1].setVieObjet(0);
        inv[taille_inventaire-1].setVitesseObjet(0);
        inv[taille_inventaire-1].setForceObjet(0);
        inv[taille_inventaire-1].setEnduranceObjet(0);
    }

