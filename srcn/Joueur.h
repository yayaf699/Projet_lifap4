#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED
#include <string>
#include "Arme.h"
#include "Statistiques.h"
#include "Inventaire.h"
#include "Objet.h"
#include "Attaque.h"

using namespace std;

class Joueur{
public:

// LES CONSTRUCTEURS ET DESTRUCTEUR

    // CONSTRUCTEUR PAR DEFAUT
    Joueur();

    // CONSTRUCTEUR PERSONNALISÉ
    Joueur(const string &n, const unsigned int &vi, const unsigned int &f, const unsigned int &v, const unsigned int &e, Inventaire in, const Arme &ar);


// LES ACCESSEURS ET MUTATEURS

    // ACCESSEUR NOM
    const string &getNom() const;

    // MUTATEUR NOM
    void setNom(const string& n);

    //MUTATEUR STATS
    void setStat(const string &s, int valeur);

// GESTION DU JOUEUR

    // CHOIX DE L'ACTION
    int choixAction();

    // OPERATEUR << POUR AFFICHER TOUTES LES STATS
    void afficherJoueur();

    int getVie();

    void SetVie(int valeur);

    Inventaire getInv();

    Arme getArme();

    int Attaquer(int i);

    void afficherInventaire() const;

    void utiliserObjet(Objet o);

    Joueur &operator=(const Joueur &j);

private:

    string nomJoueur;

    Statistiques stat; // les stats du joueur
    Inventaire inv; // l'inventaire d'objets du joueur
    Arme arm; // l'arme du joueur
};

#endif // JOUEUR_H_INCLUDED
