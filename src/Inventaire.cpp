#include <iostream>
#include <string>
#include <cassert>
#include "Inventaire.h"

using namespace std;

// CONSTRUCTEURS

    // CONSTRUCTEUR
    Inventaire::Inventaire()
    {
        taille_inventaire = 4;
        inventaire = new Objet[taille_inventaire];  
    }

    // DESTRUCTEUR
    Inventaire::~Inventaire()
    {
        taille_inventaire = NULL;
        delete inventaire;
    }


// GESTION DE L'INVENTAIRE 

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
        }
    }

    // JETER UN OBJET
    void Inventaire::retirerObjetInventaire(const unsigned int &i)
    {
        inventaire[i-1].setNomObjet("emplacement vide");
        inventaire[i-1].setVieObjet(0);
        inventaire[i-1].setVitesseObjet(0);
        inventaire[i-1].setForceObjet(0);
        inventaire[i-1].setEnduranceObjet(0);

    }

    // RECHERCHER OBJET
    const Objet &Inventaire::rechercherObjetInventaire(const string &nomObjet) const
    {
        // à finir
    }
