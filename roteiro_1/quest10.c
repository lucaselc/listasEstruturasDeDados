#include <stdio.h>
#include <stdlib.h>


int preencher(int *vet, int N, int idx){
    if(idx < N){
        printf("Posição %d -> \n", idx + 1);
        scanf("%d", &vet[idx]);
        preencher(vet,N, idx+1);
    }
}

int vet_cres(int *vet, int N, int idx){
    if(idx < N){
        printf("%d ", vet[idx]);
        vet_cres(vet,N, idx+1);
    }
}

int vet_decres(int *vet, int N, int idx){
    if(idx < N){
        vet_decres(vet,N, idx+1);
        printf("%d ", vet[idx]);      
    }
}

int maior_elemento(int *vet, int N, int idx, int maior){
    if(idx < N){
        if(vet[idx] >= maior)
            maior = vet[idx];
        maior = maior_elemento(vet, N,idx+1, maior);
    }
    return maior;
}

int main(){
    int N, maior;
    scanf("%d", &N);
    int *vet = (int*)malloc(N*sizeof(int));
    preencher(vet,N,0);

    printf("Vetor em ordem crescente -> \n");
    vet_cres(vet,N,0);
    printf("\n Vetor em ordem decrescente -> \n");
    vet_decres(vet,N,0);
    maior = maior_elemento(vet,N,0, vet[0]);
    printf("\n Maior elemento do vetor -> %d \n", maior);
    free(vet);
    return 0;

}
