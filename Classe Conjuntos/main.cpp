#include <iostream>
#include "conjuntos.hpp"
#include <cstdlib>

int main(){

    Set Armando(1,8);
    Set Verri(2,10);

    Set Prof;
    Prof = Armando.plus(Verri);

    Prof.show();

    std::system("pause");

    return 0;
}