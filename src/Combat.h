#ifndef COMBAT_H_INCLUDED
#define COMBAT_H_INCLUDED

#include <iostream>
#include "Menu.h"

using namespace std;

class Combat
{

private:

    bool etatCombat = true;
    bool joueurKO = false;
public:

    Combat(); // constructeur

    ~Combat(); // destructeur 

    void deroulementCombat(); 
    
};

#endif // fin de la classe combat