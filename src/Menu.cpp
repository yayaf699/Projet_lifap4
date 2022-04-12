#include "Menu.h"
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

    Menu::Menu() // constructeur
    {
        TonPersonnage.ajouterJoueur(2);
        Adversaire.ajouterJoueur(4);

        taille_tabMenu = 9;
        tabMenuPersonnage = new string [taille_tabMenu];
    }

    Menu::~Menu() // destructeur par défaut
    {
        for(int i = 0; i < taille_tabMenu; i++) tabMenuPersonnage[i] = "";
        delete [] tabMenuPersonnage;
    }

    void Menu::MenuPrincipale() // afficher le menu principale
    {
        // version txt
        int choix;

        cout <<"*******************FIGHT CLUB*******************"<<endl;
        cout<<endl;
        cout<<"1. JOUER"<<endl;
        cout<<endl;
        cout<<"2. AIDE"<<endl;
        cout<<endl;
        cout<<"3. QUITTER"<<endl;

        cin >> choix;

        if(choix == 1) MenuPersonnage();
        else if(choix == 2) Aide();
        else if(choix == 3) Quitter();
        
        /*   VERSION SDL
            *
            *
            * 
            * 
            * 
            * 
        */
    }
    
    void Menu::Jouer() // lancer le jeu
    {
        Combat c(TonPersonnage, Adversaire);
        c.combatDeroulement();  
    }
    
    void Menu::Aide() // voir les aides du jeu
    {

    }
    
    void Menu::Quitter() // quitter le menu et le jeu
    {
        char reponse;
        cout << "etes vous sur de vouloir quitter le jeu ? [o/n]" << endl;
        cin >> reponse;

        if(reponse == 'o') exit(0);
        else MenuPrincipale();
    }
    
    void Menu::MenuPersonnage() 
    {
        // on remplit un tableau avec le nom des personnages
        ifstream MenuPersonnage("data/Joueur_stat_inventaire.txt"); // ouvrir le fichier txt à partir de la premiere ligne
        if(MenuPersonnage.is_open())
        {
            for(int i = 0; i < taille_tabMenu; i++)
            {
                MenuPersonnage >> tabMenuPersonnage[i];
                MenuPersonnage.ignore(1000, '\n'); // saut de ligne
            }
        }

        // version txt
        for(int i = 0; i < taille_tabMenu; i++)
        {
            cout << i+1 << ". " << tabMenuPersonnage[i] << endl;
        }

        int choixPersonnage, choixAdversaire;

        cout <<"Quel personnage voulez vous choisir ?"<<endl;
        cin>>choixPersonnage;
        TonPersonnage.afficherJoueur();
        TonPersonnage.ajouterJoueur(choixPersonnage);

        cout <<"Quel adversaire voulez vous choisir ?"<<endl;
        cin>>choixAdversaire;
        Adversaire.afficherJoueur();
        Adversaire.ajouterJoueur(choixAdversaire);


        /*   VERSION SDL
            *
            *
            * 
            * 
            * 
            * 
        */
    }

    