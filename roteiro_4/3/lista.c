#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


Lista * criaLista () {
   Lista *li;
   li = ( Lista *) malloc ( sizeof ( Lista ));
   if(li != NULL )
       *li = NULL ;
   return li;
}


int listaVazia ( Lista * li){
   if(li == NULL )
       return 1;
   if (* li == NULL )
       return 1;
   return 0;
}


NO* alocarNO () {
   return (NO *) malloc ( sizeof (NO));
}

void liberarNO (NO* q){
   free (q);
}

int insereIni( Lista * li , int elem ){
   if(li == NULL ) return 0;
   NO* novo = alocarNO () ;
   if( novo == NULL ) return 0;
   novo -> info = elem ;
   novo -> prox = *li;
   novo ->ant = NULL ;
   if (! listaVazia (li))
   (* li) ->ant = novo ;
   *li = novo ;
   return 1;
}


int insereFim ( Lista * li , int elem ){
   if(li == NULL ) return 0;
   NO* novo = alocarNO () ;
   if( novo == NULL ) return 0;
   novo -> info = elem ;
   novo -> prox = NULL ;
   if( listaVazia (li)){
       novo ->ant = NULL ;
       *li = novo ;
   } else {
       NO* aux = *li;
   while (aux -> prox != NULL )
       aux = aux -> prox ;
       aux -> prox = novo ;
       novo ->ant = aux;
   }
   return 1;
}


int removeIni ( Lista * li){
   if(li == NULL ) return 0;
   if( listaVazia (li)) return 0;
   NO* aux = *li;
   *li = aux -> prox ;
   if(aux -> prox != NULL )
       aux ->prox -> ant = NULL ;
   liberarNO (aux);
   return 1;
}


int removeFim ( Lista * li){
   if(li == NULL ) return 0;
   if( listaVazia (li)) return 0;
   NO * aux = *li;
   while (aux -> prox != NULL )
       aux = aux -> prox ;
   if(aux ->ant == NULL )
       *li = aux -> prox ;
   else
       aux ->ant -> prox = NULL ;
   liberarNO (aux);
   return 1;
}


void imprimeLista ( Lista * li){
   if(li == NULL ) return ;
   if( listaVazia (li)){
       printf (" Lista vazia!\n");
       return ;
   }
   printf (" Elementos: ");
   NO* aux = *li;
   while ( aux != NULL ){
       printf ("%d ", aux->info );
       aux = aux -> prox ;
   }
   printf ("\n");
}


void destroiLista ( Lista * li){
   if(li != NULL ){
       NO* aux;
       while ((* li) != NULL ){
           aux = *li;
           *li = (* li) ->prox ;
           liberarNO (aux);
       }
       free (li);
   }
}


int tamanhoLista ( Lista * li){
   int tam = 0;
   if(li == NULL ) 
    return 0;
   if(listaVazia(li)) 
    return 0;
   NO* aux = *li;
   while (aux->prox != NULL ){
       aux = aux->prox ;
       tam++;
   }
   tam++;
   return tam;
}


int procura(Lista * li, int elem){
   if(li == NULL ) return 0;
   if( listaVazia (li)) return 0;
   NO * aux = *li;
   while (aux->prox != NULL ){
       if(aux->info == elem){
           return 1;
       }
       aux = aux->prox ;
   }
   if(aux->info == elem)
       return 1;
   else{
       return 0;
   }
}

int insere_ordenado ( Lista * li , int x ){
 if (insereIni(li, x)) {
        NO *atual = *li;
        NO *anterior = NULL;
        int trocou = 0;

        while (atual->prox != NULL && atual->info > atual->prox->info) {
            int guardaElem = atual->info;
            atual->info = atual->prox->info;
            atual->prox->info = guardaElem;
            anterior = atual;
            atual = atual->prox;
            trocou = 1;
        }
        if (trocou && anterior != NULL) {
            anterior = NULL;
            atual = *li;
            while (atual->prox != NULL && atual->info > atual->prox->info){
                int guardaElem = atual->info;
                atual->info = atual->prox->info;
                atual->prox->info = guardaElem;

                anterior = atual;
                atual = atual->prox;
            }
        }
        return 1;
    } else {
        return 0;
    }
}

int remove_ocorrente(Lista * li, int elem){
   if(procura(li, elem)){
       NO * aux = *li;
       if(aux->info == elem){
           removeIni(li);
           return 1;
       }
       while (aux->prox != NULL ){
           if(aux->info == elem){
               aux->ant->prox = aux->prox;
               aux->prox->ant = aux->ant;
               liberarNO(aux);
               return 1;
           }
           aux = aux->prox ;
       }
       if(aux->info == elem){
           removeFim(li);
           return 1;
       }
       else{
           return 0;
       }
   }
   else{
       return 0;
   }
}