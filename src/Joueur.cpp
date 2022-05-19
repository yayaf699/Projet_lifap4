#include "Joueur.h"
#include <iostream>
#include <fstream>
#include <string>
#include <jsoncpp/json/value.h>
#include <jsoncpp/json/reader.h>


using namespace std;


// LE CONSTRUCTEUR

    // constructeur par défaut
    Joueur::Joueur()
    {
        nomJoueur = "Monkey D. Nordin";
        etat = "";
        nbTourEtat = 0;
        piece = 0;

        stat.setVitesse(1);
        stat.setForce(1.1);

        inv.ajouterObjet(0,"potion",10,0,0);
        inv.ajouterObjet(1,"Superpotion",20,0,0);
        inv.ajouterObjet(2,"Megapotion",30,0,0);
        inv.ajouterObjet(3,"Hyperpotion",40,0,0);

        arm.getTabAttaque(0).setNomAttaque("hagra");
        arm.getTabAttaque(1).setNomAttaque("hagra");
        arm.getTabAttaque(2).setNomAttaque("hagra");
        arm.getTabAttaque(3).setNomAttaque("hagra");
    } 

// LES ACCESSEURS

    // accesseur nom
    const string &Joueur::getNom() const { return nomJoueur; }

    // accesseur etat
    string Joueur::getEtat() { return etat; }

    // accesseur NbTourEtat
    int Joueur::getNbTourEtat() { return nbTourEtat; }

    // accesseur stats
    Statistiques Joueur::getStats() { return stat; }

    // accesseur inventaire
    Inventaire Joueur::getInv() { return inv; }

    // accesseur arme
    Arme Joueur::getArme() { return arm; }

    // accesseur pieces
    int Joueur::getPiece() { return piece; }

// LES MUTATEURS

    // mutateur nom
    void Joueur::setNom(const string& n) { nomJoueur = n; }

    // mutateur etat
    void Joueur::setEtat(string e) { etat = e; }

    // mutateur NbTourEtat
    void Joueur::setNbTourEtat(int nb) { nbTourEtat = nb; }

    // mutateur piece
    void Joueur::setPiece(int p) { piece = p; }


// GESTION DU JOUEUR

    // choix de l'action
    int Joueur::choixAction()
    {
        int i;

        cout<<"Que voulez-vous faire ?"<<endl;
        cout<<"1. Utiliser un Objet 2. Utiliser arme"<<endl;
        cin>>i;

        return i;
    }

    // afficher joueur
    void Joueur::afficherJoueur()
    {
        cout<<"\n ******* NOM ******* \n"<<endl;
        cout<<getNom()<<endl;

        cout<<"\n ******* STAT DU JOUEUR ******* \n"<<endl;
        stat.afficherStat();

        cout<<" \n ******* INVENTAIRE ******* \n"<<endl;
        inv.afficherInventaire();

        cout<<" \n ******* ARME ******* \n"<<endl;
        arm.afficherStat();
    }

    // attaquer
    Attaque Joueur::Attaquer(int i) 
    { 
        arm
        .getTabAttaque(i)
        .setNombreUtilisationReste(arm.getTabAttaque(i).getNombreUtilisationReste()-1);

        return arm.getTabAttaque(i);
    }

    // afficher l'inventaire
    void Joueur::afficherInventaire() const { inv.afficherInventaire(); }

    // utiliser un objet
    void Joueur::utiliserObjet(Objet o)
    {
        int choix;
        if(o.getVieObjet() + stat.getVie() > 100)
        {
            stat.setVie(100); 
        }
            stat.setVie(o.getVieObjet() + stat.getVie());
            stat.setForce(o.getForceObjet() * stat.getForce());
            stat.setVitesse(o.getVitesseObjet() + stat.getVitesse());

        if(o.getAttaqueUtilisation() > 0)
        {
            // ###################################################################################################### VERSION TEXT 
            cout<<"sur quelle attaque voulez vous l'utiliser ?"<<endl;
            arm.afficherStat();
            cin>>choix;
            if(o.getAttaqueUtilisation() + arm.getTabAttaque(choix-1).getNombreUtilisationReste() >= arm.getTabAttaque(choix-1).getNombreMaxUtilisation())
            {
                arm.getTabAttaque(choix-1).setNombreUtilisationReste(arm.getTabAttaque(choix-1).getNombreMaxUtilisation());
            }
            else
            {
                arm.getTabAttaque(choix-1).setNombreUtilisationReste(o.getAttaqueUtilisation() + arm.getTabAttaque(choix-1).getNombreUtilisationReste());
            }
        }
        inv.retirerObjetInventaire(o);
    }

    // operateur =
    Joueur &Joueur::operator=(const Joueur &j)
    {
        nomJoueur = j.nomJoueur;
        etat = j.etat;
        nbTourEtat = j.nbTourEtat;
        
        stat = j.stat;
        inv = j.inv;
        arm = j.arm;

        return *this;
    }

    // ajouter un joueur
    void Joueur::ajouterJoueur(unsigned int n)
    {
        // recuperer les stats du personnage 
        ifstream Perso("data/Joueur_stats_inventaire.json");
        Json::Value PersoJson;
        Json::Reader readerPerso;

        readerPerso.parse(Perso, PersoJson); 

        // le nom
        setNom(PersoJson[n-1]["Nom"].asString());

        // les stats
        setEtat(PersoJson[n-1]["Stats"]["etat"].asString());
        setNbTourEtat(PersoJson[n-1]["Stats"]["nbTourEtat"].asInt());
        stat.setVie(PersoJson[n-1]["Stats"]["statVie"].asInt());
        stat.setVitesse(PersoJson[n-1]["Stats"]["statVitesse"].asInt());
        stat.setForce(PersoJson[n-1]["Stats"]["statForce"].asFloat()); 
        
        // le nom des objets de l'inventaire
        for(int i = 0; i < inv.getTailleInventaire(); i++)
        {   
            inv.getInventaire(i).setNomObjet(PersoJson[n-1]["Inventaire"][i].asString());
        }
        
        // le nom des attaques
        for(int i = 0; i < arm.getNbAttaque(); i++)
        {
            arm.getTabAttaque(i).setNomAttaque(PersoJson[n-1]["Attaques"][i].asString());
        } 
    
        // recuperer les stats des objets
        ifstream Objets("data/Objet.json");
        Json::Value ObjetJson;
        Json::Reader readerObjet;

        readerObjet.parse(Objets, ObjetJson);
        int j;

        for(int i = 0; i < inv.getTailleInventaire(); i++)
        {
            j = 0;
            while(PersoJson[n-1]["Inventaire"][i].asString() != ObjetJson[j]["NomObjet"].asString()) j++;    

            inv.ajouterObjet(i, ObjetJson[j]["NomObjet"].asString(),
                                ObjetJson[j]["BonusVie"].asInt(),  
                                ObjetJson[j]["BonusVitesse"].asInt(), 
                                ObjetJson[j]["BonusForce"].asFloat());
        }

        Objets.close();

        // recuperer les stats des attaques
        ifstream Attaques("data/Attaque.json");
        Json::Value AttaqueJson;
        Json::Reader readerAttaque;

        readerAttaque.parse(Attaques, AttaqueJson);

        for(int i = 0; i < arm.getNbAttaque(); i++)
        {
            j = 0;
            while(PersoJson[n-1]["Attaques"][i].asString() != AttaqueJson[j]["nom"].asString()) j++; 

            arm.ajouterAttaque(i, AttaqueJson[j]["nom"].asString(),
                                  AttaqueJson[j]["degats"].asInt(),
                                  AttaqueJson[j]["degatsSpeciaux"].asInt(),
                                  AttaqueJson[j]["typeDegats"].asString(),
                                  AttaqueJson[j]["typeAttaque"].asString(),
                                  AttaqueJson[j]["descAttaque"].asString(),
                                  AttaqueJson[j]["nombreMaxUtilisation"].asInt(),
                                  AttaqueJson[j]["etatNombreTour"].asInt());
            arm.getTabAttaque(i).setNombreUtilisationReste(arm.getTabAttaque(i).getNombreMaxUtilisation());
            
        }


            

        Attaques.close();
        Perso.close();
    }

    // actualise la vie
    void Joueur::MajVieJoueur(int degatsRecu)
    {
        if(stat.getVie() - degatsRecu == 0)
        {
            stat.setVie(0);
        }
        else
        {
            stat.setVie(stat.getVie() - degatsRecu);
        }
    }

    // acheter un objet
    void Joueur::acheterObjet(string nom_Objet, int prix)
    {
        int emplacement = 0;
        int in;

        for(int i = 0; i < inv.getTailleInventaire(); i++)
        {
            if(inv.getInventaire(i).getNomObjet() != "emplacement vide")
            {
                emplacement++;
            }
        }

        if(emplacement == 0)
        {
            cout<<"echanger avec quel objet ?"<<endl;
            afficherInventaire();
            cin>>in;
        }

        // ###################################################################################################### TEXT
        if(piece >= prix)
        {
            inv.getInventaire(emplacement-1).ajouterObjetJSON(nom_Objet);
        }
        else
        {
            cout<<"OBJET TROP CHER"<<endl;
        }
    }
