#include <iostream>
#include <string>
#include "Inventaire.h"

using namespace std;

// CONSTRUCTEURS

    // constructeur
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
        inventaire[3].setNomObjet("Soda");
    }

    // destructeur
    Inventaire::~Inventaire()
    {
        taille_inventaire = 0;
        inventaire = NULL;
        delete inventaire;
    }

// ACCESSEURS

    // accesseur TailleInventaire
    const unsigned int Inventaire::getTailleInventaire(){ return taille_inventaire; }

    // accesseur i-eme objet dans l'inventaire
    Objet Inventaire::getInventaire(const unsigned int &i){ return inventaire[i]; }

// GESTION DE L'INVENTAIRE

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
    int Inventaire::rechercherObjetInventaire(string nomObjet)
    {
        for(int i = 0; i < taille_inventaire; i++)
        {
            if(inventaire[i].getNomObjet() == nomObjet)
            {
                return i;
            }
        }
        return -1;
    }


    // JETER UN OBJET
    void Inventaire::retirerObjetInventaire(Objet &o)
    {
        if(rechercherObjetInventaire(o.getNomObjet()) < taille_inventaire-1) // si objet enlevé au milieu ou au debut du tableau
        {
            for(int i = rechercherObjetInventaire(o.getNomObjet()); i < taille_inventaire; i++)
            {
                inventaire[i-1]  = inventaire[i];
            }
        }

        inventaire[taille_inventaire-1].setVieObjet(-1);
        inventaire[taille_inventaire-1].setVitesseObjet(-1);
        inventaire[taille_inventaire-1].setForceObjet(-1);
        inventaire[taille_inventaire-1].setNomObjet("emplacement vide");
    }

  void Inventaire::ajouterObjet(const unsigned int indice, string nom, int bonusvie, int bonusvitesse, float bonusforce)
  {
       inventaire[indice].setNomObjet(nom);
       inventaire[indice].setForceObjet(bonusforce);
       inventaire[indice].setVieObjet(bonusvie);
       inventaire[indice].setVitesseObjet(bonusvitesse);
  }

