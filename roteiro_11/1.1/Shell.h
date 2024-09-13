/*---------------- File: Shell.c  ------------------+
|Shell Sort                                             |
|					      		                                    |
|					      		                                    |
| Implementado por Guilherme C. Pena em 20/11/2023      |
+-------------------------------------------------------+ */

#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Medidas de Complexidade
int comp; //Num. de comparacoes
int mov; //Num. de movimentacoes

int* copiaVetorShell(int* v, int n){
    int i;
    int *v2;
    v2 = (int*) malloc (n*sizeof(int));
    for(i=0; i<n; i++) v2[i] = v[i];
    return v2;
}
void imprimeVetorShell(int* v, int n){
    int i, prim = 1;
    printf("[");
    for(i=0; i<n; i++)
        if(prim){ printf("%d", v[i]); prim = 0; }
        else printf(", %d", v[i]);
    printf("]\n");
}

void preencheAleatorioShell(int* v, int n, int ini, int fim){
    int i;
    for(i=0; i<n; i++)
        v[i] = ini + rand() % (fim-ini + 1); 
}

void trocaShell(int* a, int *b){
	int aux = *a;
	*a = *b;
	*b = aux;
} 

void ShellSort(int *v, int n) {
  int i, j, atual;
  int h = 1;
  while(h < n) h = 3*h+1;
  while (h > 0) {
    for(i = h; i < n; i++) {
      atual = v[i];
      j = i;
      while (j > h-1 && atual <= v[j - h]) {
        v[j] = v[j - h];
        j = j - h;
      }
      v[j] = atual;
    }
    h = h/3;
  }
}

#endif