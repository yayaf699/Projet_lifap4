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
        inv.retirerObjetInventaire(o);
    }

    void Joueur::ajouterJoueur(unsigned int n)
    {
        int vie, vitesse; float force; // variable de passage pour les stats joueur et les stats objet
        string objetsNom[4]; // noms objet dans l'inventaire

        string ArmeNom;
        string attaquesNom[4];
        int degats;
        int nbUtilisationMax;

        string nomObjetRecherche; // variable de passage

        ifstream readJoueur("data/Joueur_stat_inventaire.txt"); // recuperer les stats du joueur, son inventaire, son arme et le nom des attaques
        if(readJoueur.is_open())
        {
            int i = 0;
            do
            {
            readJoueur >> nomJoueur >> vie >> vitesse >> force;
            readJoueur >> objetsNom[0] >> objetsNom[1] >> objetsNom[2] >> objetsNom[3];
            readJoueur >> ArmeNom;
            readJoueur >> attaquesNom[0] >> attaquesNom[1] >> attaquesNom[2] >> attaquesNom[3];

            readJoueur.ignore(100, '\n');
            i++;
            } while (i != n);

            //cout << nomJoueur <<" "<< vie <<" "<< vitesse <<" "<< force <<endl;
            //cout << objetsNom[0] <<" "<< objetsNom[1] <<" "<< objetsNom[2] <<" "<< objetsNom[3] <<endl;
            //cout << ArmeNom <<endl;
            //cout << attaquesNom[0] <<" "<< attaquesNom[1] <<" "<< attaquesNom[2] <<" "<< attaquesNom[3] <<endl;

            stat.setVie(vie);
            stat.setVitesse(vitesse);
            stat.setForce(force);
        }
        readJoueur.close();

        ifstream readInventaire("data/Objet.txt"); // recuperer  le contenu de l'inventaire
        if(readInventaire.is_open())
        {
            for(int i = 0; i <= 3; i++)
            {
                ifstream readInventaire("data/Objet.txt");
                do
                {
                    readInventaire >> nomObjetRecherche >> vie >> vitesse >> force;
                    readInventaire.ignore(100, '\n'); // saut de ligne
                } while(objetsNom[i] != nomObjetRecherche);

                cout << nomObjetRecherche <<" "<< vie <<" "<< vitesse <<" "<< force <<endl;
                inv.ajouterObjet(i, nomObjetRecherche, vie, vitesse, force);
            }
        }
        readInventaire.close();

        ifstream readAttaque("data/Attaque.txt"); // recuperer le contenu des attaques
        if(readAttaque.is_open())
        {
            for(int i = 0; i <= 3; i++)
            {
                ifstream readAttaque("data/Attaque.txt");
                do
                {
                    readAttaque >> nomObjetRecherche >> degats >> nbUtilisationMax;
                    readAttaque.ignore(100, '\n'); // saut de ligne
                } while (attaquesNom[i] != nomObjetRecherche);

                cout << nomObjetRecherche <<" "<<degats <<" "<<nbUtilisationMax<<endl;
                arm.ajouterAttaque(i, nomObjetRecherche, degats, nbUtilisationMax);
            }
        }
        readAttaque.close();
    }
