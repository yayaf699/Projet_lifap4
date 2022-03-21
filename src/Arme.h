#ifndef ARME_H_INCLUDED
#define ARME_H_INCLUDED
#include <string>

using namespace std;

class Arme
{

public:

// LES CONSTRUCTEURS ET DESTRUCTEUR

    // CONSTRUCTEUR PAR DEFAUT
    Arme();

    // CONSTRUCTEUR PERSONNALISÉ
    Arme(const string &n, const unsigned char &deg, const unsigned char &vit, const unsigned char &res);


// LES ACCESSEURS ET MUTATEURS 

    // ACCESSEUR NOM
    const string &getNom() const;

    // ACCESSEUR DEGATS
    const unsigned char &getDegats() const;

    // ACCESSEUR VITESSE
    const unsigned char &getVitesse() const;

    // ACCESSEUR RESISTANCE
    const unsigned char &getResistance() const;

    // MUTATEUR NOM
    void setNom(const string& n);

    // MUTATEUR DEGATS
    void setDegat(const unsigned char &deg);

    // MUTATEUR VITESSE
    void setVitesse(const unsigned char &vit);

    // MUTATEUR RESISTANCE
    void setResistance(const unsigned char &deg);

private:

    string nom;
    unsigned char degats, vitesse, resistance; 
    

};

#endif // ARME_H_INCLUDED
