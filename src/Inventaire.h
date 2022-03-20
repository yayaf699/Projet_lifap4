#ifndef INVENTAIRE_H_INCLUDED
#define INVENTAIRE_H_INCLUDED
#include <string>
#include "Objet.h"

using namespace std;


class Inventaire
{

public:

// CONSTRUCTEURS

    // CONSTRUCTEUR
    Inventaire();

    // CONSTRUCTEUR PAR COPIE
    Inventaire(const Inventaire &in);

// GESTION DE L'INVENTAIRE 

    // AFFICHER I-EME OBJET
    void afficherObjetInventaire(const unsigned char &i) const;

    // AFFICHER INVENTAIRE
    void afficherInventaire() const;

    // JETER UN OBJET
    void jeterObjetInventaire(const unsigned char &i);

private:

    const char &taille_inventaire = 4;
    Objet *inv;
    
};

#endif // INVENTAIRE_H_INCLUDED
