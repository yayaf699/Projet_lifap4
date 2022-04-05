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
    int rechercherObjetInventaire(string nomObjet) ;

     // AJOUTER OBJET
     void ajouterObjet(const unsigned int indice, string nom, int bonusvie, int bonusvitesse, float bonusforce);


private:

    int taille_inventaire;
    Objet *inventaire;
};

#endif // INVENTAIRE_H_INCLUDED
