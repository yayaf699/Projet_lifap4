#ifndef OBJET_H_INCLUDED
#define OBJET_H_INCLUDED
#include <string>

using namespace std;


class Objet
{
    
public:

// LES CONSTRUCTEURS 

    // CONSTRUCTEUR
    Objet();

    // CONSTRUCTEUR STRING
    Objet(const string &objet);

    // CONSTRUCTEUR PAR COPIE
    Objet(const Objet &o);

// LES ACCESEURS ET MUTATEURS

    // ACCESSEUR NOM OBJET
    const string &getNomObjet() const;

    // ACCESSEUR BONUS DE VIE SUR L'OBJET
    const unsigned char &getVieObjet() const;

    // ACCESSEUR BONUS DE FORCE SUR L'OBJET
    const unsigned char &getForceObjet() const;

    // ACCESSEUR BONUS DE VITESSE SUR L'OBJET
    const unsigned char &getVitesseObjet() const;

    // ACCESSEUR BONUS DE ENDURANCE SUR L'OBJET
    const unsigned char &getEnduranceObjet() const;

    // MUTATEUR NOM OBJET
    void setNomObjet(const string &n);

    // MUTATEUR BONUS DE VIE SUR L'OBJET
    void setVieObjet(const unsigned char &v);

    // MUTATEUR BONUS DE FORCE SUR L'OBJET
    void setForceObjet(const unsigned char &f);

    // MUTATEUR BONUS DE VITESSE SUR L'OBJET
    void setVitesseObjet(const unsigned char &vi);

    // MUTATEUR BONUS DE ENDURANCE SUR L'OBJET
    void setEnduranceObjet(const unsigned char &e);

private:

    string nom; // nom de l'objet
    unsigned char bonusVie, bonusForce, bonusVitesse, bonusEndurance;

};



#endif // OBJET_H_INCLUDED
