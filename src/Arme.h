#ifndef ARME_H_INCLUDED
#define ARME_H_INCLUDED
#include <string>
#include "Attaque.h"


using namespace std;


class Arme
{

public:

// LES CONSTRUCTEURS ET DESTRUCTEURS

    /**
     * @brief Construct a new Arme object
     * 
     */
    Arme();

    /**
     * @brief Destroy the Arme object
     * 
     */
    ~Arme();

// LES ACCESSEURS 

    /**
     * @brief Get the Nb Attaque object
     * 
     * @return int 
     */
    int getNbAttaque();

    /**
     * @brief Get the Tab Attaque object
     * 
     * @param i 
     * @return Attaque 
     */
    Attaque getTabAttaque(int i);

// LES MUTATEURS

    /**
     * @brief Set the Nb Attaque object
     * 
     * @param nb 
     */
    void setNbAttaque(int nb);

// GESTION ARME

    /**
     * @brief 
     * 
     * @param indice 
     * @param nomAttaque 
     * @param degats 
     * @param degatsSpeciaux 
     * @param typeDegats 
     * @param typeAttaque 
     * @param descAttaque 
     * @param nombreMaxUtilisation 
     * @param etatNombreTour 
     */
    void ajouterAttaque(int indice, 
                        string nomAttaque, 
                        int degats, 
                        int degatsSpeciaux, 
                        string typeDegats, 
                        string typeAttaque, 
                        string descAttaque, 
                        int nombreMaxUtilisation, 
                        int etatNombreTour);

    /**
     * @brief afficher les stats de toutes les attaques
     * 
     */
    void afficherStat();

    /**
     * @brief met à jour le nombre d'utilisation de l'attaque
     * 
     * @param i 
     */
    void MajNombreUtilisation(int i);

private:

    int nbAttaque; // nombre d'attaques
    Attaque *tabAttaque; // tableau d'attaques
};

#endif // ARME_H_INCLUDED
