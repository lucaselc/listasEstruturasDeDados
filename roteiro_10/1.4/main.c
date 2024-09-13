#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordena.h"

int main() {
    int N;

    printf("Digite o valor de N: ");
    scanf("%d", &N);

    Pessoa vetor[N];

    printf("Digite os %d nomes e idades:\n", N);
    for (int i = 0; i < N; i++) {
        printf("Nome: ");
        scanf("%s", vetor[i].nome);
        printf("Idade: ");
        scanf("%d", &vetor[i].idade);
    }

    selectionSortCrescente(vetor, N);
    printf("Selection Sort (crescente):\n");
    imprimirVetorPessoa(vetor, N);

    selectionSortDecrescente(vetor, N);
    printf("Selection Sort (decrescente):\n");
    imprimirVetorPessoa(vetor, N);

    insertionSortCrescente(vetor, N);
    printf("Insertion Sort (crescente):\n");
    imprimirVetorPessoa(vetor, N);

    insertionSortDecrescente(vetor, N);
    printf("Insertion Sort (decrescente):\n");
    imprimirVetorPessoa(vetor, N);


    return 0;
}
