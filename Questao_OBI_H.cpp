//problema da questao: https://www.beecrowd.com.br/judge/en/problems/view/2302
//Augusto Nascimento de Oliveira - 1 Ano do ITA
//OBI - Olimpíada Brasileira de Informática 2006 Fase 1 Nível 1

#define RED "\033[31m"
#define BOLD  "\033[1m"
#define STANDARD "\033[0m"

#include <bits/stdc++.h>

struct coordenada{
    int X;
    int Y;
};

namespace space{
    class parque{
        public:
            parque(struct coordenada local={.X=0,.Y=0}){ //se nao for colocado nada, assume-se que o valor é o (0,0)
                Localizacao_Homens.X=local.X;
                Localizacao_Homens.Y=local.Y;
            }
            void movimenta_parque(char *movimento="0"){//se nao for colocado nada, assume-se que o valor é zero, ouseja, nao houve movimento
            //1-Norte, 2-Sul, 3-Leste e 4-Oeste
            int maximo=strlen(movimento)-1;
                for(int i=0; i<maximo; i++){
                    if(movimento[i]=='1') Localizacao_Homens.Y--;
                    else if(movimento[i]=='2') Localizacao_Homens.Y++;
                    else if(movimento[i]=='3') Localizacao_Homens.X++;
                    else if(movimento[i]=='4') Localizacao_Homens.X--;
                }
            }
            struct coordenada posicao(void){
                return Localizacao_Homens;
            }
        private:
            struct coordenada Localizacao_Homens; //posicao X e Y dos homens
    };
};
int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int linha_matriz, coluna_matriz;
    int linha_microfone, coluna_microfone;
    int numero_quadrados;
    char valor[3];
    bool invade_memoria;
    int tempo;
    std::vector<int> movimento;
    space::parque mapa;
    std::set<struct coordenada> microfone;

    /**/
    std::cout<<"Coloque a quantidade de "<<RED<<"linhas"<<STANDARD<<" e "<<RED<<"colunas"<<STANDARD<<" da matriz, respectivamente: "<<std::flush;
    /**/
    std::cin>>linha_matriz>>coluna_matriz;

    /**/
    std::cout<<"Coloque a posicao em "<<RED<<"linhas"<<STANDARD<<" e "<<RED<<"colunas"<<STANDARD<<" do microfone, respectivamente: "<<std::flush;
    /**/

    std::cin>>linha_microfone>>coluna_microfone;

    invade_memoria=false;
    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
            if(linha_microfone+i>=0&&linha_microfone+i<linha_matriz\
            &&coluna_microfone+j>=0&&linha_microfone+i<linha_microfone)
                invade_memoria=true;

            if(!invade_memoria)
                microfone.insert({.X=linha_microfone+i, .Y=coluna_microfone+j});//colocando no conjunto coberto pelo microfone

            invade_memoria=false;
        }
    }

    std::cin>>numero_quadrados;
    tempo=0;
    for(int i=0; i<numero_quadrados; i++){
        std::cin>>valor;
        mapa.movimenta_parque(valor);
        if(microfone.count(mapa.posicao())) 
            tempo++; //considere tempo de um segundo na posicao
    }

    /**/
    std::cout<<"Decorreu-se um tempo de vigilância de: "<<std::flush;
    /**/
    std::cout<<tempo<<std::endl;


    return 0;
}
