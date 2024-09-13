#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int raizes(float A, float B, float C, float *X1, float *X2){
    int delta = ((pow(B,2))-(4*A*C));
    if(delta>0){
        *X1 = ((-B + sqrt(delta))/2*A);
        *X2 = ((-B - sqrt(delta))/2*A);
        return 2;
    }
    else if(delta == 0){
        *X1 = ((-B + sqrt(delta))/2*A);
        return 1;
    }
    else{
        return 0;
    }

}

int main(){
    float A, B, C;
    float *X1 = (float*)malloc(sizeof(float));
    float *X2 = (float*)malloc(sizeof(float));
    scanf("%f %f %f",&A, &B, &C);
    int raiz = raizes(A,B,C,X1,X2);
    if(raiz==0){
        printf("Não possui raizes\n");
    }

    else if(raiz==1){
        printf("Possui raiz única = %.3f\n", *X1);
    }

    else{
        printf("Possui duas raizes = X1 -> %.3f e X2 -> %.3f\n", *X1, *X2);
    }
    free(X1);
    free(X2);
    return 0;

}