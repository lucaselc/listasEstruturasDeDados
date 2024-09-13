#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "catalogo.h"

int main(){
    char nome[100], produto[100];
    double preco;
    int quantidade, total;
    CatalogoProdutos *c = (CatalogoProdutos*)malloc(sizeof(CatalogoProdutos));
    criarCatalogo(c);
    scanf("%s %lf %d", nome, &preco, &quantidade);
    adicionarProduto(c, nome, preco, quantidade);
    scanf("%s %lf %d", nome, &preco, &quantidade);
    adicionarProduto(c, nome, preco, quantidade);
    scanf("%s", produto);
    printf("Quantidade de %s no estoque: %d\n", produto ,verificarEstoque(c, produto));
    imprimirCatalogo(c);
    free(c);
    return 0;
}