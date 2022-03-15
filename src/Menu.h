#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <iostream>
#include "Joueur.h"

using namespace std;

class Menu
{
public:

    Menu(); // constructeur

    ~Menu(); // destructeur 

    void afficherMenu(); // afficher le menu

    void choisirPersonnage(); // choisir le personnage utiliser

    void voirStatPersonnage(); // voir les statiques du personnage


private:
    Joueur *tab;
    
};

#endif // fin de la classe