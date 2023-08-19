#include "velha.hpp"
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <string>

#define VERMELHO "\033[31m"
#define VERDE "\033[32m"
#define STANDARD "\033[0m"

void Jogo::verifica(){
    for(int i=0; i<3; i++){
        if(tabuleiro[i][0]==tabuleiro[i][1] && tabuleiro[i][1]==tabuleiro[i][2] && tabuleiro[i][0]!=0){
            fim = true; ganhador=true;
            return;
        }
    }
    for(int j=0; j<3; j++){
        if(tabuleiro[0][j]==tabuleiro[1][j] && tabuleiro[1][j]==tabuleiro[2][j] && tabuleiro[0][j]!=0){
            fim = true; ganhador=true;
            return;
        }
    }
    if(tabuleiro[0][0]==tabuleiro[1][1] && tabuleiro[1][1]==tabuleiro[2][2] && tabuleiro[0][0]!=0){
        fim = true; ganhador=true;
        return;
    }
    if(tabuleiro[0][2]==tabuleiro[1][1] && tabuleiro[1][1]==tabuleiro[2][0] && tabuleiro[0][2]!=0){
        fim = true; ganhador=true;
        return;
    }
}
void Jogo::jogada(){
    if(jogador==player1)
        jogador = player2;
    else
        jogador = player1;
    
    std::cout<<"Digite a linha e a coluna de sua jogada: "<<std::flush;
    int i, j;
    while(true){
        try{
            std::cin>>i>>j;
            if( (i<0 || i>2 || j<0 || j>2)||tabuleiro[i][j]!=0 ){
                throw std::invalid_argument("invalid move");
            }
            else break;
        }
        catch(const std::invalid_argument& e){
            std::cout<<"Jogada invalida!"<<std::endl;
            std::cout<<e.what()<<std::endl;
            std::cout<<"Digite"<<VERMELHO<<" outros valores"<<STANDARD<<" para a linha e a coluna de sua jogada: "<<std::flush;
        }
    }
    tabuleiro[i][j] = jogador;
    jogadas++;
    if(jogadas==9){
        fim = true;
        std::cout<<"Acabou em empate :("<<std::endl;
        system("pause");
    }
    system("cls");
    verifica();
    this->show();
}
void Jogo::show(){
    std::cout << "---------------"<<std::endl;
    for(int i=0; i<3; i++){
        std::cout<<" | "<<std::flush;
        for(int j=0; j<3; j++){
            std::cout << tabuleiro[i][j] << " | ";
        }
        std::cout << "\n---------------"<<std::endl;
    }
    if(!fim)
        this->jogada();
    else{
        std::cout<<"Fim de jogo!"<<std::endl;
        std::cout<<"O ganhador foi o jogador: ";
        jogador==player1 ? std::cout<<VERDE<<participante1<<STANDARD<<std::endl : std::cout<<participante2<<STANDARD<<std::endl;
        system("pause");
        }
};
