#include "Partie.h"
#include <iostream>

int main(void)
{
    Partie p;
    while (p.fini == false)
    {
        p.prochaine_action();
    }
    return 0;
}
