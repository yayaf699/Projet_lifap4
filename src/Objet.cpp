#include <iostream>
#include "Objet.h"

using namespace std;

// LES CONSTRUCTEURS 

    // CONSTRUCTEUR
    Objet::Objet()
    {
        nom = "emplacement vide";
        bonusVie = bonusVitesse = bonusForce = bonusEndurance = 0;
    }

    // CONSTRUCTEUR STRING
    Objet::Objet(const string &objet)
    {
        // recuperer les données d'un txt
    }

    // CONSTRUCTEUR PAR COPIE
    Objet::Objet(const Objet &o)
    {
        nom = o.nom;
        bonusVie = o.bonusVie;
        bonusVitesse = o.bonusVitesse;
        bonusForce = o.bonusForce;
        bonusEndurance = o.bonusEndurance;
    }

// LES ACCESEURS ET MUTATEURS

    // ACCESSEUR NOM OBJET
    const string &Objet::getNomObjet() const { return nom; }

    // ACCESSEUR BONUS DE VIE SUR L'OBJET
    const unsigned char &Objet::getVieObjet() const { return bonusVie; }

    // ACCESSEUR BONUS DE FORCE SUR L'OBJET
    const unsigned char &Objet::getForceObjet() const { return bonusForce; }

    // ACCESSEUR BONUS DE VITESSE SUR L'OBJET
    const unsigned char &Objet::getVitesseObjet() const { return bonusVitesse; }

    // ACCESSEUR BONUS DE ENDURANCE SUR L'OBJET
    const unsigned char &Objet::getEnduranceObjet() const { return bonusEndurance; }

    // MUTATEUR NOM OBJET
    void Objet::setNomObjet(const string &n) { nom = n; }

    // MUTATEUR BONUS DE VIE SUR L'OBJET
    void Objet::setVieObjet(const unsigned char &v) { bonusVie = v; }

    // MUTATEUR BONUS DE FORCE SUR L'OBJET
    void Objet::setForceObjet(const unsigned char &f) { bonusForce = f; }

    // MUTATEUR BONUS DE VITESSE SUR L'OBJET
    void Objet::setVitesseObjet(const unsigned char &vi) { bonusVitesse = vi; }

    // MUTATEUR BONUS DE ENDURANCE SUR L'OBJET
    void Objet::setEnduranceObjet(const unsigned char &e) { bonusEndurance = e; }
