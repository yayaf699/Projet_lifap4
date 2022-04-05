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

    // CONSTRUCTEUR TXT
    Joueur::Joueur(const string &nj)
    {
        int id, id_comp; // id du joueur qui va etre utilisé comme comparatif et id du joueur 
        int vie, vitesse;
        float force;

        ifstream readJoueur("data/Joueur.txt"); // recuperer l'id et le nom du joueur
        if(readJoueur.is_open())
        {
            do
            {
                readJoueur >> id >> nomJoueur;
                readJoueur.ignore(100, '\n'); // saut de ligne
            } while (nomJoueur != nj); 
        }
        readJoueur.close();

        ifstream readStatistiques("data/Statistiques.txt"); // recuperer les stats du joueur
        if(readStatistiques.is_open())
        {
            do
            {
                readStatistiques >> id_comp >> vie >> vitesse >> force;
                readStatistiques.ignore(100, '\n'); // saut de ligne
            } while (id_comp != id);

            stat.setVie(vie);
            stat.setVitesse(vitesse);
            stat.setForce(force);
        }
        readStatistiques.close();

        ifstream readInventaire("data/Inventaire.txt"); // recuperer l'inventaire
        int id_objet[4];
        if(readInventaire.is_open())
        {
                do
                {
                    readInventaire >> id_comp >> id_objet[0] >> id_objet[1] >> id_objet[2] >> id_objet[3];
                    readStatistiques.ignore(100, '\n'); // saut de ligne
                } while (id_comp != id);
        }
        readInventaire.close();

        ifstream readObjet("data/Objet.txt");
        if(readObjet.is_open())
        {
            string nom;
            int bonusvie, bonusvitesse;
            float bonusforce;

            for(int i = 0; i < 4; i++)
            {
                id_comp = id_objet[i];
                do
                {
                    readObjet >> id_objet[i] >> nom >> bonusvie >> bonusvitesse >> bonusforce;
                    readObjet.ignore(100, '\n'); // saut de ligne
                } while (id_comp != id_objet[i]);

                inv.ajouterObjet(i, nom, bonusvie, bonusvitesse, bonusforce);
            }
        }

        // FAIRE PAREIL AVEC L'ARME ET LES ATTAQUES
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
