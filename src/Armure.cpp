#include "Armure.h"

using namespace std;

// LES CONSTRUCTEURS ET DESTRUCTEUR

    // CONSTRUCTEUR PAR DEFAUT
    Armure::Armure()
    {
        nom = "Armure basique";
        bonusVie = 5;
        malusVitesse = -5;
    }

    // CONSTRUCTEUR PERSONNALISÉ
    Armure::Armure(const string &n, const unsigned char &vi, const char &vit)
    {
        nom = n;
        bonusVie = vi;
        malusVitesse = vit;
    }


// LES ACCESSEURS ET MUTATEURS 

    // ACCESSEUR NOM
    const string &Armure::getNom() const { return nom; }

    // ACCESSEUR BONUS VIE
    const unsigned char &Armure::getBonusVie() const { return bonusVie; }

    // ACCESSEUR MALUS VITESSE
    const char &Armure::getMalusVitesse() const { return malusVitesse; }

    // MUTATEUR NOM
    void Armure::setNom(const string &n) { nom = n; }

    // MUTATEUR BONUS VIE
    void Armure::setBonusVie(const unsigned char &vi) { bonusVie = vi; }

    // MUTATEUR MALUS VITESSE
    void Armure::setMalusVitesse(const char &vit) { malusVitesse = vit; }
