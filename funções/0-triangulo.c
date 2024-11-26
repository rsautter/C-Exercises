#include <stdio.h>

int d(int n){
    return  n*(n+1)/2;
}


int main()
{
    int i = 3;
    int j = 5;
    printf("%d -> %d\n",i,d(i) );
    printf("%d -> %d\n",j,d(j) );
    return 0;
}
