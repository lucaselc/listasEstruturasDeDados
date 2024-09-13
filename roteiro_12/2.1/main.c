#include <stdio.h>
#include "hash.h"

// void binary(int n){
// 	if(n<2) 
//           printf("%d", n%2);
// 	else{
//           binary(n/2);
// 	  printf("%d", n%2);
// 	}
// }

int main(){

    // int x = 1;
    // int d;
    // printf("%d: ", x); binary(x); printf("\n");

    // d = x << 4;

    // printf("%d: ", d); binary(d); printf("\n");

    // d = d >> 2;

    // printf("%d: ", d); binary(d); printf("\n");

    Hash *H;;
    H = criaHash(5);

    int busca;


    insereHash_semTratar_div(H, 31);
    insereHash_semTratar_div(H, 32);
    insereHash_semTratar_div(H, 64);

    printf("Divisão:.\n");

    if(!buscaHash_semTratar_div(H, 64, &busca))
        printf("Elemento NAO encontrado.\n");
    else
        printf("Elemento %d encontrado.\n", busca);
    if(!buscaHash_semTratar_div(H, 31, &busca))
        printf("Elemento NAO encontrado.\n");
    else
        printf("Elemento %d encontrado.\n", busca);
    if(!buscaHash_semTratar_div(H, 33, &busca))
        printf("Elemento NAO encontrado.\n");
    else
        printf("Elemento %d encontrado.\n", busca);

    imprimeHash(H);
    destroiHash(H);
    H = criaHash(5);

    insereHash_semTratar_mul(H, 31);
    insereHash_semTratar_mul(H, 32);
    insereHash_semTratar_mul(H, 64);

    printf("Multiplicação:.\n");

    if(!buscaHash_semTratar_mul(H, 64, &busca))
        printf("Elemento NAO encontrado.\n");
    else
        printf("Elemento %d encontrado.\n", busca);
    if(!buscaHash_semTratar_mul(H, 31, &busca))
        printf("Elemento NAO encontrado.\n");
    else
        printf("Elemento %d encontrado.\n", busca);
        if(!buscaHash_semTratar_mul(H, 33, &busca))
        printf("Elemento NAO encontrado.\n");
    else
        printf("Elemento %d encontrado.\n", busca);

    imprimeHash(H);
    destroiHash(H);
    H = criaHash(10);

    insereHash_semTratar_dobra(H, 31);
    insereHash_semTratar_dobra(H, 32);
    insereHash_semTratar_dobra(H, 64);
    
    printf("Dobra:.\n");

    if(!buscaHash_semTratar_dobra(H, 64, &busca))
        printf("Elemento NAO encontrado.\n");
    else
        printf("Elemento %d encontrado.\n", busca);
    if(!buscaHash_semTratar_dobra(H, 31, &busca))
        printf("Elemento NAO encontrado.\n");
    else
        printf("Elemento %d encontrado.\n", busca);
        if(!buscaHash_semTratar_dobra(H, 33, &busca))
        printf("Elemento NAO encontrado.\n");
    else
        printf("Elemento %d encontrado.\n", busca);

    imprimeHash(H);
    destroiHash(H);

    // insereHash_EnderAberto(H, 31);
    // insereHash_EnderAberto(H, 32);
    // insereHash_EnderAberto(H, 62);

    // if(!buscaHash_EnderAberto(H, 31, &busca))
    //     printf("Elemento NAO encontrado.\n");
    // else
    //     printf("Elemento %d encontrado.\n", busca);

    // if(!buscaHash_EnderAberto(H, 62, &busca))
    //     printf("Elemento NAO encontrado.\n");
    // else
    //     printf("Elemento %d encontrado.\n", busca);

    return 0;
}