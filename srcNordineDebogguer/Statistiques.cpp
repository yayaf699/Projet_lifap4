#include <iostream>
#include "Statistiques.h"

using namespace std;

// COSNTRUCTEURS ET DESTRUCTEURS

    // CONSTRUCTEUR
    Statistiques::Statistiques()
    {
        vie = 100;
        vitesse = 20;
        force = 1.1;
    }

    // CONSTRUCTEUR PAR COPIE
    Statistiques::Statistiques(const int &v, const int &vi, const float &f)
    {
        vie = v;
        vitesse = vi;
        force = f;
    }

// ACCESSEURS ET MUTATEURS

    // ACCESSEUR VIE
    const int &Statistiques::getVie() const
    {
        return vie;
    }


    // ACCESSEUR VITESSE
    const int &Statistiques::getVitesse() const { return vitesse; }

    // ACCESSEUR FORCE
    const float &Statistiques::getForce() const { return force; }

    // MUTATEUR VIE
    void Statistiques::setVie(const int &v) { vie = v;  }

    // MUTATEUR VITESSE
    void Statistiques::setVitesse(const int &vi) { vitesse = vi; }

    // MUTATEUR FORCE
    void Statistiques::setForce(const float &f) { force = f; }

// GESTION STATS

    void Statistiques::afficherStat()
    {
        cout<<"VIE: "<<vie<<endl;
        cout<<"VITESSE: "<<vitesse<<endl;
        cout<<"FORCE: "<<force<<endl;
    }
