#include <iostream>
#include "Objet.h"
#include "Joueur.h"

using namespace std;

        /** CONSTRUCTEURS ET DESTRUCTEURS **/

        // CONSTRUCTEUR
            Objet::Objet()
            {
                nom = "emplacement vide";
                tab = new int[4];

                for(int i = 0; i < 4; i++) tab[i] = 0;

            }

        // CONSTRUCTEUR STRING
            Objet::Objet(const string &objet)
            {
                // nom = premier mot du string

                // tab[0] = int(deuxieme mot)
                // tab[1] = int(troisieme mot)
                // tab[2] = int(quatrieme mot)
                // tab[3] = int(cinquieme mot)
            }

        // CONSTRUCTEUR PAR COPIE
            Objet(const Objet &o)
            {
                nom = objet.nom;
                for(int i = 0; i < 4; i++) tab[i] = objet.tab[i];
            }

        // DESTRUCTEUR
            Objet::~Objet()
            {
                jeterObjet();
                delete [] tab;
            }

        /** ACCESSEURS ET MUTATEURS **/

        // ACCESSEUR NOM OBJET
            string getNomObjet()
            {
                return nom;
            }

        // ACCESSEUR BONUS DE VIE SUR L'OBJET
            int getBonusVieObjet()
            {
                return tab[0];
            }

        // ACCESSEUR BONUS DE FORCE SUR L'OBJET
            int getBonusForceObjet()
            {
                return tab[1];
            }

        // ACCESSEUR BONUS DE VITESSE SUR L'OBJET
            int getBonusVitesseObjet()
            {
                return tab[2];
            }

        // ACCESSEUR BONUS DE ENDURANCE SUR L'OBJET
            int getBonusEnduranceObjet()
            {
                return tab[3];
            }

        // MUTATEUR NOM OBJET
            void setNomObjet(const string &n)
            {
                nom = n;
            }

        // MUTATEUR BONUS DE VIE SUR L'OBJET
            void setBonusVieObjet(const int &v)
            {
                tab[0] = v;
            }

        // MUTATEUR BONUS DE FORCE SUR L'OBJET
            void setBonusForceObjet(const int &f)
            {
                tab[1] = f;
            }

        // MUTATEUR BONUS DE VITESSE SUR L'OBJET
            void setBonusVitesseObjet(const int &vi)
            {
                tab[2] = vi;
            }

        // MUTATEUR BONUS DE ENDURANCE SUR L'OBJET
            void setBonusEnduranceObjet(const int &e)
            {
                tab[3] = e;
            }

        /** FONCTIONS OBJETS **/

        // AFFICHER OBJET
            void afficherObjet()
            {
                cout<<nom<<" ";
                cout<<"Bonus vie: +"<<tab[0]<<" ";
                cout<<"Bonus vitesse: +"<<tab[1]<<" ";
                cout<<"Bonus force: +"<<tab[2]<<" ";
                cout<<"Bonus endurance: +"<<tab[3]<<" ";
                cout<<endl;
            }

        // UTILISER OBJET
            void utiliserObjet()
            {
                cout<<"Vous utilisez l'objet: "<<nom<<endl;

                // BONUS DE VIE UTILISÉ
                    if(tab[0] + Joueur::getVie() > 20)
                    {
                        Joueur::setVie(20);
                    }
                    else
                    {
                        Joueur::setVie(tab[0] + Joueur::getVie());
                    }

                // BONUS DE FORCE UTILISÉ
                    if(tab[1] + Joueur::getForce() > 20)
                    {
                        Joueur::setForce(20);
                    }
                    else
                    {
                        Joueur::setForce(tab[1] + Joueur::getVie());
                    }

                // BONUS DE VITESSE UTILISÉ
                    if(tab[2] + Joueur::getVitesse() > 20)
                    {
                        Joueur::setVitesse(20);
                    }
                    else
                    {
                        Joueur::setVitesse(tab[2] + Joueur::getVie());
                    }

                // BONUS D'ENDURANCE UTILISÉ
                    if(tab[3] + Joueur::getEndurance() > 20)
                    {
                        Joueur::setEndurance(20);
                    }
                    else
                    {
                        Joueur::setEndurance(tab[3] + Joueur::getVie());
                    }

                jeterObjet(); // apres avoir utilisé l'objet il disparait
            }

        // JETER OBJET
            void jeterObjet()
            {
                nom = "emplacement vide";
                for(int i = 0; i < 4; i++) tab[i] = 0;
            }

        // PRENDRE OBJET
            void prendreObjet(const Objet &o)
            {
                Objet(o);
            }
