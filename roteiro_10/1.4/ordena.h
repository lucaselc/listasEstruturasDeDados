#ifndef ORDENA_H
#define ORDENA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char nome[50];
    int idade;
} Pessoa;

void trocarPessoa(Pessoa *a, Pessoa *b) {
    Pessoa temp = *a;
    *a = *b;
    *b = temp;
}

int compararPessoa(const void *a, const void *b) {

    int comparacaoNome = strcmp(((Pessoa*)a)->nome, ((Pessoa*)b)->nome);
    
    if (comparacaoNome != 0) {
        return comparacaoNome;
    } else {
        
        return ((Pessoa*)a)->idade - ((Pessoa*)b)->idade;
    }
}

void selectionSortCrescente(Pessoa vetor[], int n) {
    int i, j, min_index;
    for (i = 0; i < n-1; i++) {
        min_index = i;
        for (j = i+1; j < n; j++)
            if (compararPessoa(&vetor[j], &vetor[min_index]) < 0)
                min_index = j;
        trocarPessoa(&vetor[min_index], &vetor[i]);
    }
}

void selectionSortDecrescente(Pessoa vetor[], int n) {
    int i, j, max_index;
    for (i = 0; i < n-1; i++) {
        max_index = i;
        for (j = i+1; j < n; j++)
            if (compararPessoa(&vetor[j], &vetor[max_index]) > 0)
                max_index = j;
        trocarPessoa(&vetor[max_index], &vetor[i]);
    }
}

void insertionSortCrescente(Pessoa vetor[], int n) {
    int i, j;
    Pessoa chave;
    for (i = 1; i < n; i++) {
        chave = vetor[i];
        j = i - 1;
        while (j >= 0 && compararPessoa(&vetor[j], &chave) > 0) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = chave;
    }
}

void insertionSortDecrescente(Pessoa vetor[], int n) {
    int i, j;
    Pessoa chave;
    for (i = 1; i < n; i++) {
        chave = vetor[i];
        j = i - 1;
        while (j >= 0 && compararPessoa(&vetor[j], &chave) < 0) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = chave;
    }
}

void imprimirVetorPessoa(Pessoa vetor[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nome: %s, Idade: %d\n", vetor[i].nome, vetor[i].idade);
    }
    printf("\n");
}

#endif
