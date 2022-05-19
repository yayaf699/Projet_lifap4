#ifndef _IA_H_ 
#define _IA_H_
#include <iostream>
#include <string>
#include "Joueur.h"

class IA{

public:

// CONSTRUCTEURS

    /**
     * @brief Construct a new IA object
     * 
     */
    IA();

    /**
     * @brief Destroy the IA object
     * 
     */
    ~IA();

// ACCESSEURS ET MUTATEURS

  // LES ACCESSEURS

    /**
     * @brief Get the Nombre Choix Attaque object
     * 
     * @return int 
     */
    int getNombreChoixAttaque(); 

    /**
     * @brief Get the Nombre Choix Objet object
     * 
     * @return int 
     */
    int getNombreChoixObjet(); 

    /**
     * @brief Get the Indice Importance Attaque object
     * 
     * @param i 
     * @return float 
     */
    float getIndiceImportanceAttaque(int i); 

    /**
     * @brief Get the Indice Importance Objet object
     * 
     * @param i 
     * @return float 
     */
    float getIndiceImportanceObjet(int i); 

    /**
     * @brief Get the Difficulte object
     * 
     * @return float 
     */
    float getDifficulte(); 

    // les mutateurs

    /**
     * @brief Set the Nombre Choix Attaque object
     * 
     * @param nbAttaque 
     */
    void setNombreChoixAttaque(int nbAttaque); 

    /**
     * @brief Set the Nombre Choix Objet object
     * 
     * @param nbObjet 
     */
    void setNombreChoixObjet(int nbObjet); 

    /**
     * @brief Set the Indice Importance object
     * 
     * @param i 
     */
    void setIndiceImportance(int i); 

    /**
     * @brief Set the Indice Importance Attaque object
     * 
     * @param i 
     * @param iAttaque 
     */
    void setIndiceImportanceAttaque(int i, float iAttaque); 

    /**
     * @brief Set the Indice Importance Objet object
     * 
     * @param i 
     * @param iObjet 
     */
    void setIndiceImportanceObjet(int i, float iObjet); 

    /**
     * @brief Set the Difficulte object
     * 
     * @param d 
     */
    void setDifficulte(float d); 

// GESTION DE L'IA

    /**
     * @brief Récupère le meilleur choix d'action de l'IA
     * 
     * @param vieDeAdversaire 
     * @param IA_joueur 
     * @return string 
     */
    string MeilleurChoix(int vieDeAdversaire, Joueur IA_joueur);

    /**
     * @brief Récupère le meilleur choix d'attaque de l'IA
     * 
     * @param vieDeAdversaire 
     * @param IA_joueur 
     * @return Attaque 
     */
    Attaque MeilleurChoixAttaque(int vieDeAdversaire, Joueur IA_joueur);
    
    /**
     * @brief Récupère le meilleur choix d'objet de l'IA
     * 
     * @param vieDeAdversaire 
     * @param IA_joueur 
     * @return Objet 
     */
    Objet MeilleurChoixObjet(int vieDeAdversaire, Joueur IA_joueur);

private:

    // COTÉ IA 
    int nombreChoixAttaque; // nombre de choix d'attaques disponible par l'IA
    int nombreChoixObjet; // nombre de choix d'objets disponible par l'IA
    float *IndiceImportanceAttaque; // tableau d'indices qui vont conditionner un choix d'attaque
    float *IndiceImportanceObjet; // tableau d'indices qui vont conditionner un choix d'objet
    float difficulte; // % de chance que l'IA aura l'IndiceImportance le plus haut 
};

#endif