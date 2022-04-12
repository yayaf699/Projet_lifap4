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

string Attaque::getNomAttaque()
{
    return nomAttaque;
}

int Attaque::getDegats()
{
    return degats;
}

string Attaque::getTypeAttaque()
{
    return typeDegats;
}

int Attaque::getDegatSp()
{
    return degatsSpeciaux;
}

int Attaque::getNombreMaxUtilisation()
{
    return nombreMaxUtilisation;
}

string Attaque::getDescAttaque()
{
    return descAttaque;
}

void Attaque::setDescAttaque(string descAttaque_)
{
    descAttaque = descAttaque_;
}

void Attaque::setNomAttaque(string nomAtt)
{
    nomAttaque = nomAtt;
}

void Attaque::setDegats(int deg)
{
    degats = deg;
}

void Attaque::setNombreMaxUtilisation(int nombreAttMax)
{
    nombreMaxUtilisation = nombreAttMax;
}

void Attaque::setTypeDegats(string nomTypeAtt)
{
    typeDegats = nomTypeAtt;
}

string  Attaque::getTypeDegats()
{
    return typeDegats;
}
