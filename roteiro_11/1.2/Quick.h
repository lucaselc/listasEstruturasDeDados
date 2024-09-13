
#ifndef QUICK_H
#define QUICK_H


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Medidas de Complexidade
int comp; //Num. de comparacoes
int mov; //Num. de movimentacoes

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

//Versao do livro
int particiona(int *v, int ini, int fim){
    int esq, dir, pivo, aux;
    esq = ini; dir = fim;
    pivo = v[ini];
    while(esq < dir){
        while(esq <= fim && v[esq] <= pivo) esq++;
        while(dir >= 0 && v[dir] > pivo) dir--;
        if(esq < dir) trocaQuick(&v[esq], &v[dir]);
    }
    v[ini] = v[dir];
    v[dir] = pivo;
    return dir;
}

int particao(int *v, int ini, int fim){
    int i = ini, j = fim;
    int pivo = v[(ini+fim)/2];
    while (1) {
        comp++;
        while(v[i] > pivo){ i++; comp++; } // Modificado para ordenar em ordem decrescente
        
        comp++;
        while(v[j] < pivo){ j--; comp++;} // Modificado para ordenar em ordem decrescente
        
        if(i<j){
            trocaQuick(&v[i], &v[j]); // Troca os elementos encontrados
            mov++;
            i++;
            j--;
        }else
            return j; // Retorna o local onde foi feita a partição
    }    
}

void QuickSort(int *v, int ini, int fim, int n){
    if(ini < fim ){
        int q = particao(v, ini, fim);
        //printf("Parts: (%d, %d) e (%d, %d): ", ini, q, q+1, fim);
        //imprimeVetor(v, n);
        QuickSort(v, ini, q, n);
        QuickSort(v, q+1, fim, n);
    }
}

#endif