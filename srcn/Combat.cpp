#include "Combat.h"

#include<iostream>

using namespace std;

Combat::Combat(){
    tour = true;
    fini = false;
    tempsLimiteParTour = 30;
}

Combat::Combat(Joueur Perso_, Joueur IA_){
    Perso = Perso_;
    IA = IA_;
    tour = true;
    fini = false;
    tempsLimiteParTour = 30;
}


void Combat::TraiterActionAttaque(int degats){

    if (tour == false)
    {
        Perso.SetVie(Perso.getVie() + degats); // retire vie joueur qui se fait attaquer
    }
    else
    {
        IA.SetVie(IA.getVie() +degats);
    }

}

void Combat::tourDuPerso()
{
    unsigned int choix;
    do{
        cout << "que faire?\n1:Attaque\n2:Objet" << endl;
        cin >> choix;
    }
    while (choix != 1 && choix != 2 );

    switch (choix)
    {
    case 1:
            Perso.getArme().GetAttaques();
            cout << "Quel attaque utiliser ?" << endl;
            cin >> choix;
            TraiterActionAttaque(Perso.UtiliserAttaque(choix));
            cout << IA.getVie() << endl;
            break;

    case 2:
            Perso.afficherInventaire();
            cout << "Quel objet utiliser ?" << endl;
            cin >> choix;
            Perso.utiliserObjet(Perso.getInv().retourneObjetInventaire(choix));
            break;


    default:
        break;
    }



}

void Combat::tourIA() // POUR L INSTANT COPIE DU TOUR JOUEUR
   {
    unsigned int choix;
    do{
        cout << "que faire?\n1:Attaque\n2:Objet" << endl;
        cin >> choix;
    }
    while (choix != 1 && choix != 2 );

    switch (choix)
    {
    case 1:
            Perso.getArme().GetAttaques();
            cout << "Quel attaque utiliser ?\n";
            cin >> choix;
            TraiterActionAttaque(Perso.UtiliserAttaque(choix));
            break;

    case 2:
            Perso.afficherInventaire();
            cout << "Quel objet utiliser ?" << endl;
            cin >> choix;
            IA.utiliserObjet(IA.getInv().retourneObjetInventaire(choix));
            break;


    default:
        break;
    }



}

void Combat::combatDeroulement()
{
    while (fini == false)
    {
        tourDuPerso(); // donne le controle au joueur

        if(Perso.getVie() == 0) // verif sant�
        {
            fini = true;
        }

        tourIA(); // donne le controle a l'IA

        if(IA.getVie() == 0)  // verif sant�
        {
            fini = true;
        }
    }
}
