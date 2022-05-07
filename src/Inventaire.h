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

// ACCESSEURS ET MUTATEURS

    // ACCESSEUR TAILLE INVENTAIRE
    const unsigned int getTailleInventaire();

    // ACCESSEUR NOM OBJET
    const string &getNomObjetInv(const unsigned int &i);

    // ACCESSEUR NOM OBJET
    void setNomObjetInv(const unsigned int &i, const string &n);


// GESTION DE L'INVENTAIRE

    // RETOURNE I-EME OBJET
    Objet retourneObjetInventaire(const unsigned int &i);

    // AFFICHER INVENTAIRE
    void afficherInventaire() const;

    // JETER UN OBJET
    void retirerObjetInventaire(Objet &o);

    // RECHERCHER OBJET
    int rechercherObjetInventaire(string nomObjet) ;

    // AJOUTER OBJET
    void ajouterObjet(const unsigned int indice, string nom, int bonusvie, int bonusvitesse, float bonusforce);


private:

    int taille_inventaire;
    Objet *inventaire;
};

#endif // INVENTAIRE_H_INCLUDED
