#ifndef INVENTAIRE_H_INCLUDED
#define INVENTAIRE_H_INCLUDED
#include <string>
#include "Objet.h"

using namespace std;


class Inventaire
{
    private:

        int taille_inventaire;
        Objet *inv;

    public:

    /** CONSTRUCTEURS ET DESTRUCTEUR **/

        // CONSTRUCTEUR
            Inventaire();

        // CONSTRUCTEUR PAR COPIE
            Inventaire(const Inventaire &i);

        // DESTRUCTEUR
            ~Inventaire();

    /** GESTION DE L'INVENTAIRE **/

        // AFFICHER INVENTAIRE
            void afficherInventaire();

        // VIDER INVENTAIRE
            void viderInventaire();

        // AJOUTER UN OBJET
            void ajouterObjetInventaire(const Objet &o);

        // JETER UN OBJET
            void jeterObjetInventaire(const unsigned int &i);

        // AFFICHER I-EME OBJET
            void afficherObjetInventaire(const unsigned int &i);

        // RECHERCHER UN OBJET
            void rechercherObjetInventaire(const string &nomObjet);

        // UTILISER UN OBJET
            void utiliserObjetInventaire(const unsigned int &i);


};

#endif // INVENTAIRE_H_INCLUDED
