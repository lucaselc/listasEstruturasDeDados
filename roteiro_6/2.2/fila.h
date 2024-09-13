#ifndef FILAPRIO_H
#define FILAPRIO_H

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct{

    int info, prio;

} NO;

NO* alocarNO(){
    NO* n = (NO*)malloc(sizeof(NO));

    if(n != NULL){
        n->info = 0;
        n->prio = 0;
    }
    return n;

}

void destroiNO(NO* n){
    if(n == NULL) return;
    free(n);
}

typedef struct{

    int qtd;
    NO dados[MAX];

} FilaP;

FilaP* criaFilaP(){

    FilaP* fp = (FilaP*)malloc(sizeof(FilaP));
    if(fp != NULL){
        fp->qtd = 0;
    }
    return fp;

}

void destroiFilaP(FilaP* fp){

    if(fp == NULL) return;
    free(fp);


}

int tamanhoFilaP(FilaP* fp){

    if(fp == NULL) return -1;
    return fp->qtd;

}

int estaVazia(FilaP* fp){
    if(fp == NULL) return -1;
    return (fp->qtd == 0);
}

int estaCheia(FilaP* fp){
    if(fp == NULL) return -1;
    return (fp->qtd == MAX);
}

void imprimeFilaP(FilaP* fp){

    if(fp == NULL){
        printf("Fila de Prioridade não encontrada.\n");
        return;
    }

    if(estaVazia(fp)){
        printf("Fila de Prioridade vazia.\n");
        return;
    }

    printf("Elementos:");
    for(int i = 0; i < fp->qtd; i++){
        printf(" [%d, %d]", fp->dados[i].info, fp->dados[i].prio);
    }
    printf("\n");

}

void trocarNO(NO* n, NO* m){

    NO* aux = alocarNO();
    if(aux == NULL) return;
    aux->info = n->info;
    aux->prio = n->prio;
    n->info = m->info;
    n->prio = m->prio;
    m->info = aux->info;
    m->prio = aux->prio;
    destroiNO(aux);

}

void ajustaHeapInsere(FilaP* fp, int filho){

    NO* aux = alocarNO();
    if(aux == NULL) return;
    int pai = (filho-1)/2;
    int prioPai = fp->dados[pai].prio;
    int prioFilho = fp->dados[filho].prio;
    while(filho > 0 && prioPai < prioFilho){
        trocarNO(&fp->dados[filho], &fp->dados[pai]);
        filho = pai;
        pai = (pai-1)/2;
        prioPai = fp->dados[pai].prio;
        prioFilho = fp->dados[filho].prio;
    }
    destroiNO(aux);
}

void inserePrioritario(FilaP* fp, int elem, int prio){

    if(fp == NULL) return;
    if(estaCheia(fp)) return;
    fp->dados[fp->qtd].info = elem;
    fp->dados[fp->qtd].prio = prio;
    ajustaHeapInsere(fp, fp->qtd);
    fp->qtd++;
}

void verInicio(FilaP* fp, int* info, int* prio){

    if(fp == NULL) return;
    if(estaVazia(fp)) return;

    *info = fp->dados[0].info;
    *prio = fp->dados[0].prio;


}

void ajustaHeapRemove(FilaP* fp, int pai){

    NO* aux = alocarNO();
    if(aux == NULL) return;

    int filho = (2*pai)+1;

    while(filho < fp->qtd){

        if(filho < fp->qtd-1){
            if(fp->dados[filho].prio < fp->dados[filho+1].prio){
                filho++;
            }
        }

        if(fp->dados[pai].prio > fp->dados[filho].prio){
            break;
        }

        trocarNO(&fp->dados[pai], &fp->dados[filho]);
        pai = filho;
        filho = (2*pai)+1;

    }
    destroiNO(aux);
}

void removeInicio(FilaP* fp){
    if(fp == NULL) return;
    if(estaVazia(fp)) return;

    fp->qtd--;
    fp->dados[0].info = fp->dados[fp->qtd].info;
    fp->dados[0].prio = fp->dados[fp->qtd].prio;
    ajustaHeapRemove(fp, 0);
}

#endif