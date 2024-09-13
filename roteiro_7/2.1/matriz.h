#ifndef MATRIZ_H
#define MATRIZ_H

#include <stdio.h>
#include <stdlib.h>

typedef struct{

    int* diagonal;
    int* superior;
    int* inferior;
    int tam;

} MFaixa;

int zeraMatriz(MFaixa* mat);

MFaixa* criaMatriz(int tam){

    MFaixa* mat = (MFaixa*)malloc(sizeof(MFaixa));

    if(mat != NULL){

        if(tam <= 1){
            printf("ERRO: Tamanho da matriz inválido.\n");
            return NULL;
        }

        mat->tam = tam;
        mat->diagonal = (int*)malloc(tam * sizeof(int));
        mat->superior = (int*)malloc((tam-1) * sizeof(int));
        mat->inferior = (int*)malloc((tam-1) * sizeof(int));

        if(mat->diagonal == NULL || mat->superior == NULL || mat->inferior == NULL){
            return NULL;
        }

        zeraMatriz(mat);

    }

    return mat;

}

int destroiMatriz(MFaixa* mat){

    if(mat == NULL){
        printf("ERRO: Matriz não encontrada.\n");
        return 0;
    }

    free(mat->diagonal);
    free(mat->superior);
    free(mat->inferior);
    free(mat);
    
    return 1;

}

int zeraMatriz(MFaixa* mat){

    if(mat == NULL){
        printf("ERRO: Matriz não encontrada.\n");
        return 0;
    }

    int i;
    for(i = 0; i < mat->tam-1; i++){
        mat->diagonal[i] = 0;
        mat->superior[i] = 0;
        mat->inferior[i] = 0;
    }

    mat->diagonal[i] = 0;

    return 1;

}

int insereElemento(MFaixa* mat, int elem, int i, int j){

    if(mat == NULL){
        printf("ERRO: Matriz não encontrada.\n");
        return 0;
    }

    if(i == j){
        mat->diagonal[i] = elem;
    }

    else if(i+1 == j){
        mat->superior[i] = elem;
    }

    else if(i == j+1){
        mat->inferior[j] = elem;
    }

    else{
        printf("ERRO: Posição do elemento fora dos limites da matriz.\n");
        return 0;
    }

    return 1;

}

int consultaElemento(MFaixa* mat, int i, int j){

    if(mat == NULL){
        printf("ERRO: Matriz não encontrada.\n");
        return 0;
    }

    if(i == j){
        return mat->diagonal[i];
    }

    else if(i+1 == j){
        return mat->superior[i];
    }

    else if(i == j+1){
        return mat->inferior[j];
    }

    else{
        printf("ERRO: Posição do elemento fora dos limites da matriz.\n");
        return 0;
    }

}

void imprimeMatriz(MFaixa* mat){

    if(mat == NULL){
        printf("ERRO: Matriz não encontrada.\n");
    }

    for(int i = 0; i < mat->tam; i++){
        for(int j = 0; j < mat->tam; j++){
            
            if(i == j){
                printf("%d\t", mat->diagonal[i]);
            }

            else if(i+1 == j){
                printf("%d\t", mat->superior[i]);
            }

            else if(i == j+1){
                printf("%d\t", mat->inferior[j]);
            }

            else{
                printf("0\t");
            }

        }
        printf("\n");
    }

}

#endif