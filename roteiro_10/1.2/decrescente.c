#include <stdio.h>
#include "ordenacao.h"
int comp = 0;
int mov = 0;


void troca(int *a, int *b) {
   int temp = *a;
   *a = *b;
   *b = temp;
}
void BubbleSort(int *v, int n) {
   int i, j;
   for (i = 0; i < n - 1; i++) {
       for (j = 0; j < n - i - 1; j++) {
           comp++;
           if (v[j] < v[j + 1]) {
               troca(&v[j+1], &v[j]);
               mov++;
           }
       }
   }
}


void SelectionSort(int *v, int n) {
   int i, j, maior;
   for (i = 0; i < n - 1; i++) {
       maior = i;
       for (j = i + 1; j < n; j++) {
           comp++;
           if (v[j] > v[maior]) {
               maior = j;
           }
       }
       if (i != maior) {
           troca(&v[i], &v[maior]);
           mov++;
       }
   }
}


void InsertionSort(int *v, int n) {
   int i, j, atual;
   for (i = 1; i < n; i++) {
       atual = v[i];
       comp++;
       for (j = i; (j > 0) && (atual > v[j - 1]); j--) {
           v[j] = v[j - 1];
           mov++;
           comp++;
       }
       v[j] = atual;
   }
}
