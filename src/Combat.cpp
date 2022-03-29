#include "Combat.h"

#include<iostream> 

using namespace std;

Combat::Combat(){
    Perso = nullptr;
    IA = nullptr;
    tour = 0;
    tempsLimiteParTour = 30;
} 

Combat::Combat(Joueur *Perso_, Joueur *IA_){
    Perso = Perso_;
    IA = IA_;
    tour = 0;
    tempsLimiteParTour = 30;
}

void Combat::tourDuPerso(){
    unsigned int n;
    do{
        cout << "que faire?\n1:Attaque\n2:Objet" << endl; 
        cin >> n;
    }while (n != 1 && n != 2 );

    switch (n)
    {
    case 1:
        
        break;
    
    default:
        break;
    }
} 

