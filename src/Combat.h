#ifndef _COMBAT_H_
#define _COMBAT_H_
#include "Joueur.h"
#include "IA.h"
#include "jeuSdl.h"


class Combat{

public:

// LES CONSTRUCTEURS 

	/**
	 * @brief Construct a new Combat object
	 * 
	 */
	Combat();

	/**
	 * @brief Construct a new Combat object
	 * 
	 * @param Perso_ 
	 * @param IA_ 
	 */
	Combat(Joueur Perso_, Joueur IA_);

// LES ACCESSEURS

	/**
	 * @brief Get the Perso object
	 * 
	 * @return Joueur 
	 */
	Joueur getPerso();

	/**
	 * @brief Get the IA adversaire object
	 * 
	 * @return Joueur 
	 */
	Joueur getIA_adversaire();

	/**
	 * @brief Get the Tour object
	 * 
	 * @return true 
	 * @return false 
	 */
	bool getTour();

	/**
	 * @brief Get the Fini object
	 * 
	 * @return true 
	 * @return false 
	 */
	bool getFini();

	/**
	 * @brief Get the Vainqueur object
	 * 
	 * @return true 
	 * @return false 
	 */
	bool getVainqueur();

	/**
	 * @brief Get the Temps Limite Par Tour object
	 * 
	 * @return unsigned int 
	 */
	unsigned int getTempsLimiteParTour();

// LES MUTATEURS

	/**
	 * @brief Set the Tour object
	 * 
	 * @param t 
	 */
	void setTour(bool t);

	/**
	 * @brief Set the Fini object
	 * 
	 * @param f 
	 */
	void setFini(bool f);

	/**
	 * @brief Set the Vainqueur object
	 * 
	 * @param v 
	 */
	void setVainqueur(bool v);

	/**
	 * @brief Set the Temps Limite Par Tour object
	 * 
	 * @param temps 
	 */
	void setTempsLimiteParTour(unsigned int temps);

// GESTION DU COMBAT

	/**
	 * @brief Traite le tour du perso
	 * 
	 * @param sdl 
	 */
	void tourDuPerso(Sdljeu &sdl);

	/**
	 * @brief Traite le tour de l'IA
	 * 
	 * @param sdl 
	 */
	void tourIA(Sdljeu &sdl);

	/**
	 * @brief Traite l'action d'ataque
	 * 
	 * @param a 
	 */
	void TraiterActionAttaque(Attaque a);

	/**
	 * @brief Boucle de combat
	 * 
	 * @param A_me 
	 * @param B_ia 
	 * @param sdl 
	 */
	void combatDeroulement(Joueur A_me, Joueur B_ia, Sdljeu &sdl);



private:

	Joueur Perso;
	Joueur IA_adversaire;

	IA IA_cerveau;
	bool tour; // true pour joueur, false pour IA
	bool fini; // true le combat continue, false le combat s'arrete
	bool vainqueur; // true = perso, false = IA
	unsigned int tempsLimiteParTour; // en seconde

};

#endif
