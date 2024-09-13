#ifndef DESEMPENHO_H
#define DESEMPENHO_H

#include "Heap.h"
#include "Merge.h"
#include "Quick.h"
#include "Shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void medirDesempenho(int *valores, int tamanho, char *tipoOrdenacao) {
    int *copiaValores = (int *)malloc(tamanho * sizeof(int));
    for (int i = 0; i < tamanho; ++i) {
        copiaValores[i] = valores[i];
    }

    clock_t inicio, fim;
    double tempoExecucao;
    long comp = 0, mov = 0;

    inicio = clock();
    if (strcmp(tipoOrdenacao, "Heap") == 0) {
        HeapSort(copiaValores, tamanho, &comp, &mov);
    } else if (strcmp(tipoOrdenacao, "Merge") == 0) {
        MergeSort(copiaValores, 0, tamanho-1, &comp, &mov);
    } else if (strcmp(tipoOrdenacao, "Quick") == 0) {
        QuickSort(copiaValores, 0, tamanho-1, tamanho, &comp, &mov);
    } else if (strcmp(tipoOrdenacao, "Shell") == 0) {
        ShellSort(copiaValores, tamanho, &comp, &mov);
    }
    
    else {
        printf("Algoritmo de ordenação não está disponível\n");
        free(copiaValores);
        return;
    }
    fim = clock();

    tempoExecucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("Tipo de ordenacao: %s\n", tipoOrdenacao);
    printf("Tempo de execucao: %f segundos\n", tempoExecucao);
    printf("Numero de comparações: %ld\n", comp);
    printf("Numero de movimentações: %ld\n\n", mov);

    free(copiaValores);
}


#endif