#ifndef ATTAQUE_H_INCLUDED
#define ATTAQUE_H_INCLUDED
#include <string>

using namespace std;

class Attaque
{

public :

    Attaque();


    Attaque(string nomAtt,int deg,int nombreAttMax,string nomTypeAtt, int degatsSp,string descriptionAtt);


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

    int getDegatSp();

    void setDescAttaque(string descAttaque_);

    void setNomAttaque(string nomAtt);

    void setDegats(int deg);

    void setNombreMaxUtilisation(int nombreAttMax);

    void setTypeDegats(string nomTypeAtt);

     string  getTypeDegats();




private :

    string nomAttaque;
    int degats;
    int degatsSpeciaux;
    string typeDegats;
    string descAttaque;
    int nombreMaxUtilisation;
    int etatNombreTour;

};

#endif // ATTAQUE_H_INCLUDED
