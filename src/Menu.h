#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <iostream>
#include "Combat.h"
#include "Joueur.h"

using namespace std;

class Menu
{
public:

    Menu(); // constructeur par défaut
    
    ~Menu(); // destructeur par défaut

    void MenuPrincipale(); // afficher le menu principale

    void Jouer(); // lancer le jeu

    void Aide(); // voir les aides du jeu

    void Quitter(); // quitter le menu et le jeu

    void MenuPersonnage(); // afficher les personnages

    int choisirPersonnage(); // choisir le personnage et retourne l'entier de son rang dans le txt

private:

    Joueur TonPersonnage;
    Joueur Adversaire;

    int taille_tabMenu;
    string *tabMenuPersonnage;
};

#endif // fin de la classe