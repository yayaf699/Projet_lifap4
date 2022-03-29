#ifndef ATTAQUE_H_INCLUDED
#define ATTAQUE_H_INCLUDED
#include <string>

class Attaque
{
private :
    string nomAttaque;
    int degats;
    string typeAttaque;
    int nombreMaxUtilisation;
    int TabStatsAttMagique[2];
public :
    Attaque();
    Attaque(string nomAtt,int deg,int nombreAttMax,string nomTypeAtt, int TabStatsAttMag[2]);
    ~Attaque();
    // ACCESSEUR NOM ATTAQUE
    string getNomAttaque();
    // ACCESSEUR DEGATS ATTAQUE
    int getDegats();
    // ACCESSEUR TYPE ATTAQUE
    string getTypeAttaque();
    // ACCESSEUR NOMBR UTILISATION ATTAQUE
    int getNombreMaxUtilisation();
    void setNomAttaque(string nomAtt);
    void setDegats(int deg);
    void setNombreMaxUtilisation(int nombreAttMax);
    void setTypeAttaque(string nomTypeAtt);
    int UtiliserAttaque();
};

#endif // ATTAQUE_H_INCLUDED
