/**
 * @file jeuSdl.cpp
 * @author
 * @brief 
 * @version 0.1
 * @date 2022-05-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "jeuSdl.h"
#include <cassert>
#include <iostream>

using namespace std;

//================ IMAGE =================//
Image::Image () : m_surface(nullptr), m_texture(nullptr), m_hasChanged(false) {
}

Image::~Image()
{
    SDL_FreeSurface(m_surface);
    SDL_DestroyTexture(m_texture);

    m_surface = nullptr;
    m_texture = nullptr;
    m_hasChanged = false;
}

void Image::loadFromFile (const char* filename, SDL_Renderer * renderer) {
    m_surface = IMG_Load(filename);
    if (m_surface == nullptr) {
        string nfn = string("../") + filename;
        cout << "Error: cannot load "<< filename <<". Trying "<<nfn<<endl;
        m_surface = IMG_Load(nfn.c_str());
        if (m_surface == nullptr) {
            nfn = string("../") + nfn;
            m_surface = IMG_Load(nfn.c_str());
        }
    }
    if (m_surface == nullptr) {
        cout<<"Error: cannot load "<< filename <<endl;
        SDL_Quit();
        exit(1);
    }

    SDL_Surface * surfaceCorrectPixelFormat = SDL_ConvertSurfaceFormat(m_surface,SDL_PIXELFORMAT_ARGB8888,0);
    SDL_FreeSurface(m_surface);
    m_surface = surfaceCorrectPixelFormat;

    m_texture = SDL_CreateTextureFromSurface(renderer,surfaceCorrectPixelFormat);
    if (m_texture == NULL) {
        cout << "Error: problem to create the texture of "<< filename<< endl;
        SDL_Quit();
        exit(1);
    }
}

void Image::loadFromCurrentSurface (SDL_Renderer * renderer) {
    m_texture = SDL_CreateTextureFromSurface(renderer,m_surface);
    if (m_texture == nullptr) {
        cout << "Error: problem to create the texture from surface " << endl;
        SDL_Quit();
        exit(1);
    }
}

void Image::draw (SDL_Renderer * renderer, int x, int y, int w, int h) {
    int ok;
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = (w<0)?m_surface->w:w;
    r.h = (h<0)?m_surface->h:h;

    if (m_hasChanged) {
        ok = SDL_UpdateTexture(m_texture,nullptr,m_surface->pixels,m_surface->pitch);
        assert(ok == 0);
        m_hasChanged = false;
    }

    ok = SDL_RenderCopy(renderer,m_texture,nullptr,&r);
    assert(ok == 0);
}

SDL_Texture * Image::getTexture() const {return m_texture;}

void Image::setSurface(SDL_Surface * surf) {m_surface = surf;}







//================  Sdljeu  =================//
Sdljeu::Sdljeu(){
    // Initialisation de la SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    if (TTF_Init() != 0) {
        cout << "Erreur lors de l'initialisation de la SDL_ttf : " << TTF_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if( !(IMG_Init(imgFlags) & imgFlags)) {
        cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    // if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    // {
    //     cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << endl;
    //     cout << "No sound !!!" << endl;
    //     //SDL_Quit();exit(1);
    //     withSound = false;
    // }
    // else withSound = true;

	int dimx = 620;
    int dimy = 580;

    
    // Creation de la fenetre
    window = SDL_CreateWindow("Fight Club", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dimx, dimy, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == nullptr) {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; 
        SDL_Quit(); 
        exit(1);
    }

    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    withsdl = true;

    //IMAGES

    

    


}

Sdljeu::~Sdljeu(){
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

void Sdljeu::choixAffichage(){
    Image SDL_Logo, TXT_Logo;
    SDL_Logo.loadFromFile("data/logo_SDL.png", renderer);
    TXT_Logo.loadFromFile("data/logo_TXT.png", renderer);
    bool choix = false;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);

    SDL_Logo.draw(renderer, 425, 150, 200, 200);
    TXT_Logo.draw(renderer, 50, 150, 200, 200);
    SDL_Event events;
    while(!choix){
        if(SDL_PollEvent(&events)){
            if (events.type == SDL_QUIT) SDL_Quit();
            SDL_RenderPresent(renderer);
            switch(events.button.button){
                case SDL_BUTTON_LEFT: 
                if((events.button.x >= 425 && events.button.x <= 625) && (events.button.y >= 150 && events.button.y <= 350)){
                    withsdl = true;
                    choix = true;
                    break;
                }else if((events.button.x >= 50 && events.button.x <= 250) && (events.button.y >= 150 && events.button.y <= 350)){ 
                    withsdl = false; 
                    choix = true;
                    SDL_Quit();
                    break;
                }
                break;

                default: break;
            }
        }
        
    }
    




}


int Sdljeu::afficherMenu(){

        SDL_DestroyRenderer(renderer);
        renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

        TTF_Font * Font = TTF_OpenFont("data/arial.ttf", 10);
        if (!Font){
            cout << "erreur lors de l'ouverture du font" << endl;
            exit(EXIT_FAILURE);
        }
        SDL_Color TextColor {255, 255, 255};

        Image logo;
        logo.loadFromFile("data/logo_JEU.png", renderer);


        //fond noir
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_Rect rect[3];

        rect[0] = {250, 250, 150, 50 };
        rect[1] = {250, 325, 150, 50 };
        rect[2] = {250, 400, 150, 50 };
        SDL_Surface * Jouer = TTF_RenderText_Solid(Font, "JOUER", TextColor);
        SDL_Texture * txtJouer = SDL_CreateTextureFromSurface(renderer, Jouer);
        SDL_Surface * Quitter = TTF_RenderText_Solid(Font, "QUITTER", TextColor);
        SDL_Texture * txtQuitter = SDL_CreateTextureFromSurface(renderer, Quitter);
        SDL_Surface * Histoire = TTF_RenderText_Solid(Font, "HISTOIRE", TextColor);
        SDL_Texture * txtHistoire = SDL_CreateTextureFromSurface(renderer, Histoire);
        


        logo.draw(renderer, 25, 50, 575, 150);
        SDL_RenderCopy(renderer, txtJouer, NULL, &rect[0]);
        SDL_RenderCopy(renderer, txtQuitter, NULL, &rect[2]);
        SDL_RenderCopy(renderer, txtHistoire, NULL, &rect[1]);

        
        SDL_Event events;
        bool choix = false;

        
        SDL_RenderPresent(renderer);

        while(!choix)
        while(SDL_PollEvent(&events)){
            if (events.type == SDL_QUIT) quit = true;
            switch(events.button.button){
                case SDL_BUTTON_LEFT: 
                if((events.button.x >= 250 && events.button.x <= 400) && (events.button.y >= 250 && events.button.y <= 300)){
                    choix = true;
                    return 1;
                }
                if((events.button.x >= 250 && events.button.x <= 400) && (events.button.y >= 325 && events.button.y <= 375)){
                    Map maphistoire;
                    maphistoire.mainAffichage(renderer, window);
                    
                }
                if((events.button.x >= 250 && events.button.x <= 400) && (events.button.y >= 400 && events.button.y <= 450)){
                    choix = true;
                    SDL_Quit();
                    return 3;
                }
                break;

                default: break;
            }

        }
        return -1;
        

        
        
}


void Sdljeu::majLogPerso(Joueur Perso){
    TTF_Font * Font = TTF_OpenFont("data/arial.ttf", 10);
        if (!Font){
            cout << "erreur lors de l'ouverture du font" << endl;
            exit(EXIT_FAILURE);
        }
    SDL_Color TextColor {255, 255, 255};


    SDL_Surface * nom = TTF_RenderText_Solid(Font, Perso.getNom().c_str(), TextColor); 
    SDL_Texture * txtNom = SDL_CreateTextureFromSurface(renderer, nom);

    SDL_Rect rect = {30, 20, 160, 30};
    SDL_RenderCopy(renderer, txtNom, NULL, &rect);

    SDL_Surface * pv = TTF_RenderText_Solid(Font, "PV:", TextColor); 
    SDL_Texture * txtPv = SDL_CreateTextureFromSurface(renderer, pv);
    SDL_Rect rectpv = {40, 70, 20, 20};
    SDL_RenderCopy(renderer, txtPv, NULL, &rectpv);

    SDL_Rect barre_pv = {65, 70, Perso.getStats().getVie(), 20};
    if(Perso.getStats().getVie() > 50) SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    else SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);    
    SDL_RenderFillRect(renderer, &barre_pv);

    

    
}

void Sdljeu::majLogIA(Joueur IA){
    TTF_Font * Font = TTF_OpenFont("data/arial.ttf", 10);
        if (!Font){
            cout << "erreur lors de l'ouverture du font" << endl;
            exit(EXIT_FAILURE);
        }
    SDL_Color TextColor {255, 255, 255};


    SDL_Surface * nom = TTF_RenderText_Solid(Font, IA.getNom().c_str(), TextColor); 
    SDL_Texture * txtNom = SDL_CreateTextureFromSurface(renderer, nom);

    SDL_Rect rect = {440, 20, 160, 30};
    SDL_RenderCopy(renderer, txtNom, NULL, &rect);

    SDL_Surface * pv = TTF_RenderText_Solid(Font, "PV:", TextColor); 
    SDL_Texture * txtPv = SDL_CreateTextureFromSurface(renderer, pv);
    SDL_Rect rectpv = {440, 70, 20, 20};
    SDL_RenderCopy(renderer, txtPv, NULL, &rectpv);

    SDL_Rect barre_pv = {465, 70, IA.getStats().getVie(), 20};
    if(IA.getStats().getVie() > 50) SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    else SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);    
    SDL_RenderFillRect(renderer, &barre_pv);
}


void Sdljeu::initCombat(Joueur A_me, Joueur B_ia){
    SDL_DestroyRenderer(renderer);
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    Image Terrain;
    Terrain.loadFromFile("data/Terrain.jpg", renderer);
    Terrain.draw(renderer, 0, 0, 620, 580);

    Image VS;
    VS.loadFromFile("data/VS_logo.png", renderer);
    VS.draw(renderer, 250, 0, 150, 175);
    
    Image me, ia;
    string tmp = string("data/") + A_me.getNom();
    string filename = tmp + string(".bmp");
    me.loadFromFile(filename.c_str(), renderer);
    me.draw(renderer, 10, 230, 140, 200);

    tmp = string("data/") + B_ia.getNom();
    filename = tmp + string(".bmp");
    ia.loadFromFile(filename.c_str(), renderer);
    ia.draw(renderer, 470, 230, 140, 200);


    SDL_Rect log_me = {20, 20, 180, 105};
    SDL_Rect log_ia = {425, 20, 180, 105};
    SDL_Rect log_jeu = {0, 480, 620, 100};
    SDL_SetRenderDrawColor(renderer, 25, 25, 25, 255);
    SDL_RenderFillRect(renderer, &log_me);
    SDL_RenderFillRect(renderer, &log_ia);
    SDL_RenderFillRect(renderer, &log_jeu);

    majLogPerso(A_me);
    majLogIA(B_ia);



    

}

int Sdljeu::majlogs(string texte, bool attaque, Joueur j){
    TTF_Font * Font = TTF_OpenFont("data/arial.ttf", 10);
        if (!Font){
            cout << "erreur lors de l'ouverture du font" << endl;
            exit(EXIT_FAILURE);
        }
    SDL_Color TextColor {255, 255, 255};
    SDL_Surface * txt = TTF_RenderText_Solid(Font, texte.c_str(), TextColor); 
    SDL_Texture * txtTxt = SDL_CreateTextureFromSurface(renderer, txt);

    SDL_Rect rect = {0, 480, 480, 100};
    SDL_RenderCopy(renderer, txtTxt, NULL, &rect);
    //SDL_RenderPresent(renderer);
    if(attaque){
        SDL_Surface * atq = TTF_RenderText_Solid(Font, "ATTAQUE", TextColor); 
        SDL_Texture * txtAtq = SDL_CreateTextureFromSurface(renderer, atq);

        SDL_Surface * inv = TTF_RenderText_Solid(Font, "INVENTAIRE", TextColor); 
        SDL_Texture * txtInv = SDL_CreateTextureFromSurface(renderer, inv);

        SDL_Rect attq = {500, 500, 120 , 40};
        SDL_Rect inventaire = {500, 540, 120, 40};
        
        SDL_RenderCopy(renderer, txtAtq, NULL, &attq);
        SDL_RenderCopy(renderer, txtInv, NULL, &inventaire);

        SDL_RenderPresent(renderer);
        bool choix = false;
        SDL_Event events;
        while(!choix){
            while(SDL_PollEvent(&events)){
                switch(events.button.button){
                    case SDL_BUTTON_LEFT:
                    if((events.button.x >= 500 && events.button.x <=620) && (events.button.y >= 500 && events.button.y < 540)){
                        choix = true;
                        return 1;
                    }
                    if((events.button.x >= 500 && events.button.x <=620) && (events.button.y >= 540 && events.button.y < 580)){
                        choix = true;
                        return 2;
                    }
                    break;

                    default:
                    break;
                }
            }
        }
    }

    SDL_RenderPresent(renderer);

    SDL_Delay(3000);
    //return 0;
}


int Sdljeu::majlogsChoix(Joueur j, bool action){

    SDL_Delay(2000);
    TTF_Font * Font = TTF_OpenFont("data/arial.ttf", 10);
        if (!Font){
            cout << "erreur lors de l'ouverture du font" << endl;
            exit(EXIT_FAILURE);
        }
    SDL_Color TextColor {255, 255, 255};

    SDL_Rect choix[4];
    choix[0] = {0, 480, 145, 100};
    choix[1] = {145, 480, 145, 100};
    choix[2] = {290, 480, 145, 100};
    choix[3] = {435, 480, 145, 100};
    bool choisi = false;
    SDL_Event events;
    
    

    if(action){ // 1 -> attaque | 0 -> inventaire

        SDL_Rect log_jeu = {0, 480, 620, 100};
        SDL_SetRenderDrawColor(renderer, 25, 25, 25, 255);
        SDL_RenderFillRect(renderer, &log_jeu);
    
        SDL_Surface * choix1 = TTF_RenderText_Solid(Font, j.getArme().getTabAttaque(0).getNomAttaque().c_str(), TextColor); 
        SDL_Texture * txtChoix1 = SDL_CreateTextureFromSurface(renderer, choix1);
        SDL_RenderCopy(renderer, txtChoix1, NULL, &choix[0]);

        SDL_Surface * choix2 = TTF_RenderText_Solid(Font, j.getArme().getTabAttaque(1).getNomAttaque().c_str(), TextColor); 
        SDL_Texture * txtChoix2 = SDL_CreateTextureFromSurface(renderer, choix2);
        SDL_RenderCopy(renderer, txtChoix2, NULL, &choix[1]);

        SDL_Surface * choix3 = TTF_RenderText_Solid(Font, j.getArme().getTabAttaque(2).getNomAttaque().c_str(), TextColor); 
        SDL_Texture * txtChoix3 = SDL_CreateTextureFromSurface(renderer, choix3);
        SDL_RenderCopy(renderer, txtChoix3, NULL, &choix[2]);

        SDL_Surface * choix4 = TTF_RenderText_Solid(Font, j.getArme().getTabAttaque(3).getNomAttaque().c_str(), TextColor); 
        SDL_Texture * txtChoix4 = SDL_CreateTextureFromSurface(renderer, choix4);
        SDL_RenderCopy(renderer, txtChoix4, NULL, &choix[3]);
        SDL_RenderPresent(renderer);

        while(!choisi){
        while(SDL_PollEvent(&events)){
            switch(events.button.button){
                case SDL_BUTTON_LEFT:
                    if((events.button.x >= 0 && events.button.x < 145) && (events.button.y >= 480 && events.button.y < 580)){
                        choisi = true;
                        return 1;
                    }
                    if((events.button.x >= 145 && events.button.x < 290) && (events.button.y >= 480 && events.button.y < 580)){
                        choisi = true;
                        return 2;
                    }
                    if((events.button.x >= 290 && events.button.x < 435) && (events.button.y >= 480 && events.button.y < 580)){
                        choisi = true;
                        return 3;
                    }
                    if((events.button.x >= 435 && events.button.x < 620) && (events.button.y >= 480 && events.button.y < 580)){
                        choisi = true;
                        return 4;
                    }
                    break;

                    default:
                    break;
            }
        }
    }
    }
    if(!action){

        SDL_Rect log_jeu = {0, 480, 620, 100};
        SDL_SetRenderDrawColor(renderer, 25, 25, 25, 255);
        SDL_RenderFillRect(renderer, &log_jeu);

        SDL_Surface * choix1 = TTF_RenderText_Solid(Font, j.getInv().getInventaire(0).getNomObjet().c_str(), TextColor); 
        SDL_Texture * txtChoix1 = SDL_CreateTextureFromSurface(renderer, choix1);
        SDL_RenderCopy(renderer, txtChoix1, NULL, &choix[0]);

        SDL_Surface * choix2 = TTF_RenderText_Solid(Font, j.getInv().getInventaire(1).getNomObjet().c_str(), TextColor); 
        SDL_Texture * txtChoix2 = SDL_CreateTextureFromSurface(renderer, choix2);
        SDL_RenderCopy(renderer, txtChoix2, NULL, &choix[1]);

        SDL_Surface * choix3 = TTF_RenderText_Solid(Font, j.getInv().getInventaire(2).getNomObjet().c_str(), TextColor); 
        SDL_Texture * txtChoix3 = SDL_CreateTextureFromSurface(renderer, choix3);
        SDL_RenderCopy(renderer, txtChoix3, NULL, &choix[2]);

        SDL_Surface * choix4 = TTF_RenderText_Solid(Font, j.getInv().getInventaire(3).getNomObjet().c_str(), TextColor); 
        SDL_Texture * txtChoix4 = SDL_CreateTextureFromSurface(renderer, choix4);
        SDL_RenderCopy(renderer, txtChoix4, NULL, &choix[3]);
        SDL_RenderPresent(renderer);
        while(!choisi){
        while(SDL_PollEvent(&events)){
            switch(events.button.button){
                case SDL_BUTTON_LEFT:
                    if((events.button.x >= 0 && events.button.x < 145) && (events.button.y >= 480 && events.button.y < 580)){
                        choisi = true;
                        return 1;
                    }
                    if((events.button.x >= 145 && events.button.x < 290) && (events.button.y >= 480 && events.button.y < 580)){
                        choisi = true;
                        return 2;
                    }
                    if((events.button.x >= 290 && events.button.x < 435) && (events.button.y >= 480 && events.button.y < 580)){
                        choisi = true;
                        return 3;
                    }
                    if((events.button.x >= 435 && events.button.x < 620) && (events.button.y >= 480 && events.button.y < 580)){
                        choisi = true;
                        return 4;
                    }
                    break;

                    default:
                    break;
            }
        }
    }
    }
    
    
    //return 0;
        
    }





void Sdljeu::afficherPerso(const char* perso, int x, int y){
    

    Image personnage;
    string tmp = string("data/") + perso;
    string filename = tmp + string(".bmp");
    personnage.loadFromFile(filename.c_str(), renderer);

    TTF_Font * Font = TTF_OpenFont("data/arial.ttf", 10);
        if (!Font){
            cout << "erreur lors de l'ouverture du font" << endl;
            exit(EXIT_FAILURE);
        }
    SDL_Color TextColor {0, 0, 0};
    SDL_Surface * nom = TTF_RenderText_Solid(Font, perso, TextColor);
    SDL_Texture * txtNom = SDL_CreateTextureFromSurface(renderer, nom);
    SDL_Rect rnom = {x + 10, y + 10, 90, 20};

    SDL_Rect rect = {x, y, 100, 200};
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderCopy(renderer, txtNom, NULL, &rnom);
    personnage.draw(renderer, x, y + 40, 90, 150);

    SDL_RenderPresent(renderer);
    

    
}

int Sdljeu::afficherChoixPerso(std::string *tabPerso){
    SDL_DestroyRenderer(renderer);
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 250);
    SDL_RenderClear(renderer);
    int x, y, i = 0;
    for(y = 0; y <= 300; y = y + 300){
        for(x = 0; x <= 400; x = x + 100){
            afficherPerso(tabPerso[i].c_str(), x, y);
            i++;
        }
    }

    bool choix = false;
    SDL_RenderPresent(renderer);
    SDL_Event events;
    while(!choix){
        while(SDL_PollEvent(&events)){
            switch (events.button.button)
            {
            case SDL_BUTTON_LEFT:
            if((events.button.x >= 0 && events.button.x <= 99) && (events.button.y >= 0 && events.button.y <= 200)){
                return 1;
            }
            if((events.button.x >= 100 && events.button.x <= 199) && (events.button.y >= 0 && events.button.y <= 200)){
                return 2;
            }
            if((events.button.x >= 200 && events.button.x <= 299) && (events.button.y >= 0 && events.button.y <= 200)){
                return 3;
            }
            if((events.button.x >= 300 && events.button.x <= 399) && (events.button.y >= 0 && events.button.y <= 200)){
                return 4;
            }
            if((events.button.x >= 400 && events.button.x <= 499) && (events.button.y >= 0 && events.button.y <= 200)){
                return 5;
            }
            if((events.button.x >= 0 && events.button.x <= 99) && (events.button.y >= 300 && events.button.y <= 500)){
                return 6;
            }
            if((events.button.x >= 100 && events.button.x <= 199) && (events.button.y >= 300 && events.button.y <= 500)){
                return 7;
            }
            if((events.button.x >= 200 && events.button.x <= 299) && (events.button.y >= 300 && events.button.y <= 500)){
                return 8;
            }
            if((events.button.x >= 300 && events.button.x <= 399) && (events.button.y >= 300 && events.button.y <= 500)){
                return 9;
            }
            if((events.button.x >= 400 && events.button.x <= 499) && (events.button.y >= 300 && events.button.y <= 500)){
                return 10;
            }

                break;
            
            default:
                break;
            }
        }

    }

}
