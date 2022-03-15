#ifndef OBJET_H_INCLUDED
#define OBJET_H_INCLUDED
#include <string>

using namespace std;

// include .txt de tous les objets

class Objet
{

    private:
        string nom; // nom de l'objet
        int *tab; // [0] bonus de vie , [1] bonus de force , [2] bonus de vitesse , [3] bonus de endurance

    public:
        /** CONSTRUCTEURS ET DESTRUCTEURS **/

        // CONSTRUCTEUR
            Objet();

        // CONSTRUCTEUR STRING
            Objet(const string &objet);

        // CONSTRUCTEUR PAR COPIE
            Objet(const Objet &o);

        // DESTRUCTEUR
            ~Objet();

        /** ACCESSEURS ET MUTATEURS **/

        // ACCESSEUR NOM OBJET
            string getNomObjet();

        // ACCESSEUR BONUS DE VIE SUR L'OBJET
            int getBonusVieObjet();

        // ACCESSEUR BONUS DE FORCE SUR L'OBJET
            int getBonusForceObjet();

        // ACCESSEUR BONUS DE VITESSE SUR L'OBJET
            int getBonusVitesseObjet();

        // ACCESSEUR BONUS DE ENDURANCE SUR L'OBJET
            int getBonusEnduranceObjet();

        // MUTATEUR NOM OBJET
            void setNomObjet(const string &n);

        // MUTATEUR BONUS DE VIE SUR L'OBJET
            void setBonusVieObjet(const int &v);

        // MUTATEUR BONUS DE FORCE SUR L'OBJET
            void setBonusForceObjet(const int &f);

        // MUTATEUR BONUS DE VITESSE SUR L'OBJET
            void setBonusVitesseObjet(const int &vi);

        // MUTATEUR BONUS DE ENDURANCE SUR L'OBJET
            void setBonusEnduranceObjet(const int &e);

        /** FONCTIONS OBJETS **/

        // AFFICHER OBJET
            void afficherObjet();

        // UTILISER OBJET
            void utiliserObjet();

        // JETER OBJET
            void jeterObjet();

        // PRENDRE OBJET
            void prendreObjet(const Objet &objet);

};



#endif // OBJET_H_INCLUDED
