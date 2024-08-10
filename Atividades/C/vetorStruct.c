#include <stdio.h>
#include <string.h>

//scanf("%[^\n]s",name);

typedef struct Adress{
    char bairro[20];
    int rua;
    char cidade[15];
    int casa;
};

int main(){
    struct Adress endereco[2];
    for(int i = 0; i< 2; i++){
        printf("Qual sua cidade?\n");
        //fgets(endereco[i].cidade, 15, stdin );
        scanf("%[^\n]s", endereco[i].cidade);
        getchar();

        printf("qual seu bairro? \n");
        //fgets(endereco[i].bairro, 20, stdin );
        scanf("%[^\n]s", endereco[i].bairro);
        getchar();

        printf("qual sua rua? \n");
        scanf("%i", &endereco[i].rua);
        getchar();
        printf("e o numero da sua casa?\n");
        scanf("%i", &endereco[i].casa);
        getchar();
    }
    
    for(int i = 0; i < 2; i++){
        printf("-------------ENDERECO(%i)------------\n", i+1);
        printf("cidade: %s\n", endereco[i].cidade);
        printf("bairro: %s\n", endereco[i].bairro);
        printf("rua: %i\n", endereco[i].rua);
        printf("casa: %i\n", endereco[i].casa);
    }
    return 0;
}