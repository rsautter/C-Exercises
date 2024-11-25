#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define TAMANHOMAXIMO 50

int main(){
    char segredo[TAMANHOMAXIMO];
    int desvendado[TAMANHOMAXIMO];
    char letra;
    bool ganhou, encontrou;
    int i;
    int rodada = 0;

    ganhou = false;
    printf("Digite a palavra:\n");
    fgets(segredo,TAMANHOMAXIMO,stdin);

    // remove o ultimo caractere que seria o \n 
    segredo[strlen(segredo)-1] = '\0';

    for(i=0;i<strlen(segredo);i++)
        desvendado[i] = 0;

    while( (!ganhou) && rodada<5 ){
        for(i=0;i<strlen(segredo);i++){
            if(desvendado[i]==0)
                printf(" _ ");
            else
                printf(" %c ", segredo[i]);
        }
        printf("\n");
        
        printf("Digite uma letra:");
        scanf("%c", &letra);
        getchar(); // para limpar a memoria

        //busca a letra
        encontrou = false;
        for(i=0;i<strlen(segredo);i++){
            if(segredo[i]==letra){
                desvendado[i] = 1;
                encontrou = true;
            }
        }

        ganhou = true;
        for(i=0;i<strlen(segredo);i++)
            ganhou = (ganhou & desvendado[i]);
        
        if(!encontrou)
            rodada++;
    }
    if (rodada>=5){
        printf("Perdeu...\n");
    }else{
        printf("Ganhou!\n");
    }
}