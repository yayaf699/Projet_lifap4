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

void Combat::TraiterActionAttaque(degats){

    if tour == false
    {
        Perso.vie += degats; // retire vie joueur qui se fait attaqué
    }
    else
    {
        IA.vie += degats;
    }

}


void Combat::TraiterActionObjet(tabStats[3]){

    if tour == false
    {
        IA.vie += tabStats[0]; // changer la vie
        IA.vitesse += tabStats[1]; // change la vitesse
        IA.force += (tabStats[2]/100) ; // change la force
    }
    else
    {
        Perso.vie += tabStats[0]; // changer la vie
        Perso.vitesse += tabStats[1]; // change la vitesse
        Perso.force += (tabStats[2]/100) ; // change la force
    }



}

void Combat::tourDuPerso(){
    unsigned int choix;
    do{
        cout << "que faire?\n1:Attaque\n2:Objet" << endl;
        cin >> choix;
    }
    while (choix != 1 && choix != 2 );

    switch (choix)
    {
    case 1:
        do{
            choix = 0; // on reinitialise la variable choix
            Perso.arm.afficherAttaques();
            cout << "Quel attaque utiliser ?\n 1\n 2\n 3\n 4\n" << endl;
            cin >> choix;
          }while (choix != 1 && choix != 2 && choix != 3 && choix != 4 );
          switch (choix)
    {
            case 1:
                TraiterActionAttaque(Perso.arm[choix].UtiliserAttaque);
                break;
            case 2:
                TraiterActionAttaque(Perso.arm[choix].UtiliserAttaque);
                break
            case 3:
                TraiterActionAttaque(Perso.arm[choix].UtiliserAttaque);
                break
            case 4:
                TraiterActionAttaque(Perso.arm[choix].UtiliserAttaque);
                break

            default:
                break;
    }

    case 2:
        do{
            choix = 0; // on reinitialise la variable choix
            Perso.inv.afficherInventaire();
            cout << "Quel objet utiliser ?" << endl;
            cin >> choix;
          }while (choix != 1 && choix != 2 && choix != 3 && choix != 4 );
          switch (choix)
    {
            case 1:
                TraiterActionObjet(Perso.inv.retourneObjetInventaire(choix).UtiliserObjet());
                break;
            case 2:
                TraiterActionObjet(Perso.inv.retourneObjetInventaire(choix).UtiliserObjet());
                break
            case 3:
                TraiterActionObjet(Perso.inv.retourneObjetInventaire(choix).UtiliserObjet());
                break
            case 4:
                TraiterActionObjet(Perso.inv.retourneObjetInventaire(choix).UtiliserObjet());
                break

            default:
                break;
    }


    default:
        break;
    }



}

void Combat::tourIA(){ // POUR L INSTANT COPIE DU TOUR JOUEUR
    unsigned int choix;
    do{
        cout << "que faire?\n1:Attaque\n2:Objet" << endl;
        cin >> choix;
    }
    while (choix != 1 && choix != 2 );

    switch (choix)
    {
    case 1:
        do{
            choix = 0; // on reinitialise la variable choix
            Perso.arm.afficherAttaques();
            cout << "Quel attaque utiliser ?\n 1\n 2\n 3\n 4\n" << endl;
            cin >> choix;
          }while (choix != 1 && choix != 2 && choix != 3 && choix != 4 );
          switch (choix)
    {
            case 1:
                TraiterActionAttaque(Perso.arm[choix].UtiliserAttaque);
                break;
            case 2:
                TraiterActionAttaque(Perso.arm[choix].UtiliserAttaque);
                break
            case 3:
                TraiterActionAttaque(Perso.arm[choix].UtiliserAttaque);
                break
            case 4:
                TraiterActionAttaque(Perso.arm[choix].UtiliserAttaque);
                break

            default:
                break;
    }

    case 2:
        do{
            choix = 0; // on reinitialise la variable choix
            Perso.inv.afficherInventaire();
            cout << "Quel objet utiliser ?" << endl;
            cin >> choix;
          }while (choix != 1 && choix != 2 && choix != 3 && choix != 4 );
          switch (choix)
    {
            case 1:
                TraiterActionObjet(Perso.inv.retourneObjetInventaire(choix).UtiliserObjet());
                break;
            case 2:
                TraiterActionObjet(Perso.inv.retourneObjetInventaire(choix).UtiliserObjet());
                break
            case 3:
                TraiterActionObjet(Perso.inv.retourneObjetInventaire(choix).UtiliserObjet());
                break
            case 4:
                TraiterActionObjet(Perso.inv.retourneObjetInventaire(choix).UtiliserObjet());
                break

            default:
                break;
    }


    default:
        break;
    }



}


void Combat::combatDeroulement()
{
    while (fini == false)
    {
        tourDuPerso(); // donne le controle au joueur

        if(Perso.getVie() == 0) // verif santé
        {
            fini = true;
        }

        tourIA(); // donne le controle a l'IA

        if(IA.getVie() == 0)  // verif santé
        {
            fini = true;
        }
    }
}
