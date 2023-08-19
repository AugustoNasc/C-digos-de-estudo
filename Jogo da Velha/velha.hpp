#ifndef VELHA_H
#define VELHA_H
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <string>

//#include <string>
enum players{ player1=1, player2=2 };

class Jogo{
    private:
        int tabuleiro[3][3];
        int jogadas;
        players jogador;
        bool fim, ganhador;
        std::string participante1, participante2;

    public:
        Jogo(std::string primeiro, std::string segundo, enum players inicio=player2){
            if(primeiro.empty()) primeiro="Player 1"; 
            if(segundo.empty()) segundo="Player 2"; 
            participante1=primeiro;
            participante2=segundo;
            for(int i=0; i<3; i++)
                for(int j=0; j<3; j++)
                    tabuleiro[i][j] = 0;
            jogadas = 0;
            jogador = inicio;
            fim = false;
            ganhador=false;
        };
        void jogada();
        void show();
        void verifica();

};

#endif
