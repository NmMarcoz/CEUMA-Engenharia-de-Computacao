#include <stdio.h>

typedef struct Produto{
    int codigo;
    int quantidadeMinima;
    int quantidadeAtual;
    float preco;
};

int main(){
    int size = 3;
    struct Produto produtos[size];
    int indexesProdutosFaltando[size];
    int countProdutosFaltando = 0;
    float valorTotal = 0;;


    for(int i =0; i < size; i++){
        puts("Digite o nome do produto")
        scanf("%i", &produtos[i].codigo); // Scanner do código do produto

        puts("Digite a quantidade minima do estoque deste produto");
        scanf("%i", &produtos[i].quantidadeMinima); //Scanner da quantidade minima do produto

        puts("Digite a quantidade atual do estoque deste produto");
        scanf("%i", &produtos[i].quantidadeAtual);

        puts("Digite o preco do produto");
        scanf("%f", &produtos[i].preco);

        if(produtos[i].quantidadeAtual < produtos[i].quantidadeMinima){
            puts("entrou na condicao");
            printf("index: %i\n", i);

            indexesProdutosFaltando[countProdutosFaltando] = i;
            countProdutosFaltando = countProdutosFaltando + 1;


        }

        valorTotal = valorTotal + produtos[i].preco*produtos[i].quantidadeAtual;
    }
    printf("quantidade de produtos criticos: %i\n", countProdutosFaltando);
    printf("valor total: %f\n", valorTotal);
    printf("Dados dos produtos que estao em condicao critica :\n ");
    for(int i = 0; i < countProdutosFaltando; i++){
        printf("codigo do produto: %i\n", produtos[indexesProdutosFaltando[i]].codigo);
        printf("%i\n",indexesProdutosFaltando[i]);
        printf("quantidade minima: %i\n",produtos[indexesProdutosFaltando[i]].quantidadeMinima);
    
        printf("quantidade atual: %i\n" , produtos[indexesProdutosFaltando[i]].quantidadeAtual);
        printf("preco do produto: %f\n", produtos[indexesProdutosFaltando[i]].preco);
    }

    return 0;
}