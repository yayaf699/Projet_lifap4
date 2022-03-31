#ifndef OBJET_H_INCLUDED
#define OBJET_H_INCLUDED
#include <string>
//#include "data/Objet.txt"

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
    const unsigned int &getVieObjet() const;

    // ACCESSEUR BONUS DE FORCE SUR L'OBJET
    const unsigned int &getForceObjet() const;

    // ACCESSEUR BONUS DE VITESSE SUR L'OBJET
    const unsigned int &getVitesseObjet() const;

    // ACCESSEUR BONUS DE ENDURANCE SUR L'OBJET
    const unsigned int &getEnduranceObjet() const;

    // MUTATEUR NOM OBJET
    void setNomObjet(const string &n);

    // MUTATEUR BONUS DE VIE SUR L'OBJET
    void setVieObjet(const unsigned int &v);

    // MUTATEUR BONUS DE FORCE SUR L'OBJET
    void setForceObjet(const unsigned int &f);

    // MUTATEUR BONUS DE VITESSE SUR L'OBJET
    void setVitesseObjet(const unsigned int &vi);

    // MUTATEUR BONUS DE ENDURANCE SUR L'OBJET
    void setEnduranceObjet(const unsigned int &e);

// GESTION DE L'OBJET

    // L'AFFICHER L'OBJET
    void afficherObjet();

    // UTILISER L'OBJET
    void utiliserObjet();

private:

    string nom; // nom de l'objet
    unsigned int bonusVie, bonusForce, bonusVitesse;
};



#endif // OBJET_H_INCLUDED
