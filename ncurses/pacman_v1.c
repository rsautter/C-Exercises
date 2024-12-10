#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#define TAM_TELA 15
#define NUM_PAREDES 20
#define TAM_MAX 7

void imprimeLabirinto(int m[TAM_TELA][TAM_TELA]){
    int i,j;
    for(i=0;i<TAM_TELA;i++)
        for(j=0;j<TAM_TELA;j++){
            if(m[i][j]==1){
                move(i,j);
                attron(COLOR_PAIR(1));
                printw(" ");
                attron(COLOR_PAIR(1));
            }
        }
} 

int main(){
    int entrada=' ';
    int mat[TAM_TELA][TAM_TELA];
    int cx,cy;
    int cxt,cyt;
    int i,j,k;
    int tamanhoParede;
    
    srand(time(NULL));
    //inicializa matriz
    for(i=0;i<TAM_TELA;i++)
        for(j=0;j<TAM_TELA;j++)
            mat[i][j]=0;
            
    for(i=0;i<NUM_PAREDES;i++){
            tamanhoParede = (rand()%(TAM_MAX))+1;
            cxt = rand()%2;
            cyt = rand()%TAM_TELA;
            k = rand()%TAM_TELA;
            for(j=0;j<tamanhoParede;j++){
                if(cxt ==0 ){
                    mat[(j+k)%TAM_TELA][cyt] = 1;
                }else{
                    mat[cyt][(j+k)%TAM_TELA] = 1;
                }
            }
            mat[i][j] = rand()%2;
    }
    mat[0][0] = 0;
    
    //incializacao da ncurses
    initscr();
    noecho();
    raw();
    cbreak();
    getyx(stdscr, cy, cx);
    timeout(300);
    start_color();
    //par1 -> paredes
    init_pair(1, COLOR_GREEN, COLOR_GREEN);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    
    //laco principal
    while(entrada!='q'){
        refresh();
        entrada = getch();
        clear();
        switch(entrada){
            case 'w':
                cyt = (cy-1+TAM_TELA)%TAM_TELA;
                if(mat[cyt][cx] == 0)
                    cy = cyt;
                break;
            case 's':
                cyt = (cy+1)%TAM_TELA;
                if(mat[cyt][cx] == 0)
                    cy = cyt;
                break;
            case 'd':
                cxt = (cx+1)%TAM_TELA;
                if(mat[cy][cxt] == 0)
                    cx = cxt;
                break;
            case 'a':
                cxt = (cx-1+TAM_TELA)%TAM_TELA;
                if(mat[cy][cxt] == 0)
                    cx = cxt;
                break;
        }
        imprimeLabirinto(mat);
        move(cy,cx);
        attron(COLOR_PAIR(2));
        printw("*");
        attroff(COLOR_PAIR(2));
        move(TAM_TELA+1,0);
    }
    endwin();
    return 0;
}
