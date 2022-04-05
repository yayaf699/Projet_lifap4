#include "Combat.h"
#include <cstdlib>
#include<iostream>
#include<stdio.h>
#include<stdlib.h> //as system function is in the standard library




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




void Combat::TraiterActionAttaque(int degats)
{
    if (tour == false)
    {   
        if((Perso.getVie() + degats) < 0)
        {
            Perso.SetVie(0); // retire vie joueur à 0
        }
        else 
        {
            Perso.SetVie(Perso.getVie() + degats); // retire vie joueur qui se fait attaquer
        }
    }
    else
    {
        if((IA.getVie() + degats) < 0)
        {
            IA.SetVie(0); // retire vie joueur à 0
        }
        else 
        {
            IA.SetVie(IA.getVie() + degats); // retire vie joueur qui se fait attaquer
        }
    }
}



void Combat::tourDuPerso()
{
    unsigned int choix;
    do{
            system("color 30");
            cout<< "TOUR DU JOUEUR \n "<<endl;
            cout << "Que voulez vous faire ? \n \n 1. Attaquer \n \n 2. Utiliser un objet \n" << endl;
            cin >> choix;
            system("CLS"); // clean tout le texte de l'invite de commande
    }
    while (choix != 1 && choix != 2 );

    switch (choix)
    {
    case 1:
            Perso.getArme().afficher();
            cout << "\n Quel attaque utiliser ?" << endl;
            cin >> choix;
            system("CLS"); // clean tout le texte de l'invite de commande
            TraiterActionAttaque(Perso.Attaquer(choix-1)); //choix -1 car tableau

            cout << "SANTE DE L'ADVERSAIRE APRES VOTRE ATTAQUE : "<< IA.getStats().getVie()<< "\n"<<endl;
            break;

    case 2:
            cout << "VOICI LES STATS DE VOTRE PERSONNAGE : \n "<<endl;
            Perso.getStats().afficherStat();
            cout << "\n";
            Perso.getInv().afficherInventaire();
            cout << "\n Quel objet utiliser ?" << endl;
            cin >> choix;
            system("CLS"); // clean tout le texte de l'invite de commande
            Perso.utiliserObjet(Perso.getInv().retourneObjetInventaire(choix-1)); //choix -1 car tableau
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
            system("CLS"); // clean tout le texte de l'invite de commande
    }
    while (choix != 1 && choix != 2 );

    switch (choix)
    {
    case 1:
            IA.getArme().afficher();
            cout << "\n Quel attaque utiliser ?" << endl;
            cin >> choix;
            system("CLS"); // clean tout le texte de l'invite de commande
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
            system("CLS"); // clean tout le texte de l'invite de commande
            IA.utiliserObjet(IA.getInv().retourneObjetInventaire(choix-1)); //choix -1 car tableau
            break;


    default:
        break;
    }




}

void Combat::combatDeroulement()
{
    while (1==1)
    {
        tourDuPerso(); // donne le controle au joueur

        if(IA.getVie() <= 0) // verif sante
        {
            cout<<"L'IA est morte"<<endl;

            exit(1);
        }

        tour = false; // au tour de l'ia

        //IA.afficherJoueur();

        tourIA(); // donne le controle a l'IA

        if(Perso.getVie() <= 0)  // verif sante
        {
            cout<<"Le joueur est mort"<<endl;
            exit(1);
        }
        //Perso.afficherJoueur();

        tour = true; // au tour du joueur

    }
}

/*
void Combat::DecisionIa()
{
    int importanceAtt =0, importanceObjet=0,TMPimportanceAtt =0, TMPimportanceObjet=0, numAttaque, numObjet;
    for(int i=0; i<4; i=i+1)
    {
        if(IA.getArme().tabAttaque[i].getNombreMaxUtilisation > 0 ) // on retiens l'attaque la plus forte et DISPONIBLE de l'IA
        {
            TMPimportanceAtt = IA.getArme().tabAttaque[i].getDegats()/;
            numAttaque = i;
            if(TMPimportanceAtt>importanceAtt)
            {
                importanceAtt = TMPimportanceAtt;
            }
        }
        if (Perso.getVie()-IA.getArme().tabAttaque[i].getDegats() <= 0 && IA.getArme().tabAttaque[i].getNombreMaxUtilisation > 0 ) // l'ia peut tuer le joueur en 1 attaque
        {
            TMPimportanceAtt = 100000;// action les plus importante
            numAttaque = i;
            if(TMPimportanceAtt>importanceAtt)
            {
                importanceAtt = TMPimportanceAtt;
            }
        }
    }
    for(int j=0; j<4; j=j+1)
    {
        if (IA.getInventaire().getTailleInventaire > 0 ) // l'ia veut augmenter sa vitesse pour limiter les prochains degats recu
        {
            TMPimportanceObjet = IA.getInventaire().inventaire[j].getVitesseObjet();// action les plus importante
            numObjet = j;
            if(TMPimportanceObjet>importanceObjet)
            {
                importanceObjet = TMPimportanceObjet;
            }
        }
        if(IA.getVie()-Perso.getArme().tabAttaque[j].getDegats() <= 0 && Perso.getArme().tabAttaque[j].getNombreMaxUtilisation > 0 ) // l'ia peut se faire tuer par le joueur au prochain tour donc elle se soigne
        {
            TMPimportanceObjet = 100000; // action les plus importante
            numObjet = j;
            if(TMPimportanceObjet>importanceObjet)
            {
                importanceObjet = TMPimportanceObjet;
            }
        }

    }

    if(importanceAtt >= importanceObjet) // l'action la plus importante est effecut�
    {
        TraiterActionAttaque(IA.UtiliserAttaque(numAttaque));
    }
    else
    {
        TraiterActionObjet(IA.utiliserObjet(numObjet));
    }

}

*/
