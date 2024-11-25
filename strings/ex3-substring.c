#include <stdio.h>
#include <string.h>

int main(){
    char texto[] = "O tempo perguntou ao tempo quanto tempo o tempo tem, o tempo respondeu ao tempo que o tempo tem o tempo que o tempo tem.";
    char subtexto[]= "tempo";
    int i,j;
    int encontrou = -1;

    for(i=0;i<strlen(texto);i++){
        
        if(texto[i] == subtexto[0]){
            encontrou = i;
            for(j=1;j<strlen(subtexto);j++){
                if(i+j >= strlen(texto))
                    break;            
                if(texto[i+j] != subtexto[j]){
                    encontrou = -1;
                    break;
                }
            }
            if(encontrou>0){
                printf("Substring %s encontrada em: %d\n", subtexto, i-1);
            }
        }

    }
}