#include <stdio.h>
#include <stdlib.h>

float maior_elemento(float *vet, int tam){
    float maior = vet[0];
    for(int i = 0 ; i < tam; i++){
        if(vet[i] >= maior){
            maior = vet[i];
        }
    }
    return maior;
}

float menor_elemento(float *vet, int tam){
    float menor = vet[0];
    for(int i = 0 ; i < tam; i++){
        if(vet[i] <= menor){
            menor = vet[i];
        }
    }
    return menor;
}

float media_elementos(float *vet, int tam){
    float media = 0;
    for(int i = 0 ; i < tam; i++){
        media += vet[i]; 
    }
    return media/tam;
}

int main(){
    int tam;
    scanf("%d", &tam);
    float *vetA =  (float*)malloc(tam*sizeof(float));
    float *vetB =  (float*)malloc(tam*sizeof(float));
    for(int i = 0; i < tam; i++){
        vetA[i] = rand()%1000;
        vetB[i] = rand()%1000;
    }
    float mediaA = media_elementos(vetA, tam);
    float media = media_elementos(vetB, tam);
    float menorA = menor_elemento(vetA, tam);
    float menor = menor_elemento(vetB, tam);
    float maiorA = maior_elemento(vetA, tam);
    float maior = maior_elemento(vetB, tam);
    printf("A média dos elementos do vetor A é: %.2f, o maior elemento é: %.2f e o menor: %.2f\n"
    "A média dos elementos do vetor B é: %.2f, o maior elemento é: %.2f e o menor: %.2f\n"
    , mediaA, maiorA, menorA, media,  maior, menor);
    free(vetA);
    free(vetB);
    return 0;

}    