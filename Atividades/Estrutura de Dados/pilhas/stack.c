#include <stdio.h>
#include <stdlib.h>

typedef struct user{
    char name[40];
    int age;
    float height;
    struct user *prox;
}user;

user *top;

void console(user *user){
    printf("nome do usuario: %s \n", user->name);
    printf("idade do usuario: %d \n", user->age);
    printf("altura do usuario: %f \n", user->height);
}

void imprimePilha(user *top){
    printf("idade do usuario: %d \n", top->age);
    printf("altura do usuario: %f \n", top->height);
    if(top->prox == NULL){
         return;
    }
    imprimePilha(top->prox);
}

void pop(){
    if(top == NULL){
        return;
    }
    user *temp = &top;
    top = top->prox;
    temp = NULL;
}


void push(user newUser){
    if(top == NULL){
        printf("a pilha esta vazia");
        return;
    }
    user *temp = top;
    top = &newUser;
    top->prox = temp;
}

int main(){
    user *user1 = malloc(sizeof(user));
    user1->age = 25;
    user1->height = 1.84;
    top = user1;
    //console(top);
    printf("\n\n");
    user *user2 = malloc(sizeof(user));
    user2->age = 22;
    user2->height = 1.72;
    push(*user2);
    user *user3 = malloc(sizeof(user));
    user3->age = 20;
    user3->height = 2.02;
    push(*user3);
    //console(top);
    imprimePilha(top);
    printf("\n agora com o pop \n");
    pop();
    imprimePilha(top);
    printf("\n agora com o pop \n");
    pop();
    imprimePilha(top);
    return 0;
}