#include <stdio.h>

typedef struct Municipio{
  char codigo[10];
  int populacao;
  double area;
};

int main(){

    int size = 2;
    int maiorMunicipio;
    int maiorPop;
    float media = 0;

    struct Municipio municipios[size];
    for(int i = 0; i < size; i++){
        puts("digite o codigo do municipio");
        scanf("%s", municipios[i].codigo);

        puts("Digite a populacao do municipio");
        scanf("%d", &municipios[i].populacao);

        puts("digite a area do municipio");
        scanf("%f", &municipios[i].area);

        media = media + municipios[i].populacao;

        if(i == 0){
            maiorMunicipio = i;
            maiorPop = i;
            continue;
        }

        if(municipios[i].area > municipios[maiorMunicipio].area){
            maiorMunicipio = i;
        }
        if(municipios[i].populacao > municipios[maiorPop].populacao){
            maiorPop = i;
        }
    }
    printf("%f \n", media);
    media = media/size;
    printf("Codigo do maior municipio: %s\n", municipios[maiorMunicipio]);
    printf("Codigo do municipio com maior populacao %s\n", municipios[maiorPop]);
    printf("media das populacoes: %f\n", media);
    return 0;
}
