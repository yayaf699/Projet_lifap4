
#include "IA.h"
#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;


// CONSTRUCTEURS

    // constructeur
    IA::IA()
    {  
      nombreChoixObjet = nombreChoixAttaque = 4;

      IndiceImportanceObjet = new float [nombreChoixObjet];
      IndiceImportanceAttaque = new float [nombreChoixAttaque];
      difficulte = 0.99;

      for(int i = 0; i < nombreChoixObjet; i++)
      {
       IndiceImportanceObjet[i] = -1;
       IndiceImportanceAttaque[i] = -1; 
      }
    }

    // destructeur
    IA::~IA()
    {  
      nombreChoixObjet = nombreChoixAttaque = 0;
      for(int i = 0; i < nombreChoixObjet; i++)
      {
       IndiceImportanceObjet[i] = 0;
       IndiceImportanceAttaque[i] = 0; 
      }

      delete IndiceImportanceAttaque;
      delete IndiceImportanceObjet;
    }

// ACCESSEURS ET MUTATEURS

  // LES ACCESSEURS

    // accesseur nombreChoixAttaque
    int IA::getNombreChoixAttaque(){ return nombreChoixAttaque;} 

    // accesseur nombreChoixObjet
    int IA::getNombreChoixObjet(){ return nombreChoixObjet;} 

    // accesseur IndiceImportanceAttaque
    float IA::getIndiceImportanceAttaque(int i){ return IndiceImportanceAttaque[i];} 

    // accesseur IndiceImportanceObjet
    float IA::getIndiceImportanceObjet(int i){ return IndiceImportanceObjet[i];} 

    // accesseur difficulte
    float IA::getDifficulte(){ return difficulte;} 

  // LES MUTATEURS

    // mutateur nombreChoixAttaque
    void IA::setNombreChoixAttaque(int nbAttaque){ nombreChoixAttaque = nbAttaque; } 

    // mutateurs nombreChoixObjet
    void IA::setNombreChoixObjet(int nbObjet){ nombreChoixObjet = nbObjet; } 

    // mutateurs IndiceImportanceAttaque
    void IA::setIndiceImportanceAttaque(int i, float iAttaque){ IndiceImportanceAttaque[i] = iAttaque; } 

    // mutateurs IndiceImportanceObjet
    void IA::setIndiceImportanceObjet(int i, float iObjet){ IndiceImportanceObjet[i] = iObjet; } 

    // mutateurs difficulte
    void IA::setDifficulte(float d){ difficulte = d; } 

// GESTION DE L'IA

    // MeilleurChoix
    string IA::MeilleurChoix(int vieDeAdversaire, Joueur IA_joueur)
    {
      bool TrueFalse; 
      bool existeObjetVie;
      // établir le rapport vie_ia et vie_adversaire
      int rapport = IA_joueur.getStats().getVie() - vieDeAdversaire;

      // les fréquences attaque et objet
      float choixAttaque, choixObjet;

      if(nombreChoixObjet == 0) // si inventaire vide, l'IA ne fait qu'attaquer
      { 
        return "Attaque"; // fonction void on appelera meilleurchoixAttaque
      }
      else 
      {
        if( rapport < 0) // si rapport négatif on établit les probabilités d'utiliser un objet
        { 
          choixObjet = (-rapport/99) * difficulte; // la frequence de choisir d'utiliser un objet mulitplié par la difficulté"
          choixAttaque = 1 - choixObjet;

          for(int i = 0; i < nombreChoixObjet; i++)
          {
            if(IA_joueur.getInv().getInventaire(i).getVieObjet() > 0) // si objet vie
            {
              existeObjetVie = true;
            }
            else // sinon
            {
              existeObjetVie = false;
            }
          }

          TrueFalse = (rand() % 100) < (choixObjet*100); // choix au hasard sous l'influence de le frequence choixObjet + si existe un objet pour regnerer la vie
          if(TrueFalse && existeObjetVie)
          {
            return "Objet";
          }
          else
          {
            return "Attaque";
          }
        }
        else // sinon on établit les probabalités d'attaquer
        { 
          choixAttaque = (1 - rapport/99) * difficulte; // la frequence de choisir d'attaquer mulitplié par la difficulté"
          choixObjet = 1 - choixAttaque;

          TrueFalse = (rand() % 100) < (choixAttaque*100); // choix au hasard sous l'influence de le frequence choixAttaque
          if(TrueFalse == true)
          {
            return "Attaque";
          }
          else
          {
            return "Objet";
          }
        }
      }
    }

    // MeilleurChoixAttaque
    Attaque IA::MeilleurChoixAttaque(int vieDeAdversaire, Joueur IA_joueur)
    {
      return IA_joueur.getArme().getTabAttaque(0); /////////////////////////////////////////////////////////////////////////// test
    }
    
    // MeilleurChoixObjet
    Objet IA::MeilleurChoixObjet(int vieDeAdversaire, Joueur IA_joueur)
    { /*
      assert(nombreChoixObjet > 0);

      if(IA_joueur.getStats().getVie() < vieDeAdversaire && IA_joueur.getStats().getVie() < 50) // regnerer sa vie est la priorité 
      {
      // on etablie un rapport entre notre vie et celle de l'adversaire
        for(int i = 0; i < nombreChoixObjet; i++)
        {
          if(IA_joueur.getInv().getInventaire(i).getVieObjet() > 0) // si c'est un objet qui regenere la santé
          {
            int rapport = (IA_joueur.getStats().getVie() + IA_joueur.getInv().getInventaire(i).getVieObjet()) - 100; // le nombre de pv surplus si l'objet est utilisé
            IndiceImportanceObjet[i] = rapport;
            // plus le rapport est proche de 0 plus l'objet a des chances de 0
          }
        }
          // rapportSUM
          int rapportSUM = 0;

          // on determine la somme du tableau
          for(int i = 0; i < nombreChoixObjet; i++)
          {
            rapportSUM = rapportSUM + IndiceImportanceObjet[i];
          }

          // on etablie une proba 1-(iRapport/rapportSUM)
          int nbObjetsBonusAutre = 0; // compteur d'objet bonus != vie
          for(int i = 0; i < nombreChoixObjet; i++)
          { 
            if(IA_joueur.getInv().getInventaire(i).getVieObjet() > 0) // si c'est un objet qui regenere la vie
            {
              IndiceImportanceObjet[i] = 1-(IndiceImportanceObjet[i]/rapportSUM+5); // +5 pour les proba des objets qui donnent d'autre bonus
            }
            else // si c'est un objet qui ne regenere pas la vie
            {
              nbObjetsBonusAutre++;
            }
          }

          // on etabli les proba des objets qui ne regenere pas de vie
          for(int i = 0;  i < nombreChoixObjet; i++)
          {
            if(IA_joueur.getInv().getInventaire(i).getVieObjet() == 0) // si c'est un objet qui ne regenere pas la vie
            {
              IndiceImportanceObjet[i] = ((5/rapportSUM+5)/nbObjetsBonusAutre);
            }
          }
      }
      else // regnerer sa vie n'est pas la priorité 
      {
          // 90% de chance d'utiliser un objet qui ne regenere pas la vie reparti avec le meme %

          int nbObjetsBonusAutre = 0; // compteur d'objet bonus != vie
          for(int i = 0; i < nombreChoixObjet; i++)
          {
            if(IA_joueur.getInv().getInventaire(i).getVieObjet() == 0)
            {
              nbObjetsBonusAutre++;
            }
          }

          // on etabli les proba
          for(int i = 0; i < nombreChoixObjet; i++)
          {
            if(IA_joueur.getInv().getInventaire(i).getVieObjet() == 0 && nbObjetsBonusAutre != 4)
            {
              IndiceImportanceObjet[i] = 0.9/nbObjetsBonusAutre;
            }
            else if(IA_joueur.getInv().getInventaire(i).getVieObjet() > 0 && nbObjetsBonusAutre != 4) // s'il existe des objets bonus vie
            {
              IndiceImportanceObjet[i] = 0.1/(1-nbObjetsBonusAutre);
            }
          }
      }

      // trier le tableau dans l'ordre des proba
      float tri[nombreChoixObjet];
      string triNoms[nombreChoixObjet]; ////////////////////////////////////////////////////////////::

      if(1 < nombreChoixObjet) // le tableau doit faire minimum 2 case pour etre trié
      {
        for(int i = 1; i < nombreChoixObjet; i++)
        {
          if(IndiceImportanceObjet[i-1] > IndiceImportanceObjet[i])
          {
            tri[i-1] = IndiceImportanceObjet[i];
            triNoms[i-1] = IA_joueur.getInv().getInventaire(i).getNomObjet();
  
            tri[i] = IndiceImportanceObjet[i-1];
            triNoms[i] = IA_joueur.getInv().getInventaire(i-1).getNomObjet();
          }
          else
          {
            tri[i-1] = IndiceImportanceObjet[i-1];
            triNoms[i-1] = IA_joueur.getInv().getInventaire(i-1).getNomObjet();
  
  
            tri[i] = IndiceImportanceObjet[i];
            triNoms[i] = IA_joueur.getInv().getInventaire(i).getNomObjet();
          }
        }
      }
      else
      {
        if(IndiceImportanceObjet[0] > IndiceImportanceObjet[1])
        {
            tri[0] = IndiceImportanceObjet[1];
            triNoms[0] = IA_joueur.getInv().getInventaire(1).getNomObjet();
  
            tri[1] = IndiceImportanceObjet[0];
            triNoms[1] = IA_joueur.getInv().getInventaire(0).getNomObjet();
        }
        else
        {
            tri[0] = IndiceImportanceObjet[0];
            triNoms[0] = IA_joueur.getInv().getInventaire(0).getNomObjet();
  
  
            tri[1] = IndiceImportanceObjet[1];
            triNoms[1] = IA_joueur.getInv().getInventaire(1).getNomObjet();
        }
      }


      // rand 
      int rand_objet = (rand() % 100);
      Objet res;

      if(0 <= rand_objet && rand_objet < tri[0]*100) // si rand est entre 0 et x_proba % alors on retourne l'objet x
      {
        // retourne l'objet
        res = IA_joueur.getInv().getInventaire(
                                                IA_joueur
                                                .getInv()
                                                .rechercherObjetInventaire(triNoms[0])
                                                );
      } 

      for(int i = 1; i < nombreChoixObjet; i++)
      {
        if(tri[i-1]*100 <= rand_objet && rand_objet < tri[i])
        {
          // retourne l'objet
          res = IA_joueur.getInv().getInventaire(
                                                  IA_joueur
                                                  .getInv()
                                                  .rechercherObjetInventaire(triNoms[i])
                                                  );
        }
      }

      // fin
      nombreChoixObjet--; 
      return res; */

      return IA_joueur.getInv().getInventaire(0);
    }
