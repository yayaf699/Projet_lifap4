#ifndef ATTAQUE_H_INCLUDED
#define ATTAQUE_H_INCLUDED
#include <string>

using namespace std;

class Attaque
{

public :

    Attaque();


    Attaque(string nomAtt,int deg,int nombreAttMax,string nomTypeAtt, int TabStatsAttMag[3],string descriptionAtt);


    //~Attaque();

    // ACCESSEUR NOM ATTAQUE
    string getNomAttaque();

    // ACCESSEUR DEGATS ATTAQUE
    int getDegats();

    // ACCESSEUR TYPE ATTAQUE
    string getTypeAttaque();

    // ACCESSEUR NOMBR UTILISATION ATTAQUE
    int getNombreMaxUtilisation();


    string getDescAttaque();


    void setDescAttaque(string descAttaque_);


    void setNomAttaque(string nomAtt);


    void setDegats(int deg);


    void setNombreMaxUtilisation(int nombreAttMax);


    void setTypeAttaque(string nomTypeAtt);

private :

    string nomAttaque;
    int degats;
    string typeAttaque;
    string descAttaque;
    int nombreMaxUtilisation;
    int TabStatsAttMagique[3];
};

#endif // ATTAQUE_H_INCLUDED
