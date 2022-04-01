#include <iostream>
#include <string>
#include "Inventaire.h"

using namespace std;

// CONSTRUCTEURS

    // CONSTRUCTEUR
    Inventaire::Inventaire()
    {
        taille_inventaire = 4;
        inventaire = new Objet[taille_inventaire];
        inventaire[0].setNomObjet("Pillule de sante");
        inventaire[0].setVieObjet(50);
        inventaire[1].setNomObjet("Pillule de vitesse");
        inventaire[1].setVitesseObjet(50);
        inventaire[2].setNomObjet("Pillule de force");
        inventaire[2].setForceObjet(0.2);
    }

    // DESTRUCTEUR
    Inventaire::~Inventaire()
    {
        taille_inventaire = 0;
        inventaire = NULL;
        delete inventaire;
    }



// GESTION DE L'INVENTAIRE

    const unsigned int Inventaire::getTailleInventaire(){ return taille_inventaire; }

    const string &Inventaire::getObjet(const unsigned int &n){ return inventaire[n].getNomObjet(); }

    // RETOURNE I-EME OBJET
    const Objet &Inventaire::retourneObjetInventaire(const unsigned int &i) const
    {
        return inventaire[i];
    }

    // AFFICHER INVENTAIRE
    void Inventaire::afficherInventaire() const
    {
        for(int i = 0; i < taille_inventaire; i++)
        {
                cout<<i+1<<". ";
                inventaire[i].afficherObjet();
                cout<<endl;
        }
    }

    // RECHERCHER OBJET
     unsigned int Inventaire::rechercherObjetInventaire(Objet o)
    {
        for( unsigned int i = 0; i < taille_inventaire; i++){
            if(inventaire[i].getNomObjet() == o.getNomObjet())
            {
                return i;
            }

        }
    }


    // JETER UN OBJET
    void Inventaire::retirerObjetInventaire(Objet &o)
    {
        inventaire[rechercherObjetInventaire(o)].setVieObjet(0);
        inventaire[rechercherObjetInventaire(o)].setVitesseObjet(0);
        inventaire[rechercherObjetInventaire(o)].setForceObjet(0.0);
        inventaire[rechercherObjetInventaire(o)].setNomObjet("emplacement vide");

    }



