#include "Jeu.h"

using namespace std;


Jeu::Jeu(){

    for(unsigned int i = 0; i < NBJOUEUR; i++){
        tabJoueurs[i].ajouterJoueur(i);
        tabJoueurs[i].afficherJoueur();
    }


}