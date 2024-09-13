#include <stdio.h>
#include "decrescente.h"

int main(){
   int n;
   printf("Quantidade de elementos a serem ordenados: ");
   scanf("%d", &n);


   int vetor[n];
   printf("Digite os %d inteiros a serem ordenados:\n", n);
   for (int i = 0; i < n; i++) {
       scanf("%d", &vetor[i]);
   }


   int bubble[n], selection[n], insertion[n];
   for (int i = 0; i < n; i++) {
       bubble[i] = vetor[i];
       selection[i] = vetor[i];
       insertion[i] = vetor[i];
   }


   BubbleSort(bubble, n);
   SelectionSort(selection, n);
   InsertionSort(insertion, n);


 
   printf("\nValores ordenados pelo Bubble Sort: ");
   for (int i = 0; i < n; i++) {
       printf("%d ", bubble[i]);
   }
   printf("\nValores ordenados pelo Selection Sort: ");
   for (int i = 0; i < n; i++) {
       printf("%d ", selection[i]);
   }
   printf("\nValores ordenados pelo Insertion Sort: ");
   for (int i = 0; i < n; i++) {
       printf("%d ", insertion[i]);
   }
   printf("\n");

   return 0;
}
