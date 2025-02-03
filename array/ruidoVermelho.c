#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5000

float geraRandomico(){
    int i = rand();
    float saida;
    //retorna um valor entre 0 e 4999
    i = i % N;
    //retorna o valor 0.0 e 4999.0
    // 0.0 1.0 ... 4998.0 4999.0
    saida = (float) i;
    //0.0 0.5 0.7 .. 1.0
    saida = saida / (N-1);
    //0-2
    saida = saida*2.0;
    saida = saida -1.0;
    return saida;
}

int main(){
    float arr[1024];
    int i;
    
    srand(time(NULL));
    for(i=0;i<1024;i++){
        arr[i] = geraRandomico();
    }
    for (i=1;i<1024;i++){
        arr[i] = arr[i-1]+arr[i];
    }
    for (i=0;i<1024;i++){
        printf("%f,", arr[i]);
    }
    return 0;
}

