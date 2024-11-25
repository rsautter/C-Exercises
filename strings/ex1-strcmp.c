#include <stdio.h>
#include <string.h>

void main(){
    char string1[] = "Test";
    char string2[] = "Teste de comparadao";
    int i;
    int diff = 0;
    for(i=0;i<strlen(string1);i++){
        if(i>strlen(string2)){
            diff = (int) string1[i];
            break;
        }
        if(string1[i]!= string2[i]){
            diff = (int)string1[i]- (int) string2[i];
            break;
        }   
    }
    if(strlen(string2)>strlen(string1)){
        diff = -string2[strlen(string1)];
    }
    printf("Diferenca: %d\n",diff);
    printf("Strcmp: %d\n", strcmp(string1,string2));
}