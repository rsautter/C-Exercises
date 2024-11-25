#include <stdio.h>
#include <stdbool.h>
#define TAMANHO 8

void printMat(char mat[TAMANHO-1][TAMANHO]);
bool acabou(char m1[TAMANHO-1][TAMANHO],char m2[TAMANHO-1][TAMANHO]);
bool substitui(char m1[TAMANHO-1][TAMANHO],char m2[TAMANHO-1][TAMANHO], char tentativa);

int main(){
    char resolucao[TAMANHO-1][TAMANHO]={"abacate","  b    ","  a    ","  caixa"," casa  ","  xa   ","  i    "};
    char tentativas[TAMANHO-1][TAMANHO];
    char chute;
    int i,j, erros;

    //inicializando
    for(int i=0;i<TAMANHO-1;i++)
        for(int j=0;j<TAMANHO;j++)
            tentativas[i][j] = ' ';
    for(int i=0;i<TAMANHO-1;i++)
        tentativas[i][TAMANHO-1] = '\0';
    //printMat(resolucao);

    erros = 0;
    //resolvendo o jogo:  
    while(!acabou(tentativas,resolucao)){
        printf("\nErros ateh entao: %d\n",erros);
        printMat(tentativas);
        printf("Digite uma letra:\n");
        scanf("%c", &chute);
        getchar();//apenas para a limpeza do buffer de entrada
        if(!substitui(tentativas,resolucao,chute)){
            erros++;
        }
    }
    printf("Finalizado!\n");
    printMat(tentativas); 
}

void printMat(char mat[TAMANHO-1][TAMANHO]){
    int i,j;
    for(i=0;i<TAMANHO-1;i++){
        for(j=0;j<TAMANHO;j++){
            printf(" %c ", mat[i][j]);
        }
        printf("\n");
    }
}

bool substitui(char chute[TAMANHO-1][TAMANHO],char resposta[TAMANHO-1][TAMANHO], char tentativa){
    int i,j;
    bool encontrou = false;
    for(i=0;i<TAMANHO-1;i++)
        for(j=0;j<TAMANHO;j++)
            if(resposta[i][j]==tentativa){
                // notem que ao acessar o array externamente, consigo alterar seu valor
                // o encapsulamentoneste caso nao funciona, pois a variavel aponta para a regiao de memoria

                //este detalhe NAO caira na prova, mas eh importante se tentarem utilizar
                //os recursos que vimos em aula 
                chute[i][j] = tentativa;
                encontrou = true;
            }
    return encontrou;
}

bool acabou(char m1[TAMANHO-1][TAMANHO],char m2[TAMANHO-1][TAMANHO]){
    int i,j;
    for(i=0;i<TAMANHO-1;i++)
        for(j=0;j<TAMANHO;j++)
            if(m1[i][j]!=m2[i][j])
                return false;
    return true;   
}