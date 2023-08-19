#ifndef CONJUNTOS_H
#define CONJUNTOS_H

//template <typename tipo>
#include <vector>
#include <iostream>



class Set{
    private:
    std::vector<int> valores; //os valores estarão na forma ordenada

    public:
    Set();//criar vazio
    Set(int first, int last);//criar intervalo


    Set intersect(const Set&);//criar interseção
    Set diff(const Set&);
    bool exists(int) const&; //verificar se existe elemento
    Set plus(const Set&) const;//criar uniao

    void show() const&; //mostrar conjunto

    /*
    conjunto1.plus(conjunto2);
    como colocamos const, nem conjunto1 nem conjunto2 são alterados
    */ 
};

#endif
