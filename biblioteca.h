#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <iostream>
#include <string.h>

namespace Ambu {
    class Lancia{
        public:
            Lancia(char *s = "", int i=0, double d=1){
                strcpy(dadosMembro1, s);
                dadosMembro2=i;
                dadosMembro3=d;
            }
            void funcaoMembro1(){
                std::cout<<dadosMembro1<<' '<<dadosMembro2<<' '<<dadosMembro3<<std::endl;
            }
            void funcaoMembro2(int i, char *s="desconhecido"){
                dadosMembro2=i;
                std::cout<<i<<"recebido de "<<s<<std::endl;
            }
        protected:
            char dadosMembro1[20];
            int dadosMembro2;
            double dadosMembro3;
    };
    void cout(int a, int b){
        int tmp;
        tmp=a; a=b; b=tmp;
        std::cout<<a<<" "<<b<<std::endl;
    };
}
namespace Rivaldo {
    int cout(int a, int b){
        if(a<b) Ambu::cout(a, b);
        if(a%b==0) return b;
        Rivaldo::cout(b, a%b);
    };
}

#endif