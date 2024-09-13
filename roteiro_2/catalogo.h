#ifndef catalogo_h
#define catalogo_h

typedef struct Produto{
    char nome[100];
    double preco;
    int quantidade;
}Produto;

typedef struct CatalogoProdutos{
    Produto produtos[100];
    int total;
}CatalogoProdutos;

void criarCatalogo(CatalogoProdutos *c);
void adicionarProduto(CatalogoProdutos *c, char *nome, double preco, int quantidade);
int verificarEstoque(CatalogoProdutos *c, char *nome);
void imprimirCatalogo(CatalogoProdutos *c);

#endif