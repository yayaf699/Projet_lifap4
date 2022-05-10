#ifndef HISTOIRE_H_INCLUDED
#define HISTOIRE_H_INCLUDED

#include "Joueur.h"
#include "Combat.h"
#include <string>




class Histoire{

public:


	Histoire(Joueur j);


    // GESTION DU MODE HISTOIRE

	// Fonction gerant le deplacement du joueur sur la carte
	void Se_Deplacer(string orientation);

	// Fonction pour lancer un combat
    void Lancer_Combat(Joueur IA);

	// Fonction pour ouvrir le magasin
	void Magasin();

    // Fonction pour determiner la case du Joueur

	void Determine_Case();


	// Fonction pour ouvrir le magasin
	void Deroulement_Aventure();

	// LES ACCESSEURS ET MUTATEURS

    // ACCESSEUR Position X du Joueur

	int Get_Position_JOUEUR_X();

    // ACCESSEURS Position Y du Joueur

	int Get_Position_JOUEUR_Y();

    // MUTATEUR Position X du Joueur

	void Set_Position_JOUEUR_X(int NbDePas);

    // MUTATEUR Position Y du Joueur

	void Set_Position_JOUEUR_Y(int NbDePas);



private:

	int Map[47][20]; // la carte fait

	struct Info_Joueur
	{
	    Joueur j;
	    int Position_JOUEUR_X[0];
        int Position_JOUEUR_Y[0];
        int Argent;
	};

};


#endif // HISTOIRE_H_INCLUDED
