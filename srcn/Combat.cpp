#include "Combat.h"
#include <cstdlib>
#include<iostream>


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
            cout<< "TOUR DU JOUEUR \n "<<endl;
            cout << "Que voulez vous faire ? \n \n 1. Attaquer \n \n 2. Utiliser un objet \n" << endl;
            cin >> choix;
        system("CLS");
    }
    while (choix != 1 && choix != 2 );

    switch (choix)
    {
    case 1:
            Perso.getArme().afficher();
            cout << "\n Quel attaque utiliser ?" << endl;
            cin >> choix;
            TraiterActionAttaque(Perso.Attaquer(choix));
            cout << IA.getStats().getVie() << endl;
            break;

    case 2:
            Perso.getInv().afficherInventaire();
            cout << "\n Quel objet utiliser ?" << endl;
            cin >> choix;
            Perso.utiliserObjet(Perso.getInv().retourneObjetInventaire(choix));
            Perso.getStats().afficherStat();
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
        system("CLS");
    }
    while (choix != 1 && choix != 2 );

    switch (choix)
    {
    case 1:
            IA.getArme().afficher();
            cout << "\n Quel attaque utiliser ?" << endl;
            cin >> choix;
            TraiterActionAttaque(IA.Attaquer(choix));
            cout << Perso.getStats().getVie() << endl;
            break;

    case 2:
            IA.getInv().afficherInventaire();
            cout << "\n Quel objet utiliser ?" << endl;
            cin >> choix;
            IA.utiliserObjet(IA.getInv().retourneObjetInventaire(choix));
            IA.getStats().afficherStat();
            break;


    default:
        break;
    }




}

void Combat::combatDeroulement()
{
    while (1)
    {
        tourDuPerso(); // donne le controle au joueur

        if(IA.getVie() <= 0) // verif sant�
        {
            cout<<"L'IA est morte"<<endl;

            exit(1);
        }

        tour = false; // au tour de l'ia

        //IA.afficherJoueur();

        tourIA(); // donne le controle a l'IA

        if(Perso.getVie() <= 0)  // verif sant�
        {
            cout<<"Le joueur est mort"<<endl;
            exit(1);
        }
        //Perso.afficherJoueur();

        tour = true; // au tour du joueur

    }
}
