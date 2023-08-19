#include "conjuntos.hpp"
#include <stdexcept>

Set::Set(){}; //criando o conjunto vazio
Set::Set(int first, int last){
    if(first>last)
        throw std::runtime_error("invalid interval");

    while(first<=last){
        valores.push_back(first);
        first++;
    }
            
};

Set Set::plus(const Set& conjunto2) const {
    Set Conjunto_Uniao;
    std::size_t tamanho = valores.size();
    std::size_t tamanho2 = conjunto2.valores.size();
    std::size_t i=0, j=0;

    while(i<tamanho && j<tamanho2){
        if(valores[i]<conjunto2.valores[j]){
            Conjunto_Uniao.valores.push_back(valores[i]);
            i++;
        }
        else if(valores[i]>conjunto2.valores[j]){
            Conjunto_Uniao.valores.push_back(conjunto2.valores[j]);
            j++;
        }
        else{
            Conjunto_Uniao.valores.push_back(valores[i]);
            i++;
            j++;
        }
    }

    for(; i<tamanho; i++)
        Conjunto_Uniao.valores.push_back(valores[i]);

    for(; j<tamanho2; j++)
        Conjunto_Uniao.valores.push_back(conjunto2.valores[j]);

    return Conjunto_Uniao;

};

Set Set::intersect(const Set& conjunto2){

    Set Conjunto_Intersec;
    std::size_t tamanho = valores.size();
    std::size_t tamanho2 = conjunto2.valores.size();
    std::size_t i=0, j=0;

    while(i<tamanho && j<tamanho2){
        if(valores[i]<conjunto2.valores[j]){
            i++;
        }
        else if(valores[i]>conjunto2.valores[j]){
            j++;
        }
        else{
            Conjunto_Intersec.valores.push_back(valores[i]);
            i++;
            j++;
        }
    }

    return Conjunto_Intersec;

};
Set Set::diff(const Set& conjunto2){

    Set Conjunto_Diff;
    std::size_t tamanho = valores.size();
    std::size_t tamanho2 = conjunto2.valores.size();
    std::size_t i=0, j=0;

    while(i<tamanho && j<tamanho2){
        if(valores[i]<conjunto2.valores[j]){
            Conjunto_Diff.valores.push_back(valores[i]);
            i++;
        }
        else if(valores[i]>conjunto2.valores[j]){
            Conjunto_Diff.valores.push_back(conjunto2.valores[j]);
            j++;
        }
        else{
            i++;
            j++;
        }
    }

    for(; i<tamanho; i++)
        Conjunto_Diff.valores.push_back(valores[i]);

    for(; j<tamanho2; j++)
        Conjunto_Diff.valores.push_back(conjunto2.valores[j]);

    return Conjunto_Diff;

};

bool Set::exists(int e) const& {
    for(int i=0; i<valores.size(); i++){
        if(valores[i]==e)
            return true;
    }
    return false;

};

void Set::show(void) const&{
    for(int i=0; i<valores.size(); i++)
        std::cout << valores[i] << " ";

    std::cout << std::endl;
}