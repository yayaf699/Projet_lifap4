#ifndef STATISTIQUES_H_INCLUDED
#define STATISTIQUES_H_INCLUDED

class Statistiques
{
public:

// COSNTRUCTEURS ET DESTRUCTEURS

    // CONSTRUCTEUR
    Statistiques();

    // CONSTRUCTEUR PAR COPIE
    Statistiques(const int &v, const int &vi, const float &f);

// ACCESSEURS ET MUTATEURS

    // ACCESSEUR VIE
    const int &getVie() const;


    // ACCESSEUR VITESSE
    const int &getVitesse() const;

    // ACCESSEUR FORCE
    const float &getForce() const;

    // MUTATEUR VIE
    void setVie(const int &v);

    // MUTATEUR VITESSE
    void setVitesse(const int &vi);

    // MUTATEUR FORCE
    void setForce(const float &f);

// GESTION STATS

    void afficherStat();
private:

    int vie;
    int vitesse;
    float force;
};

#endif // STATISTIQUES_H_INCLUDED
