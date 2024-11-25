#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define COUPLING 0.3
#define ALPHA 4.0
#define SIZE 64

float logistico(float x){
    return ALPHA*x*(1.0f-x);
}

int main(){
    float mat[SIZE][SIZE];
    int i,j;

    for(i=0;i<SIZE;i++)
        for (j=0;j<SIZE;j++)
            mat[i][j] = powf(((float)i-SIZE/2)/SIZE,2.0)+powf(((float)j-SIZE/2)/SIZE,2.0);

    while(true){
        system("clear");

        for(i=0;i<SIZE;i++){
            for (j=0;j<SIZE;j++){
                if(mat[i][j] < 0.5)
                    printf(" ");
                else if(mat[i][j]<0.7)
                    printf(".");
                else if(mat[i][j]<0.8)
                    printf("*");
                else
                    printf("#");
            }
            printf("\n");
        }

        for(i=0;i<SIZE;i++)
            for (j=0;j<SIZE;j++)
                mat[i][j] = (1-COUPLING)*logistico(mat[i][j])+ 
    }
}   