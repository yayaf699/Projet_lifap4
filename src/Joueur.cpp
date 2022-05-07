#include "Joueur.h"
#include <iostream>
#include <fstream>
#include <string>
#include <jsoncpp/json/value.h>
#include <jsoncpp/json/reader.h>


using namespace std;


// LES CONSTRUCTEURS ET DESTRUCTEUR


    // CONSTRUCTEUR PAR DEFAUT
    Joueur::Joueur()
    {
        nomJoueur = "Monkey D. Nordin";
        etat = "";
        nbTourEtat = 0;

    } 

// LES ACCESSEURS ET MUTATEURS

    // ACCESSEUR NOM
    const string &Joueur::getNom() const { return nomJoueur; }

    // MUTATEUR NOM
    void Joueur::setNom(const string& n) { nomJoueur = n; }

    void Joueur::setStat(const string &s, float valeur)
    {   int v;
        if(s =="vie") v = 1;
        if(s == "force") v = 2;
        if(s == "vitesse") v = 3;

        switch(v){
            case 1:
            stat.setVie(stat.getVie() + valeur);
            break;

            case 2:
            stat.setForce(stat.getForce() + valeur);
            break;

            case 3:
            stat.setVitesse(stat.getVitesse() + valeur);
            break;

            default:
            break;

        }
    }

// GESTION DU JOUEUR

    // CHOIX DE L'ACTION
    int Joueur::choixAction()
    {
        int i;

        cout<<"Que voulez-vous faire ?"<<endl;
        cout<<"1. Utiliser un Objet 2. Utiliser arme"<<endl;
        cin>>i;

        return i;
    }

    // OPERATEUR << POUR AFFICHER TOUTES LES STATS
    void Joueur::afficherJoueur()
    {
        cout<<"\n ******* NOM ******* \n"<<endl;
        cout<<getNom()<<endl;

        cout<<"\n ******* STAT DU JOUEUR ******* \n"<<endl;
        stat.afficherStat();

        cout<<" \n ******* INVENTAIRE ******* \n"<<endl;
        inv.afficherInventaire();

        cout<<" \n \n******* ARME ******* \n"<<endl;
        arm.afficherStat();
    }

    Joueur &Joueur::operator=(const Joueur &j){
        stat = j.stat;
        inv = j.inv;
        arm = j.arm;

        return *this;
    }

    int  Joueur::getVie()
    {
        return stat.getVie();
    }

    void Joueur::SetVie(int valeur)
    {
        stat.setVie(valeur);
    }

    Inventaire Joueur::getInv(){
        return inv;
    }

    Arme Joueur::getArme()
    {
        return arm;
    }

    Statistiques Joueur::getStats()
    {
        return stat;
    }

    void Joueur::setEtat(string etat_)
    {
        etat = etat_;
    }

    string Joueur::getEtat()
    {
        return etat;
    }

    Attaque Joueur::Attaquer(int i)
    {
        return arm.utiliserAttaque(i);
    }

    void Joueur::afficherInventaire() const
    {
        inv.afficherInventaire();
    }

    int Joueur::getNbTourEtat()
    {
        return nbTourEtat;
    }

    void Joueur::setNbTourEtat(int nbTour)
    {
        nbTourEtat = nbTour;
    }

    // UTILISER L'OBJET
    void Joueur::utiliserObjet(Objet o)
    {
        setStat("vie", o.getVieObjet());
        setStat("force", o.getForceObjet());
        setStat("vitesse", o.getVitesseObjet());
        if(o.getNomObjet().compare("Soda")==0)
        {
            getArme().afficherStat();
            cout<<"De quelle attaque voulez vous augmentez son nombre d'utilisation ?"<<endl;
            int choix;
            cin>>choix;
            while(getArme().retourneAttaqueArme(choix-1).getNombreMaxUtilisation() !=0 )
            {
                cout<<"\n Cette attaque poss�de deja au moins 1 utilisation \n"<<endl;
                cout<<"De quelle attaque voulez vous augmentez son nombre d'utilisation ?"<<endl;
                cin >> choix;
            }
            getArme().retourneAttaqueArme(choix-1).setNombreMaxUtilisation(1);
            cout<<"ICI 2 / "<<getArme().retourneAttaqueArme(choix-1).getNombreMaxUtilisation();
            cout<<"L'attaque "<<getArme().retourneAttaqueArme(choix-1).getNomAttaque()<<" possede desormais : "<<getArme().retourneAttaqueArme(choix-1).getNombreMaxUtilisation()<<" utilisation"<<endl;
        }
        inv.retirerObjetInventaire(o);
    }

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
            inv.setNomObjetInv(i, PersoJson[n-1]["Inventaire"][i].asString());
        }
        
        // le nom des attaques
        for(int i = 0; i < arm.getNbAttaque(); i++)
        {
            arm.setNomAttaque(i, PersoJson[n-1]["Attaques"][i].asString());
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
        }

    Attaques.close();
    Perso.close();
    }
