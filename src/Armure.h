#ifndef ARMURE_H_INCLUDED
#define ARMURE_H_INCLUDED
#include <string>

using namespace std;

class Armure
{

public:

// LES CONSTRUCTEURS ET DESTRUCTEUR

    // CONSTRUCTEUR PAR DEFAUT
    Armure();

    // CONSTRUCTEUR PERSONNALISÉ
    Armure(const string &n, const unsigned char &vi, const char &vit);


// LES ACCESSEURS ET MUTATEURS 

    // ACCESSEUR NOM
    const string &getNom() const;

    // ACCESSEUR BONUS VIE
    const unsigned char &getBonusVie() const;

    // ACCESSEUR MALUS VITESSE
    const char &getMalusVitesse() const;

    // MUTATEUR NOM
    void setNom(const string &n);

    // MUTATEUR BONUS VIE
    void setBonusVie(const unsigned char &vi);

    // MUTATEUR MALUS VITESSE
    void setMalusVitesse(const char &vit);

private:

    string nom;
    unsigned char bonusVie;
    char malusVitesse;

};

#endif // ARMURE_H_INCLUDED
