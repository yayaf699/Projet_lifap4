#include <iostream>
#include "Objet.h"

using namespace std;

// LES CONSTRUCTEURS

    // CONSTRUCTEUR
    Objet::Objet()
    {
        nom = "emplacement vide";
        bonusVie = bonusVitesse = bonusForce = 0;
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
    }

// LES ACCESEURS ET MUTATEURS

    // ACCESSEUR NOM OBJET
    const string &Objet::getNomObjet() const { return nom; }

    // ACCESSEUR BONUS DE VIE SUR L'OBJET
    const unsigned int &Objet::getVieObjet() const { return bonusVie; }

    // ACCESSEUR BONUS DE FORCE SUR L'OBJET
    const float &Objet::getForceObjet() const { return bonusForce; }

    // ACCESSEUR BONUS DE VITESSE SUR L'OBJET
    const unsigned int &Objet::getVitesseObjet() const { return bonusVitesse; }

    // MUTATEUR NOM OBJET
    void Objet::setNomObjet(const string &n) { nom = n; }

    // MUTATEUR BONUS DE VIE SUR L'OBJET
    void Objet::setVieObjet(const unsigned int &v) { bonusVie = v; }

    // MUTATEUR BONUS DE FORCE SUR L'OBJET
    void Objet::setForceObjet(const  float &f) { bonusForce = f; }

    // MUTATEUR BONUS DE VITESSE SUR L'OBJET
    void Objet::setVitesseObjet(const unsigned int &vi) { bonusVitesse = vi; }


// GESTION DE L'OBJET

    // L'AFFICHER L'OBJET
    void Objet::afficherObjet()
    {
        if(nom != "emplacement vide"){
            cout<<nom<<" => ";
            cout<<"Bonus vie: +"<<getVieObjet()<<", ";
            cout<<"Bonus vitesse: +"<<getVitesseObjet()<<", ";
            cout<<"Bonus force: +"<<getForceObjet()<<"\n";
        }
        else cout << "emplacement vide";
    }


