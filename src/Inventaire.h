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

    // ACCESSEUR TAILLE INVENTAIRE
    const unsigned int getTailleInventaire();

    const string &getObjet(const unsigned int &n);

    // RETOURNE I-EME OBJET
    const Objet &retourneObjetInventaire(const unsigned int &i) const;

    // AFFICHER INVENTAIRE
    void afficherInventaire() const;

    // JETER UN OBJET
    void retirerObjetInventaire(Objet &o);

    // RECHERCHER OBJET
     unsigned int rechercherObjetInventaire(Objet o) ;


private:

    int taille_inventaire;
    Objet *inventaire;
};

#endif // INVENTAIRE_H_INCLUDED
