#ifndef ARME_H_INCLUDED
#define ARME_H_INCLUDED
#include <string>
#include "Attaque.h"


using namespace std;


class Arme
{
public:

// LES CONSTRUCTEURS ET DESTRUCTEURS

    // CONSTRUCTEUR
    Arme();

    // DESTRUCTEUR
    ~Arme();

// ACCESSEURS ET MUTATEURS

    // ACCESSEUR NOMBRE D'ATTAQUE
    int getNbAttaque();

    // ACCESSEUR ATTAQUE
    string getNomAttaque(int i);

    // MUTATEUR ATTAQUE
    void setNomAttaque(const unsigned int &i, const string &n);

// GESTION ARME

    // AJOUTER ATTAQUE
    void ajouterAttaque(int indice, string nomAttaque, int degats, int degatsSpeciaux, string typeDegats, string typeAttaque, string descAttaque, int nombreMaxUtilisation, int etatNombreTour);

    // RETOURNE I-EME ATTAQUE
    Attaque retourneAttaqueArme(const unsigned int &i);

    // AFFICHER LES STATS DE TOUTES LES ATTAQUES
    void afficherStat();

    // L'UTILISATION DE L'ATTAQUE
    Attaque utiliserAttaque(int i);

private:

    int nbAttaque;
    Attaque *tabAttaque;
};



#endif // ARME_H_INCLUDED
