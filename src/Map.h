#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include "Joueur.h"

#include <string>
#include <stdio.h>
#include <stdlib.h>


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>

#define WINDOW_WIDTH 620
#define WINDOW_HEIGHT 580

using namespace std;


class Map
{
public:

// LES CONSTRUCTEURS

    // constructeur par defaut
    Map();

    // constructeur par copie

// LE DESTRUCTEUR

    // destructeur
    ~Map();

// LES ACCESSEURS

    // accesseur numeroMap
    int getNumeroMap();

    // accesseur joueur_actuel
    Joueur getJoueur_actuel();

    // accesseur carte_actuel
    int getCarte_actuel(int x, int y);

// LES MUTATEURS

    // mutateur numeroMap
    void setNumeroMap(int n);

    // mutateur joueur_actuel
    void setJoueur_actuel(Joueur j);

    // mutateur carte_actuel
    void setCarte_actuel(int x, int y, int a);

// SDL 

    // initialisation de la SDL
    int init(char name[], SDL_Window **win, SDL_Renderer **ren);

    // fermeture de la fenetre SDL
    void close(SDL_Window *win, SDL_Renderer *ren, SDL_Surface *pic);

    // boucle SDL
    void pause(SDL_Renderer *renderer, SDL_Rect &posPerso,int carte[21][21], int & NumCarte, int & nbBossBattu);

    // charger image
    void loadPic(SDL_Renderer *ren);

    // charger texture
    SDL_Texture *loadTexture(char * filename, SDL_Renderer * ren);


// GESTION DE LA MAP

    // initialisation des map
    void initMap(SDL_Renderer *ren, int carte[21][21]);

    void initMap2(SDL_Renderer *ren, int carte[21][21]);

    void initMap3(SDL_Renderer *ren, int carte[21][21]);

    // chargement du personnage
    void initPerso(SDL_Renderer *ren, SDL_Rect &posPerso, SDL_Texture* tex_perso, SDL_Surface * pSprite);

    // les endroits ou il y a une interaction
    int PeutInteragir (int carte[21][21], SDL_Rect &posPerso);

    // gestion des personnage
    void deplacePerso(SDL_Renderer *ren,SDL_Rect &posPerso, char* direction,int carte[21][21], int numCarte);

    // lance le combat
    void lancer_Combat(SDL_Renderer *ren, char* nomPerso, int & nbBossBattu);

    // ouvrir un magasin 
    void Ouvrir_Magasin(SDL_Renderer *ren);

    // traiter l'interaction
    void TraiteInteraction(int interaction, SDL_Renderer *renderer, int & nbBossBattu);

    // Charge la carte actuelle
    void charge_carte(int carte[21][21], int NumCarte); 

    // change la carte
    void change_carte(int carte[21][21], int NumCarte, int & nbBossBattu );

    // verifier les collision
    bool Verif_Collision(int NouvellePositionX, int NouvellePositionY, int carte[21][21], int NumCarte);

    // verifier si on marche sur une piece
    void verifPiece(int NouvellePositionX, int NouvellePositionY, int carte[21][21]);

    // main affichage
    void mainAffichage(SDL_Renderer * renderer, SDL_Window * window); 


private:

 Joueur joueur_actuel;
 int carte_actuel[21][21];

};

#endif // ARME_H_INCLUDED
