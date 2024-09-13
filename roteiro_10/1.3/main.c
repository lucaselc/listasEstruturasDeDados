
#include <stdio.h>
#include <stdlib.h>
#include "ordena.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <nome_do_arquivo>\n", argv[0]);
        return 1;
    }

    FILE *arquivo = fopen(argv[1], "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int tamanho;
    fscanf(arquivo, "%d", &tamanho);

    int *valores = (int *)malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; i++) {
        fscanf(arquivo, "%d", &valores[i]);
    }

    fclose(arquivo);

    medirDesempenho(valores, tamanho, "Selecao");
    medirDesempenho(valores, tamanho, "Insercao");
    medirDesempenho(valores, tamanho, "Bubble");

    free(valores);

    return 0;
}