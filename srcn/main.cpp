#include <iostream>
#include "Joueur.h"
#include "Partie.h"
#include "Combat.h"

using namespace std;

int main(){
    Joueur a, b;
    Combat c(a, b);
    cout << "oui" << endl;
    c.combatDeroulement();
    return 0;
}
