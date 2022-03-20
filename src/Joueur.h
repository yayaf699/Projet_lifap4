#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED
#include <string.h>
#include "Inventaire.h"

using namespace std;

class Joueur
{

public:

// LES CONSTRUCTEURS ET DESTRUCTEUR

    // CONSTRUCTEUR PAR DEFAUT
    Joueur();

    // CONSTRUCTEUR PERSONNALISÉ
    Joueur(const string &n, const unsigned char &vi, const unsigned char &f, const unsigned char &v, const unsigned char &e, const Inventaire &in);

    // DESTRUCTEUR
    ~Joueur();

// LES ACCESSEURS ET MUTATEURS 

    // ACCESSEUR NOM
    const string &getNom() const;

    // ACCESSEUR VIE
    const unsigned char &getVie() const;

    // ACCESSEUR FORCE
    const unsigned char &getForce() const;

    // ACCESSEUR VITESSE
    const unsigned char &getVitesse() const;

    // ACCESSEUR ENDURANCE
    const unsigned char &getEndurance() const;

    // MUTATEUR NOM
    void setNom(const string& n);

    // MUTATEUR VIE
    void setVie(const unsigned char &vi);

    // MUTATEUR FORCE
    void setForce(const unsigned char &f);

    // MUTATEUR VITESSE
    void setVitesse(const unsigned char &v);

    // MUTATEUR ENDURANCE
    void setEndurance(const unsigned char &e);

// GESTION DU JOUEUR 

    // REGARDER L'INVENTAIRE
    void regarderInventaire() const;

    // REGARDER UN OBJET ET SES STATS
    void regarderObjet(const unsigned char &i) const;

    // UTLISER UN OBJET
    void utiliserObjet(const unsigned char &i);

    // REGARDER LES ATTAQUES
    void regarderLesAttaques() const;

    // REGARDER UNE ATTAQUE ET SES STATS
    void regarderUneAttaque(const unsigned char &i) const;

    // ATTAQUER
    void utiliserAttaque(const unsigned char &i);

    // REGARDER SON ARME ET SES STAtS
    void regarderArme() const;

    // REGARDER SON ARMURE ET SES STATS
    void regarderArmure() const;

private:

    string nom;
    unsigned char vie, force, vitesse, endurance;
    
    Inventaire *inv; // l'inventaire d'objets du joueur 

};

#endif // JOUEUR_H_INCLUDED
