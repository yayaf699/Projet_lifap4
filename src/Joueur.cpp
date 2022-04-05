#include "Joueur.h"
#include <iostream>
#include <fstream>
#include <string.h>


using namespace std;


// LES CONSTRUCTEURS ET DESTRUCTEUR


    // CONSTRUCTEUR PAR DEFAUT
    Joueur::Joueur()
    {
        nomJoueur = "Monkey D. Nordin";


        // stat.afficherStat();
        // cout << arm.getNomArme() << endl;
        // arm.GetAttaques();


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
         cout<<"\n ******* STAT DU JOUEUR ******* \n"<<endl;
         stat.afficherStat();

        cout<<" \n ******* INVENTAIRE ******* \n"<<endl;
        inv.afficherInventaire();

        cout<<" \n \n******* ARME ******* \n"<<endl;
        arm.afficher();
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


    int Joueur::Attaquer(int i)
    {
        return arm.utiliserAttaque(i);
    }

    void Joueur::afficherInventaire() const
    {
        inv.afficherInventaire();
    }

    // UTILISER L'OBJET
    void Joueur::utiliserObjet(Objet o)
    {
        setStat("vie", o.getVieObjet());
        setStat("force", o.getForceObjet());
        setStat("vitesse", o.getVitesseObjet());
        inv.retirerObjetInventaire(o);
    }

void Joueur::ajouterJoueur(unsigned int n)
    {
        int vie, vitesse;
        float force;
        string objetsNom[4];

        ifstream readJoueur("data/Joueur_stat_inventaire.txt"); // recuperer les stats du joueur et son inventaire
        if(readJoueur.is_open())
        {
            for(unsigned int i = 0; i < n; i++) readJoueur.ignore(100, '\n'); // saut de ligne
             readJoueur >> nomJoueur >> vie >> vitesse >> force >> objetsNom[0] >> objetsNom[1] >> objetsNom[2] >> objetsNom[3];
            stat.setVie(vie);
            stat.setVitesse(vitesse);
            stat.setForce(force);
        }
        readJoueur.close();

        ifstream readInventaire("data/Objet.txt"); // r
        if(readInventaire.is_open())
        {
            for(int i = 0; i < 4; i++)
            {
                string nomObjetRecherche;
                do
                {
                    readInventaire >> nomObjetRecherche >> vie >> vitesse >> force;
                    readInventaire.ignore(100, '\n'); // saut de ligne
                } while(objetNom[i] != nomObjetRecherche);

                inv.ajouterObjet(i, nomObjetRecherche, vie, vitesse, force);
            }
        }
    }