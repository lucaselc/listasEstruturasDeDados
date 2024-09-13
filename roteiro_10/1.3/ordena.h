#ifndef ORDENA_H
#define ORDENA_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void selectionSort(int arr[], int n, long *comparacoes, long *movimentacoes) {
    int i, j, minIndex, temp;
    
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                (*comparacoes)++;
                minIndex = j;
            }
        }
        if (minIndex != i) {
            (*comparacoes)++;
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            (*movimentacoes) += 3; 
        }
    }
}

void insertionSort(int arr[], int n, long *comparacoes, long *movimentacoes) {
    int i, chave, j;
    
    for (i = 1; i < n; i++) {
        chave = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > chave) {
            (*comparacoes)++;
            arr[j + 1] = arr[j];
            (*movimentacoes)++;
            j = j - 1;
        }
        arr[j + 1] = chave;
        (*movimentacoes)++;
    }
}

void BubbleSort(int arr[], int n, long *comparacoes, long *movimentacoes) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            (*comparacoes)++;
            if (arr[j] > arr[j + 1]) {
                (*comparacoes)++;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                (*movimentacoes) += 3;
            }
        }
    }
}


void medirDesempenho(int *valores, int tamanho, char *tipoOrdenacao) {
    int *copiaValores = (int *)malloc(tamanho * sizeof(int));
    for (int i = 0; i < tamanho; ++i) {
        copiaValores[i] = valores[i];
    }

    clock_t inicio, fim;
    double tempoExecucao;
    long comparacoes = 0, movimentacoes = 0;

    inicio = clock();
    if (strcmp(tipoOrdenacao, "Selecao") == 0) {
        selectionSort(copiaValores, tamanho, &comparacoes, &movimentacoes);
    } else if (strcmp(tipoOrdenacao, "Insercao") == 0) {
        insertionSort(copiaValores, tamanho, &comparacoes, &movimentacoes);
    } else if (strcmp(tipoOrdenacao, "Bubble") == 0) {
        BubbleSort(copiaValores, tamanho, &comparacoes, &movimentacoes);
    } else {
        printf("Algoritmo de ordenação não está disponível\n");
        free(copiaValores);
        return;
    }
    fim = clock();

    tempoExecucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("Tipo de ordenacao: %s\n", tipoOrdenacao);
    printf("Tempo de execucao: %f segundos\n", tempoExecucao);
    printf("Numero de comparações: %ld\n", comparacoes);
    printf("Numero de movimentações: %ld\n\n", movimentacoes);

    free(copiaValores);
}

#endif
