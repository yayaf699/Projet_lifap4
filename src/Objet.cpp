#include <iostream>
#include <fstream>
#include <jsoncpp/json/value.h>
#include <jsoncpp/json/json.h>
#include "Objet.h"

using namespace std;

// LES CONSTRUCTEURS

    // constructeur
    Objet::Objet()
    {
        nom = "emplacement vide";
        bonusVie = bonusVitesse = bonusForce = bonusAttaqueUtilisation = 0;
    }

    // constructeur par copie
    Objet::Objet(const Objet &o)
    {
        nom = o.nom;
        bonusVie = o.bonusVie;
        bonusVitesse = o.bonusVitesse;
        bonusForce = o.bonusForce;
        bonusAttaqueUtilisation = o.bonusAttaqueUtilisation;
    }

// LES ACCESEURS

    // accesseur NomObjet
    const string &Objet::getNomObjet() const { return nom; }

    // accesseur VieObjet
    const unsigned int &Objet::getVieObjet() const { return bonusVie; }

    // accesseur ForceObjet
    const float &Objet::getForceObjet() const { return bonusForce; }

    // accesseur VitesseObjet
    const unsigned int &Objet::getVitesseObjet() const { return bonusVitesse; }

    // accesseur bonusAttaqueUtilisation
    const unsigned int &Objet::getAttaqueUtilisation() const { return bonusAttaqueUtilisation; }

// LES MUTATEURS

    // mutateur NomObjet
    void Objet::setNomObjet(const string &n) { nom = n; }

    // mutateur VieObjet
    void Objet::setVieObjet(const unsigned int &v) { bonusVie = v; }

    // mutateur ForceObjet
    void Objet::setForceObjet(const  float &f) { bonusForce = f; }

    // mutateur VitesseObjet
    void Objet::setVitesseObjet(const unsigned int &vi) { bonusVitesse = vi; }

    // mutateur bonusAttaqueUtilisation
    void Objet::setAttaqueUtilisation(const unsigned int &ut) { bonusAttaqueUtilisation = ut; }


// GESTION DE L'OBJET

    // afficher l'objet en texte
    void Objet::afficherObjet()
    {
        if(nom != "emplacement vide"){
            cout<<nom<<" => ";
            cout<<"Bonus vie: +"<<getVieObjet()<<", ";
            cout<<"Bonus vitesse: +"<<getVitesseObjet()<<", ";
            cout<<"Bonus force: +"<<getForceObjet()<<"\n";
            cout<<"Bonus force: +"<<getAttaqueUtilisation()<<"\n";
        }
        else cout << "emplacement vide"; 
    }

    // ajouter l'objet à partir de son nom en recuperant ses stats dans un .json
    void Objet::ajouterObjetJSON(const string &nomJSON)
    {
        ifstream ObjetJSON("data/Objet.json");
        Json::Value actualObjet;
        Json::Reader readerObjet;

        readerObjet.parse(ObjetJSON, actualObjet);

        int i = 0;
        while(nomJSON != actualObjet[i]["NomObjet"].asString()) i++;

        nom = actualObjet[i]["NomObjet"].asString();
        bonusVie = actualObjet[i]["BonusVie"].asInt();
        bonusVitesse = actualObjet[i]["BonusVitesse"].asInt();
        bonusForce = actualObjet[i]["BonusForce"].asFloat();
        bonusAttaqueUtilisation = actualObjet[i]["bonusAttaqueUtilisation"].asInt();

        ObjetJSON.close();
    }


