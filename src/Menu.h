#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <iostream>
#include "Combat.h"
#include "Joueur.h"

#include <jsoncpp/json/value.h>
#include <jsoncpp/json/reader.h>

using namespace std;

class Menu
{
public:

// CONSTRUCTEUR ET DESTRUCTEUR 

    // constructeur par défaut
    Menu(); 
    
    // destructeur par défaut
    ~Menu(); 

// GESTION DU MENU

    // afficher le menu principale
    void MenuPrincipale(); 

    // lancer le jeu
    void Jouer(); 

    // voir les aides du jeu
    void Aide(); 

    // quitter le menu et le jeu
    void Quitter(); 

    // afficher les personnages
    void MenuPersonnage(); 

    // choisir le personnage et retourne l'entier de son rang dans le txt
    int choisirPersonnage(); 

    // afficher le menu en sdl
    void afficherMenuSDL();

private:

    Joueur TonPersonnage;
    Joueur Adversaire;

    int taille_tabMenu;
    string *tabMenuPersonnage;
};

#endif // fin de la classe