#include "Combat.h"
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


using namespace std;

// LES CONSTRUCTEURS 

	// contructeur
	Combat::Combat() 
	{  
		tour = true;
		fini = false;
		vainqueur = true;
		tempsLimiteParTour = 20;
	}

	// constructeur par copie
	Combat::Combat(Joueur Perso_, Joueur IA_) 
	{ 
		tour = true;
		fini = false;
		vainqueur = true;
		tempsLimiteParTour = 20;
	}

// LES ACCESSEURS

	// accesseur Perso
	Joueur Combat::getPerso() { return Perso; }

	// accesseur Joueur
	Joueur Combat::getIA_adversaire() { return IA_adversaire; }

	// accesseur tour
	bool Combat::getTour() { return tour; }

	// accesseur fini
	bool Combat::getFini() { return fini; }

	// accesseur vainqueur
	bool Combat::getVainqueur() { return vainqueur; }

	// acesseur tempsLimiteParTour
	unsigned int Combat::getTempsLimiteParTour() { return tempsLimiteParTour; }

// LES MUTATEURS

	// mutateur tour
	void Combat::setTour(bool t) { tour = t; }

	// mutateur fini
	void Combat::setFini(bool f) { fini = f; }

	// mutateur vainqueur
	void Combat::setVainqueur(bool v) { vainqueur = v; }

	// mutateur tempsLimiteParTour
	void Combat::setTempsLimiteParTour(unsigned int temps) { tempsLimiteParTour = temps; }

// GESTION DU COMBAT

	// traite le tour du perso
	void Combat::tourDuPerso(Sdljeu &sdl) 
	{  
		// ###################################################################################################### VERSION TEXT 
		int choix, vie_t0, vie_t1;
		sdl.majLogPerso(Perso);
		sdl.majLogIA(IA_adversaire);
		if(Perso.getStats().getVie() < 0)
		{
			cout<<Perso.getNom()<<" EST MORT"<<endl; // boite de dialogue + animation mort
			string txt = Perso.getNom() + " EST MORT";
			sdl.majlogs(txt.c_str(), false, Perso);
			vainqueur = false;
			fini = true;
		}
			do{
				cout<< "TOUR DE "<< Perso.getNom()<<endl; // boite de dialogue
				cout<<"1. Attaque"<<endl<<"2. Inventaire"<<endl; // version sdl scan code avec les fleches pour aller sur la case attaque ou inventaire et Entrer pour valider // boite de dialogue
				cout<<"QUE VOULEZ VOUS FAIRE ?"<<endl;// boite de dialogue
				if(!sdl.withsdl) cin>>choix; 

				else {
					string txt = "QUE VOULEZ VOUS FAIRE ?";
					choix = sdl.majlogs(txt, true, Perso);
					}
			}
			while(choix != 1 && choix != 2);

			if(choix == 1)
			{
				int choixAttaque;
				do
				{	
					Perso.getArme().afficherStat(); // affiche les attaques avec stats et nb utilisation restante // boite de dialogue // version sdl scan code avec les fleches pour aller sur la case attaque ou inventaire et Entrer pour valider, ECHAP pour revenir au choix Attaque/Objet recursivité
					cout<<"\n Quelle attaque voulez vous utiliser ?"; // pas dans la version sdl
					if(!sdl.withsdl) cin>>choixAttaque;
					else{
						choixAttaque = sdl.majlogsChoix(Perso, true);
					}

					if(Perso.getArme().getTabAttaque(choixAttaque-1).getNombreUtilisationReste() == 0)
					{	
						cout<<"IMPOSSIBLE ! Nombre d'utilisation de cette attaque est à 0"<<endl; // boite de dialogue	
					} 
				} while (Perso.getArme().getTabAttaque(choixAttaque-1).getNombreUtilisationReste() == 0);


				vie_t0 = IA_adversaire.getStats().getVie(); // la vie l'adversaire avant l'attaque 
				TraiterActionAttaque(Perso.Attaquer(choixAttaque-1)); 
				vie_t1 = IA_adversaire.getStats().getVie(); // la vie l'adversaire apres l'attaque


				cout<<"VOUS UTILISEZ L'ATTAQUE :"<<Perso.getArme().getTabAttaque(choixAttaque-1).getNomAttaque()<<endl; // boite de dialogue
				if(vie_t1-vie_t0 > Perso.getArme().getTabAttaque(choixAttaque-1).getDegats()) // si random degat critique // boite de dialogue
				{
					cout<<"DEGATS CRITIQUE !!!"<<endl; 
				}

				if(IA_adversaire.getEtat() != "") // Les degats speciaux ont été activés // boite de dialogue
				{
					cout<<IA_adversaire.getNom()
						<<" souffre de "
						<<IA_adversaire.getEtat()
						<<" pendant "
						<<IA_adversaire.getNbTourEtat()
						<<" tours."<<endl;
				}

				cout<<"LA BARRE DE VIE DE L'ADVERSAIRE BAISSE: "<< vie_t0 - vie_t1 <<" pv"<<endl; // boite de dialogue
				cout<<"LA VIE DE VOTRE ADVERSAIRE EST À: "<<IA_adversaire.getStats().getVie()<<endl; // fonction sdl annimation de la barre de vie qui baisse

			} 
			else if (choix == 2)
			{
				int choixObjet;

				Perso.getStats().afficherStat(); // sdl stats du perso dans une case sur le coté
				cout<<endl;
				Perso.getInv().afficherInventaire(); // boite de dialogue // version sdl scan code avec les fleches pour aller sur la case attaque ou inventaire et Entrer pour valider 
				cout<<"\n Quelle objet voulez vous utiliser ?"; // pas dans la version sdl
				if(!sdl.withsdl) cin>>choixObjet;
				else{
					sdl.majlogsChoix(Perso, false);
				}

				cout<<"VOUS UTILISEZ L'OBJET: "<<Perso.getInv().getInventaire(choixObjet-1).getNomObjet()<<endl; // boite de dialogue

				if(Perso.getInv().getInventaire(choixObjet-1).getVieObjet() > 0) // bonus vie sdl animation barre de vie qui monte
				{
					vie_t0 = Perso.getStats().getVie();
					Perso.utiliserObjet(Perso.getInv().getInventaire(choixObjet-1));
					vie_t1 = Perso.getStats().getVie();

					cout << "VOTRE VIE AUGMENTE DE :" << vie_t1 - vie_t0 << endl; // boite de dialogue
					cout<< "VOTRE VIE EST À: "<<Perso.getStats().getVie()<<" pv"<<endl; // bonus vie sdl animation barre de vie qui monte
				}
				else // autre bonus animation le personnage clignote vert prendant qql secondes
				{
					Perso.utiliserObjet(Perso.getInv().getInventaire(choixObjet-1));
				}
			} 

		// passage au tour de l'IA
		tour = false;		
	}

	// traite le tour de l'IA
	void Combat::tourIA(Sdljeu &sdl) 
	{  
		if(IA_adversaire.getStats().getVie() < 0)
		{
			cout<<IA_adversaire.getNom()<<" EST MORT"<<endl; // boite de dialogue + animation mort
			string txt = IA_adversaire.getNom() + " EST MORT";
			if(sdl.withsdl) sdl.majlogs(txt.c_str(), false, Perso);
			vainqueur = false;
			fini = true;
		}
		int vie_t0, vie_t1;
		Attaque attaqueChoisi = IA_cerveau.MeilleurChoixAttaque(Perso.getStats().getVie(), IA_adversaire);// on sauvegarde le choix random
		Objet objetChoisi = IA_cerveau.MeilleurChoixObjet(Perso.getStats().getVie(), IA_adversaire);
		

			if(IA_cerveau.MeilleurChoix(Perso.getStats().getVie(), IA_adversaire) == "Attaque") // si l'IA choisi d'attaquer
			{
				vie_t0 = Perso.getStats().getVie(); // la vie l'adversaire avant l'attaque 
				TraiterActionAttaque(attaqueChoisi);
				vie_t1 = Perso.getStats().getVie(); // la vie l'adversaire apres l'attaque
			
				cout<<IA_adversaire.getNom()<<" UTILISE L'ATTAQUE :"<<attaqueChoisi.getNomAttaque()<<endl; // boite de dialogue
				if(vie_t0 - vie_t1 > attaqueChoisi.getDegats()) // si random degat critique // boite de dialogue
				{
					cout<<"DEGATS CRITIQUE !!!"<<endl; 
				}

				if(Perso.getEtat() != "") // Les degats speciaux ont été activés // boite de dialogue
				{
					cout<<Perso.getNom()
						<<" souffre de "
						<<Perso.getEtat()
						<<" pendant "
						<<Perso.getNbTourEtat()
						<<" tours."<<endl;
				}
				cout<<"VOTRE BARRE DE VIE DE BAISSE DE: "<< vie_t0 - vie_t1 <<" pv"<<endl; // boite de dialogue
				cout<<"VOTRE VIE EST À: "<<Perso.getStats().getVie()<<endl; // fonction sdl annimation de la barre de vie qui baisse
			}
			else // si l'IA choisi d'utiliser un objet
			{ 
				cout<<IA_adversaire.getNom()<<" UTILISE L'OBJET "<<objetChoisi.getNomObjet()<<endl; // boite de dialogue

				if(objetChoisi.getVieObjet() > 0)
				{ // bonus vie sdl animation barre de vie qui monte

					vie_t0 = IA_adversaire.getStats().getVie();
					IA_adversaire.utiliserObjet(objetChoisi);  
					vie_t1 = IA_adversaire.getStats().getVie();

					cout << "VOTRE VIE AUGMENTE DE :" << vie_t1 - vie_t0 << endl; // boite de dialogue
					cout<< "VOTRE VIE EST À: "<<IA_adversaire.getStats().getVie()<<" pv"<<endl; // bonus vie sdl animation barre de vie qui monte
				}
				else
				{ // autre bonus animation le personnage clignote vert prendant qql secondes
					IA_adversaire.utiliserObjet(objetChoisi);
				}
			}
		
		tour = true; // passage au tour du joueur
	}

	// traite attaque
	void Combat::TraiterActionAttaque(Attaque a) 
	{  
		if(tour) // perso joue, IA subit
		{
			cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx PERSO"<<endl;

				int intRandom = rand() % 100;
				if(intRandom < (Perso.getStats().getVitesse() * Perso.getStats().getForce())) // vitesse*force = % de chance d'avoir un COUP CRITIQUE
				{
					srand(time(NULL));
					float MultiplicateurCrit = (((rand()%20)+5)/100)+1;  // 1.05 < x < 1.25
					int degatCrit = int(MultiplicateurCrit*a.getDegats());
	
					// MAJ vie IA
					IA_adversaire.MajVieJoueur(degatCrit);
				}
				else
				{
					// MAJ vie IA
					IA_adversaire.MajVieJoueur(a.getDegats()); 
				}
	
				if(intRandom < 10 && IA_adversaire.getNbTourEtat() == 0 && a.getDegatSp() != 0) // 10% de chance que les degats speciaux s'activent et s'ils ne sont pas deja activés 
				{
					IA_adversaire.setEtat(a.getTypeDegats());
					IA_adversaire.setNbTourEtat(a.getEtatNombreTour());
				}
			
			int cmpt = 0;
			while(a.getNomAttaque() != Perso.getArme().getTabAttaque(cmpt).getNomAttaque()) cmpt++;

			Perso.getArme().MajNombreUtilisation(cmpt);
		}
		else // IA joue, perso subit
		{
			cout<<"yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy IA"<<endl;

				int intRandom = rand() % 100;
				if(intRandom < (IA_adversaire.getStats().getVitesse() * IA_adversaire.getStats().getForce())) // vitesse*force = % de chance d'avoir un COUP CRITIQUE
				{
					srand(time(NULL));
					float MultiplicateurCrit = (((rand()%20)+5)/100)+1;  // 1.05 < x < 1.25
					int degatCrit = int(MultiplicateurCrit*a.getDegats());
	
					// MAJ vie IA
					Perso.MajVieJoueur(degatCrit);
				}
				else
				{
					// MAJ vie IA
					Perso.MajVieJoueur(a.getDegats()); 
				}
	
				if(intRandom < 10 && Perso.getNbTourEtat() == 0 && a.getDegatSp() != 0) // 10% de chance que les degats speciaux s'activent et s'ils ne sont pas deja activés 
				{
					Perso.setEtat(a.getTypeDegats());
					Perso.setNbTourEtat(a.getEtatNombreTour());
				}

			int cmpt = 0;
			while(a.getNomAttaque() != IA_adversaire.getArme().getTabAttaque(cmpt).getNomAttaque()) cmpt++;

			IA_adversaire.getArme().MajNombreUtilisation(cmpt);
		}
	}

	// bouvcle du combat
	void Combat::combatDeroulement(Joueur A_me, Joueur B_ia, Sdljeu &sdl) 
	{  
		Perso = A_me;
		IA_adversaire = B_ia;

		if(sdl.withsdl) sdl.initCombat(A_me, B_ia);

		cout<<"PERSO:"<<endl;
		cout<<"---------------------------------------------------------------"<<endl;
		Perso.afficherJoueur();
		cout<<"---------------------------------------------------------------"<<endl;
		IA_adversaire.afficherJoueur();
		cout<<"---------------------------------------------------------------"<<endl;


		while(!fini)
		{
			tourDuPerso(sdl);
			tourIA(sdl);
		}

		// si perso vainqueur il recoit un récompense en pieces
		// animation de fin de combat 

		if(vainqueur) // si perso gagne
		{
			//perso get pieces
			// boite de dialogue
		}
		else // si IA gagne
		{
			// boite de dialogue
		} 
	}