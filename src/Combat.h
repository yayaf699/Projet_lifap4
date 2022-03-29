#ifndef _COMBAT_H_
#define _COMBAT_H_
#include "Joueur.h" 


class Combat{
	private:
		Joueur *Perso;
		Joueur *IA;
		bool tour;
		unsigned int tempsLimiteParTour;

	public:
		Combat();
		Combat(Joueur *Perso_, Joueur *IA_);
		~Combat();	
		void tourDuPerso();
		void tourIA();
		void combatDeroulement();

};

#endif