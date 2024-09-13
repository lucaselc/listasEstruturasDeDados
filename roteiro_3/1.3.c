#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "conjunto.h"

int main(){
    Conjunto conjunto_x = criar_conjunto();
    Conjunto conjunto_y = criar_conjunto();
    Conjunto intersecao = criar_conjunto();
    Conjunto resultado = criar_conjunto();
    Conjunto uniao = criar_conjunto();

    inserir_elemento(&conjunto_x, 6);
    inserir_elemento(&conjunto_x, 1);
    inserir_elemento(&conjunto_y, 6);
    printf("Tamanho do conjunto x: %d\n", tam_conjunto(&conjunto_x));
    printf("Menor: %d e Maior: %d elemento do conjunto x\n",menor_conjunto(&conjunto_x), maior_conjunto(&conjunto_x));
    intersecao_conjuntos(&conjunto_x, &conjunto_y, &intersecao);
    printf("Intercesão dos conjuntos: \n");
    print_elementos(&intersecao);
    printf("Diferença dos conjuntos:\n");
    diferenca_conjuntos(&conjunto_x,&conjunto_y, &resultado);
    print_elementos(&resultado);
    if(conjuntos_iguais(&conjunto_x, &conjunto_y)){
        printf("Conjuntos iguais\n");
    }else{
        printf("Conjuntos diferentes\n");
    }
    remover_elemento(&conjunto_y,6);
    if(conjunto_vazio(&conjunto_y)){
        printf("Conjunto vazio\n");
    }else{
        printf("Conjunto não vazio\n");
    }
    inserir_elemento(&conjunto_y, 7);
    printf("União: \n");
    uniao_conjunto(&conjunto_x, &conjunto_y, &uniao);
    print_elementos(&uniao);
    liberar_conjunto(&conjunto_x);
    liberar_conjunto(&conjunto_y);
    liberar_conjunto(&resultado);
    liberar_conjunto(&uniao);
    return 0;
    
}