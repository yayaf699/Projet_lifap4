#include <string>
#include <iostream>
#include "Attaque.h"
using namespace std;

Attaque::Attaque()
{
    nomAttaque = "Coup d'epee";
    degats = 100;
    typeAttaque = "Legere";
    descAttaque = "Un simple coup d'epee";
    nombreMaxUtilisation = 50;
    int TabStatsAttMagique[3];
    for (int i = 0 ; i< 3 ; i=i+1)
    {
        TabStatsAttMagique[i] = 0;
    }
}

Attaque::Attaque(string nomAtt,int deg,int nombreAttMax,string nomTypeAtt, int TabStatsAttMag[3],string descriptionAtt)
{
    nomAttaque = nomAtt;
    degats = deg;
    typeAttaque = nomTypeAtt;
    descAttaque = descriptionAtt;
    nombreMaxUtilisation = nombreAttMax;
    for (int i = 0 ; i< 3 ; i=i+1)
    {
        TabStatsAttMagique[i] = 0;
    } // c'est un tableau qui contient des statistiques que l'attaque changera � l'adversaire

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
    return typeAttaque;
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

void Attaque::setTypeAttaque(string nomTypeAtt)
{
    typeAttaque = nomTypeAtt;
}

