#include <stdio.h>
#include <stdbool.h>

bool verificaPrimo(int x){
    int i;
    if ( x<= 1){
        return false;
    }
    for (i=2;i<x;i++){
        if(x%i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int i = 15;
    printf("%d\n", verificaPrimo(i));

}