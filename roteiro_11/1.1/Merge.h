/*---------------- File: Merge.c  ----------------------+
|Merge Sort                                             |
|					      		                        |
|					      		                        |
| Implementado por Guilherme C. Pena em 08/11/2023      |
+-------------------------------------------------------+ */
#ifndef MERGE_H
#define MERGE_H


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Medidas de Complexidade
int comp; //Num. de comparacoes
int mov; //Num. de movimentacoes

int* copiaVetorMerge(int* v, int n){
    int i;
    int *v2;
    v2 = (int*) malloc (n*sizeof(int));
    for(i=0; i<n; i++) v2[i] = v[i];
    return v2;
}
void imprimeVetorMerge(int* v, int n){
    int i, prim = 1;
    printf("[");
    for(i=0; i<n; i++)
        if(prim){ printf("%d", v[i]); prim = 0; }
        else printf(", %d", v[i]);
    printf("]\n");
}

void preencheAleatorioMerge(int* v, int n, int ini, int fim){
    int i;
    for(i=0; i<n; i++)
        v[i] = ini + rand() % (fim-ini + 1); 
}

void trocaMerge(int* a, int *b){
	int aux = *a;
	*a = *b;
	*b = aux;
} 

void Merge(int *v, int ini, int meio, int fim){
    int tam = fim-ini+1;
    //Vetor Auxiliar - A
    int *A = (int*) malloc (tam*sizeof(int));
    int i = ini, j = meio+1, k = 0;
    while (i<=meio && j<=fim) {
        if (v[i] < v[j]){ A[k] = v[i]; i++; }
        else { A[k] = v[j]; j++; }
        k++;
    }
    while (i<=meio) { A[k] = v[i];  i++;  k++; }
    while (j<=fim) { A[k] = v[j];  j++;  k++; }
    for(i = ini, k=0; i<=fim; i++, k++) v[i] = A[k];
    free(A);
}

void MergeSort(int *v, int ini, int fim){
    if(ini < fim ){
        int meio = (ini + fim)/2;
        MergeSort(v, ini, meio);
        MergeSort(v, meio+1, fim);
        Merge(v, ini, meio, fim);
    }
}


#endif