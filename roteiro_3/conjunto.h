#ifndef CONJUNTO_H
#define CONJUNTO_H

typedef struct Conjunto
{
    int *elementos;
    int tam;
}Conjunto;

Conjunto criar_conjunto();
void inserir_elemento(Conjunto* conjunto, int elemento);
bool pertece_conjunto(Conjunto* conjunto, int elemento);
int maior_conjunto(Conjunto* conjunto);
int menor_conjunto(Conjunto* conjunto);
bool conjuntos_iguais(Conjunto* conjunto_x ,Conjunto* conjunto_y);
bool conjunto_vazio(Conjunto* conjunto);
void remover_elemento(Conjunto* conjunto, int elemento);
void intersecao_conjuntos(Conjunto* conjunto_x ,Conjunto* conjunto_y,  Conjunto* intersecao);
void print_elementos(Conjunto* conjunto);
void diferenca_conjuntos(Conjunto* conjunto_x ,Conjunto* conjunto_y, Conjunto* resultado);
void uniao_conjunto(Conjunto* conjunto_x ,Conjunto* conjunto_y, Conjunto* uniao);
void liberar_conjunto(Conjunto* conjunto);
int tam_conjunto(Conjunto* conjunto);

#endif