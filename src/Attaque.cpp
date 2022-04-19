#include <string>
#include <iostream>
#include "Attaque.h"
using namespace std;

Attaque::Attaque()
{
    nomAttaque = "Coup d'epee";
    degats = 100;
    typeDegats = "Legere";
    descAttaque = "Un simple coup d'epee";
    nombreMaxUtilisation = 50;
    degatsSpeciaux = 10;
}

Attaque::Attaque(string nomAtt,int deg,int nombreAttMax,string typeDegats_, int degatsSp,string descriptionAtt)
{
    nomAttaque = nomAtt;
    degats = deg;
    degatsSpeciaux = degatsSp;
    typeDegats = typeDegats_;
    descAttaque = descriptionAtt;
    nombreMaxUtilisation = nombreAttMax;


}

// Attaque::~Attaque()
// {
//     nomAttaque ="";
//     degats =0;
//     typeAttaque ="";
//     nombreMaxUtilisation = 0;
//     for (int i = 0 ; i< 3 ; i=i+1)
//     {
//         TabStatsAttMagique[i] = 0;
//     }
// }

    // ACCESSEUR NOM ATTAQUE
    string Attaque::getNomAttaque() { return nomAttaque; }

    // ACCESSEUR DEGATS ATTAQUE
    int Attaque::getDegats() { return degats; }

    // ACCESSEUR NOMBRE UTILISATION ATTAQUE
    int Attaque::getNombreMaxUtilisation() { return nombreMaxUtilisation; }

    // ACCESSEUR DESCRIPTION D'ATTAQUE
    string Attaque::getDescAttaque() { return descAttaque; }

    // ACCESSEUR DEGATS SPECIAUX
    int Attaque::getDegatSp() { return degatsSpeciaux; }

    // ACCESSEUR TYPE DE DEGATS
    string  Attaque::getTypeDegats() { return typeDegats; }

    // ACCESSEUR TYPE DE DEGATS
    string  Attaque::getTypeAttaque() { return typeAttaque; }

    // ACCESSEUR NOMBRE TOUR ETAT 
    int Attaque::getEtatNombreTour() { return etatNombreTour; }

    // MUTATEUR NOM ATTAQUE
    void Attaque::setNomAttaque(string nomAttaque_) { nomAttaque = nomAttaque_; }

    // MUTATEUR DEGATS ATTAQUE
    void Attaque::setDegats(int degats_) { degats = degats_; }

    // MUTATEUR NOMBRE UTILISATION ATTAQUE
    void Attaque::setNombreMaxUtilisation(int NombreMaxUtilisation_) { nombreMaxUtilisation = NombreMaxUtilisation_; }

    // MUTATEUR DESCRIPTION D'ATTAQUE
    void Attaque::setDescAttaque(string DescAttaque_) { descAttaque = DescAttaque_; }

    // MUTATEUR DEGATS SPECIAUX
    void Attaque::setDegatSp(int degatSP_) { degatsSpeciaux = degatSP_; }

    // MUTATEUR TYPE DE DEGATS
    void Attaque::setTypeDegats(string typeDegats_) { typeDegats = typeDegats_; }

    // MUTATEUR TYPE ATTAQUE
    void  Attaque::setTypeAttaque(string typeAttaque_) { typeAttaque = typeAttaque_; }

    // MUTATEUR NOMBRE TOUR ETAT 
    int Attaque::setEtatNombreTour(int etatNombreTour_) { etatNombreTour = etatNombreTour_; }
