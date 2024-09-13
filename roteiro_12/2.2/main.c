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

    insereHash_EnderAberto_lin(H, 31);
    insereHash_EnderAberto_lin(H, 32);
    insereHash_EnderAberto_lin(H, 64);

    printf("Linear:.\n");

    if(!buscaHash_EnderAberto_lin(H, 64, &busca))
        printf("Elemento NAO encontrado.\n");
    else
        printf("Elemento %d encontrado.\n", busca);
    if(!buscaHash_EnderAberto_lin(H, 31, &busca))
        printf("Elemento NAO encontrado.\n");
    else
        printf("Elemento %d encontrado.\n", busca);
    if(!buscaHash_EnderAberto_lin(H, 33, &busca))
        printf("Elemento NAO encontrado.\n");
    else
        printf("Elemento %d encontrado.\n", busca);

    imprimeHash(H);
    destroiHash(H);
    H = criaHash(5);

    insereHash_EnderAberto_quad(H, 31);
    insereHash_EnderAberto_quad(H, 32);
    insereHash_EnderAberto_quad(H, 64);

    printf("Quadratica:.\n");

    if(!buscaHash_EnderAberto_quad(H, 64, &busca))
        printf("Elemento NAO encontrado.\n");
    else
        printf("Elemento %d encontrado.\n", busca);
    if(!buscaHash_EnderAberto_quad(H, 31, &busca))
        printf("Elemento NAO encontrado.\n");
    else
        printf("Elemento %d encontrado.\n", busca);
    if(!buscaHash_EnderAberto_quad(H, 33, &busca))
        printf("Elemento NAO encontrado.\n");
    else
        printf("Elemento %d encontrado.\n", busca);

    imprimeHash(H);
    destroiHash(H);
    H = criaHash(5);

    insereHash_EnderAberto_duplo(H, 31);
    insereHash_EnderAberto_duplo(H, 32);
    insereHash_EnderAberto_duplo(H, 64);
    
    printf("Duplo:.\n");

    if(!buscaHash_EnderAberto_duplo(H, 64, &busca))
        printf("Elemento NAO encontrado.\n");
    else
        printf("Elemento %d encontrado.\n", busca);
    if(!buscaHash_EnderAberto_duplo(H, 31, &busca))
        printf("Elemento NAO encontrado.\n");
    else
        printf("Elemento %d encontrado.\n", busca);
    if(!buscaHash_EnderAberto_duplo(H, 33, &busca))
        printf("Elemento NAO encontrado.\n");
    else
        printf("Elemento %d encontrado.\n", busca);

    imprimeHash(H);
    destroiHash(H);

    return 0;

}