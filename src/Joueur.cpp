#include <iostream>
#include "Joueur.h"

using namespace std;

// LES CONSTRUCTEURS ET DESTRUCTEUR

    // CONSTRUCTEUR PAR DEFAUT
    Joueur::Joueur()
    {
        nom = "Perso1";
        vie = 20; // 20/20
        vitesse = force = endurance = 10; // 10/20

        inv = new Inventaire;
    }

    // CONSTRUCTEUR PERSONNALISÉ
    Joueur::Joueur(const string &n, const unsigned char &vi, const unsigned char &f, const unsigned char &v, const unsigned char &e, const Inventaire &in)
    {
        nom = n;
        vie = vi;
        vitesse = v;
        force = f;
        endurance = e;

        // récuperer inventaire
    }

    // DESTRUCTEUR
    Joueur::~Joueur()
    {
        nom = " ";
        vie = vitesse = force = endurance = 0;

        delete inv;
    }

// LES ACCESSEURS ET MUTATEURS 

    // ACCESSEUR NOM
    const string &Joueur::getNom() const { return nom; }

    // ACCESSEUR VIE
    const unsigned char &Joueur::getVie() const { return vie; }

    // ACCESSEUR FORCE
    const unsigned char &Joueur::getForce() const { return force; }

    // ACCESSEUR VITESSE
    const unsigned char &Joueur::getVitesse() const { return vitesse; }

    // ACCESSEUR ENDURANCE
    const unsigned char &Joueur::getEndurance() const { return endurance; }

    // MUTATEUR NOM
    void Joueur::setNom(const string& n) { nom = n; }

    // MUTATEUR VIE
    void Joueur::setVie(const unsigned char &vi) { vie = vi; }

    // MUTATEUR FORCE
    void Joueur::setForce(const unsigned char &f) { force = f; }

    // MUTATEUR VITESSE
    void Joueur::setVitesse(const unsigned char &v) { vitesse = v; }

    // MUTATEUR ENDURANCE
    void Joueur::setEndurance(const unsigned char &e) { endurance = e; }

// GESTION DU JOUEUR 

    // REGARDER L'INVENTAIRE
    void Joueur::regarderInventaire() const
    {

    }

    // REGARDER UN OBJET ET SES STATS
    void Joueur::regarderObjet(const unsigned char &i) const
    {

    }

    // UTLISER UN OBJET
    void Joueur::utiliserObjet(const unsigned char &i)
    {

    }

    // REGARDER LES ATTAQUES
    void Joueur::regarderLesAttaques() const
    {

    }

    // REGARDER UNE ATTAQUE ET SES STATS
    void Joueur::regarderUneAttaque(const unsigned char &i) const
    {

    }

    // ATTAQUER
    void Joueur::utiliserAttaque(const unsigned char &i)
    {

    }

    // REGARDER SON ARME ET SES STAtS
    void Joueur::regarderArme() const
    {

    }

    // REGARDER SON ARMURE ET SES STATS
    void Joueur::regarderArmure() const
    {
        
    }