/*problema da questao https://www.beecrowd.com.br/judge/en/problems/view/2452
OBI - Olimpíada Brasileira de Informática 2014 Fase 1 Nível 1
*/
//Augusto Nascimento de Oliveira - 1 Ano do ITA

#include <bits/stdc++.h>
#define RED "\033[31m"
#define BOLD  "\033[1m"
#define STANDARD "\033[0m"
int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int F, R;
    std::vector<int> posicao;
    int valor;

    int distancia_inicial;
    int distancia_final;
    int maior_distancia_meio;
    int maior_distancia_das_pontas;
    int dias_meio;
    /**/
    std::cout<<"Insira o "<<RED<<"comprimento da fita"<<STANDARD<<" e o"<<RED<<\
 " numero de posicoes preenchidas,"<<STANDARD<< BOLD<<" respectivamente:"<<STANDARD<<std::flush;
    /**/
    std::cin>>F >> R /*comprimerto da fita*/ /*numero de posiçoes*/;

    /**/
    std::cout<<"Insira a posicao de onde esta cada gota:"<<std::flush;
    /**/

    for(int i=0; i<R; i++){
        std::cin>>valor;
        posicao.push_back(valor); //lendo os valores no vetor
    }
    std::sort(posicao.begin(), posicao.end()); //ordenando o vetor
    //desnecessario, mas quero praticar iterator

    //vamos ver quantos dias leva para preencher a ponta esquerda
    //note que esse caso sera diferente dos outros, por haver apenas
    //uma "fonte" de dispersão da gota

    distancia_inicial=posicao[0]-1;

    //analogamente para a ponta direita

    distancia_final=F-posicao[R-1];

    //comparemos apenas o maior desses valores

    if(distancia_inicial>distancia_final){
        maior_distancia_das_pontas=distancia_inicial;
    }
    else maior_distancia_das_pontas=distancia_final;

    maior_distancia_meio=posicao[1]-posicao[0]-1;
    for(int i=1; i<R; i++){
        if(maior_distancia_meio<posicao[i]-posicao[i-1]-1){
            maior_distancia_meio=posicao[i]-posicao[i-1]-1;
        }
    }

    /*se for impar, precisara de mais um dia para preencher*/
    if(maior_distancia_meio%2!=0){
        dias_meio=maior_distancia_meio/2+1;
    }
    else
        dias_meio=maior_distancia_meio/2;

    /**/
    std::cout<<"A maior quantidade de dias sera: "<<std::flush;
    /**/

    if(dias_meio>maior_distancia_das_pontas){
        std::cout<<dias_meio<<std::endl;
    }
    else{
        std::cout<<maior_distancia_das_pontas<<std::endl;
    }

    return 0;
}