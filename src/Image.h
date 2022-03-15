#include "Pixel.h"
#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>




using namespace std;

#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED

class Image
{

public:

    // Constructeur par défaut de la classe: initialise dimx et dimy à 0
    // ce constructeur n'alloue pas de pixel
    Image();

    // Constructeur de la classe: initialise dimx et dimy (après vérification)
    // puis alloue le tableau de pixel dans le tas (image noire)
    Image(const unsigned int & dimx, const unsigned int & dimy);

    // Destructeur de la classe: déallocation de la mémoire du tableau de pixels
    // et mise à jour des champs dimx et dimy à 0
    ~Image();

     // Accesseur : récupère le pixel original de coordonnées (x,y) en vérifiant leur validité
     // la formule pour passer d'un tab 2D à un tab 1D est tab[y*dimx+x]
    Pixel &getPix(const unsigned int &x, const unsigned int &y) const;

    // Mutateur : modifie le pixel de coordonnées (x,y)
    void setPix(const unsigned int & x, const unsigned int & y, const Pixel & couleur);

    // Dessine un rectangle plein de la couleur dans l'image (en utilisant setPix, indices en paramètre compris)
    void dessinerRectangle(const unsigned int & Xmin, const unsigned int & Ymin, const unsigned int & Xmax, const unsigned int & Ymax, const Pixel  & couleur);

    // Efface l'image en la remplissant de la couleur en paramètre
   // (en appelant dessinerRectangle avec le bon rectangle)
    void effacer(const Pixel & couleur);

    // Effectue une série de tests vérifiant que le module fonctionne et
    // que les données membres de l'objet sont conformes
    void testRegression();



    void sauver(const string & filename) const;

    void ouvrir(const string & filename);

    void afficherConsole();

    // Afficher une image en ouvrant une fenetre
    void afficher();

private:

    Pixel *tab; // le tableau 1D de pixel
    unsigned int dimx, dimy; // les dimensions de l'image

    SDL_Surface * surface = nullptr;
    SDL_Texture * texture = nullptr;
    SDL_Window * window = nullptr;
    SDL_Renderer * renderer = nullptr;
    bool has_changed;

    // Fonctions membres privées afficher

    void loadFromFile (const char* filename, SDL_Renderer * renderer);
    void draw (SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1);

    void afficherInit();
    void afficherBoucle();
    void afficherDetruit();
};

#endif // IMAGE_H_INCLUDED
