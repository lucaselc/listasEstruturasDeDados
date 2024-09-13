# ifndef LISTA_H
# define LISTA_H

typedef struct NO{
   int info ;
   struct NO* ant;
   struct NO* prox ;
}NO;
typedef struct NO* Lista ;
#endif


Lista *criaLista();
int listaVazia(Lista * li);
NO* alocarNO();
void liberarNO(NO* q);
int insereIni(Lista * li , int elem );
int insereFim(Lista * li , int elem );
int removeIni(Lista * li);
int removeFim(Lista * li);
void imprimeLista(Lista * li);
void destroiLista(Lista * li);
int tamanhoLista (Lista * li);
int procura(Lista *li, int elem);
int insere_ordenado(Lista * li , int elem );
int remove_ocorrente(Lista * li, int elem);
