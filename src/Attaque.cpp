#include <string>
#include <iostream>
#include <fstream>
#include <jsoncpp/json/value.h>
#include <jsoncpp/json/json.h>
#include "Attaque.h"

using namespace std;

// LES CONSTRUCTEURS 
    
    // constructeur
    Attaque::Attaque()
        {
        nomAttaque = "coup de poing";
        degats = 10;
        degatsSpeciaux = 5;
        typeDegats = "Legere";
        typeAttaque = "Confusion";
        descAttaque = "un coup de poing dans la figure";
        nombreMaxUtilisation = nombreUtilisationReste = 30;
        etatNombreTour = 2;
    }

    // constructeur par copie
    Attaque::Attaque(string nomAttaque_, int degats_, int degatsSpeciaux_, int typeDegats_, string typeAttaque_, string descAttaque_, int nombreMaxUtilisation_, int etatNombreTour_)
    {
        nomAttaque = nomAttaque_;
        degats = degats_;
        degatsSpeciaux = degatsSpeciaux_;
        typeDegats = typeDegats_;
        typeAttaque = typeAttaque_;
        descAttaque = descAttaque_;
        nombreMaxUtilisation = nombreUtilisationReste = nombreMaxUtilisation_;
        etatNombreTour = etatNombreTour_;
    }

// LES ACCESSEURS

    // accesseur nomAttaque
    string Attaque::getNomAttaque(){ return nomAttaque; }

    // accesseur degats
    int Attaque::getDegats(){ return degats; }

    // accesseur degatsSpeciaux
    int Attaque::getDegatSp(){ return degatsSpeciaux; }

    // accesseur typeDegats
    string Attaque::getTypeAttaque(){ return typeDegats; }

    // accesseur typeAttaque
    string Attaque::getTypeDegats(){ return typeAttaque; }

    // accesseur descAttaque
    string Attaque::getDescAttaque(){ return descAttaque; }

    // accesseur nombreUtilisationReste
    int Attaque::getNombreUtilisationReste(){ return nombreUtilisationReste; }

    // accesseur nombreMaxUtilisation
    int Attaque::getNombreMaxUtilisation(){ return nombreMaxUtilisation; }

    // accesseur etatNombreTour
    int Attaque::getEtatNombreTour(){ return etatNombreTour; }

// LES MUTATEURS 

    // mutateur nomAttaque
    void Attaque::setNomAttaque(string nomAttaque_){ nomAttaque = nomAttaque_; }

    // mutateur degats
    void Attaque::setDegats(int degats_){ degats = degats_; }

    // mutateur degatsSpeciaux
    void Attaque::setDegatSp(int degatSP_){ degatsSpeciaux = degatSP_; }

    // mutateur typeDegats
    void Attaque::setTypeDegats(string typeDegats_){ typeDegats = typeDegats_; }

    // mutateur typeAttaque
    void Attaque::setTypeAttaque(string typeAttaque_){ typeAttaque = typeAttaque_; }

    // mutateur descAttaque
    void Attaque::setDescAttaque(string descAttaque_) { descAttaque = descAttaque_; }

    // mutateur nombreUtilisationReste
    void Attaque::setNombreUtilisationReste(int nombreUtilisationReste_){ nombreUtilisationReste = nombreUtilisationReste_; }

    // mutateur nombreMaxUtilisation
    void Attaque::setNombreMaxUtilisation(int NombreMaxUtilisation_){ nombreMaxUtilisation = NombreMaxUtilisation_; }

    // mutateur etatNombreTour
    void Attaque::setEtatNombreTour(int etatNombreTour_){ etatNombreTour = etatNombreTour_; }

// GESTION DES ATTAQUES

    // ajouter une attaque à partir des données dans un .json
    void Attaque::ajouterAttaqueJSON(const string &nomJSON)
    {
        ifstream AttaqueJSON("data/Attaque.json");
        Json::Value actualAttaque;
        Json::Reader readerAttaque;

        readerAttaque.parse(AttaqueJSON, actualAttaque);

        int i = 0;
        while(nomJSON != actualAttaque[i]["nom"].asString()) i++;

        nomAttaque = actualAttaque[i]["nom"].asString();
        degats = actualAttaque[i]["degats"].asInt();
        degatsSpeciaux = actualAttaque[i]["degatsSpeciaux"].asInt();
        typeDegats = actualAttaque[i]["typeDegats"].asString();
        typeAttaque = actualAttaque[i]["typeAttaque"].asString();
        descAttaque = actualAttaque[i]["descAttaque"].asString();
        nombreUtilisationReste = nombreMaxUtilisation = actualAttaque[i]["nombreMaxUtilisation"].asInt();
        etatNombreTour = actualAttaque[i]["etatNombreTour"].asInt();

        AttaqueJSON.close();
    }

    // ajouter une attaque
    void Attaque::ajouterAttaque(Attaque a)
    {
        nomAttaque = a.getNomAttaque();
        degats = a.getDegats();
        degatsSpeciaux = a.getDegatSp();
        typeDegats = a.getTypeDegats();
        typeAttaque = a.getTypeAttaque();
        descAttaque = a.getDescAttaque();
        nombreMaxUtilisation = nombreUtilisationReste = a.getNombreMaxUtilisation();
        etatNombreTour = a.getEtatNombreTour();
    }