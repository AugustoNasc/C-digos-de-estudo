#include <iostream>

/*objetivo é imprimir uma tabela no formato latex
por ex: 1 & 1 & 3\\
        2 & 0 & 1\\
        será a tabela:
        1 1 3
        2 0 1
        */
class Aluno{

    public:
    Aluno(int numero_Jogadas= 33){
        vezes_que_aluno_jogou=numero_Jogadas;
    };
    void DigitaJogada(void){
        for(int i=0; i<vezes_que_aluno_jogou; i++){
            std::cin>>resultados[i];
        }
    }
    int getResultados(int i){
        if(i<vezes_que_aluno_jogou)
            return resultados[i];
        else
            return -1;
    }
    private:
        int vezes_que_aluno_jogou;
        int resultados[34];
};

void PrintaTabela(Aluno aluno1, Aluno aluno2, Aluno aluno3);

int main(){
    Aluno Ambulancia(34), Jamal, Forte_five;
        Ambulancia.DigitaJogada();
        Jamal.DigitaJogada();
        Forte_five.DigitaJogada();

        PrintaTabela(Ambulancia, Jamal, Forte_five);

    return 0;
}

void PrintaTabela(Aluno aluno1, Aluno aluno2, Aluno aluno3){
    for(int i=0; i<34; i++)
    std::cout<<i+1<< " & "<<aluno1.getResultados(i)<<" & "<<aluno2.getResultados(i)<<"  & "<<aluno3.getResultados(i)<<"  \\\\"<<std::endl;
}