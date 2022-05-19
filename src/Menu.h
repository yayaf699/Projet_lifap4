/**
 * @file Menu.h
 * @author
 * @brief 
 * @version 0.1
 * @date 2022-04-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <iostream>
#include "Combat.h"
#include "Joueur.h"
#include "jeuSdl.h"

#include <jsoncpp/json/value.h>
#include <jsoncpp/json/reader.h>

using namespace std;

/**
 * @brief Classe Menu
 * 
 */
class Menu
{
public:


// CONSTRUCTEUR ET DESTRUCTEUR 

    /**
     * @brief Constructeur de la classe Menu
     * 
     */
    Menu(); 
    
    /**
     * @brief Destructeur de la classe Menu
     * 
     */
    ~Menu(); 

// GESTION DU MENU

    /**
     * @brief affiche le menu principal
     * 
     * @param sdl 
     */
    void MenuPrincipal(Sdljeu &sdl); 

    /**
     * @brief lance le Combat après avoir choisi les 2 personnages qui combattront
     * 
     * @param sdl 
     */
    void Jouer(Sdljeu &sdl); 

    // voir les aides du jeu
    void Aide(); 

    /**
     * @brief quitte la fenêtre sdl et le jeu
     * 
     * @param sdl 
     */
    void Quitter(Sdljeu &sdl); 

    /**
     * @brief Menu qui permet de choisir les personnages qui vont combattre
     * 
     * @param sdl 
     */
    void MenuPersonnage(Sdljeu &sdl); 


private:

    /**
     * @brief Le Joueur correspondant à notre personnage
     * 
     */
    Joueur TonPersonnage;

    /**
     * @brief Le joueur qu'utilisera l'adversaire
     * 
     */
    Joueur Adversaire;

    /**
     * @brief Le tableau de noms des personnages
     * 
     */
    string *tabMenuPersonnage;
    /**
     * @brief Le nombre de personnages pour pouvoir parcourir le tableau
     * 
     */
    int taille_tabMenu;
};

#endif // fin de la classe