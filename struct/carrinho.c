#include <stdio.h>
#include <string.h>
#define N 10

struct item{
 char nome[50];
 float preco;
};

struct carrinho{
  struct item itens[N];
  int nItens;
};

struct carrinho adicionaNovo(struct carrinho c){
    struct item i;
    struct carrinho novo = c;
    printf("Digite o nome do item:\n");
    scanf("%s",i.nome);
    //fgets(i.nome,50,stdin);
    //fflush(stdin);
    printf("Digite o preco: \n");
    scanf("%f", &i.preco);
    
    novo.itens[novo.nItens] = i;
    novo.nItens++;
    return novo;
}

void imprimeCarrinho(struct carrinho c){
    int i;
    printf("\n==================\nO carrinho contem %d itens\n",c.nItens);
    for(i=0;i<c.nItens;i++)
        printf("%s - %f\n", c.itens[i].nome, c.itens[i].preco);
}

int main(){
 /*
 Declare um carrinho de compras como um array
 */
 struct carrinho c;
 c.nItens = 0;
 c = adicionaNovo(c); 
 c = adicionaNovo(c);
 c = adicionaNovo(c);
 imprimeCarrinho(c);
 /*struct item carrinho[N];
 int nItens = 0;
 
 strcpy(carrinho[0].nome,"macarrao");
 carrinho[0].preco = 2.5;
 nItens++;
 
 strcpy(carrinho[1].nome,"feijao");
 carrinho[1].preco  = 15.0;
 nItens++;
 
 //strcpy(carrinho[2].nome,"arroz");
 //carrinho[2].preco  = 3.0;
 //nItens++;
 
 imprimeCarrinho(carrinho,nItens);
 */   
 return 0;
}
