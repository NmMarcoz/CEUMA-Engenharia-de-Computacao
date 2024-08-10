// DISCIPLINA: LINGUAGEM DE PROGRAMAÇÃO ESTRUTURADA
// OBJETOS DE CONHECIMENTO: ESTRUTURAS CONDICIONAIS, ESTRUTURAS DE REPETIÇÃO,
// ARRAYS E MODULARIZAÇÃO.
// RECURSOS DE COMPETÊNCIA: 1) projetar e implementar software para sistemas de
// comunicação. 2) Planejar, especificar, projetar, implementar, testar, verificar e validar sistemas
// de computação (sistemas digitais), incluindo computadores, sistemas baseados em
// microprocessadores, sistemas de comunicações e sistemas de automação, seguindo teorias,
// princípios, métodos, técnicas e procedimentos da Computação e da Engenharia.
// CENÁRIO DE PROBLEMATIZAÇÃO E PERGUNTA:

// Para o cenário descrito, abaixo, implemente um programa em Linguagem C que solucione
// corretamente o problema apresentado. Declare todas as variáveis e indique todas as bibliotecas
// necessárias.

// Dois arrays bidimensionais de 10x10 (matrizes quadradas) de valores inteiros devem ser
// declarados. Seus valores devem ser informados pelo usuário em tempo de execução.

// Entretanto, o 1º array bidimensional deve conter apenas valores positivos (incluindo 0) e o 2º
// array bidimensional deve conter apenas valores negativos. Logo, a quantidade de valores
// positivos e negativos, respectivamente em cada array bidimensional, deve ser garantida antes
// do processamento das operações serem realizadas. Do contrário, nenhum processamento deve
// ser realizado. Faça esta validação de entradas de dados utilizando alguma das estruturas de
// repetição para garantir valores válidos para cada array e a quantidade correta de cada um.
// Sobre estes dois arrays, faça:

// a) Calcule a soma das diagonais principais das duas matrizes e exiba o resultado; (Check)

// b) Crie e exiba a matriz Oposta de cada uma matrize. Na matriz Oposta os elementos (check)
// apresentam sinais diferentes da matriz original). Caso o valor seja 0 (zero) não é necessário
// inverter o sinal. Por exemplo:

// C) Crie uma função que verifique e informe se a 1ª matriz é do tipo Identidade (quando os
// elementos da diagonal principal são todos iguais a 1 e os outros elementos são todos iguais a 0
// (zero).


#include <stdio.h>
//Funções

int tamanho = 10; // Para definir o tamanho das matrizes.
int verificarIdentidade(int matriz[tamanho][tamanho]){ //
    int j = 0;
    for(int i = 0; i < tamanho; i++){ //
        if(matriz[i][j] != 1){
            return 0;
       }
       j++;
    }
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < 2; j++){
            if(i == j){
                continue;
            }
            if(matriz[i][j]!=0){
                return 0;
            }
        }
    }
    return 1;
}

int somaDiagonais(int matriz[tamanho][tamanho]){
    int j = 0;
    int soma = 0;
    for(int i = 0; i < tamanho; i++){
        soma+= matriz[i][j];
        j++;
    }
    return soma;
}

void inverteMatriz (int matriz[tamanho][tamanho]){
    int matrizInvertida[tamanho][tamanho];
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j ++){
            if(matriz[i][j] == 0 ) matrizInvertida[i][j] = 0;
            matrizInvertida[i][j] = matriz[i][j] * -1;
            printf("%i\n", matrizInvertida[i][j]);
        }
    }
}

int main(){
    int matriz1[tamanho][tamanho];
    int matriz2[tamanho][tamanho];
    // Entrada de dados
    //matriz1
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            printf("digite um numero inteiro positivo\n");
            scanf("%i", &matriz1[i][j]);
            while(matriz1[i][j] < 0){
                printf("digite apenas valores positivos!\n");
                scanf("%i", &matriz1[i][j]);
            }
        }
    }
    //matriz2

    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            printf("digite um numero inteiro negativo\n");
            scanf("%i", &matriz2[i][j]);
            while(matriz2[i][j] > 0){
                printf("digite apenas valores negativos!\n");
                scanf("%i", &matriz2[i][j]);
            }
        }
    }
    // Parte do processamento
    printf("soma das diagonais da matriz 1: %i\n", somaDiagonais(matriz1));
    printf("soma das diagonais da matriz 2: %i\n", somaDiagonais(matriz2));
    printf("Resultado da matriz invertida 1: \n");
    inverteMatriz(matriz1);
    printf("Resultado da matriz invertida 2: \n");
    inverteMatriz(matriz2);
    if(verificarIdentidade(matriz1) == 1){
        printf("A matriz 1 e do tipo identidade\n");
    }else{
        printf("A matriz 1 nao e do tipo identidade \n");
    }
    // if(verificarIdentidade(matriz2) == 1){
    //     printf("A matriz 2 e do tipo identidade \n");
    // }else{
    //     printf("A matriz 2 nao é do tipo identidade \n");
    // }
    return 0;
}


