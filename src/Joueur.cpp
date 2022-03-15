#include <iostream>
#include "Joueur.h"
#include "Inventaire.h"
#include <string.h>

using namespace std;

    /** CONSTRUCTEURS ET DESTRUCTEUR **/

        // CONSTRUCTEUR
            Joueur::Joueur()
            {
                nom = "Ocelot"; // nom par défaut si le joueur ne choisi
                tab = new int[4];
                tab[0] = 20; // la vie à 20/20
                
                for(int i = 1; i < 5; i++) tab[i] = 10; // 10/20 par défaut

                // on initialise l'inventaire
                // rajouter le constructeur de l'arme
            }

        // CONSTRUCTEUR PERSONNALISÉ
            Joueur::Joueur(const string &n, const int &vi, const int &f, const int &v, const int &e)
            {
                nom = n;

                // le joueur possède 40 points à utiliser dans ses stats
                tab = new int[4];
                tab[0] = vi;
                tab[1] = f;
                tab[2] = v;
                tab[3] = e;

               // on initialise l'inventaire
                // rajouter le constructeur de l'arme
            }

        // DESTRUCTEUR
            Joueur::~Joueur()
            {
                nom = " ";
                delete [] tab;

                // rajouter le destructeur d'inventaire
                // rajouter le destructeur de l'arme
            }

    /** ACCESSEURS ET MUTATEURS **/

        // ACCESSEUR NOM
            string Joueur::getNom()
            {
                return nom;
            }

        // ACCESSEUR VIE
            int Joueur::getVie()
            {
                return tab[0];
            }

        // ACCESSEUR FORCE
            int Joueur::getForce()
            {
                return tab[1];
            }

        // ACCESSEUR VITESSE
            int Joueur::getVitesse()
            {
                return tab[2];
            }

        // ACCESSEUR ENDURANCE
            int Joueur::getEndurance()
            {
                return tab[3];
            }

        // MUTATEUR NOM
            void Joueur::setNom(const string& n)
            {
                nom = n;
            }

        // MUTATEUR VIE
            void Joueur::setVie(const int &vi)
            {
                tab[0] = vi;
            }

        // MUTATEUR FORCE
            void Joueur::setForce(const int &f)
            {
                tab[1] = f;
            }

        // MUTATEUR VITESSE
            void Joueur::setVitesse(const int &v)
            {
                tab[2] = v;
            }

        // MUTATEUR ENDURANCE
            void Joueur::setEndurance(const int &e)
            {
                tab[3] = e;
            }
