
// Questão: Escreva um programa para ler duas matrizes com valores informados pelo usuario e:
//a) Verificar se são iguais
//b) Subtrair uma matriz na outra
//c) Ordenar as duas matrizes em ordem crescente */"
#include <stdio.h>
#define SIZE_MATRIZ  3

void exibeMatriz(int matriz[SIZE_MATRIZ][SIZE_MATRIZ]){
    for (int i = 0; i < SIZE_MATRIZ; i++) {
        for (int j = 0; j < SIZE_MATRIZ; j++) {
            printf("Valor da matriz: %i \n", matriz[i][j]);
        }
    }
}

void matrizSaoIguais(int matriz_1[SIZE_MATRIZ][SIZE_MATRIZ], int matriz_2[SIZE_MATRIZ][SIZE_MATRIZ]){
    int count = 0;
    for (int i = 0; i < SIZE_MATRIZ ; i++){
        for(int j = 0; j < SIZE_MATRIZ; j++){
            if(matriz_1[i][j] == matriz_2[i][j]){
                count++;
            }
        }
    }
    if(count == SIZE_MATRIZ*SIZE_MATRIZ){
        printf("as matrizes sao iguais\n");
    }else{
        printf("as matrizes nao sao iguais\n");
    }

}

void ordenaMatriz(int matriz[SIZE_MATRIZ][SIZE_MATRIZ]){
    int temp = 0;
    int temp2 = 0;
    int matrizArray[SIZE_MATRIZ*SIZE_MATRIZ];
    for(int i = 0; i < SIZE_MATRIZ*SIZE_MATRIZ; i++){
        if(i < 3){
            matrizArray[i] = matriz[0][i];
        }
        if(i >=3 && i < 6){
            matrizArray[i] = matriz[1][i - 3];
        }
        if(i >=6 && i < 9){
            matrizArray[i] = matriz[2][i - 6];
        }
    }
    for (int i = 0; i < SIZE_MATRIZ*SIZE_MATRIZ; i++) {
        for (int j = 0; j < SIZE_MATRIZ * SIZE_MATRIZ; j++) {
            //printf("i: %i, j: %i\n", i, j);
            if (matrizArray[j] > matrizArray[j + 1] && j + 1 < SIZE_MATRIZ * SIZE_MATRIZ) {
                temp = matrizArray[j];
                matrizArray[j] = matrizArray[j + 1];
                matrizArray[j + 1] = temp;
            }
        }

        int count = 0;
        int j = 0;
        for (int i = 0; i < SIZE_MATRIZ * SIZE_MATRIZ; i++) {
            if (i % SIZE_MATRIZ == 0 && i != 0) {
                j++;
            }
            matriz[j][count] = matrizArray[i];
            count == 2 ? count = 0 : count++;

        }
    }
    exibeMatriz(matriz);
}



int main(){
    //setlocale(LC_ALL, "Portuguese");
    int matriz_1[SIZE_MATRIZ][SIZE_MATRIZ];
    int matriz_2[SIZE_MATRIZ][SIZE_MATRIZ];

    //a
    for(int i = 0; i < SIZE_MATRIZ; i++){
        for(int j = 0; j < 3; j++){
            printf("digite um numero para a matriz\n");
            scanf("%d", &matriz_1[i][j]);
        }
    }
    for(int i = 0; i < SIZE_MATRIZ; i++){
        for(int j = 0; j < 3; j++){
            printf("digite um numero para a segunda matriz\n");
            scanf("%d", &matriz_2[i][j]);
        }
    }


    //b
    int matrizSubtraida[SIZE_MATRIZ][SIZE_MATRIZ];
    for(int i = 0; i < 3 ; i++){
        for(int j = 0; j < 3; j ++){
            matrizSubtraida[i][j] = matriz_1[i][j] - matriz_2[i][j];

        }
    }
    printf("COMPARANDO SE AS MATRIZES SAO IGUAIS\n");

    matrizSaoIguais(matriz_1, matriz_2);
    printf("Exibindo a matriz subtraída\n");
    exibeMatriz(matrizSubtraida);
    printf("---------------------------------------------------\n");

    printf("Ordenando a matriz\n");
    ordenaMatriz(matriz_1);
    printf("---------------------------------------------------\n");\

    printf("Ordenando a matriz 2\n");
    ordenaMatriz(matriz_2);
    printf("---------------------------------------------------\n");

    return 0;
}