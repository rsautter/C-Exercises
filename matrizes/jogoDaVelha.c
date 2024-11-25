#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void printMat(char m[3][3]){
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf(" %c ", m[i][j]);
            if(j<2)
                printf("|");
        }
        if(i<2)
            printf("\n-----------\n");
    }
    printf("\n");
}

bool acabou(char m[3][3]){
    int i,j;
    bool temVazio = false;

    //verifica as linhas
    for(i=0;i<3;i++){
        if(m[i][0] != ' ' && m[i][0] == m[i][1] && m[i][1] == m[i][2]){
            return true; // Vitoria na linha i
        }
    }
    
    //verifica as colunas
    for(j=0;j<3;j++){
        if(m[0][j] != ' ' && m[0][j] == m[1][j] && m[1][j] == m[2][j]){
            return true; // Vitoria na coluna j
        }
    }
    
    //verifica as diagonais
    if((m[0][0] != ' ' && m[0][0] == m[1][1] && m[1][1] == m[2][2]) || 
       (m[0][2] != ' ' && m[0][2] == m[1][1] && m[1][1] == m[2][0])){
        return true; // Vitoria na diagonal
    }
    
    //verifica se tem espacos ainda
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(m[i][j] == ' '){
                return false; 
            }
        }
    }

    return true;
}

bool jogada(char m[3][3], unsigned int x, unsigned int y){
    int i,j;
    if(m[x%3][y%3]!=' ')
        return false;
    m[x%3][y%3] = 'x';
    if(acabou(m)){
        return true;
    }

    do{
        i = rand()%3;
        j = rand()%3;
    }while(m[i][j]!=' ');

    m[i][j] = 'o';
    return true;
}

int main(){
    char estado[3][3];
    unsigned int i,j;

    srand(time(NULL));


    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            estado[i][j] = ' ';

    while(!acabou(estado)){
        printMat(estado);
        printf("Digite a linha:\n");
        scanf("%u",&i);
        printf("Digite a coluna:\n");
        scanf("%u",&j);
        if(!jogada(estado,i,j)){
            printf("Jogada invalida\n");
        }
    }
    printMat(estado);
}