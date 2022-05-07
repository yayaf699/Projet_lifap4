#ifndef _COMBAT_H_
#define _COMBAT_H_
#include "Joueur.h"


class Combat{

public:

// LES CONSTRUCTEURS 

	//CONSTRUCTEUR
	Combat();

	//CONSTRUCTEUR PAR COPIE
	Combat(const Joueur &Perso_, const Joueur &IA_);

// GESTION DU COMBAT

	// 
	void tourDuPerso();

	//
    void Clear();

	//
	void tourIA();

	//
	void combatDeroulement();

	//
	void TraiterActionAttaque(Attaque att);

	//
	void DecisionIa();

	//
	void VerifierEtatJoueur();

private:

	Joueur Perso;
	Joueur IA;
	bool tour;
	bool fini;
	unsigned int tempsLimiteParTour;

};

#endif
