#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista * criaLista(){
    Lista *li;
    li = ( Lista *)malloc( sizeof ( Lista ));
    if(li != NULL )
        li->tam = 0;
    return li;
}

void destroiLista ( Lista * li){
    if(li != NULL){
        free(li);
    }

}

int tamanhoLista ( Lista * li){
    if(li == NULL ){
    return -1;
    }
    return li -> tam;
}
int listaCheia ( Lista * li){
    if(li == NULL )
        return -1;
    return (li -> tam == MAX);
}

int listaVazia ( Lista * li){
    if(li == NULL ){
    return -1;
    }
    return (li -> tam == 0);
}
int insereFim ( Lista *li , int elem ){
    if(li == NULL )
        return 0;
    if (!listaCheia (li)){
        li -> dados [li ->tam] = elem;
        li ->tam++;
        printf ("Elemento inserido com sucesso!\n"); return 1;
        }else {
        printf ("Elemento nao inserido - Lista Cheia!\n"); return 0;
    }
}

int insereInicio ( Lista *li , int elem ){
    if(li == NULL )
        return 0;
    if (!listaCheia (li)){
        for(int i=li ->tam -1; i >=0; i--)
            li -> dados [i +1] = li -> dados [i];
        li -> dados [0] = elem;
        li ->tam ++;
        printf ("Elemento inserido com sucesso!\n"); return 1;
        } else {
        printf ("Elemento nao inserido - Lista Cheia!\n"); return 0;
        }
}

int removeFim ( Lista *li){
    if(li == NULL )
        return 0;
    if(! listaVazia (li)){
        li ->tam--;
        printf (" Elemento removido com sucesso !\n");
        return 1;
    }else {
        printf (" Nenhum elemento removido - Lista Vazia !\n");
        return 0;
    }
}

int removeInicio ( Lista *li){
    if(li == NULL ) 
        return 0;
    if (! listaVazia (li)){
        for(int i =0; i<li ->tam -1; i++)
            li -> dados [i] = li -> dados [i +1];
        li ->tam --;
        printf (" Elemento removido com sucesso!\n");
        return 1;
    } else {
        printf (" Nenhum elemento removido - Lista Vazia!\n");
        return 0;
    }
}

int imprimeLista ( Lista * li){
    if(li == NULL ) 
        return 0;
    if(listaVazia (li)){
        printf ("Lista vazia!\n"); return 0;
    }
    printf ("Elementos : ");
    for(int i = 0; i<li->tam; i ++) {
        printf ("%d ", li -> dados [i]) ;
    }
    printf ("\n");
    return 1;
}

int procura( Lista *li, int x){
    if (li == NULL) {
        return 0;
    }
    for(int i = 0; i< li->tam; i++){
        if(li -> dados[i] == x)
            return i;
    }
    return -1;
}

int insere_ordenada(Lista *li, int x) {
    if (li == NULL)
        return 0;

    if (listaCheia(li)){
        printf("Elemento não inserido - Lista Cheia!\n");
        return 0;  
    }

    int i;
    for (i = 0; i < li->tam && x > li->dados[i]; i++){
    }
    for (int j = li->tam; j > i; j--) {
        li->dados[j] = li->dados[j-1];
    }

    li->dados[i] = x;
    li->tam++;
    printf("Elemento inserido com sucesso!\n");
    return 1;
}

int remove_ocorrente( Lista *li, int x){
    if (li == NULL)
        return 0;

    for(int i = 0; i<li->tam; i++){
        if(x == li->dados[i]){
            for(int j = i; j<li->tam-1; j++){
                li->dados[j] = li->dados[j+1];
            }
            li->tam --;
            return 0;
        }
    }
}