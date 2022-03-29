#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED
#include "Inventaire.h"
#include "Arme.h"
#include "Statistiques.h"

using namespace std;

class Joueur
{
public:

// LES CONSTRUCTEURS ET DESTRUCTEUR

    // CONSTRUCTEUR PAR DEFAUT
    Joueur();

    // CONSTRUCTEUR PERSONNALISÉ
    Joueur(const string &n, const unsigned int &vi, const unsigned int &f, const unsigned int &v, const unsigned int &e, const Inventaire &in, const Arme &ar);

    // DESTRUCTEUR
    ~Joueur();

// LES ACCESSEURS ET MUTATEURS 

    // ACCESSEUR NOM
    const string &getNom() const;

    // MUTATEUR NOM
    void setNom(const string& n);


// GESTION DU JOUEUR 

    // CHOIX DE L'ACTION
    int choixAction();

    // OPERATEUR << POUR AFFICHER TOUTES LES STATS
    void afficherJoueur(); 

private:

    string nomJoueur;

    Statistiques *stat; // les stats du joueur
    Inventaire *inv; // l'inventaire d'objets du joueur 
    Arme *arm; // l'arme du joueur
};

#endif // JOUEUR_H_INCLUDED
