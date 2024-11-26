#include <stdio.h>
#include <stdlib.h>

/**
 * Uma funcao eh declarada conforme o exemplo abaixo
 * A entrada sao dois numeros inteiros, quando chamarmos a funcao,
 * precisamos dizer qual valor eh cada um
 * por exemplo:
 * 
 * soma(5, 6)
 * 
 * Neste exemplo tambem eh retornado um inteiro, pois antes do nome da 
 * funcao esta escrito int
 * na linha , ha um comando return que declara qual o valor retornar da chamada
 * 
 * int x,y,z:
 * z = soma(x,y);
 * 
 * ao executar o valor eh retornado como um inteiro que pode ser atribuido a uma nova 
 * variavel 
*/
int soma(int i, int j){
    // k eh uma variavel que estah somente dentro da funcao soma, ela existe somente entre os {}
    int k;

    // imprime os valores de entrada i e j
    printf("A entrada da funcao foi %d e %d\n",i,j);

    //soma os dois valores de entrada e coloca na variavel k
    k = i+j;


    //o comando a seguir retorna o valor da funcao
    return k;
}

int main(){
    int x, y,z;

    //atribuindo valores as variaveis
    x = 3;
    y = 5;

    //executando o trecho de codigo da linha 12 a 35
    z = soma(x,y);
    printf("A soma eh %d\n", z);

    //executando e imprimindo sem salvar em uma variavel
    // esta eh outra forma de utilizar a saida de uma variavel, desta vez sem especificar
    printf("A soma eh: %d\n", soma(x,y));
}