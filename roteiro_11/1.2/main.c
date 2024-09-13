#include <stdio.h>
#include "Heap.h"
#include "Merge.h"
#include "Quick.h"
#include "Shell.h"


int main(){

   int n;
   printf("Quantidade de elementos a serem ordenados: ");
   scanf("%d", &n);


   int vetor[n];
   printf("Digite os %d inteiros a serem ordenados:\n", n);
   for (int i = 0; i < n; i++) {
       scanf("%d", &vetor[i]);
   }

   int heap[n], merge[n], quick[n], shell[n];
   for (int i = 0; i < n; i++) {
       heap[i] = vetor[i];
       merge[i] = vetor[i];
       quick[i] = vetor[i];
       shell[i] = vetor[i];
   }

   HeapSort(heap, n);
   MergeSort(merge, 0, n-1);
   QuickSort(quick, 0, n-1, n);
   ShellSort(shell, n);

   printf("\nValores ordenados pelo Heap Sort: ");
   for (int i = 0; i < n; i++) {
       printf("%d ", heap[i]);
   }

   printf("\nValores ordenados pelo Merge Sort: ");
   for (int i = 0; i < n; i++) {
       printf("%d ", merge[i]);
   }
   
   printf("\nValores ordenados pelo Quick Sort: ");
   for (int i = 0; i < n; i++) {
       printf("%d ", quick[i]);
   }

   printf("\nValores ordenados pelo Shell Sort: ");
   for (int i = 0; i < n; i++) {
       printf("%d ", shell[i]);
   }

   printf("\n");


   return 0;
}
