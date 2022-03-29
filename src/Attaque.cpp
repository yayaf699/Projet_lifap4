#include <string>
#include <iostream>

Attaque::Attaque()
{
    nomAttaque = "Coup d'épée";
    degats = 10;
    typeAttaque = "Legere";
    nombreMaxUtilisation = 50;
    TabStatsAttMagique = {0,0,0};
}

Attaque::Attaque(nomAtt, deg, nombreAttMax, nomTypeAtt, TabStatsAttMag)
{
    nomAttaque = nomAtt;
    degats = deg;
    typeAttaque = nombreAttMax;
    nombreMaxUtilisation = nomTypeAtt;
    TabStatsAttMagique = TabStatsAttMag; // c'est un tableau qui contient des statistiques que l'attaque changera à l'adversaire

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

int UtiliserAttaque()
{
     /*if (typeAttaque=="Strategique")
     {
         return TabStatsAttMagique;
     }
    */

    return degats;
}
