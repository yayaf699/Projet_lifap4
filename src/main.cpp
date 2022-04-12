#include <iostream>
#include "Joueur.h"
#include "Partie.h"
#include "Combat.h"
#include "Statistiques.h"
#include "Arme.h"
#include "Inventaire.h"
#include "Attaque.h"
#include "Objet.h"
#include "Menu.h"

using namespace std;

int main(){
    Joueur a, b;
    a.ajouterJoueur(5);
    Combat c(a, b);
    c.combatDeroulement();
    return 0;
}
