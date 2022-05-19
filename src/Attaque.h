#ifndef ATTAQUE_H_INCLUDED
#define ATTAQUE_H_INCLUDED
#include <string>

using namespace std;

class Attaque
{

public :

// LES CONSTRUCTEURS 
    
    /**
     * @brief Construct a new Attaque object
     * 
     */
    Attaque();

    /**
     * @brief Construct a new Attaque object
     * 
     * @param nomAttaque_ 
     * @param degats_ 
     * @param degatsSpeciaux_ 
     * @param typeDegats_ 
     * @param typeAttaque_ 
     * @param descAttaque_ 
     * @param nombreMaxUtilisation_ 
     * @param etatNombreTour_ 
     */
    Attaque(string nomAttaque_, int degats_, int degatsSpeciaux_, int typeDegats_, string typeAttaque_, string descAttaque_, int nombreMaxUtilisation_, int etatNombreTour_);

// LES ACCESSEURS

    /**
     * @brief Get the Nom Attaque object
     * 
     * @return string 
     */
    string getNomAttaque();

    /**
     * @brief Get the Degats object
     * 
     * @return int 
     */
    int getDegats();

    /**
     * @brief Get the Degat Sp object
     * 
     * @return int 
     */
    int getDegatSp();

    /**
     * @brief Get the Type Attaque object
     * 
     * @return string 
     */
    string getTypeAttaque();

    /**
     * @brief Get the Type Degats object
     * 
     * @return string 
     */
    string getTypeDegats();

    /**
     * @brief Get the Desc Attaque object
     * 
     * @return string 
     */
    string getDescAttaque();

    /**
     * @brief Get the Nombre Utilisation Reste object
     * 
     * @return int 
     */
    int getNombreUtilisationReste();

    /**
     * @brief Get the Nombre Max Utilisation object
     * 
     * @return int 
     */
    int getNombreMaxUtilisation();

    /**
     * @brief Get the Etat Nombre Tour object
     * 
     * @return int 
     */
    int getEtatNombreTour();

// LES MUTATEURS 

    /**
     * @brief Set the Nom Attaque object
     * 
     * @param nomAttaque_ 
     */
    void setNomAttaque(string nomAttaque_);

    /**
     * @brief Set the Degats object
     * 
     * @param degats_ 
     */
    void setDegats(int degats_);

    /**
     * @brief Set the Degat Sp object
     * 
     * @param degatSP_ 
     */
    void setDegatSp(int degatSP_);

    /**
     * @brief Set the Type Degats object
     * 
     * @param typeDegats_ 
     */
    void setTypeDegats(string typeDegats_);

    /**
     * @brief Set the Type Attaque object
     * 
     * @param typeAttaque_ 
     */
    void setTypeAttaque(string typeAttaque_);

    /**
     * @brief Set the Desc Attaque object
     * 
     * @param descAttaque_ 
     */
    void setDescAttaque(string descAttaque_);

    /**
     * @brief Set the Nombre Utilisation Reste object
     * 
     * @param nombreUtilisationReste_ 
     */
    void setNombreUtilisationReste(int nombreUtilisationReste_);

    /**
     * @brief Set the Nombre Max Utilisation object
     * 
     * @param NombreMaxUtilisation_ 
     */
    void setNombreMaxUtilisation(int NombreMaxUtilisation_);

    /**
     * @brief Set the Etat Nombre Tour object
     * 
     * @param etatNombreTour_ 
     */
    void setEtatNombreTour(int etatNombreTour_);

// GESTION DES ATTAQUES

    /**
     * @brief ajouter une attaque à partir des données dans un .json
     * 
     * @param nomJSON 
     */
    void ajouterAttaqueJSON(const string &nomJSON);

    /**
     * @brief Ajoute une attaque
     * 
     * @param a 
     */
    void ajouterAttaque(Attaque a);

private :

    string nomAttaque;
    int degats;
    int degatsSpeciaux;
    string typeDegats;
    string typeAttaque;
    string descAttaque;
    int nombreUtilisationReste;
    int nombreMaxUtilisation;
    int etatNombreTour;

};

#endif // ATTAQUE_H_INCLUDED