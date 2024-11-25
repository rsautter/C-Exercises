#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#ifdef __linux__
    #include <unistd.h>
#else
    #include <windows.h>
#endif

#define SLEEPTIME 300
#define SIZE 16
#define PARTICULAS 30

void main(){
    int mat[SIZE][SIZE];
    int i,j;
    int x,y;
    
    srand(time(NULL));

    //inicializacao:
    for(i=0;i<SIZE;i++)
        for(j=0;j<SIZE;j++)
            mat[i][j] = 0;
    
    //posicao randomica
    i = 0;
    while(i<PARTICULAS){
        x = rand()%SIZE;
        y = rand()%SIZE;
        if(mat[x][y] == 0){
            //se estah vazio:
            mat[x][y] = 1;
            i++;
        }
    }

    while(1){
        do{
            x = rand()%SIZE;
            y = rand()%SIZE;
        } while(mat[x][y]!=1);

        //como vamos atualizar a posicao, seta a posicao como zero
        i = x;
        j = y;

        // a particula se desloca uma posicao 
        // perceba que ela pode voltar tambem
        x = x+(rand()%3)-1;
        y = y+(rand()%3)-1;

        //garantindo as condicoes de borda:
        //perceba que SIZE tambem eh somado
        //isso serve para o caso da particula ir para
        //uma posicao negativa
        //ex: 
        //  x anterior era 0
        // sorteou -1 -> x=-1
        // se size vale 64 -> x = (-1+64)%64 = 63
        x = (x+SIZE)%SIZE;
        y = (y+SIZE)%SIZE;

        //verifica se espaco estah vazio
        if(mat[x][y]==0){
            mat[i][j] = 0;
            mat[x][y] = 1;
        }

        //apagando a tela (verifica se o sistema eh linux ou nao)
        //nao foi tratado o caso do sistema operacional mac
        #ifdef __linux__
            system("clear");
        #else
            system("cls");
        #endif

        printf("(%d,%d) -> (%d,%d)\n",i,j,x,y);
        //imprime a matriz:
        printf("_");
        for(i=0;i<SIZE;i++)
            printf("___");
        printf("_\n");
        for(i=0;i<SIZE;i++){
            printf("|");
            for(j=0;j<SIZE;j++){
                if(mat[i][j]==0)
                    printf("   ");
                else
                    printf(" * ");
            }
            printf("|\n");
        }
        printf("_");
        for(i=0;i<SIZE;i++)
            printf("___");
        printf("_\n");

        
        //faz o terminal parar por um instante
        #ifdef __linux__
            sleep(SLEEPTIME/1000); // na unistd eh em segundos
            usleep(1000*(SLEEPTIME%1000)); //para fracoes de segundos usamos usleep (em microsegundos)
        #else
            Sleep(SLEEPTIME);// na windows.h eh em milisegundos, note o S maiusculo
        #endif
    }

}