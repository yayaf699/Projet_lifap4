#include <iostream>
#include "Histoire.h"
#include <string>
#include <assert.h>

using namespace std;

Histoire::Histoire(Joueur j){

    info.Argent = 0;
    info.j = j;
    info.Position_JOUEUR_X = 0;
    info.Position_JOUEUR_Y = 0;


    Map[47][20] = {
    "###############################################",
    "###############################################",
    "###############################################",
    "###############################################",
    "###############################################",
    "###############################################",
    "###############################################",
    "###############################################",
    "####--#########################################",
    "####--2########################################",
    "###1--#########################################",
    "####---########################################",
    "####---------2#################################",
    "###########--##################################",
    "###########--1#################################",
    "###########--------------------------2#########",
    "##################################---##########",
    "##################################---##########",
    "########################------------ 1#########",
    "########################--#####################",
    "#0------------------------#####################",
    "###############################################"
    };


}

Histoire::Se_Deplacer(string orientation){


    switch (orientation)
    {

    case "haut":
            if(Map[Get_Position_JOUEUR_X()] [Get_Position_JOUEUR_Y()+1] != '#')
            {
                info.Set_Position_JOUEUR_Y(1);
                assert (info.Get_Position_JOUEUR_Y > 0 ); // Ne pas sortir de la Map
            }
            break;
    case "bas":
         if(Map[Get_Position_JOUEUR_X()] [Get_Position_JOUEUR_Y()-1] != '#')
            {
                Info_Joueur.Set_Position_JOUEUR_Y(-1);
                assert (Info_Joueur.Get_Position_JOUEUR_Y > 0 );
            }
            break;
    case "gauche":
         if(Map[Get_Position_JOUEUR_X()-1] [Get_Position_JOUEUR_Y()] != '#')
            {
                Info_Joueur.Set_Position_JOUEUR_X(-1);
                assert (Info_Joueur.Get_Position_JOUEUR_X > 0 );
            }
            break;
    case "droite":
         if(Map[Get_Position_JOUEUR_X()+1] [Get_Position_JOUEUR_Y()] != '#')
            {
                Info_Joueur.Set_Position_JOUEUR_X (1);
                assert (Info_Joueur.Get_Position_JOUEUR_X > 0 );
            }
            break;
    default:
        Info_Joueur.Set_Position_JOUEUR_X (0);
        assert (Info_Joueur.Get_Position_JOUEUR_X > 0 );

        Info_Joueur.Set_Position_JOUEUR_Y (0);
        assert (Info_Joueur.Get_Position_JOUEUR_Y > 0 );

        break;
    }

}

void Histoire::Set_Position_JOUEUR_X(int NbDePas)
{
    info.Position_JOUEUR_X += NbDePas;
}

void Histoire::Set_Position_JOUEUR_Y(int NbDePas)
{
    info.Position_JOUEUR_Y += NbDePas;
}

int Histoire::Get_Position_JOUEUR_X()
{
    return Position_JOUEUR_X;
}

int Histoire::Get_Position_JOUEUR_Y()
{
    return Position_JOUEUR_Y;
}


void Histoire::Lancer_Combat(Joueur IA){

    Combat c(info.j , IA);
    c.combatDeroulement();

}

void Histoire::Determine_Case(){

    if(Map[Get_Position_JOUEUR_X()] [Get_Position_JOUEUR_Y()]  == 1) // 1 => combat
    {
        Joueur IA;
        Lancer_Combat(IA);
    }
    else(Map[Get_Position_JOUEUR_X()] [Get_Position_JOUEUR_Y()]  == 2) // 2 => magasin
    {
        Magasin();
    }


}

void Histoire::Magasin(){

    cout<<"Bienvenue dans le magasin"<<endl;
    cout<<"Aucun article n'est en vente"<<endl;
    cout<<"Vous avez "<<info.Argent<<endl;

}

void Histoire::Deroulement_Aventure(){

    while(Joueur.getVie != 0)
    {
        Se_Deplacer("droite");
        Determine_Case();
        Se_Deplacer("droite");
        Determine_Case();
        Se_Deplacer("haut");
    }

}

