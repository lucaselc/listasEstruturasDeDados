#include <stdio.h>
#include <stdlib.h>

int negativos(float *vet, int N){
    int neg=0;
    for(int i = 0; i < N; i++){
        if(vet[i]< 0){
            neg++;
        }    
    }
    return neg;
}

int main(){
    int N;
    scanf("%d", &N);
    float *vet =  (float*)malloc(N*sizeof(float));
    for(int i=0; i<N; i++){
        scanf("%f", &vet[i]);
    }
    int neg = negativos(vet,N);
    printf("No array há %d números negativos\n", neg);
    free(vet);
    return 0;
}