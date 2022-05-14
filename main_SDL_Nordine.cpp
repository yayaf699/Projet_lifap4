#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>


#define WINDOW_WIDTH 620
#define WINDOW_HEIGHT 580

int init(char name[], SDL_Window *win, SDL_Renderer *ren);
void close(SDL_Window *win, SDL_Renderer *ren, SDL_Surface *pic);
void pause();
void loadPic(SDL_Renderer *ren);
SDL_Texture *loadTexture(char * filename, SDL_Renderer * ren);

//Initialisation de la SDL
int init(char *name, SDL_Window **win, SDL_Renderer **ren)
{

    int success = 1;

    if(SDL_Init(SDL_INIT_EVERYTHING)<0)
    {
        fprintf(stderr,"�chec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        success = 0;
    }
    else{
        *win = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

        if( win == NULL )
        {
            fprintf(stderr,"�chec � la cr�ation de la fen�tre (%s)\n",SDL_GetError());
            success = 0;
        }
        else
        {
            *ren = SDL_CreateRenderer(*win,-1,SDL_RENDERER_ACCELERATED);
            if( ren == NULL )
            {
                fprintf(stderr,"�chec � la cr�ation de la fen�tre (%s)\n",SDL_GetError());
                success = 0;
            }
        }
    }
    TTF_Init();

    return success;
}




//Chargement de la carte
void initMap(SDL_Renderer *ren, int carte[21][21])
{

    SDL_Surface* pMewtwo= SDL_LoadBMP("mewtwo.bmp"); // Cree le sprite de Mewtwo

    SDL_SetColorKey(pMewtwo, SDL_TRUE, SDL_MapRGB(pMewtwo->format, 255, 255, 255));

     SDL_Rect dst_MewTwo;

    SDL_Texture* tex_MewTwo = SDL_CreateTextureFromSurface(ren,pMewtwo);

     SDL_QueryTexture(tex_MewTwo, NULL, NULL, &dst_MewTwo.w, &dst_MewTwo.h);

     dst_MewTwo.x = 183;
     dst_MewTwo.y = 62;
     dst_MewTwo.w = 65;
     dst_MewTwo.h = 65;

     SDL_Surface* pDonkey= SDL_LoadBMP("donkey.bmp"); // Cree le sprite de Donkey Kong

    SDL_SetColorKey(pDonkey, SDL_TRUE, SDL_MapRGB(pDonkey->format, 0, 255, 255));

    SDL_Rect dst_Donkey;

    SDL_Texture* tex_Donkey = SDL_CreateTextureFromSurface(ren,pDonkey);

     SDL_QueryTexture(tex_Donkey, NULL, NULL, &dst_Donkey.w, &dst_Donkey.h);

     dst_Donkey.x = 16;
     dst_Donkey.y = 0;
     dst_Donkey.w = 50;
     dst_Donkey.h = 50;

    SDL_Surface* pMedusa= SDL_LoadBMP("medusa.bmp"); // Cree le sprite de Medusa

    SDL_SetColorKey(pMedusa, SDL_TRUE, SDL_MapRGB(pMedusa->format, 255, 255, 255));

    SDL_Rect dst_Medusa;

    SDL_Texture* tex_Medusa = SDL_CreateTextureFromSurface(ren,pMedusa);

     SDL_QueryTexture(tex_Medusa, NULL, NULL, &dst_Medusa.w, &dst_Medusa.h);

     dst_Medusa.x = 400;
     dst_Medusa.y = 330;
     dst_Medusa.w = 50;
     dst_Medusa.h = 50;

      SDL_Surface* pShop = SDL_LoadBMP("shop.bmp"); // Cree le sprite du magasin

    SDL_SetColorKey(pShop, SDL_TRUE, SDL_MapRGB(pShop->format, 255, 255, 255));

     SDL_Rect dst_Shop;

    SDL_Texture* tex_Shop = SDL_CreateTextureFromSurface(ren,pShop);

     SDL_QueryTexture(tex_Shop, NULL, NULL, &dst_Shop.w, &dst_Shop.h);

     dst_Shop.x = 400;
     dst_Shop.y = 20;
     dst_Shop.w = 100;
     dst_Shop.h = 140;

      SDL_Surface* pBush= SDL_LoadBMP("bush.bmp"); // Cree le sprite de buisson

    SDL_SetColorKey(pBush, SDL_TRUE, SDL_MapRGB(pBush->format, 0, 255, 255));

    SDL_Rect dst_Bush;

    SDL_Texture* tex_Bush = SDL_CreateTextureFromSurface(ren,pBush);

     SDL_QueryTexture(tex_Bush, NULL, NULL, &dst_Bush.w, &dst_Bush.h);

     dst_Bush.w = 35;
     dst_Bush.h = 25;

     SDL_Surface* pBuche= SDL_LoadBMP("buche.bmp"); // Cree le sprite de buisson

    SDL_SetColorKey(pBuche, SDL_TRUE, SDL_MapRGB(pBuche->format, 255, 255, 255));

    SDL_Rect dst_Buche;

    SDL_Texture* tex_Buche = SDL_CreateTextureFromSurface(ren,pBuche);

     SDL_QueryTexture(tex_Buche, NULL, NULL, &dst_Bush.w, &dst_Buche.h);

     dst_Buche.w = 15;
     dst_Buche.h = 75;
     dst_Buche.x = 404;
     dst_Buche.y = 22;

     SDL_Surface* pFeu= SDL_LoadBMP("feu.bmp"); // Cree le sprite de buisson

    SDL_SetColorKey(pFeu, SDL_TRUE, SDL_MapRGB(pFeu->format, 255, 255, 255));

    SDL_Rect dst_Feu;

    SDL_Texture* tex_Feu = SDL_CreateTextureFromSurface(ren,pFeu);

     SDL_QueryTexture(tex_Feu, NULL, NULL, &dst_Feu.w, &dst_Feu.h);

     dst_Feu.w = 40;
     dst_Feu.h = 40;
     dst_Feu.x = 455;
     dst_Feu.y = 44;

     SDL_Surface* pLac = SDL_LoadBMP("lake.bmp"); // Cree le sprite de buisson

    SDL_SetColorKey(pLac, SDL_TRUE, SDL_MapRGB(pLac->format, 255, 255, 255));

    SDL_Rect dst_Lac;

    SDL_Texture* tex_Lac = SDL_CreateTextureFromSurface(ren,pLac);

     SDL_QueryTexture(tex_Lac, NULL, NULL, &dst_Lac.w, &dst_Lac.h);

     dst_Lac.w = 150;
     dst_Lac.h = 100;
     dst_Lac.x = 350;
     dst_Lac.y = 310;

    SDL_Surface* pRoche= SDL_LoadBMP("stone.bmp");

    SDL_SetColorKey(pRoche, SDL_TRUE, SDL_MapRGB(pRoche->format, 255, 255, 255)); // supprime le background des images rochers
   // SDL_SetColorKey(pRoche, SDL_TRUE, SDL_MapRGB(pRoche->format, 162, 162, 162)); // supprime le background des images rochers

     SDL_Rect dst;

    SDL_Texture* tex_Roche = SDL_CreateTextureFromSurface(ren,pRoche);

     SDL_QueryTexture(tex_Roche, NULL, NULL, &dst.w, &dst.h);


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
                default:
                        break;
            }
        }
    }

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
     SDL_FreeSurface(pDonkey);
     SDL_FreeSurface(pMewtwo);
     SDL_FreeSurface(pFeu);
     SDL_FreeSurface(pShop);
     SDL_FreeSurface(pLac);
     SDL_FreeSurface(pBuche);
     SDL_FreeSurface(pMedusa);

}

void initMap2(SDL_Renderer *ren, int carte[21][21])
{
    SDL_Surface* pBg_Mine= SDL_LoadBMP("bg_mine.bmp");

    SDL_SetColorKey(pBg_Mine, SDL_TRUE, SDL_MapRGB(pBg_Mine->format, 255, 255, 255));

    SDL_Rect dst_Bg_Mine;

    dst_Bg_Mine.x = 1;
    dst_Bg_Mine.y = 8;
    dst_Bg_Mine.w = 170;
    dst_Bg_Mine.h = 200;


    SDL_Texture* tex_Bg_Mine = SDL_CreateTextureFromSurface(ren,pBg_Mine);

    SDL_QueryTexture(tex_Bg_Mine, NULL, NULL, &dst_Bg_Mine.w, &dst_Bg_Mine.h);

    SDL_Surface* pGoku = SDL_LoadBMP("goku.bmp"); // Cree le sprite de Mewtwo

    SDL_SetColorKey(pGoku, SDL_TRUE, SDL_MapRGB(pGoku->format, 255, 255, 255));

     SDL_Rect dst_Goku;

    SDL_Texture* tex_Goku = SDL_CreateTextureFromSurface(ren,pGoku);

     SDL_QueryTexture(tex_Goku, NULL, NULL, &dst_Goku.w, &dst_Goku.h);

     dst_Goku.x = 290;
     dst_Goku.y = 82;
     dst_Goku.w = 65;
     dst_Goku.h = 65;

     SDL_Surface* pSnake = SDL_LoadBMP("snake.bmp"); // Cree le sprite de Snake

    SDL_SetColorKey(pSnake, SDL_TRUE, SDL_MapRGB(pSnake->format, 180, 180, 180));

     SDL_Rect dst_Snake;

    SDL_Texture* tex_Snake = SDL_CreateTextureFromSurface(ren,pSnake);

     SDL_QueryTexture(tex_Snake, NULL, NULL, &dst_Snake.w, &dst_Snake.h);

     dst_Snake.x = 30;
     dst_Snake.y = 448;

    SDL_Surface* pMario = SDL_LoadBMP("mario.bmp"); // Cree le sprite de Snake

    SDL_SetColorKey(pMario, SDL_TRUE, SDL_MapRGB(pMario->format, 195, 195, 195));

     SDL_Rect dst_Mario;

    SDL_Texture* tex_Mario = SDL_CreateTextureFromSurface(ren,pMario);

     SDL_QueryTexture(tex_Mario, NULL, NULL, &dst_Mario.w, &dst_Mario.h);

     dst_Mario.x = 30;
     dst_Mario.y = 310;
     dst_Mario.h = 50;
     dst_Mario.w = 30;


    SDL_Surface* pPont = SDL_LoadBMP("pont.bmp"); // Cree le sprite de Snake

    SDL_SetColorKey(pPont, SDL_TRUE, SDL_MapRGB(pPont->format, 255, 255, 255));

     SDL_Rect dst_Pont;

    SDL_Texture* tex_Pont = SDL_CreateTextureFromSurface(ren,pPont);

     SDL_QueryTexture(tex_Pont, NULL, NULL, &dst_Pont.w, &dst_Pont.h);

     dst_Pont.x = 125;
     dst_Pont.y = 125;

     SDL_Surface* pShop_2 = SDL_LoadBMP("shop_5.bmp"); // Cree le sprite de Snake

    SDL_SetColorKey(pShop_2, SDL_TRUE, SDL_MapRGB(pShop_2->format, 255, 255, 255));

     SDL_Rect dst_Shop_2;

    SDL_Texture* tex_Shop_2 = SDL_CreateTextureFromSurface(ren,pShop_2);

     SDL_QueryTexture(tex_Shop_2, NULL, NULL, &dst_Shop_2.w, &dst_Shop_2.h);

     dst_Shop_2.x = 365;
     dst_Shop_2.y = 300;


     SDL_Surface* pPlateforme_lave = SDL_LoadBMP("plateforme_lave.bmp"); // Cree le sprite de Snake

    SDL_SetColorKey(pPlateforme_lave, SDL_TRUE, SDL_MapRGB(pPlateforme_lave->format, 255, 255, 255));

     SDL_Rect dst_Plateforme_lave;

    SDL_Texture* tex_Plateforme_lave = SDL_CreateTextureFromSurface(ren,pPlateforme_lave);

     SDL_QueryTexture(tex_Plateforme_lave, NULL, NULL, &dst_Plateforme_lave.w, &dst_Plateforme_lave.h);

     dst_Plateforme_lave.x = 225;
     dst_Plateforme_lave.y = 110;
     dst_Plateforme_lave.w = 140;
     dst_Plateforme_lave.h = 120;

    SDL_Surface* pLave= SDL_LoadBMP("lava.bmp");

    SDL_SetColorKey(pLave, SDL_TRUE, SDL_MapRGB(pLave->format, 255, 255, 255));

    SDL_Rect dst_Lave;

    dst_Lave.x = 150;
    dst_Lave.y = 90;
    dst_Lave.w = 170;
    dst_Lave.h = 200;


    SDL_Texture* tex_Lave = SDL_CreateTextureFromSurface(ren,pLave);

    SDL_QueryTexture(tex_Lave, NULL, NULL, &dst_Lave.w, &dst_Lave.h);


    SDL_Surface* pStone2 = SDL_LoadBMP("stone2.bmp");

    SDL_SetColorKey(pStone2, SDL_TRUE, SDL_MapRGB(pStone2->format, 255, 255, 255)); // supprime le background des images rochers

    SDL_Rect dst;

    SDL_Texture* tex_Stone2 = SDL_CreateTextureFromSurface(ren,pStone2);

    SDL_QueryTexture(tex_Stone2, NULL, NULL, &dst.w, &dst.h);

    SDL_RenderCopy(ren, tex_Bg_Mine, NULL, &dst_Bg_Mine);

    SDL_SetRenderDrawColor(ren, 67,77, 88, 100); // met la fenetre en gris fonc�

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
                default:
                        break;
            }
        }
    }

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
    SDL_FreeSurface(pSnake);
    SDL_FreeSurface(pMario);
    SDL_FreeSurface(pPont);
    SDL_FreeSurface(pLave);
    SDL_FreeSurface(pPlateforme_lave);
    SDL_FreeSurface(pStone2);


}

void initMap3(SDL_Renderer *ren, int carte[21][21])
{
    SDL_Surface* pBlue_falcon= SDL_LoadBMP("blue_falcon.bmp");

    SDL_SetColorKey(pBlue_falcon, SDL_TRUE, SDL_MapRGB(pBlue_falcon->format, 255, 255, 255));

    SDL_Rect dst_Blue_falcon;

    dst_Blue_falcon.x = 350;
    dst_Blue_falcon.y = 30;


    SDL_Texture* tex_Blue_falcon = SDL_CreateTextureFromSurface(ren,pBlue_falcon);

    SDL_QueryTexture(tex_Blue_falcon, NULL, NULL, &dst_Blue_falcon.w, &dst_Blue_falcon.h);

    SDL_Surface* pFalcon = SDL_LoadBMP("falcon.bmp"); // Cree le sprite de Mewtwo

    SDL_SetColorKey(pFalcon, SDL_TRUE, SDL_MapRGB(pFalcon->format, 255, 255, 255));

     SDL_Rect dst_Falcon;

    SDL_Texture* tex_Falcon = SDL_CreateTextureFromSurface(ren,pFalcon);

     SDL_QueryTexture(tex_Falcon, NULL, NULL, &dst_Falcon.w, &dst_Falcon.h);

     dst_Falcon.x = 450;
     dst_Falcon.y = 90;

     SDL_Surface* pMegaman = SDL_LoadBMP("megaman.bmp"); // Cree le sprite de Megaman

     SDL_SetColorKey(pMegaman, SDL_TRUE, SDL_MapRGB(pMegaman->format, 255, 255, 255));

     SDL_Rect dst_Megaman;

     SDL_Texture* tex_Megaman = SDL_CreateTextureFromSurface(ren,pMegaman);

     SDL_QueryTexture(tex_Megaman, NULL, NULL, &dst_Megaman.w, &dst_Megaman.h);

     dst_Megaman.x = 450;
     dst_Megaman.y = 400;
     dst_Megaman.w = 40;
     dst_Megaman.h = 60;

    SDL_Surface* pRyu = SDL_LoadBMP("ryu.bmp"); // Cree le sprite de Snake

    SDL_SetColorKey(pRyu, SDL_TRUE, SDL_MapRGB(pRyu->format, 255, 255, 255));

     SDL_Rect dst_Ryu;

    SDL_Texture* tex_Ryu = SDL_CreateTextureFromSurface(ren,pRyu);

     SDL_QueryTexture(tex_Ryu, NULL, NULL, &dst_Ryu.w, &dst_Ryu.h);

     dst_Ryu.x = 50;
     dst_Ryu.y = 25;
     dst_Ryu.h = 65;
     dst_Ryu.w = 40;

     SDL_Surface* pShop_3 = SDL_LoadBMP("shop_3.bmp"); // Cree le sprite de Snake

    SDL_SetColorKey(pShop_3, SDL_TRUE, SDL_MapRGB(pShop_3->format, 255, 255, 255));

     SDL_Rect dst_Shop_3;

    SDL_Texture* tex_Shop_3 = SDL_CreateTextureFromSurface(ren,pShop_3);

     SDL_QueryTexture(tex_Shop_3, NULL, NULL, &dst_Shop_3.w, &dst_Shop_3.h);

     dst_Shop_3.x = 20;
     dst_Shop_3.y = 300;

    SDL_Surface* pDojo = SDL_LoadBMP("dojo.bmp");
    SDL_Rect dst_Dojo;

    dst_Dojo.x = 30;
    dst_Dojo.y = 20;

    SDL_Texture* tex_Dojo = SDL_CreateTextureFromSurface(ren,pDojo);

    SDL_QueryTexture(tex_Dojo, NULL, NULL, &dst_Dojo.w, &dst_Dojo.h);

    SDL_Surface* pHerbe = SDL_LoadBMP("hebre.bmp");
    SDL_Rect dst_Herbe;

    dst_Herbe.x = -5;
    dst_Herbe.y = -15;

    SDL_Texture* tex_Herbe = SDL_CreateTextureFromSurface(ren,pHerbe);

    SDL_QueryTexture(tex_Herbe, NULL, NULL, &dst_Herbe.w, &dst_Herbe.h);
        SDL_RenderCopy(ren, tex_Herbe, NULL, &dst_Herbe);




    SDL_Surface* pStone2 = SDL_LoadBMP("stone2.bmp");

    SDL_SetColorKey(pStone2, SDL_TRUE, SDL_MapRGB(pStone2->format, 255, 255, 255)); // supprime le background des images rochers

    SDL_Rect dst;

    SDL_Texture* tex_Stone2 = SDL_CreateTextureFromSurface(ren,pStone2);

    SDL_QueryTexture(tex_Stone2, NULL, NULL, &dst.w, &dst.h);

    SDL_RenderCopy(ren, tex_Blue_falcon, NULL, &dst_Blue_falcon);

    SDL_SetRenderDrawColor(ren, 67,77, 88, 100); // met la fenetre en gris fonc�

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
                default:
                        break;
            }
        }
    }

    SDL_RenderCopy(ren, tex_Shop_3, NULL, &dst_Shop_3);
    SDL_RenderCopy(ren, tex_Falcon, NULL, &dst_Falcon);
    SDL_RenderCopy(ren, tex_Megaman, NULL, &dst_Megaman);
    SDL_RenderCopy(ren, tex_Ryu, NULL, &dst_Ryu);

    SDL_RenderPresent(ren);

    SDL_FreeSurface(pShop_3);
    SDL_FreeSurface(pFalcon);
    SDL_FreeSurface(pMegaman);
    SDL_FreeSurface(pRyu);
    SDL_FreeSurface(pDojo);
    SDL_FreeSurface(pBlue_falcon);
    SDL_FreeSurface(pStone2);


}

//Chargement du perosnnage
void initPerso(SDL_Renderer *ren, SDL_Rect &posPerso, SDL_Texture* tex_perso, SDL_Surface * pSprite)
{

     SDL_SetColorKey(pSprite, SDL_TRUE, SDL_MapRGB(pSprite->format, 0, 0, 255));


     SDL_RenderCopy(ren, tex_perso, NULL, &posPerso);

         SDL_RenderPresent(ren);


}

int PeutInteragir (int carte[21][21], SDL_Rect &posPerso) // verifie si le joueur est proche d'une interaction
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

//Deplacement du perosnnage
void deplacePerso(SDL_Renderer *ren,SDL_Rect &posPerso, char* direction,int carte[21][21], int numCarte)
{

    SDL_Surface* pSprite = NULL;

    if(direction == "left")
    {
        pSprite = SDL_LoadBMP("link_gauche.bmp");
    }
    else if(direction == "up")
    {
        pSprite = SDL_LoadBMP("link_haut.bmp");
    }
    else if(direction == "down")
    {
        pSprite = SDL_LoadBMP("link_bas.bmp");
    }
    else if(direction == "right")
    {
        pSprite = SDL_LoadBMP("link_droite.bmp");
    }
    else
    {
         pSprite = SDL_LoadBMP("link_bas.bmp");
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
    SDL_RenderPresent(ren);

}

void lancer_Combat(SDL_Renderer *ren, char* nomPerso)
{
    SDL_Surface* pAdversaire;

    SDL_Rect pos_Adversaire;
    pos_Adversaire.x = 50;
    pos_Adversaire.y =  -10;
    pos_Adversaire.w = 0;
    pos_Adversaire.h = 0;

    if(nomPerso == "MewTwo")
    {
        pAdversaire = SDL_LoadBMP("mewtwoFight.bmp");
    }
    else if(nomPerso == "DonkeyKong")
    {
        pAdversaire = SDL_LoadBMP("DonkeyKong_fight.bmp");
    }
    else if(nomPerso == "Medusa")
    {
        pAdversaire = SDL_LoadBMP("Medusa_fight.bmp");
        pos_Adversaire.x = 0;
        pos_Adversaire.y = 0;
    }
    else if(nomPerso == "Goku")
    {
        pAdversaire = SDL_LoadBMP("Goku_fight.bmp");
        pos_Adversaire.x = 0;
        pos_Adversaire.y = 0;
    }
    else if(nomPerso == "Snake")
    {
        pAdversaire = SDL_LoadBMP("Snake_fight.bmp");
        pos_Adversaire.x = 0;
        pos_Adversaire.y = -10;
    }
    else if(nomPerso == "Mario")
    {
        pAdversaire = SDL_LoadBMP("Mario_fight.bmp");
        pos_Adversaire.x = 150;
        pos_Adversaire.y = 50;
    }
     else if(nomPerso == "Falcon")
    {
        pAdversaire = SDL_LoadBMP("Falcon_fight.bmp");
    }
    else if(nomPerso == "Megaman")
    {
        pAdversaire = SDL_LoadBMP("Megaman_fight.bmp");
    }
    else if(nomPerso == "Ryu")
    {
        pAdversaire = SDL_LoadBMP("Ryu_fight.bmp");
        pos_Adversaire.x = 200;
        pos_Adversaire.y = 75;
    }

    SDL_SetColorKey(pAdversaire, SDL_TRUE, SDL_MapRGB(pAdversaire->format, 255, 255, 255));



    SDL_Texture* tex_Adversaire = SDL_CreateTextureFromSurface(ren,pAdversaire);
    SDL_QueryTexture(tex_Adversaire, NULL, NULL, &pos_Adversaire.w, &pos_Adversaire.h);
    SDL_RenderCopy(ren, tex_Adversaire, NULL, &pos_Adversaire);
    SDL_RenderPresent(ren);
}

void Ouvrir_Magasin(SDL_Renderer *ren)
{
    SDL_Surface* pShop_Open;
    pShop_Open = SDL_LoadBMP("shop_open.bmp");


    SDL_SetColorKey(pShop_Open, SDL_TRUE, SDL_MapRGB(pShop_Open->format, 255, 255, 255));

    SDL_Rect pos_Shop_Open;

    pos_Shop_Open.x = 50;
    pos_Shop_Open.y =  -10;
    pos_Shop_Open.w = 0;
    pos_Shop_Open.h = 0;

    SDL_Texture* tex_Shop_Open = SDL_CreateTextureFromSurface(ren,pShop_Open);
    SDL_QueryTexture(tex_Shop_Open, NULL, NULL, &pos_Shop_Open.w, &pos_Shop_Open.h);
    SDL_RenderCopy(ren, tex_Shop_Open, NULL, &pos_Shop_Open);
    SDL_RenderPresent(ren);
}

SDL_Texture *loadTexture(char *filename, SDL_Renderer *ren)
{
    SDL_Texture *tex = NULL;
    SDL_Surface *pic = NULL;
    pic = SDL_LoadBMP(filename);

    if (pic == NULL)
    {
        fprintf(stderr,"�chec lors du chargement de l'image (%s)\n",SDL_GetError());
        return NULL;
    }

    tex = SDL_CreateTextureFromSurface(ren, pic);
    SDL_FreeSurface(pic);

    if (tex == NULL)
    {
        fprintf(stderr,"�chec lors du chargement de l'image (%s)\n",SDL_GetError());
    }

    return tex;
}

//Fermeture de la SDL
void close( SDL_Window *win, SDL_Renderer *ren, SDL_Surface *pic)
{
    SDL_FreeSurface(pic);
    pic = NULL;
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    win = NULL;

    TTF_Quit();
    SDL_Quit();
}


void TraiteInteraction(int interaction, SDL_Renderer *renderer)
{
    switch(interaction){
    case 1:
        lancer_Combat(renderer, "MewTwo");
        break;
    case 2:
        lancer_Combat(renderer, "DonkeyKong");
        break;
    case 3:
        lancer_Combat(renderer, "Medusa");
        break;
    case 4:
        Ouvrir_Magasin(renderer);
        break;
    case 5:
        lancer_Combat(renderer, "Goku");
        break;
    case 6:
        lancer_Combat(renderer, "Snake");
        break;
    case 7:
        lancer_Combat(renderer, "Mario");
        break;
    case 8:
        Ouvrir_Magasin(renderer);
        break;
    case 9:
        lancer_Combat(renderer, "Falcon");
        break;
    case 10:
        lancer_Combat(renderer, "Megaman");
        break;
    case 11:
        lancer_Combat(renderer, "Ryu");
        break;
    case 12:
        Ouvrir_Magasin(renderer);
        break;
    default:
        break;
    }
}

void change_carte(int carte[21][21], int NumCarte) // Change la carte actuelle
{
    switch(NumCarte){
        case 2:
            carte[0][0]=10;
            carte[0][1]=10;
            carte[0][2]=10;
            carte[0][3]=10;
            carte[0][4]=10;
            carte[0][5]=10;
            carte[0][6]=10;
            carte[0][7]=10;
            carte[0][8]=10;
            carte[0][9]=10;
            carte[0][10]=10;
            carte[0][11]=10;
            carte[0][12]=10;
            carte[0][13]=10;
            carte[0][14]=10;
            carte[0][15]=10;
            carte[0][16]=10;
            carte[0][17]=10;
            carte[0][18]=10;
            carte[0][19]=10;
            carte[0][20]=10;

            carte[1][0]=10;
            carte[1][1]=3;
            carte[1][2]=1;
            carte[1][3]=1;
            carte[1][4]=1;
            carte[1][5]=1;
            carte[1][6]=1;
            carte[1][7]=1;
            carte[1][8]=1;
            carte[1][9]=1;
            carte[1][10]=1;
            carte[1][11]=1;
            carte[1][12]=10;
            carte[1][13]=12;
            carte[1][14]=1;
            carte[1][15]=1;
            carte[1][16]=1;
            carte[1][17]=1;
            carte[1][18]=10;
            carte[1][19]=9;
            carte[1][20]=10;

            carte[2][0]=10;
            carte[2][1]=1;
            carte[2][2]=1;
            carte[2][3]=1;
            carte[2][4]=1;
            carte[2][5]=1;
            carte[2][6]=1;
            carte[2][7]=1;
            carte[2][8]=1;
            carte[2][9]=1;
            carte[2][10]=1;
            carte[2][11]=1;
            carte[2][12]=10;
            carte[2][13]=1;
            carte[2][14]=1;
            carte[2][15]=1;
            carte[2][16]=1;
            carte[2][17]=1;
            carte[2][18]=10;
            carte[2][19]=1;
            carte[2][20]=10;

            carte[3][0]=10;
            carte[3][1]=1;
            carte[3][2]=1;
            carte[3][3]=1;
            carte[3][4]=1;
            carte[3][5]=7;
            carte[3][6]=1;
            carte[3][7]=1;
            carte[3][8]=1;
            carte[3][9]=1;
            carte[3][10]=1;
            carte[3][11]=1;
            carte[3][12]=10;
            carte[3][13]=1;
            carte[3][14]=1;
            carte[3][15]=1;
            carte[3][16]=1;
            carte[3][17]=1;
            carte[3][18]=10;
            carte[3][19]=1;
            carte[3][20]=10;

            carte[4][0]=10;
            carte[4][1]=1;
            carte[4][2]=1;
            carte[4][3]=1;
            carte[4][4]=1;
            carte[4][5]=7;
            carte[4][6]=1;
            carte[4][7]=1;
            carte[4][8]=1;
            carte[4][9]=1;
            carte[4][10]=1;
            carte[4][11]=1;
            carte[4][12]=10;
            carte[4][13]=1;
            carte[4][14]=1;
            carte[4][15]=1;
            carte[4][16]=1;
            carte[4][17]=1;
            carte[4][18]=10;
            carte[4][19]=1;
            carte[4][20]=10;

            carte[5][0]=10;
            carte[5][1]=1;
            carte[5][2]=1;
            carte[5][3]=1;
            carte[5][4]=1;
            carte[5][5]=1;
            carte[5][6]=1;
            carte[5][7]=1;
            carte[5][8]=1;
            carte[5][9]=1;
            carte[5][10]=1;
            carte[5][11]=1;
            carte[5][12]=10;
            carte[5][13]=1;
            carte[5][14]=1;
            carte[5][15]=1;
            carte[5][16]=1;
            carte[5][17]=1;
            carte[5][18]=10;
            carte[5][19]=1;
            carte[5][20]=10;

            carte[6][0]=10;
            carte[6][1]=1;
            carte[6][2]=1;
            carte[6][3]=1;
            carte[6][4]=0;
            carte[6][5]=-1;
            carte[6][6]=0;
            carte[6][7]=1;
            carte[6][8]=1;
            carte[6][9]=1;
            carte[6][10]=1;
            carte[6][11]=1;
            carte[6][12]=1;
            carte[6][13]=1;
            carte[6][14]=1;
            carte[6][15]=1;
            carte[6][16]=1;
            carte[6][17]=1;
            carte[6][18]=10;
            carte[6][19]=1;
            carte[6][20]=10;

            carte[7][0]=10;
            carte[7][1]=1;
            carte[7][2]=1;
            carte[7][3]=0;
            carte[7][4]=0;
            carte[7][5]=-1;
            carte[7][6]=0;
            carte[7][7]=0;
            carte[7][8]=1;
            carte[7][9]=1;
            carte[7][10]=1;
            carte[7][11]=1;
            carte[7][12]=1;
            carte[7][13]=1;
            carte[7][14]=1;
            carte[7][15]=1;
            carte[7][16]=1;
            carte[7][17]=1;
            carte[7][18]=10;
            carte[7][19]=1;
            carte[7][20]=10;

            carte[8][0]=10;
            carte[8][1]=1;
            carte[8][2]=1;
            carte[8][3]=0;
            carte[8][4]=0;
            carte[8][5]=-1;
            carte[8][6]=0;
            carte[8][7]=0;
            carte[8][8]=1;
            carte[8][9]=1;
            carte[8][10]=1;
            carte[8][11]=1;
            carte[8][12]=1;
            carte[8][13]=1;
            carte[8][14]=1;
            carte[8][15]=1;
            carte[8][16]=1;
            carte[8][17]=1;
            carte[8][18]=1;
            carte[8][19]=1;
            carte[8][20]=10;

            carte[9][0]=10;
            carte[9][1]=1;
            carte[9][2]=1;
            carte[9][3]=0;
            carte[9][4]=0;
            carte[9][5]=-1;
            carte[9][6]=0;
            carte[9][7]=0;
            carte[9][8]=1;
            carte[9][9]=1;
            carte[9][10]=1;
            carte[9][11]=1;
            carte[9][12]=1;
            carte[9][13]=1;
            carte[9][14]=1;
            carte[9][15]=1;
            carte[9][16]=1;
            carte[9][17]=1;
            carte[9][18]=1;
            carte[9][19]=1;
            carte[9][20]=10;

            carte[10][0]=10;
            carte[10][1]=1;
            carte[10][2]=1;
            carte[10][3]=0;
            carte[10][4]=0;
            carte[10][5]=7;
            carte[10][6]=0;
            carte[10][7]=0;
            carte[10][8]=1;
            carte[10][9]=1;
            carte[10][10]=1;
            carte[10][11]=1;
            carte[10][12]=1;
            carte[10][13]=1;
            carte[10][14]=1;
            carte[10][15]=1;
            carte[10][16]=1;
            carte[10][17]=1;
            carte[10][18]=1;
            carte[10][19]=1;
            carte[10][20]=10;

            carte[11][0]=10;
            carte[11][1]=1;
            carte[11][2]=1;
            carte[11][3]=0;
            carte[11][4]=0;
            carte[11][5]=7;
            carte[11][6]=0;
            carte[11][7]=0;
            carte[11][8]=1;
            carte[11][9]=1;
            carte[11][10]=1;
            carte[11][11]=1;
            carte[11][12]=1;
            carte[11][13]=1;
            carte[11][14]=1;
            carte[11][15]=1;
            carte[11][16]=1;
            carte[11][17]=1;
            carte[11][18]=1;
            carte[11][19]=1;
            carte[11][20]=10;

            carte[12][0]=10;
            carte[12][1]=1;
            carte[12][2]=1;
            carte[12][3]=0;
            carte[12][4]=0;
            carte[12][5]=8;
            carte[12][6]=0;
            carte[12][7]=0;
            carte[12][8]=1;
            carte[12][9]=1;
            carte[12][10]=1;
            carte[12][11]=1;
            carte[12][12]=1;
            carte[12][13]=1;
            carte[12][14]=1;
            carte[12][15]=1;
            carte[12][16]=1;
            carte[12][17]=1;
            carte[12][18]=1;
            carte[12][19]=1;
            carte[12][20]=10;

            carte[13][0]=10;
            carte[13][1]=1;
            carte[13][2]=1;
            carte[13][3]=0;
            carte[13][4]=0;
            carte[13][5]=8;
            carte[13][6]=0;
            carte[13][7]=0;
            carte[13][8]=1;
            carte[13][9]=1;
            carte[13][10]=1;
            carte[13][11]=1;
            carte[13][12]=1;
            carte[13][13]=1;
            carte[13][14]=1;
            carte[13][15]=1;
            carte[13][16]=1;
            carte[13][17]=1;
            carte[13][18]=1;
            carte[13][19]=1;
            carte[13][20]=10;

            carte[14][0]=10;
            carte[14][1]=1;
            carte[14][2]=1;
            carte[14][3]=0;
            carte[14][4]=0;
            carte[14][5]=0;
            carte[14][6]=0;
            carte[14][7]=0;
            carte[14][8]=1;
            carte[14][9]=1;
            carte[14][10]=1;
            carte[14][11]=1;
            carte[14][12]=1;
            carte[14][13]=1;
            carte[14][14]=1;
            carte[14][15]=1;
            carte[14][16]=1;
            carte[14][17]=1;
            carte[14][18]=1;
            carte[14][19]=1;
            carte[14][20]=10;

            carte[15][0]=10;
            carte[15][1]=1;
            carte[15][2]=1;
            carte[15][3]=1;
            carte[15][4]=0;
            carte[15][5]=0;
            carte[15][6]=0;
            carte[15][7]=1;
            carte[15][8]=1;
            carte[15][9]=1;
            carte[15][10]=1;
            carte[15][11]=1;
            carte[15][12]=1;
            carte[15][13]=1;
            carte[15][14]=11;
            carte[15][15]=1;
            carte[15][16]=1;
            carte[15][17]=1;
            carte[15][18]=1;
            carte[15][19]=1;
            carte[15][20]=10;

            carte[16][0]=10;
            carte[16][1]=1;
            carte[16][2]=1;
            carte[16][3]=1;
            carte[16][4]=1;
            carte[16][5]=1;
            carte[16][6]=1;
            carte[16][7]=1;
            carte[16][8]=1;
            carte[16][9]=1;
            carte[16][10]=1;
            carte[16][11]=1;
            carte[16][12]=1;
            carte[16][13]=11;
            carte[16][14]=11;
            carte[16][15]=1;
            carte[16][16]=1;
            carte[16][17]=1;
            carte[16][18]=1;
            carte[16][19]=1;
            carte[16][20]=10;

            carte[17][0]=10;
            carte[17][1]=1;
            carte[17][2]=1;
            carte[17][3]=1;
            carte[17][4]=1;
            carte[17][5]=1;
            carte[17][6]=1;
            carte[17][7]=1;
            carte[17][8]=1;
            carte[17][9]=1;
            carte[17][10]=1;
            carte[17][11]=1;
            carte[17][12]=1;
            carte[17][13]=11;
            carte[17][14]=11;
            carte[17][15]=11;
            carte[17][16]=1;
            carte[17][17]=1;
            carte[17][18]=1;
            carte[17][19]=1;
            carte[17][20]=10;

            carte[18][0]=10;
            carte[18][1]=1;
            carte[18][2]=1;
            carte[18][3]=1;
            carte[18][4]=1;
            carte[18][5]=1;
            carte[18][6]=1;
            carte[18][7]=1;
            carte[18][8]=1;
            carte[18][9]=1;
            carte[18][10]=1;
            carte[18][11]=1;
            carte[18][12]=1;
            carte[18][13]=11;
            carte[18][14]=11;
            carte[18][15]=1;
            carte[18][16]=1;
            carte[18][17]=1;
            carte[18][18]=1;
            carte[18][19]=1;
            carte[18][20]=10;

            carte[19][0]=10;
            carte[19][1]=1;
            carte[19][2]=1;
            carte[19][3]=1;
            carte[19][4]=1;
            carte[19][5]=1;
            carte[19][6]=1;
            carte[19][7]=1;
            carte[19][8]=1;
            carte[19][9]=1;
            carte[19][10]=1;
            carte[19][11]=1;
            carte[19][12]=1;
            carte[19][13]=1;
            carte[19][14]=1;
            carte[19][15]=1;
            carte[19][16]=1;
            carte[19][17]=1;
            carte[19][18]=1;
            carte[19][19]=1;
            carte[19][20]=10;

            carte[20][0]=10;
            carte[20][1]=10;
            carte[20][2]=10;
            carte[20][3]=10;
            carte[20][4]=10;
            carte[20][5]=10;
            carte[20][6]=10;
            carte[20][7]=10;
            carte[20][8]=10;
            carte[20][9]=10;
            carte[20][10]=10;
            carte[20][11]=10;
            carte[20][12]=10;
            carte[20][13]=10;
            carte[20][14]=10;
            carte[20][15]=10;
            carte[20][16]=10;
            carte[20][17]=10;
            carte[20][18]=10;
            carte[20][19]=10;
            carte[20][20]=10;
            break;
        case 3:
            carte[0][0]=10;
            carte[0][1]=10;
            carte[0][2]=10;
            carte[0][3]=10;
            carte[0][4]=10;
            carte[0][5]=10;
            carte[0][6]=10;
            carte[0][7]=10;
            carte[0][8]=10;
            carte[0][9]=10;
            carte[0][10]=10;
            carte[0][11]=10;
            carte[0][12]=10;
            carte[0][13]=10;
            carte[0][14]=10;
            carte[0][15]=10;
            carte[0][16]=10;
            carte[0][17]=10;
            carte[0][18]=10;
            carte[0][19]=10;
            carte[0][20]=10;

            carte[1][0]=10;
            carte[1][1]=1;
            carte[1][2]=1;
            carte[1][3]=1;
            carte[1][4]=1;
            carte[1][5]=1;
            carte[1][6]=1;
            carte[1][7]=1;
            carte[1][8]=1;
            carte[1][9]=1;
            carte[1][10]=1;
            carte[1][11]=1;
            carte[1][12]=10;
            carte[1][13]=13;
            carte[1][14]=13;
            carte[1][15]=13;
            carte[1][16]=1;
            carte[1][17]=1;
            carte[1][18]=1;
            carte[1][19]=9;
            carte[1][20]=10;

            carte[2][0]=10;
            carte[2][1]=16;
            carte[2][2]=16;
            carte[2][3]=1;
            carte[2][4]=1;
            carte[2][5]=1;
            carte[2][6]=1;
            carte[2][7]=1;
            carte[2][8]=1;
            carte[2][9]=1;
            carte[2][10]=1;
            carte[2][11]=1;
            carte[2][12]=10;
            carte[2][13]=13;
            carte[2][14]=13;
            carte[2][15]=13;
            carte[2][16]=1;
            carte[2][17]=1;
            carte[2][18]=1;
            carte[2][19]=1;
            carte[2][20]=10;

            carte[3][0]=10;
            carte[3][1]=1;
            carte[3][2]=1;
            carte[3][3]=1;
            carte[3][4]=1;
            carte[3][5]=7;
            carte[3][6]=1;
            carte[3][7]=1;
            carte[3][8]=1;
            carte[3][9]=1;
            carte[3][10]=1;
            carte[3][11]=1;
            carte[3][12]=10;
            carte[3][13]=13;
            carte[3][14]=13;
            carte[3][15]=13;
            carte[3][16]=1;
            carte[3][17]=1;
            carte[3][18]=1;
            carte[3][19]=1;
            carte[3][20]=10;

            carte[4][0]=10;
            carte[4][1]=1;
            carte[4][2]=1;
            carte[4][3]=1;
            carte[4][4]=1;
            carte[4][5]=7;
            carte[4][6]=1;
            carte[4][7]=1;
            carte[4][8]=1;
            carte[4][9]=1;
            carte[4][10]=1;
            carte[4][11]=1;
            carte[4][12]=10;
            carte[4][13]=13;
            carte[4][14]=13;
            carte[4][15]=13;
            carte[4][16]=1;
            carte[4][17]=1;
            carte[4][18]=1;
            carte[4][19]=1;
            carte[4][20]=10;

            carte[5][0]=10;
            carte[5][1]=1;
            carte[5][2]=1;
            carte[5][3]=1;
            carte[5][4]=1;
            carte[5][5]=1;
            carte[5][6]=1;
            carte[5][7]=1;
            carte[5][8]=1;
            carte[5][9]=1;
            carte[5][10]=1;
            carte[5][11]=1;
            carte[5][12]=10;
            carte[5][13]=13;
            carte[5][14]=13;
            carte[5][15]=13;
            carte[5][16]=1;
            carte[5][17]=1;
            carte[5][18]=1;
            carte[5][19]=1;
            carte[5][20]=10;

            carte[6][0]=10;
            carte[6][1]=1;
            carte[6][2]=1;
            carte[6][3]=1;
            carte[6][4]=0;
            carte[6][5]=-1;
            carte[6][6]=0;
            carte[6][7]=1;
            carte[6][8]=1;
            carte[6][9]=1;
            carte[6][10]=1;
            carte[6][11]=1;
            carte[6][12]=10;
            carte[6][13]=1;
            carte[6][14]=1;
            carte[6][15]=1;
            carte[6][16]=1;
            carte[6][17]=1;
            carte[6][18]=1;
            carte[6][19]=1;
            carte[6][20]=10;

            carte[7][0]=10;
            carte[7][1]=1;
            carte[7][2]=1;
            carte[7][3]=0;
            carte[7][4]=0;
            carte[7][5]=-1;
            carte[7][6]=0;
            carte[7][7]=0;
            carte[7][8]=1;
            carte[7][9]=1;
            carte[7][10]=1;
            carte[7][11]=1;
            carte[7][12]=1;
            carte[7][13]=1;
            carte[7][14]=1;
            carte[7][15]=1;
            carte[7][16]=1;
            carte[7][17]=1;
            carte[7][18]=1;
            carte[7][19]=1;
            carte[7][20]=10;

            carte[8][0]=10;
            carte[8][1]=1;
            carte[8][2]=1;
            carte[8][3]=0;
            carte[8][4]=0;
            carte[8][5]=-1;
            carte[8][6]=0;
            carte[8][7]=0;
            carte[8][8]=1;
            carte[8][9]=1;
            carte[8][10]=1;
            carte[8][11]=1;
            carte[8][12]=1;
            carte[8][13]=1;
            carte[8][14]=1;
            carte[8][15]=1;
            carte[8][16]=1;
            carte[8][17]=1;
            carte[8][18]=1;
            carte[8][19]=1;
            carte[8][20]=10;

            carte[9][0]=10;
            carte[9][1]=1;
            carte[9][2]=1;
            carte[9][3]=0;
            carte[9][4]=0;
            carte[9][5]=-1;
            carte[9][6]=0;
            carte[9][7]=0;
            carte[9][8]=1;
            carte[9][9]=1;
            carte[9][10]=1;
            carte[9][11]=1;
            carte[9][12]=1;
            carte[9][13]=1;
            carte[9][14]=1;
            carte[9][15]=1;
            carte[9][16]=1;
            carte[9][17]=1;
            carte[9][18]=1;
            carte[9][19]=1;
            carte[9][20]=10;

            carte[10][0]=10;
            carte[10][1]=1;
            carte[10][2]=1;
            carte[10][3]=0;
            carte[10][4]=0;
            carte[10][5]=7;
            carte[10][6]=0;
            carte[10][7]=0;
            carte[10][8]=1;
            carte[10][9]=1;
            carte[10][10]=1;
            carte[10][11]=1;
            carte[10][12]=1;
            carte[10][13]=1;
            carte[10][14]=1;
            carte[10][15]=1;
            carte[10][16]=1;
            carte[10][17]=1;
            carte[10][18]=1;
            carte[10][19]=1;
            carte[10][20]=10;

            carte[11][0]=10;
            carte[11][1]=1;
            carte[11][2]=1;
            carte[11][3]=0;
            carte[11][4]=0;
            carte[11][5]=7;
            carte[11][6]=0;
            carte[11][7]=0;
            carte[11][8]=1;
            carte[11][9]=1;
            carte[11][10]=1;
            carte[11][11]=1;
            carte[11][12]=1;
            carte[11][13]=1;
            carte[11][14]=1;
            carte[11][15]=1;
            carte[11][16]=1;
            carte[11][17]=1;
            carte[11][18]=1;
            carte[11][19]=1;
            carte[11][20]=10;

            carte[12][0]=10;
            carte[12][1]=10;
            carte[12][2]=10;
            carte[12][3]=10;
            carte[12][4]=10;
            carte[12][5]=10;
            carte[12][6]=10;
            carte[12][7]=1;
            carte[12][8]=1;
            carte[12][9]=1;
            carte[12][10]=1;
            carte[12][11]=1;
            carte[12][12]=1;
            carte[12][13]=1;
            carte[12][14]=1;
            carte[12][15]=1;
            carte[12][16]=1;
            carte[12][17]=1;
            carte[12][18]=1;
            carte[12][19]=1;
            carte[12][20]=10;

            carte[13][0]=10;
            carte[13][1]=1;
            carte[13][2]=1;
            carte[13][3]=0;
            carte[13][4]=0;
            carte[13][5]=1;
            carte[13][6]=0;
            carte[13][7]=0;
            carte[13][8]=1;
            carte[13][9]=1;
            carte[13][10]=1;
            carte[13][11]=1;
            carte[13][12]=1;
            carte[13][13]=1;
            carte[13][14]=1;
            carte[13][15]=1;
            carte[13][16]=1;
            carte[13][17]=1;
            carte[13][18]=1;
            carte[13][19]=1;
            carte[13][20]=10;

            carte[14][0]=10;
            carte[14][1]=1;
            carte[14][2]=1;
            carte[14][3]=0;
            carte[14][4]=0;
            carte[14][5]=0;
            carte[14][6]=0;
            carte[14][7]=0;
            carte[14][8]=1;
            carte[14][9]=1;
            carte[14][10]=1;
            carte[14][11]=1;
            carte[14][12]=1;
            carte[14][13]=1;
            carte[14][14]=1;
            carte[14][15]=1;
            carte[14][16]=1;
            carte[14][17]=1;
            carte[14][18]=1;
            carte[14][19]=1;
            carte[14][20]=10;

            carte[15][0]=10;
            carte[15][1]=1;
            carte[15][2]=1;
            carte[15][3]=1;
            carte[15][4]=0;
            carte[15][5]=0;
            carte[15][6]=0;
            carte[15][7]=1;
            carte[15][8]=1;
            carte[15][9]=1;
            carte[15][10]=1;
            carte[15][11]=1;
            carte[15][12]=1;
            carte[15][13]=1;
            carte[15][14]=1;
            carte[15][15]=1;
            carte[15][16]=1;
            carte[15][17]=1;
            carte[15][18]=1;
            carte[15][19]=1;
            carte[15][20]=10;

            carte[16][0]=10;
            carte[16][1]=1;
            carte[16][2]=1;
            carte[16][3]=1;
            carte[16][4]=1;
            carte[16][5]=1;
            carte[16][6]=1;
            carte[16][7]=1;
            carte[16][8]=1;
            carte[16][9]=1;
            carte[16][10]=1;
            carte[16][11]=1;
            carte[16][12]=1;
            carte[16][13]=1;
            carte[16][14]=1;
            carte[16][15]=1;
            carte[16][16]=1;
            carte[16][17]=1;
            carte[16][18]=1;
            carte[16][19]=1;
            carte[16][20]=10;

            carte[17][0]=10;
            carte[17][1]=1;
            carte[17][2]=1;
            carte[17][3]=1;
            carte[17][4]=1;
            carte[17][5]=1;
            carte[17][6]=1;
            carte[17][7]=1;
            carte[17][8]=1;
            carte[17][9]=1;
            carte[17][10]=1;
            carte[17][11]=1;
            carte[17][12]=1;
            carte[17][13]=1;
            carte[17][14]=1;
            carte[17][15]=1;
            carte[17][16]=1;
            carte[17][17]=1;
            carte[17][18]=1;
            carte[17][19]=1;
            carte[17][20]=10;

            carte[18][0]=10;
            carte[18][1]=1;
            carte[18][2]=1;
            carte[18][3]=1;
            carte[18][4]=14;
            carte[18][5]=14;
            carte[18][6]=1;
            carte[18][7]=1;
            carte[18][8]=1;
            carte[18][9]=1;
            carte[18][10]=1;
            carte[18][11]=1;
            carte[18][12]=1;
            carte[18][13]=1;
            carte[18][14]=1;
            carte[18][15]=1;
            carte[18][16]=15;
            carte[18][17]=15;
            carte[18][18]=1;
            carte[18][19]=1;
            carte[18][20]=10;

            carte[19][0]=10;
            carte[19][1]=1;
            carte[19][2]=1;
            carte[19][3]=1;
            carte[19][4]=1;
            carte[19][5]=1;
            carte[19][6]=1;
            carte[19][7]=1;
            carte[19][8]=1;
            carte[19][9]=1;
            carte[19][10]=1;
            carte[19][11]=1;
            carte[19][12]=1;
            carte[19][13]=1;
            carte[19][14]=1;
            carte[19][15]=1;
            carte[19][16]=1;
            carte[19][17]=1;
            carte[19][18]=1;
            carte[19][19]=1;
            carte[19][20]=10;

            carte[20][0]=10;
            carte[20][1]=10;
            carte[20][2]=10;
            carte[20][3]=10;
            carte[20][4]=10;
            carte[20][5]=10;
            carte[20][6]=10;
            carte[20][7]=10;
            carte[20][8]=10;
            carte[20][9]=10;
            carte[20][10]=10;
            carte[20][11]=10;
            carte[20][12]=10;
            carte[20][13]=10;
            carte[20][14]=10;
            carte[20][15]=10;
            carte[20][16]=10;
            carte[20][17]=10;
            carte[20][18]=10;
            carte[20][19]=10;
            carte[20][20]=10;
            break;
        default:
            break;
    }

}

bool Verif_Collision(int NouvellePositionX, int NouvellePositionY, int carte[21][21], int NumCarte)
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

            break;
        default:
            break;
    }

    return false;
}

//Permet de laisser la fen�tre affich�e jusqu'� fermeture par l'utilisateur
void pause(SDL_Renderer *renderer, SDL_Rect &posPerso,int carte[21][21], int & NumCarte)
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
            change_carte(carte,NumCarte);
            deplacePerso(renderer,posPerso, "right",carte,NumCarte);
        }
        if (posPerso.y < 25)
        {
            posPerso.x = 275;
            posPerso.y = 475;
            NumCarte = 3;
            change_carte(carte,NumCarte);
            deplacePerso(renderer,posPerso, "right",carte,NumCarte);
        }

        switch(event.type)
            {
                case SDL_QUIT:
                    quit = 1;
                    break;

                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_SPACE:
                            if(PeutInteragir(carte,posPerso) != -1) // -1 siginifie qu'aucune interaction n'est possible
                            {
                                TraiteInteraction(PeutInteragir(carte,posPerso), renderer);
                                carte[20][9] = 1;
                                carte[14][0] = 1;
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

int main(int argc, char** argv)
{
    int carte[21][21];
    carte[0][0]=0;
    carte[0][1]=0;
    carte[0][2]=0;
    carte[0][3]=0;
    carte[0][4]=0;
    carte[0][5]=0;
    carte[0][6]=0;
    carte[0][7]=0;
    carte[0][8]=0;
    carte[0][9]=0;
    carte[0][10]=0;
    carte[0][11]=0;
    carte[0][12]=0;
    carte[0][13]=0;
    carte[0][14]=0;
    carte[0][15]=0;
    carte[0][16]=0;
    carte[0][17]=0;
    carte[0][18]=0;
    carte[0][19]=0;
    carte[0][20]=0;

    carte[1][0]=0;
    carte[1][1]=3;
    carte[1][2]=1;
    carte[1][3]=1;
    carte[1][4]=1;
    carte[1][5]=1;
    carte[1][6]=1;
    carte[1][7]=1;
    carte[1][8]=1;
    carte[1][9]=1;
    carte[1][10]=1;
    carte[1][11]=1;
    carte[1][12]=1;
    carte[1][13]=1;
    carte[1][14]=1;
    carte[1][15]=1;
    carte[1][16]=1;
    carte[1][17]=1;
    carte[1][18]=1;
    carte[1][19]=1;
    carte[1][20]=0;

    carte[2][0]=0;
    carte[2][1]=1;
    carte[2][2]=1;
    carte[2][3]=1;
    carte[2][4]=1;
    carte[2][5]=1;
    carte[2][6]=1;
    carte[2][7]=1;
    carte[2][8]=1;
    carte[2][9]=1;
    carte[2][10]=1;
    carte[2][11]=1;
    carte[2][12]=1;
    carte[2][13]=1;
    carte[2][14]=1;
    carte[2][15]=1;
    carte[2][16]=1;
    carte[2][17]=1;
    carte[2][18]=1;
    carte[2][19]=1;
    carte[2][20]=0;

    carte[3][0]=0;
    carte[3][1]=1;
    carte[3][2]=1;
    carte[3][3]=0;
    carte[3][4]=0;
    carte[3][5]=0;
    carte[3][6]=0;
    carte[3][7]=0;
    carte[3][8]=0;
    carte[3][9]=0;
    carte[3][10]=0;
    carte[3][11]=0;
    carte[3][12]=0;
    carte[3][13]=0;
    carte[3][14]=0;
    carte[3][15]=0;
    carte[3][16]=0;
    carte[3][17]=0;
    carte[3][18]=0;
    carte[3][19]=1;
    carte[3][20]=0;

    carte[4][0]=0;
    carte[4][1]=1;
    carte[4][2]=1;
    carte[4][3]=0;
    carte[4][4]=1;
    carte[4][5]=1;
    carte[4][6]=1;
    carte[4][7]=1;
    carte[4][8]=0;
    carte[4][9]=0;
    carte[4][10]=1;
    carte[4][11]=0;
    carte[4][12]=1;
    carte[4][13]=1;
    carte[4][14]=1;
    carte[4][15]=1;
    carte[4][16]=1;
    carte[4][17]=1;
    carte[4][18]=0;
    carte[4][19]=1;
    carte[4][20]=0;

    carte[5][0]=0;
    carte[5][1]=1;
    carte[5][2]=1;
    carte[5][3]=0;
    carte[5][4]=1;
    carte[5][5]=0;
    carte[5][6]=0;
    carte[5][7]=1;
    carte[5][8]=1;
    carte[5][9]=1;
    carte[5][10]=1;
    carte[5][11]=0;
    carte[5][12]=1;
    carte[5][13]=0;
    carte[5][14]=0;
    carte[5][15]=0;
    carte[5][16]=1;
    carte[5][17]=0;
    carte[5][18]=0;
    carte[5][19]=1;
    carte[5][20]=0;

    carte[6][0]=0;
    carte[6][1]=1;
    carte[6][2]=0;
    carte[6][3]=0;
    carte[6][4]=1;
    carte[6][5]=1;
    carte[6][6]=0;
    carte[6][7]=1;
    carte[6][8]=0;
    carte[6][9]=1;
    carte[6][10]=1;
    carte[6][11]=0;
    carte[6][12]=1;
    carte[6][13]=1;
    carte[6][14]=1;
    carte[6][15]=0;
    carte[6][16]=1;
    carte[6][17]=1;
    carte[6][18]=0;
    carte[6][19]=1;
    carte[6][20]=0;

    carte[7][0]=0;
    carte[7][1]=1;
    carte[7][2]=1;
    carte[7][3]=0;
    carte[7][4]=1;
    carte[7][5]=0;
    carte[7][6]=0;
    carte[7][7]=1;
    carte[7][8]=0;
    carte[7][9]=0;
    carte[7][10]=1;
    carte[7][11]=0;
    carte[7][12]=0;
    carte[7][13]=0;
    carte[7][14]=1;
    carte[7][15]=0;
    carte[7][16]=1;
    carte[7][17]=0;
    carte[7][18]=0;
    carte[7][19]=1;
    carte[7][20]=0;

    carte[8][0]=0;
    carte[8][1]=1;
    carte[8][2]=1;
    carte[8][3]=0;
    carte[8][4]=2;
    carte[8][5]=0;
    carte[8][6]=0;
    carte[8][7]=1;
    carte[8][8]=0;
    carte[8][9]=0;
    carte[8][10]=1;
    carte[8][11]=1;
    carte[8][12]=1;
    carte[8][13]=1;
    carte[8][14]=1;
    carte[8][15]=0;
    carte[8][16]=1;
    carte[8][17]=1;
    carte[8][18]=1;
    carte[8][19]=1;
    carte[8][20]=0;

    carte[9][0]=0;
    carte[9][1]=1;
    carte[9][2]=1;
    carte[9][3]=0;
    carte[9][4]=0;
    carte[9][5]=0;
    carte[9][6]=0;
    carte[9][7]=0;
    carte[9][8]=0;
    carte[9][9]=0;
    carte[9][10]=0;
    carte[9][11]=0;
    carte[9][12]=0;
    carte[9][13]=0;
    carte[9][14]=0;
    carte[9][15]=0;
    carte[9][16]=0;
    carte[9][17]=0;
    carte[9][18]=0;
    carte[9][19]=1;
    carte[9][20]=0;

    carte[10][0]=0;
    carte[10][1]=1;
    carte[10][2]=1;
    carte[10][3]=1;
    carte[10][4]=1;
    carte[10][5]=1;
    carte[10][6]=1;
    carte[10][7]=1;
    carte[10][8]=1;
    carte[10][9]=1;
    carte[10][10]=1;
    carte[10][11]=1;
    carte[10][12]=1;
    carte[10][13]=1;
    carte[10][14]=1;
    carte[10][15]=1;
    carte[10][16]=1;
    carte[10][17]=1;
    carte[10][18]=1;
    carte[10][19]=1;
    carte[10][20]=0;

    carte[11][0]=0;
    carte[11][1]=1;
    carte[11][2]=1;
    carte[11][3]=1;
    carte[11][4]=1;
    carte[11][5]=1;
    carte[11][6]=1;
    carte[11][7]=1;
    carte[11][8]=1;
    carte[11][9]=1;
    carte[11][10]=1;
    carte[11][11]=1;
    carte[11][12]=1;
    carte[11][13]=1;
    carte[11][14]=1;
    carte[11][15]=1;
    carte[11][16]=1;
    carte[11][17]=1;
    carte[11][18]=1;
    carte[11][19]=1;
    carte[11][20]=0;

    carte[12][0]=0;
    carte[12][1]=1;
    carte[12][2]=1;
    carte[12][3]=1;
    carte[12][4]=1;
    carte[12][5]=1;
    carte[12][6]=1;
    carte[12][7]=1;
    carte[12][8]=1;
    carte[12][9]=1;
    carte[12][10]=1;
    carte[12][11]=1;
    carte[12][12]=1;
    carte[12][13]=1;
    carte[12][14]=1;
    carte[12][15]=1;
    carte[12][16]=1;
    carte[12][17]=1;
    carte[12][18]=1;
    carte[12][19]=1;
    carte[12][20]=0;

    carte[13][0]=0;
    carte[13][1]=1;
    carte[13][2]=1;
    carte[13][3]=1;
    carte[13][4]=1;
    carte[13][5]=1;
    carte[13][6]=1;
    carte[13][7]=1;
    carte[13][8]=1;
    carte[13][9]=1;
    carte[13][10]=1;
    carte[13][11]=1;
    carte[13][12]=1;
    carte[13][13]=1;
    carte[13][14]=1;
    carte[13][15]=1;
    carte[13][16]=1;
    carte[13][17]=1;
    carte[13][18]=1;
    carte[13][19]=1;
    carte[13][20]=0;

    carte[14][0]=0;
    carte[14][1]=1;
    carte[14][2]=1;
    carte[14][3]=1;
    carte[14][4]=1;
    carte[14][5]=1;
    carte[14][6]=1;
    carte[14][7]=1;
    carte[14][8]=1;
    carte[14][9]=1;
    carte[14][10]=1;
    carte[14][11]=1;
    carte[14][12]=1;
    carte[14][13]=1;
    carte[14][14]=4;
    carte[14][15]=1;
    carte[14][16]=1;
    carte[14][17]=1;
    carte[14][18]=1;
    carte[14][19]=1;
    carte[14][20]=0;

    carte[15][0]=0;
    carte[15][1]=1;
    carte[15][2]=1;
    carte[15][3]=1;
    carte[15][4]=1;
    carte[15][5]=1;
    carte[15][6]=1;
    carte[15][7]=1;
    carte[15][8]=1;
    carte[15][9]=1;
    carte[15][10]=1;
    carte[15][11]=1;
    carte[15][12]=1;
    carte[15][13]=4;
    carte[15][14]=4;
    carte[15][15]=4;
    carte[15][16]=1;
    carte[15][17]=1;
    carte[15][18]=1;
    carte[15][19]=1;
    carte[15][20]=0;

    carte[16][0]=0;
    carte[16][1]=6;
    carte[16][2]=6;
    carte[16][3]=6;
    carte[16][4]=5;
    carte[16][5]=5;
    carte[16][6]=1;
    carte[16][7]=1;
    carte[16][8]=1;
    carte[16][9]=1;
    carte[16][10]=1;
    carte[16][11]=1;
    carte[16][12]=1;
    carte[16][13]=4;
    carte[16][14]=4;
    carte[16][15]=4;
    carte[16][16]=1;
    carte[16][17]=1;
    carte[16][18]=1;
    carte[16][19]=1;
    carte[16][20]=0;

    carte[17][0]=0;
    carte[17][1]=6;
    carte[17][2]=6;
    carte[17][3]=6;
    carte[17][4]=5;
    carte[17][5]=5;
    carte[17][6]=1;
    carte[17][7]=1;
    carte[17][8]=1;
    carte[17][9]=1;
    carte[17][10]=1;
    carte[17][11]=1;
    carte[17][12]=1;
    carte[17][13]=4;
    carte[17][14]=4;
    carte[17][15]=4;
    carte[17][16]=1;
    carte[17][17]=1;
    carte[17][18]=1;
    carte[17][19]=1;
    carte[17][20]=0;

    carte[18][0]=0;
    carte[18][1]=6;
    carte[18][2]=6;
    carte[18][3]=6;
    carte[18][4]=5;
    carte[18][5]=5;
    carte[18][6]=1;
    carte[18][7]=1;
    carte[18][8]=1;
    carte[18][9]=1;
    carte[18][10]=1;
    carte[18][11]=1;
    carte[18][12]=1;
    carte[18][13]=4;
    carte[18][14]=4;
    carte[18][15]=4;
    carte[18][16]=1;
    carte[18][17]=1;
    carte[18][18]=1;
    carte[18][19]=1;
    carte[18][20]=0;

    carte[19][0]=0;
    carte[19][1]=6;
    carte[19][2]=6;
    carte[19][3]=6;
    carte[19][4]=5;
    carte[19][5]=5;
    carte[19][6]=1;
    carte[19][7]=1;
    carte[19][8]=1;
    carte[19][9]=1;
    carte[19][10]=1;
    carte[19][11]=1;
    carte[19][12]=1;
    carte[19][13]=1;
    carte[19][14]=4;
    carte[19][15]=1;
    carte[19][16]=1;
    carte[19][17]=1;
    carte[19][18]=1;
    carte[19][19]=1;
    carte[19][20]=0;

    carte[20][0]=0;
    carte[20][1]=0;
    carte[20][2]=0;
    carte[20][3]=0;
    carte[20][4]=0;
    carte[20][5]=0;
    carte[20][6]=0;
    carte[20][7]=0;
    carte[20][8]=0;
    carte[20][9]=0;
    carte[20][10]=0;
    carte[20][11]=0;
    carte[20][12]=0;
    carte[20][13]=0;
    carte[20][14]=0;
    carte[20][15]=0;
    carte[20][16]=0;
    carte[20][17]=0;
    carte[20][18]=0;
    carte[20][19]=0;
    carte[20][20]=0;

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Surface *picture = NULL;




    if(!init("Fight Club - Mode Histoire",&window,&renderer))
    {
        exit(EXIT_FAILURE);
    }

     SDL_Rect posPerso;

     posPerso.x = 50;
     posPerso.y = 450;

     int NumCarte = 1;

     initMap(renderer,carte);
     initMap(renderer,carte);

    deplacePerso(renderer,posPerso, "",carte,NumCarte); // initialise le perso


    pause(renderer,posPerso,carte,NumCarte);

    close(window,renderer,picture);


    return EXIT_SUCCESS;
}
