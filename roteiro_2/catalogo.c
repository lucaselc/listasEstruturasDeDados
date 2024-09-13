#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "catalogo.h"

void criarCatalogo(CatalogoProdutos *c){
    c->total = 0;
}

void adicionarProduto(CatalogoProdutos *c, char *nome, double preco, int quantidade){
    strcpy(c->produtos[c->total].nome, nome);
    c->produtos[c->total].preco = preco;
    c->produtos[c->total].quantidade = quantidade;
    c->total += 1;
}

int verificarEstoque(CatalogoProdutos *c, char *nome){
    for(int i = 0; i < 100; i++){
        if(strcmp(c->produtos[i].nome, nome) == 0){
            return c->produtos[i].quantidade;
        }
    }
    return 0;
}

void imprimirCatalogo(CatalogoProdutos *c){
    printf("\n - CATÁLOGO - \n");
    for(int i = 0; i < c->total; i++){
        printf("Nome: %s - Preço: R$%.2lf - Quantidade:%d\n", c->produtos[i].nome, c->produtos[i].preco, c->produtos[i].quantidade);
    }
}