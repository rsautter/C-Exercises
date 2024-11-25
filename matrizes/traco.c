#include <stdio.h>
#include <math.h>
#define N 5

void main(){
    int mat[N][N]= {{5,0,15,0,7}, {7,0,15,0,6},{0,0,6,0,9},{0,25,0,8,0},{0,12,0,14,-1}};
    int i,j;
    int p1[2];
    int p2[2];
    float d;

    //imprimindo
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    p1[0] = 0;
    p1[1] = 0;
    
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            if(mat[p1[0]][p1[1]]<mat[i][j]){
                p1[0] = i;
                p1[1] = j;
            }

    printf("O maior elemento eh: %d em (%d, %d)",mat[p1[0]][p1[1]], p1[0],p1[1]);   
 
    p2[0] = 0;
    p2[1] = 0;
    
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            if(mat[p2[0]][p2[1]]>mat[i][j]){
                p2[0] = i;
                p2[1] = j;
            }
    printf("\nO menor elemento eh: %d em (%d, %d)\n",mat[p2[0]][p2[1]], p2[0],p2[1]);   
    d = sqrtf(powf((float) p1[0]-p2[0],2.0)+powf((float) p1[1]-p2[1],2.0));
    printf("A distancia eh %f\n", d);
 }