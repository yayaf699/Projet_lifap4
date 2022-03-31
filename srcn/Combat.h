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
		Combat(const Joueur &Perso_, const Joueur &IA_);
		//~Combat();
		void tourDuPerso();
		void tourIA();
		void combatDeroulement();
		void TraiterActionAttaque(int degats);
		

};

#endif
