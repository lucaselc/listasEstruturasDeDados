#include <stdio.h>
#include <stdlib.h>


int sequencia_cres(int N){
    if(N > 0){
        sequencia_cres(N-1);
        printf("%d", N);
    }
}

int sequencia_decres(int N){
    if(N > 0){
        printf("%d", N);
        sequencia_decres(N-1);
    }
}


int main(){
    printf("Sequência crescente\n");
    sequencia_cres(5);
    printf("\n");
    printf("Sequência decrescente\n");
    sequencia_decres(5);
    printf("\n");
    return 0;

}