#include <iostream>
#include "Statistiques.h"

Statistiques::Statistiques()
{
    vitalite = 100;
    vitesse = 20;
    force = 1.1;
}

Statistiques::Statistiques(int vie, int vit, float force)
{
    vitalite = vie;
    vitesse = vit;
    force = force;
}

int Statistiques::getVie()
{
    return vitalite;
}

int Statistiques::getVitesse()
{
    return vitesse;
}

float Statistiques::getForce()
{
    return force;
}

void Statistiques::getVie(int vie)
{
    vitalite = vie;
}

void Statistiques::getVie(int vit)
{
    vitesse = vit;
}

void Statistiques::getVie(float force)
{
    force = force;
}
