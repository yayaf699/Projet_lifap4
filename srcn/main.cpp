#include <iostream>
#include "Joueur.h"
#include "Partie.h"
#include "Combat.h"

using namespace std;

int main(){
    Joueur j, ia;
    Combat c(j,ia);
    cout << "oui" << endl;
    c.combatDeroulement();
    return 0;
}
