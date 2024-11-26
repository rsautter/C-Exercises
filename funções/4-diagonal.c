#include <stdio.h>
#include <math.h>

int main(){
    float altura, largura; 
    float diagonal;

    //Lendo a entrada
    printf("Digite a altura:\n");
    scanf("%f", &altura);
    printf("Digite a largura:\n");
    scanf("%f", &largura);

    // calcula a diagonal como  raiz(altura ao quadrado + largura ao quadrado)
    //essas funcoes estao na math.h
    diagonal = sqrtf(powf(altura,2.0)+powf(largura,2.0));
    printf("A diagonal eh: %f\n", diagonal);
}