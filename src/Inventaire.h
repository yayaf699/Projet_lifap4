#ifndef INVENTAIRE_H_INCLUDED
#define INVENTAIRE_H_INCLUDED
#include "Objet.h"

using namespace std;


class Inventaire
{
public:

// CONSTRUCTEUR ET DESTRUCTEUR

    // CONSTRUCTEUR
    Inventaire();

    // DESTRUCTEUR
    ~Inventaire();


// GESTION DE L'INVENTAIRE 

    // RETOURNE I-EME OBJET
    const Objet &retourneObjetInventaire(const unsigned int &i) const;

    // AFFICHER INVENTAIRE
    void afficherInventaire() const;

    // JETER UN OBJET
    void retirerObjetInventaire(const unsigned int &i);

    // RECHERCHER OBJET
    const Objet &rechercherObjetInventaire(const string &nomObjet) const; 

private:

    int taille_inventaire;
    Objet *inventaire; 
};

#endif // INVENTAIRE_H_INCLUDED
