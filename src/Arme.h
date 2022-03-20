#ifndef ARME_H_INCLUDED
#define ARME_H_INCLUDED
#include <string.h>

using namespace std;

class Joueur
{

public:

// LES CONSTRUCTEURS ET DESTRUCTEUR

    // CONSTRUCTEUR PAR DEFAUT
    Arme();

    // CONSTRUCTEUR PERSONNALISÉ
    Arme(const string &n, const unsigned char &deg);

    // DESTRUCTEUR
    ~Arme();

// LES ACCESSEURS ET MUTATEURS 

    // ACCESSEUR NOM
    const string &getNom() const;

    // ACCESSEUR DEGATS
    const unsigned char &getDegats() const;

    // ACCESSEUR RESISTANCE
    const unsigned char &getResistance() const;

    // MUTATEUR NOM
    void setNom(const string& n);

    // MUTATEUR DEGATS
    void setDegat(const unsigned char &deg);

    // MUTATEUR RESISTANCE
    void setDegat(const unsigned char &deg);


// GESTION DE L'ARME

    // CHANGEMENT D'ETAT DE L'ARME
    void changementEtat();

private:

    string nom;
    unsigned char degats, vitesse, resistance; 
    

};

#endif // ARME_H_INCLUDED
