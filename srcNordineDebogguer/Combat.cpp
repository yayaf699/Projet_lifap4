#include "Combat.h"

#include<iostream>

using namespace std;

Combat::Combat(){
    Perso = nullptr;
    IA = nullptr;
    tour = 0;
    fini = false;
    tempsLimiteParTour = 30;
}

Combat::Combat(Joueur *Perso_, Joueur *IA_){
    Perso = Perso_;
    IA = IA_;
    tour = 0;
    fini = false;
    tempsLimiteParTour = 30;
}

Combat::~Combat()
{
    Joueur *Perso = NULL;
    Joueur *IA = NULL;
    bool tour = false;
    bool fini = false;
	tempsLimiteParTour = 0;
}

void Combat::TraiterActionAttaque(int degats){

    if (tour == false)
    {
        Perso->setStat("vie",1); // retire vie joueur qui se fait attaqu�
    }
    else
    {
        IA->SetVie(IA->getVie() +degats);
    }

}


void Combat::TraiterActionObjet(int tabStats[3])
{

    if (tour == false)
    {
        IA->SetVie(IA->getVie() +tabStats[0]); // changer la vie
        IA->SetVie(IA->getVie() +tabStats[1]); // change la vitesse
        IA->SetVie(IA->getVie() + tabStats[2]/100) ; // change la force
    }
    else
    {
        Perso->SetVie(IA->getVie() +tabStats[0]); // changer la vie
        Perso->SetVie(IA->getVie() +tabStats[1]); // change la vitesse
        Perso->SetVie(IA->getVie() + tabStats[2]/100); // change la force
    }



}

void Combat::tourDuPerso()
{
    unsigned int choix=0;
    do{
        cout << "que faire?\n1:Attaque\n2:Objet" << endl;
        cin >> choix;
    }
    while (choix != 1 && choix != 2 );

    switch (choix)
    {
    case 1:
            choix = 0; // on reinitialise la variable choix
            Perso->GetAttaques();
            cout << "Quel attaque utiliser ?\n 1\n 2\n 3\n 4\n" << endl;
            cin >> choix;
            TraiterActionAttaque(Perso->UtiliserAttaque(choix));

    case 2:
            choix = 0; // on reinitialise la variable choix
            Perso->afficherInventaire();
            cout << "Quel objet utiliser ?" << endl;
            cin >> choix;
            TraiterActionObjet(Perso->utiliserObjet(choix));


    default:
        break;
    }



}

void Combat::tourIA() // POUR L INSTANT COPIE DU TOUR JOUEUR
   {
    unsigned int choix=0;
    do{
        cout << "que faire?\n1:Attaque\n2:Objet" << endl;
        cin >> choix;
    }
    while (choix != 1 && choix != 2 );

    switch (choix)
    {
    case 1:
            choix = 0; // on reinitialise la variable choix
            Perso->GetAttaques();
            cout << "Quel attaque utiliser ?\n 1\n 2\n 3\n 4\n" << endl;
            cin >> choix;
            TraiterActionAttaque(Perso->UtiliserAttaque(choix));

    case 2:
            choix = 0; // on reinitialise la variable choix
            Perso->afficherInventaire();
            cout << "Quel objet utiliser ?" << endl;
            cin >> choix;
            TraiterActionObjet(Perso->utiliserObjet(choix));


    default:
        break;
    }



}

void Combat::combatDeroulement()
{
    while (fini == false)
    {
        tourDuPerso(); // donne le controle au joueur

        if(Perso->getVie() == 0) // verif sant�
        {
            fini = true;
        }

        tourIA(); // donne le controle a l'IA

        if(IA->getVie() == 0)  // verif sant�
        {
            fini = true;
        }
    }
}
