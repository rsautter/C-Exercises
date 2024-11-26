#include <stdio.h>
#include <math.h>

int main(){
    float raio, volume;

    printf("Digite o raio:\n");
    scanf("%f", &raio);

    // M_PI eh uma constante da math.h
    // powf eh a funcao potencia para numeros em ponto flutuante do tipo float
    volume = 4.0f * M_PI * powf(raio,3.0f)/ 3.0f;
    printf("O volume de uma esfera de raio %f eh: %f\n", raio, volume);
}
