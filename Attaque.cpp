#include <iostream>
#include "Statistiques.h"

Attaque::Attaque()
{
    nomAttaque = "Coup d'épée";
    degats = 10;
    typeAttaque = "Legere";
    nombreMaxUtilisation = 50;
}

Attaque::Attaque(string nomAtt,int deg,int nombreAttMax,string nomTypeAtt)
{
    nomAttaque = nomAtt;
    degats = deg;
    typeAttaque = nombreAttMax;
    nombreMaxUtilisation = nomTypeAtt;

}

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

void Attaque::setNomAttaque(nomAtt)
{
    nomAttaque = nomAtt;
}

void Attaque::setDegats(deg)
{
    degats = deg;
}

void Attaque::setNombreMaxUtilisation(nombreAttMax)
{
    nombreMaxUtilisation = nombreAttMax;
}

void Attaque::setTypeAttaque(nomTypeAtt)
{
    typeAttaque = nomTypeAtt;
}
