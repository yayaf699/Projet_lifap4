#ifndef STATISTIQUES_H_INCLUDED
#define STATISTIQUES_H_INCLUDED

class Statistiques{

private :
    int vie;
    int vitesse;
    float force;
public :
    Statistiques();
    Statistiques(int vit, int vie, float forc);
    ~Statistiques();
    int getVie();
    float getForce();
    int getVitesse();
    void setVie(int vie);
    void setForce(float forc);
    void setVitesse(int vit);

};

#endif // STATISTIQUES_H_INCLUDED
