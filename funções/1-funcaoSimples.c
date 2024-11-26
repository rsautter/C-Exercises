#include <stdio.h>
#include <stdlib.h>

/**
 * Uma funcao eh declarada conforme o exemplo abaixo
 * A entrada eh um inteiro, quando chamarmos a funcao,
 * precisamos dizer qual valor eh
 * por exemplo:
 * 
 * funcao(5)
*/
void funcao(int i){
    printf("A entrada da funcao foi %d\n",i);
}

int main(){
    int x;

    x = 3;

    //executando o trecho de codigo da linha 12 a 14
    funcao(x);
}