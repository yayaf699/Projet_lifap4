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
        cout<<"\n ******* NOM ******* \n"<<endl;
        cout<<getNom()<<endl;

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
        if(o.getNomObjet().compare("Soda")==0)
        {
            getArme().affAttaques();
            cout<<"De quelle attaque voulez vous augmentez son nombre d'utilisation ?"<<endl;
            int choix;
            cin>>choix;
            while(getArme().getAtk(choix-1).getNombreMaxUtilisation() !=0 )
            {
                cout<<"\n Cette attaque poss�de deja au moins 1 utilisation \n"<<endl;
                cout<<"De quelle attaque voulez vous augmentez son nombre d'utilisation ?"<<endl;
                cin >> choix;
            }
            getArme().getAtk(choix-1).setNombreMaxUtilisation(1);
            cout<<"ICI 2 / "<<getArme().getAtk(choix-1).getNombreMaxUtilisation();
            cout<<"L'attaque "<<getArme().getAtk(choix-1).getNomAttaque()<<" possede desormais : "<<getArme().getAtk(choix-1).getNombreMaxUtilisation()<<" utilisation"<<endl;
        }
        inv.retirerObjetInventaire(o);
    }

    void Joueur::ajouterJoueur(unsigned int n)
    {
        // sens de lecture du fichier Joueur_stat_inventaire
        // nom etat nbTourEtat statVie statVitesse statForce objet1 objet2 objet3 objet4 nomArme attaque1 attaque2 attaque3 attaque4
        
        string nom, etat;
        int nbTour, statVie, statVitesse;
        float statForce;

        string objets[4];
        string nomArme;
        string attaques[4];

        string ElementRecherche; // variable de passage

        ifstream readJoueur("data/Joueur_stat_inventaire.txt"); // recuperer les stats du joueur, son inventaire, son arme et le nom des attaques
        if(readJoueur.is_open())
        {
            int i = 1;
            do
            {
            readJoueur.ignore(1000, '\n');
            i++;
            } while (i != n); // on parcours le fichier qu'une fois

            readJoueur >> nom >> etat >> nbTour >> statVie >> statVitesse >> statForce;
            readJoueur >> objets[0] >> objets[1] >> objets[2] >> objets[3];
            readJoueur >> nomArme;
            readJoueur >> attaques[0] >> attaques[1] >> attaques[2] >> attaques[3];

            setNom(nom);
            setEtat(etat);

            stat.setVie(statVie);
            stat.setVitesse(statVitesse);
            stat.setForce(statForce); 

            arm.setNomArme(nomArme);       
        }
        readJoueur.close();

        ifstream readInventaire("data/Objet.txt"); // recuperer  le contenu de l'inventaire
        if(readInventaire.is_open())
        {
            for(int i = 0; i <= 3; i++) // parcourir le fichier en fonction du nombre d'objets
            {
                ifstream readInventaire("data/Objet.txt");
                do
                {
                    readInventaire >> ElementRecherche >> statVie >> statVitesse >> statForce;
                    readInventaire.ignore(1000, '\n'); // saut de ligne
                } while(objets[i] != ElementRecherche);

                inv.ajouterObjet(i, ElementRecherche, statVie, statVitesse, statForce);
                readInventaire.close();
            }
        }
        readInventaire.close();
/*
        // lecture des stats des attaques 
        // sens de lecture
        // nom degats degatsSpeciaux typeDegats descAttaque nombreMaxUtilisation etatNombreTour
        int degats, degatsSpeciaux, nombreMaxUtilisation, etatNombreTour;
        string typeDegats, typeAttaque;
        string descAttaque = "";
        string concatenationChaine;
        string description = "";

        ifstream readAttaque("data/Attaque.txt"); // recuperer le contenu des attaques
        if(readAttaque.is_open())
        {
            for(int i = 0; i <= 3; i++)
            {
                ifstream readAttaque("data/Attaque.txt");
                do
                {
                    readAttaque >> nom >> degats >> degatsSpeciaux >> typeDegats >> typeAttaque;

                    // descAttaque concatenation des mots
                    while (descAttaque != "/")
                    {
                        readAttaque >> concatenationChaine >> descAttaque;
                        description = description + " " + concatenationChaine + " " +  descAttaque + " ";
                    }

                    readAttaque >> nombreMaxUtilisation >> etatNombreTour;
                    readAttaque.ignore(1000, '\n'); // saut de ligne
                } while (attaques[i] != ElementRecherche);

                arm.ajouterAttaque(i, nom, degats, degatsSpeciaux, typeDegats, typeAttaque, descAttaque, nombreMaxUtilisation, etatNombreTour);
                readAttaque.close();
            }
        }
        readAttaque.close();
*/
    }
