#include <iostream>
#include <string>
#include <assert.h>
#include "Inventaire.h"
#include "Objet.h"

using namespace std;


    /** CONSTRUCTEURS ET DESTRUCTEUR **/

        // CONSTRUCTEUR
            Inventaire::Inventaire()
            {
                taille_inventaire = 5;
                inv = new Objet[taille_inventaire];

                /* for(int i = 0; i < taille_inventaire; i++) inv[i].Objet(); */ /** ERROR **/
            }

        // CONSTRUCTEUR PAR COPIE
            Inventaire::Inventaire(const Inventaire &in)
            {
                taille_inventaire = in.taille_inventaire;
                /* for(int i = 0; i < taille_inventaire; i++) inv[i].Objet(in.inv[i]); */ /** ERROR **/
            }

        // DESTRUCTEUR
            Inventaire::~Inventaire()
            {
                viderInventaire();
                delete [] inv;
            }

    /** GESTION DE L'INVENTAIRE **/

        // AFFICHER INVENTAIRE
            void Inventaire::afficherInventaire()
            {
                for(int i = 0; i < taille_inventaire; i++)
                {
                    if(inv[i].getNomObjet() == "emplacement vide")
                    {
                        cout<<inv[i].getNomObjet()<<endl;
                    }
                    else
                    {
                        cout<<i<<". ";
                        inv[i].afficherObjet();
                    }
                }
            }

        // VIDER INVENTAIRE
            void Inventaire::viderInventaire()
            {
                for(int i = 0; i < taille_inventaire; i++) inv[i].jeterObjet();
            }

        // AJOUTER UN OBJET
            void Inventaire::ajouterObjetInventaire(const Objet &o)
            {
                int i = 0;
                char reponse;

                while(inv[i].getNomObjet() != "emplacement vide" && i < 5) i++;

                if(inv[i].getNomObjet() != "emplacement vide")
                {
                    cout<<"Inventaire plein!"<<endl;
                    cout<<"Voulez-vous jeter un objet [o/n]? Attention l'objet jeté va disparaitre"<<endl;
                    cin>>reponse;

                        if(reponse == 'o')
                        {
                            afficherInventaire();

                            cout<<"Quel objet voulez-vous jeter en échange de l'objet "<<inv[i].getNomObjet()<<" ?"<<endl;
                            cin>>i;

                            inv[i].prendreObjet(o);
                        }
                        else if (reponse == 'n')
                        {
                            cout<<"vous gardez l'objet "<<inv[i].getNomObjet()<<endl;
                        }
                }
                else
                {
                    inv[i].prendreObjet(o);
                }


            }

        // JETER UN OBJET
            void Inventaire::jeterObjetInventaire(const unsigned int &i)
            {
                if((i < 0) && (i > taille_inventaire))
                {
                    cout<<"Impossible !"<<endl;
                }
                else
                {
                    if(i != taille_inventaire-1)
                    {
                        for(int j = i; j < taille_inventaire-1; j++) inv[i] = inv[i+1];
                    }
                     inv[taille_inventaire-1].jeterObjet();
                }
            }

        // AFFICHER I-EME OBJET
            void Inventaire::afficherObjetInventaire(const unsigned int &i)
            {
                if((i > 0) && (i < taille_inventaire))
                {
                    inv[i].afficherObjet();
                }
                else
                {
                    cout<<"Impossible !"<<endl;
                }
            }

        // RECHERCHER UN OBJET
            void Inventaire::rechercherObjetInventaire(const string &nomObjet)
            {
                int i = 0;

                while(i < taille_inventaire && nomObjet != inv[i].getNomObjet())
                {
                    i++;
                }

                if(i == taille_inventaire-1 && nomObjet != inv[i].getNomObjet())
                {
                    cout<<"vous ne possedez pas cet objet."<<endl;
                }
                else
                {
                    cout<<"vous possedez cet objet !"<<endl;
                }
            }

        // UTILISER UN OBJET
            void Inventaire::utiliserObjetInventaire(const unsigned int &i)
            {
                assert(i > 0);
                assert(i < taille_inventaire);

                inv[i].utiliserObjet();
            }
