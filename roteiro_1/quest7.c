#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ordenar(char* vet, int N){
    if(N >= 0){
        printf("%c ", vet[N-1]);
        ordenar(vet, N-1);
    }
}

int main(){
    int N;
    scanf("%d", &N);
    char vet[N];
    for(int i = 0; i<N; i++){
        scanf("%s", &vet[i]);
    }
    ordenar(vet,N);
    printf("\n");
    return 0;

}
