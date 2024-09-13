/*---------------- File: Quick.c  ----------------------+
|Quick Sort                                             |
|					      		                        |
|					      		                        |
| Implementado por Guilherme C. Pena em 14/11/2023      |
+-------------------------------------------------------+ */
#ifndef QUICK_H
#define QUICK_H


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int* copiaVetorQuick(int* v, int n){
    int i;
    int *v2;
    v2 = (int*) malloc (n*sizeof(int));
    for(i=0; i<n; i++) v2[i] = v[i];
    return v2;
}
void imprimeVetorQuick(int* v, int n){
    int i, prim = 1;
    printf("[");
    for(i=0; i<n; i++)
        if(prim){ printf("%d", v[i]); prim = 0; }
        else printf(", %d", v[i]);
    printf("]\n");
}

void preencheAleatorioQuick(int* v, int n, int ini, int fim){
    int i;
    for(i=0; i<n; i++){
        v[i] = ini + rand() % (fim-ini + 1); 
        //v[i] = (n-i); //Para o pior caso
    }
}

void trocaQuick(int* a, int *b){
	int aux = *a;
	*a = *b;
	*b = aux;
} 

int particao(int *v, int ini, int fim, long *comp, long *mov){
    int i = ini, j = fim;
    int pivo = v[(ini+fim)/2];
    while (1) {

        while(v[i] < pivo){ i++; (*comp)++; } // Incrementa comparação

        while(v[j] > pivo){ j--; (*comp)++; } // Incrementa comparação
        
        if(i < j){
            (*comp)++;
            (*mov)++;
            trocaQuick(&v[i], &v[j]); // Troca os elementos encontrados
            i++;
            j--;
        } else {
            return j; // Retorna o local onde foi feita a partição
        }
    }    
}

void QuickSort(int *v, int ini, int fim, int n, long *comp, long *mov){
    if(ini < fim ){
        int q = particao(v, ini, fim, comp, mov);
        QuickSort(v, ini, q, n, comp, mov);
        QuickSort(v, q+1, fim, n, comp, mov);
    }
}

#endif