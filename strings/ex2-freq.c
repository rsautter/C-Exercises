#include <stdio.h>
#include <string.h>

void main(){
    char texto[] = "Minha terra tem palmeiras,\nOnde canta o Sabia;\nAs aves, que aqui gorjeiam,\nNao gorjeiam como la.";
    int frequencia[26];
    int maior;
    int i,j;
    
    for(i=0;i<26;i++)
        frequencia[i] = 0;

    for(i=0;i<strlen(texto);i++){
        j = (int) texto[i] - 'a';
        if(j>-1 && j<27)
            frequencia[j]++;
    }

    maior = 0;
    for(i=0;i<26;i++){
        if(frequencia[i]>0){
            printf("%c:%d  ", (char)i+'a', frequencia[i]);
        }
        if(frequencia[maior] < frequencia[i])
            maior = i;
    }

    printf("\nO caracter mais frequente eh: %c\n", (char) maior+'a');

}