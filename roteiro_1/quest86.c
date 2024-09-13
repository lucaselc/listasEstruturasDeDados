#include <stdio.h>
#include <stdlib.h>

int somatorio(int maior, int menor){
    if(maior > menor)
        return maior + somatorio(maior-1, menor);
}

int main(){
    int soma= 0, num1, num2;
    scanf("%d %d", &num1, &num2);
    int maior, menor;
    if(num1>num2){
        maior= num1;
        menor= num2;
    }else{
        maior=num2;
        menor=num1;
    }
    soma = somatorio(maior, menor);
    printf("Soma do intervalo =  %d\n", soma);
    return 0;
}