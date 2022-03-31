#ifndef _COMBAT_H_
#define _COMBAT_H_
#include "Joueur.h"


class Combat{
	private:
		Joueur Perso;
		Joueur IA;
		bool tour;
		bool fini;
		unsigned int tempsLimiteParTour;

	public:
		Combat();
		Combat(Joueur Perso_, Joueur IA_);
		//~Combat();
		void tourDuPerso();
		void tourIA();
		void combatDeroulement();
		void TraiterActionAttaque(int degats);
		void TraiterActionObjet(int tabStats[3]);

};

#endif
