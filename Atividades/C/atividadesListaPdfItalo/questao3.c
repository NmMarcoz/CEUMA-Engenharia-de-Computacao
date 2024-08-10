//3. Construa uma estrutura aluno com nome, numero de matr ´ ´ıcula e curso. Leia do usuario ´
//a informac¸ao de 5 alunos, armazene em vetor dessa estrutura e imprima os dados na ˜
//tela

#include <stdio.h>

typedef struct aluno{
    char matricula[10];
    char nome[30];
    char curso[15];
};

int main(){
    struct aluno alunos[5];
    for(int i = 0; i < 5; i++){
        puts("Digite o nome do aluno");
        scanf("%[^\n]s", alunos[i].nome);
        getchar();

        puts("Digite a matricula");
        scanf("%[^\n]s", alunos[i].matricula);
        getchar();

        puts("Digite o curso");
        scanf("%[^\n]s", alunos[i].curso);
        getchar();
    }

    for (int i = 0; i < 5; i++) {
        printf("DADOS DO ALUNO (%i) \n", i+1);

        printf("nome: %s\n", alunos[i].nome);
        printf("matricula: %s\n", alunos[i].matricula);
        printf("curso: %s\n", alunos[i].curso);
        puts("....");
    }
    return 0;
}