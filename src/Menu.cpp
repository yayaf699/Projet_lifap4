#include "Menu.h"

#include <iostream>
#include <cstdlib>
#include <fstream>



using namespace std;

    Menu::Menu() // constructeur
    {
        TonPersonnage.ajouterJoueur(2);
        Adversaire.ajouterJoueur(4);

        taille_tabMenu = 10; // nombre de personnages dans le jeu
        tabMenuPersonnage = new string [taille_tabMenu];
    }

    Menu::~Menu() // destructeur par défaut
    {
        for(int i = 0; i < taille_tabMenu; i++) tabMenuPersonnage[i] = "";
        delete [] tabMenuPersonnage;
    }

    void Menu::MenuPrincipal(Sdljeu &sdl) // afficher le menu principale
    {
        sdl.choixAffichage();
        // version txt
        int choix;

        cout <<"*******************FIGHT CLUB*******************"<<endl;
        cout<<endl;
        cout<<"1. JOUER"<<endl;
        cout<<endl;
        cout<<"2. AIDE"<<endl;
        cout<<endl;
        cout<<"3. QUITTER"<<endl;

        if(!sdl.withsdl) cin >> choix;
        else choix = sdl.afficherMenu();
        if(choix == 1) MenuPersonnage(sdl);
        else if(choix == 3) Quitter(sdl);
        else if(choix == 2) Aide();
    }
    
    void Menu::Jouer(Sdljeu &sdl) // lancer le jeu
    {
        Combat c;
        c.combatDeroulement(TonPersonnage, Adversaire, sdl);  
    }
    
    void Menu::Aide() // voir les aides du jeu
    {

    }
    
    void Menu::Quitter(Sdljeu &sdl) // quitter le menu et le jeu
    {
        char reponse;
        cout << "etes vous sur de vouloir quitter le jeu ? [o/n]" << endl;
        if(!sdl.withsdl) cin >> reponse;
        else reponse = 'o';

        if(reponse == 'o') exit(0);
        else MenuPrincipal(sdl);
       
    }
    
    void Menu::MenuPersonnage(Sdljeu &sdl) 
    {
    // on remplit un tableau avec le nom des personnages
        ifstream Perso("data/Joueur_stats_inventaire.json");
        Json::Value PersoJson;
        Json::Reader readerPerso;

        readerPerso.parse(Perso, PersoJson); 

        for(int i = 0; i < taille_tabMenu; i++)
        {
            tabMenuPersonnage[i] = PersoJson[i]["Nom"].asString();
        }

        Perso.close();
        

    
        for(int i = 0; i < taille_tabMenu; i++)
        {
            cout << i+1 << ". " << tabMenuPersonnage[i] << endl;
        }

        int choixPersonnage, choixAdversaire;

        cout <<"Quel personnage voulez vous choisir ?"<<endl;
        if (!sdl.withsdl) cin>>choixPersonnage;
        else choixPersonnage = sdl.afficherChoixPerso(tabMenuPersonnage);
        TonPersonnage.afficherJoueur();
        TonPersonnage.ajouterJoueur(choixPersonnage);

        for(int i = 0; i < taille_tabMenu; i++)
        {
            if(choixPersonnage != i+1) cout << i+1 << ". " << tabMenuPersonnage[i] << endl;
        }

        cout <<"Quel adversaire voulez vous choisir ?"<<endl;
        if(!sdl.withsdl) cin>>choixAdversaire;
        else do{
            choixAdversaire = sdl.afficherChoixPerso(tabMenuPersonnage);
        }while(choixAdversaire == choixPersonnage);
        Adversaire.afficherJoueur();
        Adversaire.ajouterJoueur(choixAdversaire);
        Jouer(sdl);
    }

    