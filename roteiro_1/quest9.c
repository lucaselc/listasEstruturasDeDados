#include <stdio.h>
#include <stdlib.h>

int multi(int M, int N){
    if(N > 0)
        return M + multi(M, N-1);
    else if(N == 0)
        return 0;
}

int main(){
    int result=0,M,N;
    scanf("%d %d", &M, &N);
    result = multi(M,N);
    printf("Resultado da multiplicação =  %d\n", result);
    return 0;
}