#include <iostream>
#include "Arme.h"

using namespace std;

// LES CONSTRUCTEURS ET DESTRUCTEUR

    // CONSTRUCTEUR PAR DEFAUT
    Arme::Arme()
    {
        nom = "Épée basique";
        degats = vitesse = resistance = 1; // 1/20
    }

    // CONSTRUCTEUR PERSONNALISÉ
    Arme::Arme(const string &n, const unsigned char &deg, const unsigned char &vit, const unsigned char &res)
    {
        nom = n;
        degats = deg;
        vitesse = vit;
        resistance = res;
    }

// LES ACCESSEURS ET MUTATEURS 

    // ACCESSEUR NOM
    const string &Arme::getNom() const { return nom; }

    // ACCESSEUR DEGATS
    const unsigned char &Arme::getDegats() const { return degats; }

    // ACCESSEUR VITESSE
    const unsigned char &Arme::getVitesse() const { return vitesse; }

    // ACCESSEUR RESISTANCE
    const unsigned char &Arme::getResistance() const { return resistance; }

    // MUTATEUR NOM
    void Arme::setNom(const string& n) { nom = n; }

    // MUTATEUR DEGATS
    void Arme::setDegat(const unsigned char &deg) { degats = deg; }

    // MUTATEUR VITESSE
    void Arme::setVitesse(const unsigned char &vit) { vitesse = vit; }

    // MUTATEUR RESISTANCE
    void Arme::setResistance(const unsigned char &res) { resistance = res; }
