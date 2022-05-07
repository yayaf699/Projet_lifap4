#ifndef ATTAQUE_H_INCLUDED
#define ATTAQUE_H_INCLUDED
#include <string>

using namespace std;

class Attaque
{

public :

// LES CONSTRUCTEURS 
    
    // CONSTRUCTEUR
    Attaque();

    // CONSTRUCTEUR PAR COPIE
    Attaque(string nomAttaque_, int degats_, int degatsSpeciaux_, int typeDegats_, string typeAttaque_, string descAttaque_, int nombreMaxUtilisation_, int etatNombreTour_);

// LES ACCESSEURS ET MUTATEURS 

    // ACCESSEUR NOM ATTAQUE
    string getNomAttaque();

    // ACCESSEUR DEGATS ATTAQUE
    int getDegats();

    // ACCESSEUR NOMBRE UTILISATION ATTAQUE
    int getNombreMaxUtilisation();

    // ACCESSEUR DESCRIPTION D'ATTAQUE
    string getDescAttaque();

    // ACCESSEUR DEGATS SPECIAUX
    int getDegatSp();

    // ACCESSEUR TYPE ATTAQUE
    string getTypeDegats();

    // ACCsESSEUR TYPE DE DEGATS
    string getTypeAttaque();

    // ACCESSEUR NOMBRE TOUR ETAT 
    int getEtatNombreTour();

    // MUTATEUR NOM ATTAQUE
    void setNomAttaque(string nomAttaque_);

    // MUTATEUR DEGATS ATTAQUE
    void setDegats(int degats_);

    // MUTATEUR NOMBRE UTILISATION ATTAQUE
    void setNombreMaxUtilisation(int NombreMaxUtilisation_);

    // MUTATEUR DESCRIPTION D'ATTAQUE
    void setDescAttaque(string DescAttaque_);

    // MUTATEUR DEGATS SPECIAUX
    void setDegatSp(int degatSP_);

    // MUTATEUR TYPE DE DEGATS
    void setTypeDegats(string typeDegats_);

    // MUTATEUR TYPE ATTAQUE
    void setTypeAttaque(string typeAttaque_);

    // MUTATEUR NOMBRE TOUR ETAT 
    void setEtatNombreTour(int etatNombreTour_);

// GESTION DES ATTAQUES

    // AJOUTER ATTAQUE JSON
    void ajouterAttaqueJSON(const string &nomJSON);

    // AJOUTER ATTAQUE
    void ajouterAttaque(Attaque a);

private :

    string nomAttaque;
    int degats;
    int degatsSpeciaux;
    string typeDegats;
    string typeAttaque;
    string descAttaque;
    int nombreMaxUtilisation;
    int etatNombreTour;

};

#endif // ATTAQUE_H_INCLUDED