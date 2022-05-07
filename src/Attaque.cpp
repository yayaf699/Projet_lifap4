#include <string>
#include <iostream>
#include <fstream>
#include <jsoncpp/json/value.h>
#include <jsoncpp/json/json.h>
#include "Attaque.h"

using namespace std;

// LES CONSTRUCTEURS 

    // CONSTRUCTEUR PAR COPIE
    Attaque::Attaque()
        {
        nomAttaque = "coup de poing";
        degats = 10;
        degatsSpeciaux = 5;
        typeDegats = "Legere";
        typeAttaque = "Confusion";
        descAttaque = "un coup de poing dans la figure";
        nombreMaxUtilisation = 30;
        etatNombreTour = 2;
    }

    // CONSTRUCTEUR PAR COPIE
    Attaque::Attaque(string nomAttaque_, int degats_, int degatsSpeciaux_, int typeDegats_, string typeAttaque_, string descAttaque_, int nombreMaxUtilisation_, int etatNombreTour_)
    {
        nomAttaque = nomAttaque_;
        degats = degats_;
        degatsSpeciaux = degatsSpeciaux_;
        typeDegats = typeDegats_;
        typeAttaque = typeAttaque_;
        descAttaque = descAttaque_;
        nombreMaxUtilisation = nombreMaxUtilisation_;
        etatNombreTour = etatNombreTour_;
    }

// LES ACCESSEURS ET MUTATEURS 

    // ACCESSEUR NOM ATTAQUE
    string Attaque::getNomAttaque() { return nomAttaque; }

    // ACCESSEUR DEGATS ATTAQUE
    int Attaque::getDegats() { return degats; }

    // ACCESSEUR NOMBRE UTILISATION ATTAQUE
    int Attaque::getNombreMaxUtilisation() { return nombreMaxUtilisation; }

    // ACCESSEUR DEGATS SPECIAUX
    int Attaque::getDegatSp() { return degatsSpeciaux; }

    // ACCESSEUR DESCRIPTION D'ATTAQUE
    string Attaque::getDescAttaque() { return descAttaque; }

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
    void Attaque::setEtatNombreTour(int etatNombreTour_) { etatNombreTour = etatNombreTour_; }

// GESTION DES ATTAQUES

    // AJOUTER ATTAQUE JSON
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
        nombreMaxUtilisation = actualAttaque[i]["nombreMaxUtilisation"].asInt();
        etatNombreTour = actualAttaque[i]["etatNombreTour"].asInt();
    }

    // AJOUTER ATTAQUE
    void Attaque::ajouterAttaque(Attaque a)
    {
        nomAttaque = a.getNomAttaque();
        degats = a.getDegats();
        degatsSpeciaux = a.getDegatSp();
        typeDegats = a.getTypeDegats();
        typeAttaque = a.getTypeAttaque();
        descAttaque = a.getDescAttaque();
        nombreMaxUtilisation = a.getNombreMaxUtilisation();
        etatNombreTour = a.getEtatNombreTour();
    }