#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "conjunto.h"

Conjunto criar_conjunto(){
    Conjunto conjunto;
    conjunto.elementos = NULL;
    conjunto.tam = 0;
    return conjunto;

}
void inserir_elemento(Conjunto* conjunto, int elemento){
    for(int i = 0; i<conjunto->tam; i++){
        if(conjunto->elementos[i]==elemento)
        return;
    }
    conjunto->tam++;
    conjunto->elementos=(int*)realloc(conjunto->elementos, conjunto->tam*sizeof(int));
    conjunto->elementos[conjunto->tam-1]= elemento;
}
bool pertece_conjunto(Conjunto* conjunto, int elemento){
    for(int i = 0; i<conjunto->tam; i++){
        if(conjunto->elementos[i]==elemento)
        return true;
    }
    return false;

}
int maior_conjunto(Conjunto* conjunto){
    int maior = conjunto->elementos[0];
    for(int i = 0; i<conjunto->tam; i++){
        if(conjunto->elementos[i]>maior)
            maior = conjunto->elementos[i];
    }
    return maior;
}
int menor_conjunto(Conjunto* conjunto){
    int menor = conjunto->elementos[0];
    for(int i = 0; i<conjunto->tam; i++){
        if(conjunto->elementos[i]<menor)
            menor = conjunto->elementos[i];
    }
    return menor;
}
bool conjuntos_iguais(Conjunto* conjunto_x ,Conjunto* conjunto_y){
    if(conjunto_x->tam != conjunto_y->tam){
        return false;
    }
    for(int i=0; i<conjunto_x->tam; i++){
        if(false == pertece_conjunto(conjunto_y, conjunto_x->elementos[i]))
            return false;
    }
    return true;
}

bool conjunto_vazio(Conjunto* conjunto){
    if(conjunto->tam==0)
        return true;
    return false;
}

void remover_elemento(Conjunto* conjunto, int elemento){
    for(int i = 0; i<conjunto->tam; i++){
        if(conjunto->elementos[i]==elemento)
        {
            for(int j=0; j<conjunto->tam -1; j++){
                conjunto->elementos[j]= conjunto->elementos[j+1];
            }
            conjunto->elementos = (int*)realloc(conjunto->elementos, conjunto->tam*sizeof(int));
            conjunto->tam--;
            return;
        }
    }
    
}
int tam_conjunto(Conjunto* conjunto){
    return conjunto->tam;
}
void intersecao_conjuntos(Conjunto* conjunto_x ,Conjunto* conjunto_y,  Conjunto* intersecao){
    for(int i=0; i<conjunto_x->tam; i++){
        int elemento = conjunto_x->elementos[i];
        if(pertece_conjunto(conjunto_y, elemento))
            inserir_elemento(intersecao, elemento);
    }
}
void print_elementos(Conjunto* conjunto){
    for(int i=0; i<conjunto->tam; i++){
        printf("%d ", conjunto->elementos[i]);
    }
    printf("\n");
}
void diferenca_conjuntos(Conjunto* conjunto_x ,Conjunto* conjunto_y, Conjunto* resultado){
    for(int i=0; i<conjunto_x->tam; i++){
        int elemento = conjunto_x->elementos[i];
        if(false == pertece_conjunto(conjunto_y, elemento))
            inserir_elemento(resultado, elemento);
    }
}
void uniao_conjunto(Conjunto* conjunto_x ,Conjunto* conjunto_y, Conjunto* uniao){
    for(int i=0; i<conjunto_x->tam; i++){
        inserir_elemento(uniao, conjunto_x->elementos[i]);
    }

    for(int i=0; i<conjunto_y->tam; i++){
        if(false==pertece_conjunto(uniao,conjunto_y->elementos[i]))
            inserir_elemento(uniao, conjunto_y->elementos[i]);
    }
}
void liberar_conjunto(Conjunto* conjunto){
    free(conjunto->elementos);
    conjunto->tam=0;
    conjunto->elementos=NULL;
}