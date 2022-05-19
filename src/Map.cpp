#include "Map.h"

using namespace std;


// LES CONSTRUCTEURS

    // constructeur par defaut
    Map::Map()
    { 
        joueur_actuel.ajouterJoueur(8);

        for(int i = 0; i < 20; i++)
        {
            
            for(int j = 0; j < 20; j++)
            {
                carte_actuel[i][j] = 0;
            }
        }
    }

    // destructeur
    Map::~Map()
    {

        for(int i = 0; i < 20; i++)
        {
            
            for(int j = 0; j < 20; j++)
            {
                carte_actuel[i][j] = 0;
            }
        }   
    }

// LES ACCESSEURS

    // accesseur joueur_actuel
    Joueur Map::getJoueur_actuel(){ return joueur_actuel; }

    // accesseur carte_actuel
    int Map::getCarte_actuel(int x, int y) { return carte_actuel[x][y]; }

// LES MUTATEURS


    // mutateur joueur_actuel
    void Map::setJoueur_actuel(Joueur j){ joueur_actuel = j; }

    // mutateur carte_actuel
    void Map::setCarte_actuel(int x, int y, int a){ carte_actuel[x][y] = a; }

// SDL 

    // initialisation de la SDL
    int Map::init(char name[], SDL_Window **win, SDL_Renderer **ren)
    { 

    int success = 1;

    if(SDL_Init(SDL_INIT_EVERYTHING)<0)
    {
        fprintf(stderr,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        success = 0;
    }
    else{
        *win = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

        if( win == NULL )
        {
            fprintf(stderr,"Échec à la création de la fenêtre (%s)\n",SDL_GetError());
            success = 0;
        }
        else
        {
            *ren = SDL_CreateRenderer(*win,-1,SDL_RENDERER_ACCELERATED);
            if( ren == NULL )
            {
                fprintf(stderr,"Échec à la création de la fenêtre (%s)\n",SDL_GetError());
                success = 0;
            }
        }
    }
    TTF_Init();


    return success;
    }

    // fermeture de la fenetre SDL
    void Map::close(SDL_Window *win, SDL_Renderer *ren, SDL_Surface *pic)
    { 
     SDL_FreeSurface(pic);
    pic = NULL;
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    win = NULL;

    TTF_Quit();
    SDL_Quit();
    }

    // boucle SDL
    void Map::pause(SDL_Renderer *renderer, SDL_Rect &posPerso,int carte[21][21], int & NumCarte, int & nbBossBattu)
    { 

    int quit = 0;
    SDL_Event event;

    while (!quit)
    {
        SDL_RenderClear(renderer);
        SDL_WaitEvent(&event);

        if (posPerso.x > 500)
        {
            posPerso.x = 50;
            NumCarte = 2;
            change_carte(carte,NumCarte,nbBossBattu );
            deplacePerso(renderer,posPerso, "right",carte,NumCarte);
        }
        if (posPerso.y < 25)
        {
            posPerso.x = 275;
            posPerso.y = 475;
            NumCarte = 3;
            change_carte(carte,NumCarte,nbBossBattu );
            deplacePerso(renderer,posPerso, "right",carte,NumCarte);
        }
        if(NumCarte == 1 && nbBossBattu == 3)
        {
			carte[20][9] = 1;
            deplacePerso(renderer,posPerso, "",carte,NumCarte);
			nbBossBattu = 0;
		}
        if(NumCarte == 2 && nbBossBattu == 3)
        {
            carte[14][0] = 1;
            deplacePerso(renderer,posPerso, "",carte,NumCarte);
			nbBossBattu = 0;
		}
		if(NumCarte == 3 && nbBossBattu == 3)
        {
				
			SDL_RenderClear(renderer);

            SDL_Surface* EcranVictoire = SDL_LoadBMP("data/mewtwoFight.bmp");
            
            SDL_Rect dstEcranVictoire;
            
            dstEcranVictoire.w = 50;
            
            dstEcranVictoire.h = 50;
            
			SDL_Texture* tex_EcranVictoire = SDL_CreateTextureFromSurface(renderer,EcranVictoire);

			SDL_RenderCopy(renderer, tex_EcranVictoire, NULL, &dstEcranVictoire);
			
			 SDL_RenderPresent(renderer);

		}


        switch(event.type)
            {
                case SDL_QUIT:
                    quit = 1;
                    break;

                case SDL_MOUSEBUTTONUP:
                    if(/*piece >= 1 &&*/event.motion.y > 370 && event.motion.x > 100 && event.motion.y < 410 && event.motion.x < 210)
                    {
                        deplacePerso(renderer,posPerso, "down",carte,NumCarte);
                        //piece -=1;
                        joueur_actuel.acheterObjet("Potion",1);
                    }
                    if(/*piece >= 3 &&*/event.motion.y > 370 && event.motion.x > 255 && event.motion.y < 410 && event.motion.x < 365)
                    {
                        deplacePerso(renderer,posPerso, "down",carte,NumCarte);
                        //piece -=3;
                        joueur_actuel.acheterObjet("VitessePlus",3);

                    }
                    if(/*piece >= 5 &&*/event.motion.y > 370 && event.motion.x > 410 && event.motion.y < 410 && event.motion.x < 520)
                    {
                        deplacePerso(renderer,posPerso, "down",carte,NumCarte);
                        //piece -=5;
                        joueur_actuel.acheterObjet("Force", 5);

                    }
                    break;
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_SPACE:
                            if(PeutInteragir(carte,posPerso) != -1) // -1 siginifie qu'aucune interaction n'est possible
                            {
                                TraiteInteraction(PeutInteragir(carte,posPerso), renderer, nbBossBattu);
                            }
                            break;
                        case SDLK_DOWN:
                            if(Verif_Collision(posPerso.x, posPerso.y + 25, carte, NumCarte))
                            {
                                break;
                            }
                            else
                            {
                                posPerso.y += 25;
                                verifPiece(posPerso.x,posPerso.y,carte);
                                deplacePerso(renderer,posPerso, "down",carte,NumCarte);
                            }
                            break;
                        case SDLK_UP:
                            if(Verif_Collision(posPerso.x, posPerso.y - 25, carte, NumCarte))
                            {
                                break;
                            }
                            else
                            {
                                posPerso.y -= 25;
                                verifPiece(posPerso.x,posPerso.y,carte);
                                deplacePerso(renderer,posPerso, "up",carte,NumCarte);
                            }
                            break;
                        case SDLK_RIGHT:
                            if(Verif_Collision(posPerso.x + 25, posPerso.y, carte, NumCarte))
                            {
                                break;
                            }
                            else
                            {
                                posPerso.x += 25;
                                verifPiece(posPerso.x,posPerso.y,carte);
                                deplacePerso(renderer,posPerso, "right",carte,NumCarte);
                            }

                            break;
                        case SDLK_LEFT:
                            if(Verif_Collision(posPerso.x -25, posPerso.y , carte, NumCarte))
                            {
                                break;
                            }
                            else
                            {
                                posPerso.x -= 25;
                                verifPiece(posPerso.x,posPerso.y,carte);
                                deplacePerso(renderer,posPerso, "left",carte,NumCarte);
                            }
                            break;

                        default:
                            break;
                    }

                default:
                    break;

            }
            
       }
    }

    // charger texture
    SDL_Texture *Map::loadTexture(char * filename, SDL_Renderer * ren)
    { 
   SDL_Texture *tex = NULL;
    SDL_Surface *pic = NULL;
    pic = SDL_LoadBMP(filename);

    if (pic == NULL)
    {
        fprintf(stderr,"Échec lors du chargement de l'image (%s)\n",SDL_GetError());
        return NULL;
    }

    tex = SDL_CreateTextureFromSurface(ren, pic);
    SDL_FreeSurface(pic);

    if (tex == NULL)
    {
        fprintf(stderr,"Échec lors du chargement de l'image (%s)\n",SDL_GetError());
    }

    return tex;
    }


// GESTION DE LA MAP

    // Chargement de la carte 1
void Map::initMap(SDL_Renderer *ren, int carte[21][21])
{
   SDL_Surface* pMewtwo= SDL_LoadBMP("data/mewtwo.bmp"); // Cree le sprite de Mewtwo

    SDL_SetColorKey(pMewtwo, SDL_TRUE, SDL_MapRGB(pMewtwo->format, 255, 255, 255));

     SDL_Rect dst_MewTwo;

    SDL_Texture* tex_MewTwo = SDL_CreateTextureFromSurface(ren,pMewtwo);

     SDL_QueryTexture(tex_MewTwo, NULL, NULL, &dst_MewTwo.w, &dst_MewTwo.h);

     dst_MewTwo.x = 183;
     dst_MewTwo.y = 62;
     dst_MewTwo.w = 65;
     dst_MewTwo.h = 65;

     SDL_Surface* pDonkey= SDL_LoadBMP("data/donkey.bmp"); // Cree le sprite de Donkey Kong

    SDL_SetColorKey(pDonkey, SDL_TRUE, SDL_MapRGB(pDonkey->format, 0, 255, 255));

    SDL_Rect dst_Donkey;

    SDL_Texture* tex_Donkey = SDL_CreateTextureFromSurface(ren,pDonkey);

     SDL_QueryTexture(tex_Donkey, NULL, NULL, &dst_Donkey.w, &dst_Donkey.h);

     dst_Donkey.x = 16;
     dst_Donkey.y = 0;
     dst_Donkey.w = 50;
     dst_Donkey.h = 50;

    SDL_Surface* pMedusa= SDL_LoadBMP("data/medusa.bmp"); // Cree le sprite de Medusa

    SDL_SetColorKey(pMedusa, SDL_TRUE, SDL_MapRGB(pMedusa->format, 255, 255, 255));

    SDL_Rect dst_Medusa;

    SDL_Texture* tex_Medusa = SDL_CreateTextureFromSurface(ren,pMedusa);

     SDL_QueryTexture(tex_Medusa, NULL, NULL, &dst_Medusa.w, &dst_Medusa.h);

     dst_Medusa.x = 400;
     dst_Medusa.y = 330;
     dst_Medusa.w = 50;
     dst_Medusa.h = 50;

      SDL_Surface* pShop = SDL_LoadBMP("data/shop.bmp"); // Cree le sprite du magasin

    SDL_SetColorKey(pShop, SDL_TRUE, SDL_MapRGB(pShop->format, 255, 255, 255));

     SDL_Rect dst_Shop;

    SDL_Texture* tex_Shop = SDL_CreateTextureFromSurface(ren,pShop);

     SDL_QueryTexture(tex_Shop, NULL, NULL, &dst_Shop.w, &dst_Shop.h);

     dst_Shop.x = 400;
     dst_Shop.y = 20;
     dst_Shop.w = 100;
     dst_Shop.h = 140;

      SDL_Surface* pBush= SDL_LoadBMP("data/bush.bmp"); // Cree le sprite de buisson

    SDL_SetColorKey(pBush, SDL_TRUE, SDL_MapRGB(pBush->format, 0, 255, 255));

    SDL_Rect dst_Bush;

    SDL_Texture* tex_Bush = SDL_CreateTextureFromSurface(ren,pBush);

     SDL_QueryTexture(tex_Bush, NULL, NULL, &dst_Bush.w, &dst_Bush.h);

     dst_Bush.w = 35;
     dst_Bush.h = 25;

     SDL_Surface* pBuche= SDL_LoadBMP("data/buche.bmp"); // Cree le sprite de buisson

    SDL_SetColorKey(pBuche, SDL_TRUE, SDL_MapRGB(pBuche->format, 255, 255, 255));

    SDL_Rect dst_Buche;

    SDL_Texture* tex_Buche = SDL_CreateTextureFromSurface(ren,pBuche);

     SDL_QueryTexture(tex_Buche, NULL, NULL, &dst_Bush.w, &dst_Buche.h);

     dst_Buche.w = 15;
     dst_Buche.h = 75;
     dst_Buche.x = 404;
     dst_Buche.y = 22;

     SDL_Surface* pFeu= SDL_LoadBMP("data/feu.bmp"); // Cree le sprite de buisson

    SDL_SetColorKey(pFeu, SDL_TRUE, SDL_MapRGB(pFeu->format, 255, 255, 255));

    SDL_Rect dst_Feu;

    SDL_Texture* tex_Feu = SDL_CreateTextureFromSurface(ren,pFeu);

     SDL_QueryTexture(tex_Feu, NULL, NULL, &dst_Feu.w, &dst_Feu.h);

     dst_Feu.w = 40;
     dst_Feu.h = 40;
     dst_Feu.x = 455;
     dst_Feu.y = 44;

     SDL_Surface* pLac = SDL_LoadBMP("data/lake.bmp"); // Cree le sprite de buisson

    SDL_SetColorKey(pLac, SDL_TRUE, SDL_MapRGB(pLac->format, 255, 255, 255));

    SDL_Rect dst_Lac;

    SDL_Texture* tex_Lac = SDL_CreateTextureFromSurface(ren,pLac);

     SDL_QueryTexture(tex_Lac, NULL, NULL, &dst_Lac.w, &dst_Lac.h);

     dst_Lac.w = 150;
     dst_Lac.h = 100;
     dst_Lac.x = 350;
     dst_Lac.y = 310;



    SDL_Surface* pRoche= SDL_LoadBMP("data/stone.bmp");

    SDL_SetColorKey(pRoche, SDL_TRUE, SDL_MapRGB(pRoche->format, 255, 255, 255)); // supprime le background des images rochers
   // SDL_SetColorKey(pRoche, SDL_TRUE, SDL_MapRGB(pRoche->format, 162, 162, 162)); // supprime le background des images rochers

     SDL_Rect dst;

    SDL_Texture* tex_Roche = SDL_CreateTextureFromSurface(ren,pRoche);

     SDL_QueryTexture(tex_Roche, NULL, NULL, &dst.w, &dst.h);

     SDL_Surface* pPiece = SDL_LoadBMP("data/piece.bmp");

    SDL_SetColorKey(pPiece, SDL_TRUE, SDL_MapRGB(pPiece->format, 255, 255, 255));


    SDL_Texture* tex_Piece = SDL_CreateTextureFromSurface(ren,pPiece);

    SDL_QueryTexture(tex_Piece, NULL, NULL, &dst.w, &dst.h);

     dst.x = (WINDOW_WIDTH - dst.w)*0;
     dst.y = (WINDOW_HEIGHT- dst.h)*0;

     SDL_RenderClear(ren);

     SDL_SetRenderDrawColor(ren, 196, 145, 71, 100); // met la fenetre en blanche

    for(int i=0; i<21; i=i+1)
    {
        for(int j=0; j<21; j=j+1)
        {
            dst.x = 25*i  ;
            dst.y = 25*j ;

            switch(carte[i][j]){
                case 0:
                        SDL_RenderCopy(ren, tex_Roche, NULL, &dst);
                        break;

                case 1:
                        SDL_RenderCopy(ren, tex_Bush, NULL, &dst);
                        break;
                case 20:
                        SDL_RenderCopy(ren, tex_Piece, NULL, &dst);
                        break;
                default:
                        break;
            }
        }
    }


    TTF_Font * font = TTF_OpenFont("CaslonBold.ttf", 13);
    SDL_Color White = {255, 255, 255};
        /*

    SDL_Surface* surfaceObjectif1 = TTF_RenderText_Solid(font, "- Battre les", White);
    SDL_Texture* tex_Objectif1 = SDL_CreateTextureFromSurface(ren,surfaceObjectif1);

    SDL_Rect dst_Objectif1;
    dst_Objectif1.x = 525;
    dst_Objectif1.y = 20;
    dst_Objectif1.w = 90;
    dst_Objectif1.h = 30;

    SDL_RenderCopy(ren, tex_Objectif1, NULL, &dst_Objectif1);
  

    SDL_Surface* surfaceObjectif2 = TTF_RenderText_Solid(font, "adversaires", White);
    SDL_Texture* tex_Objectif2 = SDL_CreateTextureFromSurface(ren,surfaceObjectif2);

    SDL_Rect dst_Objectif2;
    dst_Objectif2.x = 525;
    dst_Objectif2.y = 50;
    dst_Objectif2.w = 90;
    dst_Objectif2.h = 30;

    SDL_RenderCopy(ren, tex_Objectif2, NULL, &dst_Objectif2);

    SDL_Surface* surfaceObjectif3 = TTF_RenderText_Solid(font, " - S'enfuir   ", White);
    SDL_Texture* tex_Objectif3 = SDL_CreateTextureFromSurface(ren,surfaceObjectif3);

    SDL_Rect dst_Objectif3;
    dst_Objectif3.x = 525;
    dst_Objectif3.y = 100;
    dst_Objectif3.w = 90;
    dst_Objectif3.h = 30;

    */

    //SDL_RenderCopy(ren, tex_Objectif3, NULL, &dst_Objectif3);

    SDL_RenderCopy(ren, tex_MewTwo, NULL, &dst_MewTwo);
    SDL_RenderCopy(ren, tex_Donkey, NULL, &dst_Donkey);
    SDL_RenderCopy(ren, tex_Feu, NULL, &dst_Feu);
    SDL_RenderCopy(ren, tex_Shop, NULL, &dst_Shop);
    SDL_RenderCopy(ren, tex_Buche, NULL, &dst_Buche);
    SDL_RenderCopy(ren, tex_Lac, NULL, &dst_Lac);
    SDL_RenderCopy(ren, tex_Medusa, NULL, &dst_Medusa);



     SDL_RenderPresent(ren);

     SDL_FreeSurface(pBush);
     SDL_FreeSurface(pRoche);
     SDL_FreeSurface(pPiece);
     SDL_FreeSurface(pDonkey);
     SDL_FreeSurface(pMewtwo);
     SDL_FreeSurface(pFeu);
     SDL_FreeSurface(pShop);
     SDL_FreeSurface(pLac);
     SDL_FreeSurface(pBuche);
     SDL_FreeSurface(pMedusa);

}

    // Chargement de la carte 2
void Map::initMap2(SDL_Renderer *ren, int carte[21][21])
{
   SDL_Surface* pBg_Mine= SDL_LoadBMP("data/bg_mine.bmp");

    SDL_SetColorKey(pBg_Mine, SDL_TRUE, SDL_MapRGB(pBg_Mine->format, 255, 255, 255));

    SDL_Rect dst_Bg_Mine;

    dst_Bg_Mine.x = 1;
    dst_Bg_Mine.y = 8;
    dst_Bg_Mine.w = 170;
    dst_Bg_Mine.h = 200;


    SDL_Texture* tex_Bg_Mine = SDL_CreateTextureFromSurface(ren,pBg_Mine);

    SDL_QueryTexture(tex_Bg_Mine, NULL, NULL, &dst_Bg_Mine.w, &dst_Bg_Mine.h);

    SDL_Surface* pGoku = SDL_LoadBMP("data/goku.bmp"); // Cree le sprite de Mewtwo

    SDL_SetColorKey(pGoku, SDL_TRUE, SDL_MapRGB(pGoku->format, 255, 255, 255));

     SDL_Rect dst_Goku;

    SDL_Texture* tex_Goku = SDL_CreateTextureFromSurface(ren,pGoku);

     SDL_QueryTexture(tex_Goku, NULL, NULL, &dst_Goku.w, &dst_Goku.h);

     dst_Goku.x = 290;
     dst_Goku.y = 82;
     dst_Goku.w = 65;
     dst_Goku.h = 65;

     SDL_Surface* pSnake = SDL_LoadBMP("data/snake.bmp"); // Cree le sprite de Snake

    SDL_SetColorKey(pSnake, SDL_TRUE, SDL_MapRGB(pSnake->format, 180, 180, 180));

     SDL_Rect dst_Snake;

    SDL_Texture* tex_Snake = SDL_CreateTextureFromSurface(ren,pSnake);

     SDL_QueryTexture(tex_Snake, NULL, NULL, &dst_Snake.w, &dst_Snake.h);

     dst_Snake.x = 30;
     dst_Snake.y = 448;

    SDL_Surface* pMario = SDL_LoadBMP("data/mario.bmp"); // Cree le sprite de Snake

    SDL_SetColorKey(pMario, SDL_TRUE, SDL_MapRGB(pMario->format, 195, 195, 195));

     SDL_Rect dst_Mario;

    SDL_Texture* tex_Mario = SDL_CreateTextureFromSurface(ren,pMario);

     SDL_QueryTexture(tex_Mario, NULL, NULL, &dst_Mario.w, &dst_Mario.h);

     dst_Mario.x = 30;
     dst_Mario.y = 310;
     dst_Mario.h = 50;
     dst_Mario.w = 30;


    SDL_Surface* pPont = SDL_LoadBMP("data/pont.bmp"); // Cree le sprite de Snake

    SDL_SetColorKey(pPont, SDL_TRUE, SDL_MapRGB(pPont->format, 255, 255, 255));

     SDL_Rect dst_Pont;

    SDL_Texture* tex_Pont = SDL_CreateTextureFromSurface(ren,pPont);

     SDL_QueryTexture(tex_Pont, NULL, NULL, &dst_Pont.w, &dst_Pont.h);

     dst_Pont.x = 125;
     dst_Pont.y = 125;

     SDL_Surface* pShop_2 = SDL_LoadBMP("data/shop_2.bmp"); // Cree le sprite de Snake

    SDL_SetColorKey(pShop_2, SDL_TRUE, SDL_MapRGB(pShop_2->format, 255, 255, 255));

     SDL_Rect dst_Shop_2;

    SDL_Texture* tex_Shop_2 = SDL_CreateTextureFromSurface(ren,pShop_2);

     SDL_QueryTexture(tex_Shop_2, NULL, NULL, &dst_Shop_2.w, &dst_Shop_2.h);

     dst_Shop_2.x = 365;
     dst_Shop_2.y = 300;


     SDL_Surface* pPlateforme_lave = SDL_LoadBMP("data/plateforme_lave.bmp"); // Cree le sprite de Snake

    SDL_SetColorKey(pPlateforme_lave, SDL_TRUE, SDL_MapRGB(pPlateforme_lave->format, 255, 255, 255));

     SDL_Rect dst_Plateforme_lave;

    SDL_Texture* tex_Plateforme_lave = SDL_CreateTextureFromSurface(ren,pPlateforme_lave);

     SDL_QueryTexture(tex_Plateforme_lave, NULL, NULL, &dst_Plateforme_lave.w, &dst_Plateforme_lave.h);

     dst_Plateforme_lave.x = 225;
     dst_Plateforme_lave.y = 110;
     dst_Plateforme_lave.w = 140;
     dst_Plateforme_lave.h = 120;

    SDL_Surface* pLave= SDL_LoadBMP("data/lava.bmp");

    SDL_SetColorKey(pLave, SDL_TRUE, SDL_MapRGB(pLave->format, 255, 255, 255));

    SDL_Rect dst_Lave;

    dst_Lave.x = 150;
    dst_Lave.y = 90;
    dst_Lave.w = 170;
    dst_Lave.h = 200;


    SDL_Texture* tex_Lave = SDL_CreateTextureFromSurface(ren,pLave);

    SDL_QueryTexture(tex_Lave, NULL, NULL, &dst_Lave.w, &dst_Lave.h);

    SDL_Surface* pStone2 = SDL_LoadBMP("data/stone2.bmp");

    SDL_SetColorKey(pStone2, SDL_TRUE, SDL_MapRGB(pStone2->format, 255, 255, 255)); // supprime le background des images rochers

    SDL_Rect dst;

    SDL_Texture* tex_Stone2 = SDL_CreateTextureFromSurface(ren,pStone2);

    SDL_QueryTexture(tex_Stone2, NULL, NULL, &dst.w, &dst.h);

    SDL_Surface* pPiece = SDL_LoadBMP("data/piece.bmp");

    SDL_SetColorKey(pPiece, SDL_TRUE, SDL_MapRGB(pPiece->format, 255, 255, 255));


    SDL_Texture* tex_Piece = SDL_CreateTextureFromSurface(ren,pPiece);

    SDL_QueryTexture(tex_Piece, NULL, NULL, &dst.w, &dst.h);

    SDL_RenderCopy(ren, tex_Bg_Mine, NULL, &dst_Bg_Mine);

    SDL_SetRenderDrawColor(ren, 67,77, 88, 100); // met la fenetre en gris foncé

    for(int i=0; i<21; i=i+1)
    {
        for(int j=0; j<21; j=j+1)
        {
            dst.x = 25*i ;
            dst.y = 25*j ;

            switch(carte[i][j]){
                case 10:
                        SDL_RenderCopy(ren, tex_Stone2, NULL, &dst);
                        break;
                case 20:
                        SDL_RenderCopy(ren, tex_Piece, NULL, &dst);
                        break;
                default:
                        break;
            }
        }
    }
    /*
    TTF_Font * font = TTF_OpenFont("CaslonBold.ttf", 13);
    SDL_Color White = {255, 255, 255};
    SDL_Surface* surfaceObjectif1 = TTF_RenderText_Solid(font, "- Battre les", White);
    SDL_Texture* tex_Objectif1 = SDL_CreateTextureFromSurface(ren,surfaceObjectif1);

    SDL_Rect dst_Objectif1;
    dst_Objectif1.x = 525;
    dst_Objectif1.y = 20;
    dst_Objectif1.w = 90;
    dst_Objectif1.h = 30;

    SDL_RenderCopy(ren, tex_Objectif1, NULL, &dst_Objectif1);

    SDL_Surface* surfaceObjectif2 = TTF_RenderText_Solid(font, "adversaires", White);
    SDL_Texture* tex_Objectif2 = SDL_CreateTextureFromSurface(ren,surfaceObjectif2);

    SDL_Rect dst_Objectif2;
    dst_Objectif2.x = 525;
    dst_Objectif2.y = 50;
    dst_Objectif2.w = 90;
    dst_Objectif2.h = 30;

    SDL_RenderCopy(ren, tex_Objectif2, NULL, &dst_Objectif2);

    SDL_Surface* surfaceObjectif3 = TTF_RenderText_Solid(font, " - S'enfuir   ", White);
    SDL_Texture* tex_Objectif3 = SDL_CreateTextureFromSurface(ren,surfaceObjectif3);

    SDL_Rect dst_Objectif3;
    dst_Objectif3.x = 525;
    dst_Objectif3.y = 100;
    dst_Objectif3.w = 90;
    dst_Objectif3.h = 30;

    SDL_RenderCopy(ren, tex_Objectif3, NULL, &dst_Objectif3);

    */

    SDL_RenderCopy(ren, tex_Lave, NULL, &dst_Lave);
    SDL_RenderCopy(ren, tex_Shop_2, NULL, &dst_Shop_2);
    SDL_RenderCopy(ren, tex_Plateforme_lave, NULL, &dst_Plateforme_lave);
    SDL_RenderCopy(ren, tex_Pont, NULL, &dst_Pont);
    SDL_RenderCopy(ren, tex_Goku, NULL, &dst_Goku);
    SDL_RenderCopy(ren, tex_Snake, NULL, &dst_Snake);
    SDL_RenderCopy(ren, tex_Mario, NULL, &dst_Mario);

    SDL_RenderPresent(ren);

    SDL_FreeSurface(pShop_2);
    SDL_FreeSurface(pGoku);
    SDL_FreeSurface(pPiece);
    SDL_FreeSurface(pSnake);
    SDL_FreeSurface(pMario);
    SDL_FreeSurface(pPont);
    SDL_FreeSurface(pLave);
    SDL_FreeSurface(pPlateforme_lave);
    SDL_FreeSurface(pStone2);

}

    // Chargement de la carte 3
void Map::initMap3(SDL_Renderer *ren, int carte[21][21])
{
     SDL_Surface* pBlue_falcon= SDL_LoadBMP("data/blue_falcon.bmp");

    SDL_SetColorKey(pBlue_falcon, SDL_TRUE, SDL_MapRGB(pBlue_falcon->format, 255, 255, 255));

    SDL_Rect dst_Blue_falcon;

    dst_Blue_falcon.x = 350;
    dst_Blue_falcon.y = 30;


    SDL_Texture* tex_Blue_falcon = SDL_CreateTextureFromSurface(ren,pBlue_falcon);

    SDL_QueryTexture(tex_Blue_falcon, NULL, NULL, &dst_Blue_falcon.w, &dst_Blue_falcon.h);

    SDL_Surface* pFalcon = SDL_LoadBMP("data/falcon.bmp"); // Cree le sprite de Mewtwo

    SDL_SetColorKey(pFalcon, SDL_TRUE, SDL_MapRGB(pFalcon->format, 255, 255, 255));

     SDL_Rect dst_Falcon;

    SDL_Texture* tex_Falcon = SDL_CreateTextureFromSurface(ren,pFalcon);

     SDL_QueryTexture(tex_Falcon, NULL, NULL, &dst_Falcon.w, &dst_Falcon.h);

     dst_Falcon.x = 450;
     dst_Falcon.y = 90;

     SDL_Surface* pMegaman = SDL_LoadBMP("data/megaman.bmp"); // Cree le sprite de Megaman

     SDL_SetColorKey(pMegaman, SDL_TRUE, SDL_MapRGB(pMegaman->format, 255, 255, 255));

     SDL_Rect dst_Megaman;

     SDL_Texture* tex_Megaman = SDL_CreateTextureFromSurface(ren,pMegaman);

     SDL_QueryTexture(tex_Megaman, NULL, NULL, &dst_Megaman.w, &dst_Megaman.h);

     dst_Megaman.x = 450;
     dst_Megaman.y = 400;
     dst_Megaman.w = 40;
     dst_Megaman.h = 60;

    SDL_Surface* pRyu = SDL_LoadBMP("data/ryu.bmp"); // Cree le sprite de Snake

    SDL_SetColorKey(pRyu, SDL_TRUE, SDL_MapRGB(pRyu->format, 255, 255, 255));

     SDL_Rect dst_Ryu;

    SDL_Texture* tex_Ryu = SDL_CreateTextureFromSurface(ren,pRyu);

     SDL_QueryTexture(tex_Ryu, NULL, NULL, &dst_Ryu.w, &dst_Ryu.h);

     dst_Ryu.x = 50;
     dst_Ryu.y = 25;
     dst_Ryu.h = 65;
     dst_Ryu.w = 40;

     SDL_Surface* pShop_3 = SDL_LoadBMP("data/shop_3.bmp"); // Cree le sprite de Snake

    SDL_SetColorKey(pShop_3, SDL_TRUE, SDL_MapRGB(pShop_3->format, 255, 255, 255));

     SDL_Rect dst_Shop_3;

    SDL_Texture* tex_Shop_3 = SDL_CreateTextureFromSurface(ren,pShop_3);

     SDL_QueryTexture(tex_Shop_3, NULL, NULL, &dst_Shop_3.w, &dst_Shop_3.h);

     dst_Shop_3.x = 20;
     dst_Shop_3.y = 300;

    SDL_Surface* pDojo = SDL_LoadBMP("data/dojo.bmp");
    SDL_Rect dst_Dojo;

    dst_Dojo.x = 30;
    dst_Dojo.y = 20;

    SDL_Texture* tex_Dojo = SDL_CreateTextureFromSurface(ren,pDojo);

    SDL_QueryTexture(tex_Dojo, NULL, NULL, &dst_Dojo.w, &dst_Dojo.h);

    SDL_Surface* pHerbe = SDL_LoadBMP("data/hebre.bmp");
    SDL_Rect dst_Herbe;

    dst_Herbe.x = -5;
    dst_Herbe.y = -15;

    SDL_Texture* tex_Herbe = SDL_CreateTextureFromSurface(ren,pHerbe);

    SDL_QueryTexture(tex_Herbe, NULL, NULL, &dst_Herbe.w, &dst_Herbe.h);
        SDL_RenderCopy(ren, tex_Herbe, NULL, &dst_Herbe);




    SDL_Surface* pStone2 = SDL_LoadBMP("data/stone2.bmp");

    SDL_SetColorKey(pStone2, SDL_TRUE, SDL_MapRGB(pStone2->format, 255, 255, 255)); // supprime le background des images rochers

    SDL_Rect dst;

    SDL_Texture* tex_Stone2 = SDL_CreateTextureFromSurface(ren,pStone2);

    SDL_QueryTexture(tex_Stone2, NULL, NULL, &dst.w, &dst.h);

    SDL_Surface* pPiece = SDL_LoadBMP("data/piece.bmp");

    SDL_SetColorKey(pPiece, SDL_TRUE, SDL_MapRGB(pPiece->format, 255, 255, 255));


    SDL_Texture* tex_Piece = SDL_CreateTextureFromSurface(ren,pPiece);

    SDL_QueryTexture(tex_Piece, NULL, NULL, &dst.w, &dst.h);

    SDL_RenderCopy(ren, tex_Blue_falcon, NULL, &dst_Blue_falcon);

    SDL_SetRenderDrawColor(ren, 67,77, 88, 100); // met la fenetre en gris foncé

    SDL_RenderCopy(ren, tex_Dojo, NULL, &dst_Dojo);

    for(int i=0; i<21; i=i+1)
    {
        for(int j=0; j<21; j=j+1)
        {
            dst.x = 25*i ;
            dst.y = 25*j ;

            switch(carte[i][j]){
                case 10:
                        SDL_RenderCopy(ren, tex_Stone2, NULL, &dst);
                        break;
                case 20:
                        SDL_RenderCopy(ren, tex_Piece, NULL, &dst);
                        break;
                default:
                        break;
            }
        }
    }

    /*
    TTF_Font * font = TTF_OpenFont("CaslonBold.ttf", 13);
    SDL_Color White = {255, 255, 255};
    SDL_Surface* surfaceObjectif1 = TTF_RenderText_Solid(font, "- Battre les", White);
    SDL_Texture* tex_Objectif1 = SDL_CreateTextureFromSurface(ren,surfaceObjectif1);

    SDL_Rect dst_Objectif1;
    dst_Objectif1.x = 525;
    dst_Objectif1.y = 20;
    dst_Objectif1.w = 90;
    dst_Objectif1.h = 30;

    SDL_RenderCopy(ren, tex_Objectif1, NULL, &dst_Objectif1);

    SDL_Surface* surfaceObjectif2 = TTF_RenderText_Solid(font, "adversaires", White);
    SDL_Texture* tex_Objectif2 = SDL_CreateTextureFromSurface(ren,surfaceObjectif2);

    SDL_Rect dst_Objectif2;
    dst_Objectif2.x = 525;
    dst_Objectif2.y = 50;
    dst_Objectif2.w = 90;
    dst_Objectif2.h = 30;

    SDL_RenderCopy(ren, tex_Objectif2, NULL, &dst_Objectif2);

    SDL_Surface* surfaceObjectif3 = TTF_RenderText_Solid(font, " - S'enfuir   ", White);
    SDL_Texture* tex_Objectif3 = SDL_CreateTextureFromSurface(ren,surfaceObjectif3);

    SDL_Rect dst_Objectif3;
    dst_Objectif3.x = 525;
    dst_Objectif3.y = 100;
    dst_Objectif3.w = 90;
    dst_Objectif3.h = 30;

    SDL_RenderCopy(ren, tex_Objectif3, NULL, &dst_Objectif3);

    */

    SDL_RenderCopy(ren, tex_Shop_3, NULL, &dst_Shop_3);
    SDL_RenderCopy(ren, tex_Falcon, NULL, &dst_Falcon);
    SDL_RenderCopy(ren, tex_Megaman, NULL, &dst_Megaman);
    SDL_RenderCopy(ren, tex_Ryu, NULL, &dst_Ryu);
    

    SDL_RenderPresent(ren);

    SDL_FreeSurface(pShop_3);
    SDL_FreeSurface(pFalcon);
    SDL_FreeSurface(pPiece);
    SDL_FreeSurface(pMegaman);
    SDL_FreeSurface(pRyu);
    SDL_FreeSurface(pDojo);
    SDL_FreeSurface(pBlue_falcon);
    SDL_FreeSurface(pStone2);



}

    // chargement du personnage
    void Map::initPerso(SDL_Renderer *ren, SDL_Rect &posPerso, SDL_Texture* tex_perso, SDL_Surface * pSprite)
    {
     SDL_SetColorKey(pSprite, SDL_TRUE, SDL_MapRGB(pSprite->format, 0, 0, 255));


     SDL_RenderCopy(ren, tex_perso, NULL, &posPerso);

         SDL_RenderPresent(ren);
    }

    // les endroits ou il y a une interaction
    int Map::PeutInteragir (int carte[21][21], SDL_Rect &posPerso)
    { 
    //INTERACTION MAP 1
    if(carte[(posPerso.x/25)+1][(posPerso.y/25)] == 2)
    {
        return 1;
    }
    if(carte[(posPerso.x/25)-1][(posPerso.y/25)] == 2)
    {
        return 1;
    }
    if(carte[(posPerso.x/25)][(posPerso.y/25)+1] == 2)
    {
        return 1;
    }
    if(carte[(posPerso.x/25)][(posPerso.y/25)-1] == 2)
    {
        return 1;
    }
    if(carte[(posPerso.x/25)+1][(posPerso.y/25)] == 3)
    {
        return 2;
    }
    if(carte[(posPerso.x/25)-1][(posPerso.y/25)] == 3)
    {
        return 2;
    }
    if(carte[(posPerso.x/25)][(posPerso.y/25)+1] == 3)
    {
        return 2;
    }
    if(carte[(posPerso.x/25)][(posPerso.y/25)-1] == 3)
    {
        return 2;
    }
     if(carte[(posPerso.x/25)+1][(posPerso.y/25)] == 4)
    {
        return 3;
    }
    if(carte[(posPerso.x/25)-1][(posPerso.y/25)] == 4)
    {
        return 3;
    }
    if(carte[(posPerso.x/25)][(posPerso.y/25)+1] == 4)
    {
        return 3;
    }
    if(carte[(posPerso.x/25)][(posPerso.y/25)-1] == 4)
    {
        return 3;
    }
     if(carte[(posPerso.x/25)+1][(posPerso.y/25)] == 5)
    {
        return 4;
    }
    if(carte[(posPerso.x/25)-1][(posPerso.y/25)] == 5)
    {
        return 4;
    }
    if(carte[(posPerso.x/25)][(posPerso.y/25)+1] == 5)
    {
        return 4;
    }
    if(carte[(posPerso.x/25)][(posPerso.y/25)-1] == 5)
    {
        return 4;
    }
    //INTERACTION MAP 2
    if(carte[(posPerso.x/25)][(posPerso.y/25)-1] == 8)
    {
        return 5;
    }
     if(carte[(posPerso.x/25)+1][(posPerso.y/25)] == 8)
    {
        return 5;
    }
    if(carte[(posPerso.x/25)-1][(posPerso.y/25)] == 8)
    {
        return 5;
    }
    if(carte[(posPerso.x/25)][(posPerso.y/25)+1] == 8)
    {
        return 5;
    }
    if(carte[(posPerso.x/25)][(posPerso.y/25)-1] == 8)
    {
        return 5;
    }
    if(carte[(posPerso.x/25)][(posPerso.y/25)-1] == 8)
    {
        return 5;
    }
     if(carte[(posPerso.x/25)+1][(posPerso.y/25)] == 9)
    {
        return 6;
    }
    if(carte[(posPerso.x/25)-1][(posPerso.y/25)] == 9)
    {
        return 6;
    }
    if(carte[(posPerso.x/25)][(posPerso.y/25)+1] == 9)
    {
        return 6;
    }
    if(carte[(posPerso.x/25)][(posPerso.y/25)-1] == 9)
    {
        return 6;
    }

    if(carte[(posPerso.x/25)+1][(posPerso.y/25)] == 12)
    {
        return 7;
    }
    if(carte[(posPerso.x/25)-1][(posPerso.y/25)] == 12)
    {
        return 7;
    }
    if(carte[(posPerso.x/25)][(posPerso.y/25)+1] == 12)
    {
        return 7;
    }
    if(carte[(posPerso.x/25)][(posPerso.y/25)-1] == 12)
    {
        return 7;
    }

    if(carte[(posPerso.x/25)+1][(posPerso.y/25)] == 11)
    {
        return 8;
    }
    if(carte[(posPerso.x/25)-1][(posPerso.y/25)] == 11)
    {
        return 8;
    }
    if(carte[(posPerso.x/25)][(posPerso.y/25)+1] == 11)
    {
        return 8;
    }
    if(carte[(posPerso.x/25)][(posPerso.y/25)-1] == 11)
    {
        return 8;
    }
    if(carte[(posPerso.x/25)+1][(posPerso.y/25)] == 14)
    {
        return 9;
    }
    if(carte[(posPerso.x/25)-1][(posPerso.y/25)] == 14)
    {
        return 9;
    }
    if(carte[(posPerso.x/25)][(posPerso.y/25)+1] == 14)
    {
        return 9;
    }
    if(carte[(posPerso.x/25)][(posPerso.y/25)-1] == 14)
    {
        return 9;
    }
    if(carte[(posPerso.x/25)+1][(posPerso.y/25)] == 15)
    {
        return 10;
    }
    if(carte[(posPerso.x/25)-1][(posPerso.y/25)] == 15)
    {
        return 10;
    }
    if(carte[(posPerso.x/25)][(posPerso.y/25)+1] == 15)
    {
        return 10;
    }
    if(carte[(posPerso.x/25)][(posPerso.y/25)-1] == 15)
    {
        return 10;
    }
    if(carte[(posPerso.x/25)+1][(posPerso.y/25)] == 16)
    {
        return 11;
    }
    if(carte[(posPerso.x/25)-1][(posPerso.y/25)] == 16)
    {
        return 11;
    }
    if(carte[(posPerso.x/25)][(posPerso.y/25)+1] == 16)
    {
        return 11;
    }
    if(carte[(posPerso.x/25)][(posPerso.y/25)-1] == 16)
    {
        return 11;
    }
    if(carte[(posPerso.x/25)+1][(posPerso.y/25)] == 13)
    {
        return 12;
    }
    if(carte[(posPerso.x/25)-1][(posPerso.y/25)] == 13)
    {
        return 12;
    }
    if(carte[(posPerso.x/25)][(posPerso.y/25)+1] == 13)
    {
        return 12;
    }
    if(carte[(posPerso.x/25)][(posPerso.y/25)-1] == 13)
    {
        return 12;
    }

    return -1;
    }

    // gestion des personnage
void Map::deplacePerso(SDL_Renderer *ren,SDL_Rect &posPerso, char* direction,int carte[21][21], int numCarte)
{
   SDL_Surface* pSprite = NULL;

    if(direction == "left")
    {
        pSprite = SDL_LoadBMP("data/link_gauche.bmp");
    }
    else if(direction == "up")
    {
        pSprite = SDL_LoadBMP("data/link_haut.bmp");
    }
    else if(direction == "down")
    {
        pSprite = SDL_LoadBMP("data/link_bas.bmp");
    }
    else if(direction == "right")
    {
        pSprite = SDL_LoadBMP("data/link_droite.bmp");
    }
    else
    {
         pSprite = SDL_LoadBMP("data/link_bas.bmp");
    }


    SDL_SetColorKey(pSprite, SDL_TRUE, SDL_MapRGB(pSprite->format, 255, 255, 255));


    SDL_Texture* tex_perso = SDL_CreateTextureFromSurface(ren ,pSprite);
    SDL_QueryTexture(tex_perso, NULL, NULL, &posPerso.w, &posPerso.h);

    switch(numCarte){
        case 1:
            initMap(ren,carte);
            break;
        case 2:
            initMap2(ren,carte);
            break;
         case 3:
            initMap3(ren,carte);
            break;
        default:
            break;
    }
    posPerso.h = 28;
    posPerso.w = 35;
    SDL_RenderCopy(ren, tex_perso, NULL, &posPerso);
/*
    if(PeutInteragir(carte,posPerso)!= -1)
    {
         TTF_Font * font = TTF_OpenFont("CaslonBold.ttf", 50);
         SDL_Color White = {255, 255, 255};
         SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, "Appuyer sur [SPACE_BAR] pour interagir ", White);
         SDL_Texture* tex_Message = SDL_CreateTextureFromSurface(ren,surfaceMessage);

         SDL_Rect dst_Message;
         dst_Message.x = 130;
         dst_Message.y = 520;
         dst_Message.w = 400;
         dst_Message.h = 40;

         SDL_RenderCopy(ren, tex_Message, NULL, &dst_Message);

    }

    */
    SDL_RenderPresent(ren);

}

    // lance le combat
    void Map::lancer_Combat(SDL_Renderer *ren, char* nomPerso, int & nbBossBattu)
    {
     SDL_Surface* pAdversaire;

    SDL_Rect pos_Adversaire;
    pos_Adversaire.x = 50;
    pos_Adversaire.y =  -10;
    pos_Adversaire.w = 0;
    pos_Adversaire.h = 0;

    if(nomPerso == "MewTwo")
    {
        pAdversaire = SDL_LoadBMP("data/mewtwoFight.bmp");
    }
    else if(nomPerso == "DonkeyKong")
    {
        pAdversaire = SDL_LoadBMP("data/DonkeyKong_fight.bmp");
    }
    else if(nomPerso == "Medusa")
    {
        pAdversaire = SDL_LoadBMP("data/Medusa_fight.bmp");
        pos_Adversaire.x = 0;
        pos_Adversaire.y = 0;
    }
    else if(nomPerso == "Goku")
    {
        pAdversaire = SDL_LoadBMP("data/Goku_fight.bmp");
        pos_Adversaire.x = 0;
        pos_Adversaire.y = 0;
    }
    else if(nomPerso == "Snake")
    {
        pAdversaire = SDL_LoadBMP("data/Snake_fight.bmp");
        pos_Adversaire.x = 0;
        pos_Adversaire.y = -10;
    }
    else if(nomPerso == "Mario")
    {
        pAdversaire = SDL_LoadBMP("data/Mario_fight.bmp");
        pos_Adversaire.x = 150;
        pos_Adversaire.y = 50;
    }
     else if(nomPerso == "Falcon")
    {
        pAdversaire = SDL_LoadBMP("data/Falcon_fight.bmp");
    }
    else if(nomPerso == "Megaman")
    {
        pAdversaire = SDL_LoadBMP("data/Megaman_fight.bmp");
    }
    else if(nomPerso == "Ryu")
    {
        pAdversaire = SDL_LoadBMP("data/Ryu_fight.bmp");
        pos_Adversaire.x = 200;
        pos_Adversaire.y = 75;
    }

    SDL_SetColorKey(pAdversaire, SDL_TRUE, SDL_MapRGB(pAdversaire->format, 255, 255, 255));



    SDL_Texture* tex_Adversaire = SDL_CreateTextureFromSurface(ren,pAdversaire);
    SDL_QueryTexture(tex_Adversaire, NULL, NULL, &pos_Adversaire.w, &pos_Adversaire.h);
    SDL_RenderCopy(ren, tex_Adversaire, NULL, &pos_Adversaire);
    SDL_RenderPresent(ren);
    
    nbBossBattu +=1;
    }

    // ouvrir un magasin 
    void Map::Ouvrir_Magasin(SDL_Renderer *ren)
    { 
    SDL_Surface* pShop_Open;
    pShop_Open = SDL_LoadBMP("data/shop_open.bmp");

    SDL_SetColorKey(pShop_Open, SDL_TRUE, SDL_MapRGB(pShop_Open->format, 127, 127, 127));

    SDL_Rect pos_Shop_Open;

    pos_Shop_Open.x = 40;
    pos_Shop_Open.y = 80;
    pos_Shop_Open.w = 0;
    pos_Shop_Open.h = 0;

    SDL_Texture* tex_Shop_Open = SDL_CreateTextureFromSurface(ren,pShop_Open);
    SDL_QueryTexture(tex_Shop_Open, NULL, NULL, &pos_Shop_Open.w, &pos_Shop_Open.h);

    /*
    TTF_Font * font = TTF_OpenFont("CaslonBold.ttf", 13);
    SDL_Color White = {255, 255, 255};
    /////////////////////////////char str[32];
    /////////////////////////////snprintf(str, sizeof (str), "%d", joueur_actuel.getPiece());
    /////////////////////////////    string  nbpiece = joueur_actuel.getPiece());
    ///////////////////////////// string tmp_piece = nbpiece.c_str();
    ///////////////////////////// char * piece = (char *) tmp_piece.c_str();
    
    SDL_Surface* surfaceNbPiece= TTF_RenderText_Solid(font, "5", White);
    SDL_Texture* tex_NbPiece = SDL_CreateTextureFromSurface(ren,surfaceNbPiece);

    SDL_Rect dst_NbPiece;
    dst_NbPiece.x = 350;
    dst_NbPiece.y = 20;
    dst_NbPiece.w = 90;
    dst_NbPiece.h = 90;

    SDL_RenderCopy(ren, tex_NbPiece, NULL, &dst_NbPiece);

    */

    SDL_RenderCopy(ren, tex_Shop_Open, NULL, &pos_Shop_Open);
    SDL_RenderPresent(ren);
    }

    // traiter l'interaction
    void Map::TraiteInteraction(int interaction, SDL_Renderer *renderer, int & nbBossBattu)
    { 
    switch(interaction){
    case 1:
        lancer_Combat(renderer, "MewTwo", nbBossBattu);
        break;
    case 2:
        lancer_Combat(renderer, "DonkeyKong", nbBossBattu);
        break;
    case 3:
        lancer_Combat(renderer, "Medusa", nbBossBattu);
        break;
    case 4:
        Ouvrir_Magasin(renderer);
        break;
    case 5:
        lancer_Combat(renderer, "Goku", nbBossBattu);
        break;
    case 6:
        lancer_Combat(renderer, "Snake", nbBossBattu);
        break;
    case 7:
        lancer_Combat(renderer, "Mario", nbBossBattu);
        break;
    case 8:
        Ouvrir_Magasin(renderer);
        break;
    case 9:
        lancer_Combat(renderer, "Falcon", nbBossBattu);
        break;
    case 10:
        lancer_Combat(renderer, "Megaman", nbBossBattu);
        break;
    case 11:
        lancer_Combat(renderer, "Ryu", nbBossBattu);
        break;
    case 12:
        Ouvrir_Magasin(renderer);
        break;
    default:
        break;
    }
    }

    // Charge la carte actuelle
int chargerCarte(int carte[21][21], int NumCarte)
{
    FILE* fichier = NULL;
    char ligneFichier[21 * 21 + 1] = {};
    int i = 0, j = 0;
	switch(NumCarte)
	{
		case 1:
			fichier = fopen("data/carte1.lvl", "r");
			if (fichier == NULL)
			return 0;
			break;	
			
		case 2:
			fichier = fopen("data/carte2.lvl", "r");
			if (fichier == NULL)
			return 0;
			break;	
		case 3:
			fichier = fopen("data/carte3.lvl", "r");
			if (fichier == NULL)
			return 0;
			break;	
	}
 
    fgets(ligneFichier, 21 * 21 + 1, fichier);
 
    for (i = 0 ; i < 21 ; i++)
    {
        for (j = 0 ; j < 21 ; j++)
        {
            switch (ligneFichier[(i * 21) + j])
            {
                case '0':
                    carte[i][j] = 0;
                    break;
                case '1':
                    carte[i][j] = 1;
                    break;
                case '2':
                    carte[i][j] = 2;
                    break;
                case '3':
                    carte[i][j] = 3;
                    break;
                case '4':
                    carte[i][j] = 4;
                    break;
                case '5':
                    carte[i][j] = 5;
                    break;
				case '6':
                    carte[i][j] = 6;
                    break;
                case '7':
                    carte[i][j] = 7;
                    break;
                case '8':
                    carte[i][j] = 8;
                    break;
                case '9':
                    carte[i][j] = 9;
                    break;
                case 'a':
                    carte[i][j] = 20;
                    break;                
                case 'b':
                    carte[i][j] = 10;
                    break;
                case 'c':
                    carte[i][j] = 11;
                    break;
                case 'd':
                    carte[i][j] = 12;
                    break;
                case 'e':
                    carte[i][j] = -1;
                    break;
                case 'f':
                    carte[i][j] = 13;
                    break;
                case 'g':
                    carte[i][j] = 14;
                    break;
                case 'h':
                    carte[i][j] = 15;
                    break;
                case 'i':
                    carte[i][j] = 16;
                    break;
                case 'j':
                    carte[i][j] = 17;
                    break;
 
            }
        }
    }
 
    fclose(fichier);
    return 1;
}

    // verifier les collision
    bool Map::Verif_Collision(int NouvellePositionX, int NouvellePositionY, int carte[21][21], int NumCarte)
    {
    switch(NumCarte){
        case 1:
            if (carte[(NouvellePositionX )/25][(NouvellePositionY)/25] == 0) {return true;}
            if (carte[(NouvellePositionX )/25][(NouvellePositionY)/25] == 2) {return true;}
            if (carte[(NouvellePositionX )/25][(NouvellePositionY)/25] == 3) {return true;}
            if (carte[(NouvellePositionX )/25][(NouvellePositionY)/25] == 4) {return true;}
            if (carte[(NouvellePositionX )/25][(NouvellePositionY)/25] == 5) {return true;}
            if (carte[(NouvellePositionX )/25][(NouvellePositionY)/25] == 6) {return true;}
            break;
        case 2:
            if (carte[(NouvellePositionX )/25][(NouvellePositionY)/25] == 0) {return true;}
            if (carte[(NouvellePositionX )/25][(NouvellePositionY)/25] == 8) {return true;}
            if (carte[(NouvellePositionX )/25][(NouvellePositionY)/25] == 9) {return true;}
            if (carte[(NouvellePositionX )/25][(NouvellePositionY)/25] == 10) {return true;}
            if (carte[(NouvellePositionX )/25][(NouvellePositionY)/25] == 11) {return true;}
            if (carte[(NouvellePositionX )/25][(NouvellePositionY)/25] == 12) {return true;}
            break;
        case 3:
            if (carte[(NouvellePositionX )/25][(NouvellePositionY)/25] == 10) {return true;}
            if (carte[(NouvellePositionX )/25][(NouvellePositionY)/25] == 13) {return true;}
            if (carte[(NouvellePositionX )/25][(NouvellePositionY)/25] == 14) {return true;}
            if (carte[(NouvellePositionX )/25][(NouvellePositionY)/25] == 15) {return true;}
            if (carte[(NouvellePositionX )/25][(NouvellePositionY)/25] == 16) {return true;}
            if (carte[(NouvellePositionX )/25][(NouvellePositionY)/25] == 17) {return true;}

            break;
        default:
            break;
    }

    return false;
    }

    // verifier si on marche sur une piece
    void Map::verifPiece(int NouvellePositionX, int NouvellePositionY, int carte[21][21])
    { 
    if(carte[NouvellePositionX/25][NouvellePositionY/25]==20)
    {
        carte[NouvellePositionX/25][NouvellePositionY/25]=-1;
        joueur_actuel.setPiece(joueur_actuel.getPiece()+1);
    }
    }

void Map::change_carte(int carte[21][21], int NumCarte, int & nbBossBattu ) // Change la carte actuelle
{
	nbBossBattu = 0;
	chargerCarte(carte,NumCarte);
}

    // main affichage
    void Map::mainAffichage(SDL_Renderer * renderer, SDL_Window * window)
    {
    int carte[21][21];
    chargerCarte(carte,1);
    SDL_Surface * picture = NULL;
    
    int nbBossBattu = 0;



     SDL_Rect posPerso;

     posPerso.x = 50;
     posPerso.y = 450;

     int NumCarte = 1;

     initMap(renderer,carte);
     initMap(renderer,carte);
	 deplacePerso(renderer,posPerso, "",carte,NumCarte); // initialise le perso
     deplacePerso(renderer,posPerso, "",carte,NumCarte); // initialise le perso


    pause(renderer,posPerso,carte,NumCarte, nbBossBattu);

    close(window,renderer,picture);


    }
