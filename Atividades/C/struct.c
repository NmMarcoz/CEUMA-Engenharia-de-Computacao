#include <stdio.h>
#include <string.h>
struct cidade{
    char desc[20];
}

struct cidade cidades{"isso mesmo"
}

typedef struct User{
    char name[20];
    int age;
    float height;
    float notas[4];
};

struct notas{
    float notas[4];
} notas1, notas2;

float media(struct User u){
    float media = u.notas[0] + u.notas[1] + u.notas[2] + u.notas[3];
    media = media/4;
    return media;
}


int main(){
    struct User usuario;

    puts("digite o nome do usuario");
    scanf("%s", usuario.name);
    puts("digite a idade do usuario");
    scanf("%d", &usuario.age);
    while(usuario.age < 0){
        puts("digite uma idade válida");
        scanf("%i", &usuario.age);
    }
    puts("digite a altura do usuário");
    scanf("%f", &usuario.height);
    while(usuario.height <= 0){
        puts("digite uma altura válida");
        scanf("%f", &usuario.height);
    }

    for(int i = 0; i < 4; i++){
        printf("digite a %i nota\n", i+1);
        scanf("%f", &usuario.notas[i]);
        while(usuario.notas[i] < 0 || usuario.notas[i] > 10){
            puts("Digite somente notas entre 0 e 10");
            scanf("%f", &usuario.notas[i]);
        }
    }

    printf("media do usuario: %f", media(usuario));

    return 0;
}


