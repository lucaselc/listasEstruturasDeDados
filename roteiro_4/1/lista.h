#ifndef LISTA_H
#define LISTA_H
#define MAX 100
typedef struct {
int dados [MAX];
int tam;
}Lista;
Lista* criaLista();
void destroiLista ( Lista * li);
int tamanhoLista ( Lista * li);
int listaCheia ( Lista * li);
int listaVazia ( Lista * li);
int insereFim ( Lista *li , int elem );
int insereInicio ( Lista *li , int elem );
int removeFim ( Lista *li);
int removeInicio ( Lista *li);
int imprimeLista ( Lista * li);
int procura( Lista *li, int x);
int insere_ordenada(Lista *li, int x);
int remove_ocorrente( Lista *li, int x);

#endif