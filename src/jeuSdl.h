#ifndef JEU_H
#define JEU_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <string>
#include "Joueur.h"
#include "Map.h"


class Image{

public:
  SDL_Texture * m_texture;
  SDL_Surface * m_surface;
  bool m_hasChanged;
  Image ();
  ~Image();
  void loadFromFile (const char* filename, SDL_Renderer * renderer);
  void loadFromCurrentSurface (SDL_Renderer * renderer);
  void draw (SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1);
  SDL_Texture * getTexture() const;
  void setSurface(SDL_Surface * surf);

};


class Sdljeu {
    
public:
  
  SDL_Window * window;
  SDL_Renderer * renderer;
  bool quit = false;

  /**
   * @brief Définit si on utilise l'affichage graphique ou non
   * 
   */
  bool withsdl;

  /**
   * @brief Constructeur de la classe Sdljeu
   * 
   */
  Sdljeu();

  /**
   * @brief Destructeur de la classe SDLjeu
   * 
   */
  ~Sdljeu();

  /**
   * @brief Fonction qui permet de choisir entre affichage texte et affichage graphique
   * 
   */
  void choixAffichage();

  /**
   * @brief Affiche le menu, et retorune un chiffre correspondant au choix de l'utilisateur
   * 
   * @return int 
   */
  int afficherMenu();
  /**
   * @brief Affiche un personnage dont le nom est saisi en paramètre sur la position saisie également en paramètres
   * 
   * @param perso 
   * @param x 
   * @param y 
   */
  void afficherPerso(const char* perso, int x, int y);

  /**
   * @brief reprend la fonction afficherPerso mais avec le tableau de personnage du menu
   * @brief retourne l'indice du personnage choisi dans le tableau
   * 
   * @param tabPerso 
   * @return int 
   */
  int afficherChoixPerso(std::string * tabPerso);

  /**
   * @brief Initialise la fenêtre de combat en SDL
   * 
   * @param A_me 
   * @param B_ia 
   */
  void initCombat(Joueur A_me, Joueur B_ia);

  /**
   * @brief Met à jour les pv de notre personnage dans sa fenêtre
   * 
   * @param Perso 
   */
  void majLogPerso(Joueur Perso);

  /**
   * @brief Met à jour les pv de l'IA dans sa fenêtre 
   * 
   * @param IA 
   */
  void majLogIA(Joueur IA);

  /**
   * @brief Met à jour la boîte de dialogue lors du tour de notre personnage
   * 
   * @param j 
   * @param action 
   * @return int 
   */
  int majlogsChoix(Joueur j, bool action);

  /**
   * @brief 
   * 
   * @param texte 
   * @param attaque 
   * @param j 
   * @return int 
   */
  int majlogs(std::string texte, bool attaque, Joueur j);


};

#endif