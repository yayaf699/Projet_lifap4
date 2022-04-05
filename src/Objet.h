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
    Objet(const string &nomObjet);

    // CONSTRUCTEUR PAR COPIE
    Objet(const Objet &o);

// LES ACCESEURS ET MUTATEURS

    // ACCESSEUR NOM OBJET
    const string &getNomObjet() const;

    // ACCESSEUR BONUS DE VIE SUR L'OBJET
    const unsigned int &getVieObjet() const;

    // ACCESSEUR BONUS DE FORCE SUR L'OBJET
    const float &getForceObjet() const;

    // ACCESSEUR BONUS DE VITESSE SUR L'OBJET
    const unsigned int &getVitesseObjet() const;


    // MUTATEUR NOM OBJET
    void setNomObjet(const string &n);

    // MUTATEUR BONUS DE VIE SUR L'OBJET
    void setVieObjet(const unsigned int &v);

    // MUTATEUR BONUS DE FORCE SUR L'OBJET
    void setForceObjet(const  float &f);

    // MUTATEUR BONUS DE VITESSE SUR L'OBJET
    void setVitesseObjet(const unsigned int &vi);


// GESTION DE L'OBJET

    // L'AFFICHER L'OBJET
    void afficherObjet();


private:

    string nom; // nom de l'objet
    unsigned int bonusVie, bonusVitesse;
    float bonusForce;
};



#endif // OBJET_H_INCLUDED
