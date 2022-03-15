#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED
#include <string.h>

using namespace std;

class Joueur
{
    private:

        string nom;
        int *tab; // [0] vie , [1] force , [2] vitesse , [3] endurance

    public:

    /** CONSTRUCTEURS ET DESTRUCTEUR **/

        // CONSTRUCTEUR
            Joueur();

        // CONSTRUCTEUR PERSONNALISÉ
            Joueur(const string &n, const int &vi, const int &f, const int &v, const int &e);

        // DESTRUCTEUR
            ~Joueur();

    /** ACCESSEURS ET MUTATEURS **/

        // ACCESSEUR NOM
            string getNom();

        // ACCESSEUR VIE
            int getVie();

        // ACCESSEUR FORCE
            int getForce();

        // ACCESSEUR VITESSE
            int getVitesse();

        // ACCESSEUR ENDURANCE
            int getEndurance();

        // MUTATEUR NOM
            void setNom(const string& n);

        // MUTATEUR VIE
            void setVie(const int &vi);

        // MUTATEUR FORCE
            void setForce(const int &f);

        // MUTATEUR VITESSE
            void setVitesse(const int &v);

        // MUTATEUR ENDURANCE
            void setEndurance(const int &e);

};

#endif // JOUEUR_H_INCLUDED
