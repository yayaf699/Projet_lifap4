#include "Combat.h"
#include <cstdlib>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
//#include <Windows.h>
#ifdef _WIN32 // lorsqu'on compile avec windows
const bool os = true;
#elif __linux__
const bool os = false;
#endif

using namespace std;


Combat::Combat(){
    tour = true;
    fini = false;
    tempsLimiteParTour = 30;
}

Combat::Combat(const Joueur &Perso_, const Joueur &IA_){
    Perso = Perso_;
    IA = IA_;
    tour = true;
    fini = false;
    tempsLimiteParTour = 30;
}

void Combat::Clear()
{
    if(os)
    {
        system("CLS"); // clean tout le texte de l'invite de commande
    }
    else
    {
        system("clear");
    }
}

void Combat::TraiterActionAttaque(Attaque att)
{
    if (tour == false)
    {
        if((Perso.getEtat().compare("invincible") == 0 | Perso.getEtat().compare("invisible") == 0)&& Perso.getNbTourEtat() > 0)
        {
            return ;
        }
        if(Perso.getVie() - att.getDegats() < 0)
        {
            Perso.SetVie(0); // retire vie joueur à 0
        }
        else
        {
            int tmpRandVarCoupCrit = (rand() % 100) +1;
            if(tmpRandVarCoupCrit<20) // 20 % de chance que ATTAQUE CRITIQUE se produisent
            {
                srand(time(NULL));
                int MultiplicateurCrit = (rand() % (int(1.5*10)-10))+1;
                int degatCrit = ((float(MultiplicateurCrit)/10)+1.0)*att.getDegats();
                cout<<"COUP CRITIQUE : "<<"cette attaque inflige : "<<degatCrit<<" degats !"<<endl;
                Perso.SetVie(Perso.getVie() - att.getDegats());
            }
            else
            {
                Perso.SetVie(Perso.getVie() - att.getDegats()); // retire vie joueur qui se fait attaquer
            }
        }
        if(att.getTypeAttaque().compare("stun") == 0 | att.getTypeAttaque().compare("gele") == 0 | att.getTypeAttaque().compare("petrification") == 0)
        {
            int tmpRandVar = (rand() % 100) +1;
            if(tmpRandVar<70) // 70 % de chance que GELE SE PRODUIT
            {
                IA.setEtat(att.getTypeAttaque());
                IA.setNbTourEtat(3);
                cout<<"Le JOUEUR subit "<< att.getTypeAttaque() <<endl;
                return ;
            }
        }
        else if(att.getTypeAttaque().compare("saignement") == 0 | att.getTypeAttaque().compare("brulure") == 0 | att.getTypeAttaque().compare("poison") == 0)
        {
            int tmpRandVar = (rand() % 100) +1;
            if(tmpRandVar>50) // 50 % de chance que SAIGNEMENT SE PRODUIT
            {
                Perso.setEtat(att.getTypeAttaque());
                Perso.setNbTourEtat(5);
                cout<<"Le JOUEUR subit "<< att.getTypeAttaque() <<endl;
                return ;
            }
        }
        else if(att.getTypeAttaque().compare("invincible") == 0 | att.getTypeAttaque().compare("invisible") == 0)
        {
                IA.setEtat(att.getTypeAttaque());
                IA.setNbTourEtat(2);
                cout<<"L'IA est "<< att.getTypeAttaque() << " pendant 2 tours"<<endl;
                return ;
        }
    }
    else
    {
        if((IA.getEtat().compare("invincible") == 0 | IA.getEtat().compare("invisible") == 0)&& IA.getNbTourEtat() > 0)
        {
            return ;
        }
         if(IA.getVie() - att.getDegats() < 0)
        {
            IA.SetVie(0); // retire vie joueur à 0
        }
        else
        {
            int tmpRandVarCoupCrit = (rand() % 100) +1;
            if(tmpRandVarCoupCrit<20) // 20 % de chance que ATTAQUE CRITIQUE se produisent
            {
                srand(time(NULL));
                int MultiplicateurCrit = (rand() % (int(1.5*10)-10))+1;
                int degatCrit = ((float(MultiplicateurCrit)/10)+1.0)*att.getDegats();
                cout<<"COUP CRITIQUE : "<<"cette attaque inflige : "<<degatCrit<<" degats !"<<endl;
                IA.SetVie(IA.getVie() - att.getDegats());
            }
            else
            {
                IA.SetVie(IA.getVie() - att.getDegats()); // retire vie joueur qui se fait attaquer
            }
        }
        if(att.getTypeAttaque().compare("stun") == 0 | att.getTypeAttaque().compare("gele") == 0 | att.getTypeAttaque().compare("petrification") == 0)
        {
            int tmpRandVar = (rand() % 100) +1;
            if(tmpRandVar<70) // 70 % de chance que GELE SE PRODUIT
            {
                IA.setEtat(att.getTypeAttaque());
                IA.setNbTourEtat(3);
                cout<<"L'IA subit "<< att.getTypeAttaque() <<endl;
                return ;

            }
        }
        else if(att.getTypeAttaque().compare("saignement") == 0 | att.getTypeAttaque().compare("brulure") == 0 | att.getTypeAttaque().compare("poison") == 0)
        {
            int tmpRandVar = (rand() % 100) +1;
            if(tmpRandVar>50) // 50 % de chance que SAIGNEMENT SE PRODUIT
            {
                IA.setEtat(att.getTypeAttaque());
                IA.setNbTourEtat(5);
                return ;
            }
        }
        else if(att.getTypeAttaque().compare("invincible") == 0 | att.getTypeAttaque().compare("invisible") == 0)
        {
                Perso.setEtat(att.getTypeAttaque());
                Perso.setNbTourEtat(2);
                cout<<"Le JOUEUR est "<< att.getTypeAttaque() << " pendant 2 tours"<<endl;
                return ;
        }
    }
}



void Combat::tourDuPerso()
{
    unsigned int choix;
    do{
            if(os==true){system("color 30");}
            cout<< "TOUR DU JOUEUR \n "<<endl;
            cout << "Que voulez vous faire ? \n \n 1. Attaquer \n \n 2. Utiliser un objet \n" << endl;
            cin >> choix;
            Clear(); //fonction qui nettoie l'invite de commande
    }
    while (choix != 1 && choix != 2 );

    switch (choix)
    {
    case 1:
            Perso.getArme().afficherStat();
            cout << "\n Quel attaque utiliser ?" << endl;
            cin >> choix;
            while(Perso.getArme().retourneAttaqueArme(choix-1).getNombreMaxUtilisation() == 0)
            {
                cout<<"\n Cette attaque n'est plus utilisable \n"<<endl;
                cout << "\n Quel attaque utiliser ?" << endl;
                cin >> choix;
            }
            Clear();
            TraiterActionAttaque(Perso.Attaquer(choix-1));
            cout<<"VOUS AVEZ UTILISEZ "<<Perso.getArme().retourneAttaqueArme(choix-1).getNomAttaque()<<"\n"<<endl;
            cout << "SANTE DE L'ADVERSAIRE APRES VOTRE ATTAQUE : "<< IA.getStats().getVie()<< "\n"<<endl;
            break;

    case 2:
            cout << "VOICI LES STATS DE VOTRE PERSONNAGE : \n "<<endl;
            Perso.getStats().afficherStat();
            cout << "\n";
            Perso.getInv().afficherInventaire();
            cout << "\n Quel objet utiliser ?" << endl;
            cin >> choix;
            Clear();
            cout<<"VOUS AVEZ UTILISEZ "<<Perso.getInv().retourneObjetInventaire(choix-1).getNomObjet()<<"\n"<<endl;
            Perso.utiliserObjet(Perso.getInv().retourneObjetInventaire(choix-1)); //choix -1 car tableau
            cout << "VOTRE SANTE APRES UTILISATION DE L'OBJET : "<< Perso.getStats().getVie()<< "\n"<<endl;
            break;


    default:
        break;
    }



}

void Combat::tourIA() // POUR L INSTANT COPIE DU TOUR JOUEUR
   {
    unsigned int choix;
    do{
            cout<< "TOUR DE L'IA \n" <<endl;
            cout << "Que voulez vous faire ? \n \n 1. Attaquer \n \n 2. Utiliser un objet \n" << endl;
            cin >> choix;
            Clear();

    }
    while (choix != 1 && choix != 2 );

    switch (choix)
    {
    case 1:
            IA.getArme().afficherStat();
            cout << "\n Quel attaque utiliser ?" << endl;
            cin >> choix;
            Clear();
            TraiterActionAttaque(IA.Attaquer(choix-1)); //choix -1 car tableau
            cout << "VOTRE SANTE APRES L'ATTAQUE RECU : "<< Perso.getStats().getVie() << "\n" << endl;
            break;

    case 2:
            cout << "VOICI LES STATS DE VOTRE PERSONNAGE : \n "<<endl;
            IA.getStats().afficherStat();
            cout << "\n";
            IA.getInv().afficherInventaire();
            cout << "\n Quel objet utiliser ?" << endl;
            cin >> choix;
            Clear();
            IA.utiliserObjet(IA.getInv().retourneObjetInventaire(choix-1)); //choix -1 car tableau
            break;


    default:
        break;
    }




}


void Combat::VerifierEtatJoueur()
{

    if(tour==false)
    {
        if(IA.getEtat().compare("")!=0) // c'est optimiser pour ne pas rentrer pour rien
        {
            if(IA.getNbTourEtat()>0) // DANS CETTE FONCTION ON TRAITE ETAT JOUEUR (SAIGNEMENT,PARALYSIE...)
            {
                    if(IA.getEtat().compare("saignement") == 0 | IA.getEtat().compare("brulure") == 0 | IA.getEtat().compare("poison") == 0)
                {
                    int tmpRandVar = (rand() % 100) +1;
                    if(tmpRandVar>=50) // 50% de CHANCE DE SUBIR LE SAIGNEMENT
                    {
                        IA.SetVie(IA.getVie()-10);
                        cout<<"L'IA saigne : -10 pv"<<endl;
                        cout << "SA SANTE DESORMAIS : "<< IA.getStats().getVie() << "\n" << endl;
                    }
                }
            }
            else
            {
                IA.setEtat("");
            }
        }
        if(Perso.getEtat().compare("")!=0) // c'est optimiser pour ne pas rentrer pour rien
        {
            if(Perso.getNbTourEtat()>0) // DANS CETTE FONCTION ON TRAITE ETAT JOUEUR (SAIGNEMENT,PARALYSIE...)
            {
                    if(Perso.getEtat().compare("stun") == 0 | Perso.getEtat().compare("gele") == 0 | Perso.getEtat().compare("petrification") == 0)
                {
                    for(int i =0; i<3;i=i+1) // -1 car je laisse le tour
                    {
                            cout<<"ETAT JOUEUR : "<<Perso.getEtat()<< " pendant "<< Perso.getNbTourEtat()<< " tours"<<endl;
                            DecisionIa();
                            //sleep(7000); // sur windows, mettez votre commande linux en bas sans retirer elle (C EST DES MILLISECONDES)
                            Perso.setNbTourEtat(Perso.getNbTourEtat()-1);
                    }
                }
            }
            else
            {
                Perso.setEtat("");
            }
        }
    }


   if(tour==true)
    {
        if(Perso.getEtat().compare("")!=0) // c'est optimiser pour ne pas rentrer pour rien
        {
            if(Perso.getNbTourEtat()>0) // DANS CETTE FONCTION ON TRAITE ETAT JOUEUR (SAIGNEMENT,PARALYSIE...)
            {
                    if(Perso.getEtat().compare("saignement") == 0 | Perso.getEtat().compare("brulure") == 0 | Perso.getEtat().compare("poison") == 0)
                {
                    int tmpRandVar = (rand() % 100) +1;
                    if(tmpRandVar>=50) // 50% de CHANCE DE SUBIR LE SAIGNEMENT
                    {
                        Perso.SetVie(Perso.getVie()-10);
                        cout<<"LE JOUEUR saigne : -10 pv"<<endl;
                        cout << "SA SANTE DESORMAIS : "<< Perso.getStats().getVie() << "\n" << endl;
                    }
                }
            }
        }
        if(IA.getEtat().compare("")!=0) // c'est optimiser pour ne pas rentrer pour rien
        {
            if(IA.getNbTourEtat()>0) // DANS CETTE FONCTION ON TRAITE ETAT JOUEUR (SAIGNEMENT,PARALYSIE...)
            {
                    if(IA.getEtat().compare("stun") == 0 | IA.getEtat().compare("gele") == 0 | IA.getEtat().compare("petrification") == 0)
                {
                    for(int i =0; i<3;i=i+1) // -1 car je laisse le tour
                    {
                            cout<<"ETAT IA : "<<IA.getEtat()<< " pendant "<< IA.getNbTourEtat()<< " tours"<<endl;
                            tourDuPerso();
                            IA.setNbTourEtat(IA.getNbTourEtat()-1);
                    }
                }
            }
        }
    }

    if(Perso.getVie() <= 0) // verif sante
        {
            cout<<Perso.getNom() << " (Joueur) est mort "<<endl;

            exit(1);
        }

    if(IA.getVie() <= 0) // verif sante
        {
            cout<<IA.getNom() << " (IA) est mort "<<endl;

            exit(1);
        }

}


void Combat::combatDeroulement()
{
    if(Perso.getStats().getVitesse()>=IA.getStats().getVitesse())
    {
        while(1)
        {
            tourDuPerso(); // donne le controle au joueur
            VerifierEtatJoueur();
            tour = false; // au tour de l'ia
            cout<<"L'IA reflechi a son prochain tour (c'est faux mais faut que t'ai le temps de lire)"<<endl;
            //sleep(7000); // sur windows, mettez votre commande linux en bas sans retirer elle (C EST DES MILLISECONDES)
            DecisionIa(); // donne le controle a l'IA
            VerifierEtatJoueur();
            tour = true; // au tour du joueur
            Perso.setNbTourEtat(Perso.getNbTourEtat()-1); // FIN      TOUR
            IA.setNbTourEtat(IA.getNbTourEtat()-1);         //        DE
        }
    }
    else
    {
        while(1)
        {
            tour = false;
            cout<<"L'IA reflechi a son prochain tour (c'est faux mais faut que t'ai le temps de lire)"<<endl;
            //sleep(7000); // sur windows, mettez votre commande linux en bas sans retirer elle (C EST DES MILLISECONDES)
            DecisionIa(); // donne le controle a l'IA
            VerifierEtatJoueur();
            tour = true; // au tour du joueur
            tourDuPerso(); // donne le controle au joueur
            VerifierEtatJoueur();
            Perso.setNbTourEtat(Perso.getNbTourEtat()-1); // FIN      TOUR
            IA.setNbTourEtat(IA.getNbTourEtat()-1);         //        DE
        }
    }
}


void Combat::DecisionIa() //IA OFFENSIF
{
    Clear();
    int importanceAtt =0;
    int importanceObjet=0;
    int TMPimportanceAtt =0;
    int TMPimportanceObjet = 0;
    int numAttaque, numObjet;
    for(int i=0; i<4; i=i+1)
    {
        if(IA.getArme().retourneAttaqueArme(i).getNombreMaxUtilisation() > 0 ) // on retiens l'attaque la plus forte et DISPONIBLE de l'IA
        {
            TMPimportanceAtt = IA.getArme().retourneAttaqueArme(i).getDegats();
            if(TMPimportanceAtt>importanceAtt)
            {
                importanceAtt = TMPimportanceAtt;
                numAttaque = i;
            }

        }
        if (Perso.getVie()-IA.getArme().retourneAttaqueArme(i).getDegats()<= 0 && IA.getArme().retourneAttaqueArme(i).getNombreMaxUtilisation() > 0 ) // l'ia peut tuer le joueur en 1 attaque
        {
            TMPimportanceAtt = 100000;// action les plus importante
            if(TMPimportanceAtt>importanceAtt)
            {
                importanceAtt = TMPimportanceAtt;
                 numAttaque = i;
            }
        }

        if(IA.getInv().rechercherObjetInventaire("Pillule de sante")  != -1 && IA.getVie()-Perso.getArme().retourneAttaqueArme(i).getDegats() <= 0 && Perso.getArme().retourneAttaqueArme(i).getNombreMaxUtilisation() > 0 ) // l'ia peut se faire tuer par le joueur au prochain tour donc elle se soigne
        {
            TMPimportanceObjet = 100000; // action les plus importante
            importanceObjet = 100000; // action les plus importante
            numObjet = IA.getInv().rechercherObjetInventaire("Pillule de sante");
        }

    }

    if(importanceAtt >= importanceObjet) // l'action la plus importante est effecutee
    {
        cout<<"L'ADVERSAIRE A UTILISER "<<IA.getArme().retourneAttaqueArme(numAttaque).getNomAttaque()<<"\n"<<endl;
        TraiterActionAttaque(IA.Attaquer(numAttaque));
        IA.getArme().retourneAttaqueArme(numAttaque).setNombreMaxUtilisation(IA.getArme().retourneAttaqueArme(numAttaque).getNombreMaxUtilisation()-1);
    }
    else
    {
        cout<<"L'ADVERSAIRE A UTILISER "<<IA.getInv().retourneObjetInventaire(numObjet).getNomObjet() <<"\n"<<endl;
        IA.utiliserObjet(IA.getInv().retourneObjetInventaire(numObjet));
    }
    cout << "VOTRE SANTE APRES L'ATTAQUE RECU : "<< Perso.getStats().getVie() << "\n" << endl;

}



