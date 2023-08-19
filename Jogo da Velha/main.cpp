#include "velha.hpp"
#include <iostream>
#include <string>

int main(){
    
    std::string nome1, nome2;
    std::cout<<"JOGO DA VELHA"<<std::endl;
    std::cout<<"-------------"<<std::endl;
    std::cout<<"Digite o nome do jogador 1: "<<std::flush;

    std::getline(std::cin, nome1);
    
    std::cout<<"Digite o nome do jogador 2: "<<std::flush;
    std::getline(std::cin, nome2);

    Jogo partida(nome1, nome2);
    partida.show();

    return 0;
}
