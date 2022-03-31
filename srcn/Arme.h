#ifndef ARME_H_INCLUDED
#define ARME_H_INCLUDED
#include <string>
#include "Attaque.h"


using namespace std;


class Arme
{
public:

// LES CONSTRUCTEURS ET DESTRUCTEURS

    // CONSTRUCTEUR
    Arme();

    // CONSTRUCTEUR PAR COPIE
    Arme(const string &n, const int &nb, Attaque tab[]);

    // DESTRUCTEUR
    ~Arme();

// ACCESSEURS ET MUTATEURS

    // ACCESSEUR NOM
    const string &getNomArme() const;

    // ACCESSEUR ATTAQUE
    const unsigned int &utiliserAttaque(const unsigned int &i);

    // MUTATEUR NOM
    void setNomArme(const string &n);

    void affAttaques();


// GESTION ARME

    // CHOIX DE L'ATTAQUE
    const unsigned int &choixAttaque();

    // AFFICHER LES STATS DE L'ARME
    void afficher() const;


private:

    string nomArme;
    int nbAttaque;
    Attaque *tabAttaque;
};



#endif // ARME_H_INCLUDED