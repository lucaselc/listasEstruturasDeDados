
#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int* copiaVetorHeap(int* v, int n){
    int i;
    int *v2;
    v2 = (int*) malloc (n*sizeof(int));
    for(i=0; i<n; i++) v2[i] = v[i];
    return v2;
}
void imprimeVetorHeap(int* v, int n){
    int i, prim = 1;
    printf("[");
    for(i=0; i<n; i++)
        if(prim){ printf("%d", v[i]); prim = 0; }
        else printf(", %d", v[i]);
    printf("]\n");
}

void preencheAleatorioHeap(int* v, int n, int ini, int fim){
    int i;
    for(i=0; i<n; i++){
        v[i] = ini + rand() % (fim-ini + 1); 
        //v[i] = (n-i); //Para o pior caso
    }
}

void trocaHeap(int* a, int *b){
	int aux = *a;
	*a = *b;
	*b = aux;
} 

void criaHeap(int *v, int pai, int fim, long* comp, long* mov){
    int aux = v[pai];
    int filho = 2*pai + 1;
    while(filho <= fim){
        if(filho < fim && v[filho] < v[filho+1]){
            filho++;
        }
        (*comp)++; // Contabiliza a comparação

        if(aux < v[filho]){
            v[pai] = v[filho];
            pai = filho;
            filho = 2*pai + 1;
            (*mov)++; // Contabiliza a movimentação
        } else {
            filho = fim + 1;
        }
    }
    v[pai] = aux;
}

void HeapSort(int *v, int n, long* comp, long* mov){
    int i;
    for(i=(n-1)/2; i>=0; i--)
        criaHeap(v, i, n-1, comp, mov);
    for(i=n-1; i>=1; i--){
        trocaHeap(&v[0], &v[i]);
        criaHeap(v, 0, i-1, comp, mov);
    }
}


#endif