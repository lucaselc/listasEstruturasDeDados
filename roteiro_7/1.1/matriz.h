#ifndef MATRIZ_H
#define MATRIZ_H

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct{

    int dados[MAX][MAX];
    int lin, col;

} Matriz;

int zeraMatriz(Matriz* mat);

Matriz* criaMatriz(int l, int c){

    if(l < 0 || l > MAX || c < 0 || c > MAX){
        printf("Valores de linha e/ou coluna inválido(s).\n");
        return NULL;
    }

    Matriz* mat = (Matriz*)malloc(sizeof(Matriz));

    if(mat != NULL){
        mat->lin = l;
        mat->col = c;
        zeraMatriz(mat);
    }

    return mat;

}

int destroiMatriz(Matriz* mat){

    if(mat == NULL){
        printf("Matriz não encontrada.\n");
        return 0;
    }

    free(mat);
    return 1;

}

int zeraMatriz(Matriz* mat){

    if(mat == NULL){
        printf("Matriz não encontrada.\n");
        return 0;
    }

    for(int i = 0; i < mat->lin; i++){
        for(int j = 0; j < mat->col; j++){
            mat->dados[i][j] = 0;
        }
    }

    return 1;

}

int insereElemento(Matriz* mat, int elem, int l, int c){

    if(mat == NULL){
        printf("Matriz não encontrada.\n");
        return 0;
    }

    if(l < 0 || l > MAX || c < 0 || c > MAX){
        printf("Valores de linha e/ou coluna inválido(s).\n");
        return 0;
    }

    mat->dados[l][c] = elem;
    return 1;

}

int consultaElemento(Matriz* mat, int* p, int l, int c){

    if(mat == NULL){
        printf("Matriz não encontrada.\n");
        return 0;
    }

    if(l < 0 || l > MAX || c < 0 || c > MAX){
        printf("Valores de linha e/ou coluna inválido(s).\n");
        return 0;
    }

    *p = mat->dados[l][c];
    return 1;
 
}

void imprimeMatriz(Matriz* mat){

    if(mat == NULL){
        printf("Matriz não encontrada.\n");
        return;
    }

    printf("Elementos:\n");
    for(int i = 0; i < mat->lin; i++){
        printf("[\t");
        for(int j = 0; j < mat->col; j++){
            printf("%d\t", mat->dados[i][j]);
        }
        printf("]\n");
    }

}

Matriz* criaTransposta(Matriz* mat){

    if(mat == NULL){
        printf("Matriz não encontrada.\n");
        return NULL;
    }

    Matriz* transp = criaMatriz(mat->col, mat->lin);

    for(int i = 0; i < transp->lin; i++){
        for(int j = 0; j < transp->col; j++){
            transp->dados[i][j] = mat->dados[j][i];
        }
    }

    return transp;

}

int testeQuadrada(Matriz* mat){

    if(mat == NULL){
        printf("Matriz não encontrada.\n");
        return 0;
    }

    return (mat->lin == mat->col);

}

int testeSimetrica(Matriz* mat){

    if(mat == NULL){
        printf("Matriz não encontrada.\n");
        return 0;
    }

    if(!testeQuadrada(mat)){
        printf("Matriz não quadrada.\n");
        return 0;
    }

    for(int i = 0; i < mat->lin; i++){
        for(int j = i+1; j < mat->col; j++){
            if(mat->dados[i][j] != mat->dados[j][i]){
                return 0;
            }
        }
    }

    return 1;

}

Matriz* criaTriangSuperior(Matriz* mat){

    if(mat == NULL){
        printf("Matriz não encontrada.\n");
        return 0;
    }

    if(!testeQuadrada(mat)){
        printf("Matriz não quadrada.\n");
        return 0;
    }

    Matriz* triangSup = criaMatriz(mat->lin, mat->col);

    for(int i = 0; i < mat->lin; i++){
        for(int j = 0; j < mat->col; j++){
            if(i <= j){
                triangSup->dados[i][j] = mat->dados[i][j];
            }
        }
    }

    return triangSup;

}

Matriz* criaTriangInferior(Matriz* mat){

    if(mat == NULL){
        printf("Matriz não encontrada.\n");
        return 0;
    }

    if(!testeQuadrada(mat)){
        printf("Matriz não quadrada.\n");
        return 0;
    }

    Matriz* triangInf = criaMatriz(mat->lin, mat->col);

    for(int i = 0; i < mat->lin; i++){
        for(int j = 0; j < mat->col; j++){
            if(i >= j){
                triangInf->dados[i][j] = mat->dados[i][j];
            }
        }
    }

    return triangInf;

}

Matriz* criaDiagonal(Matriz* mat){

    if(mat == NULL){
        printf("Matriz não encontrada.\n");
        return 0;
    }

    if(!testeQuadrada(mat)){
        printf("Matriz não quadrada.\n");
        return 0;
    }

    Matriz* diag = criaMatriz(mat->lin, mat->col);

    for(int i = 0; i < diag->lin; i++){
        diag->dados[i][i] = mat->dados[i][i];
    }

    return diag;

}

#endif