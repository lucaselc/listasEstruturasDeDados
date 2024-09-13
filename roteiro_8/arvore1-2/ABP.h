#ifndef ABP_H
#define ABP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NO{
    int matricula;
    char nome[200];
    double nota;
    struct NO* esq;
    struct NO* dir;
}NO;

typedef struct NO* ABP;

NO* alocarNO(){
    return (NO*) malloc (sizeof(NO));
}

void liberarNO(NO* q){
    free(q);
}

ABP* criaABP(){
    ABP* raiz = (ABP*) malloc (sizeof(ABP));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void destroiRec(NO* no){
    if(no == NULL) return;
    destroiRec(no->esq);
    destroiRec(no->dir);
    liberarNO(no);
    no = NULL;
}

void destroiABP(ABP* raiz){
    if(raiz != NULL){
        destroiRec(*raiz);
        free(raiz);
    }
}

int estaVazia(ABP* raiz){
    if(raiz == NULL) return 0;
    return (*raiz == NULL);
}


int insereRec(NO** raiz, int matricula, char* nome, double nota){
    if(*raiz == NULL){
        NO* novo = alocarNO();
        if(novo == NULL) return 0;
        novo->matricula = matricula;
        strcpy(novo->nome, nome);
        novo->nota = nota;
        novo->esq = NULL; novo->dir = NULL;
        *raiz = novo;
    }else{
        if((*raiz)->matricula == matricula){
            printf("Matricula Existente!\n"); 
            return 0;
        }
        if(matricula < (*raiz)->matricula)
            return insereRec(&(*raiz)->esq, matricula, nome, nota);
        else if(matricula > (*raiz)->matricula)
            return insereRec(&(*raiz)->dir, matricula, nome, nota);
    }
    return 1;
}

int inserematricula(ABP* raiz, int matricula, char* nome, double nota){
    if(raiz == NULL) return 0;
    return insereRec(raiz, matricula, nome, nota);
}

int pesquisaRec(NO** raiz, int matricula, char* nome){
    if(*raiz == NULL) return 0;
    if((*raiz)->matricula == matricula && !strcmp((*raiz)->nome, nome)) return 1;
    if(matricula < (*raiz)->matricula)
        return pesquisaRec(&(*raiz)->esq, matricula, nome);
    else 
        return pesquisaRec(&(*raiz)->dir, matricula, nome);
}

int pesquisa(ABP* raiz, int matricula, char* nome){
    if(raiz == NULL) return 0;
    if(estaVazia(raiz)) return 0;
    return pesquisaRec(raiz, matricula, nome);
}

int removeRec(NO** raiz, int matricula, char* nome){
    if(*raiz == NULL) return 0;
    if((*raiz)->matricula == matricula && !strcmp((*raiz)->nome, nome)){
        NO* aux;
        if((*raiz)->esq == NULL && (*raiz)->dir == NULL){
            //Caso 1 - NO sem filhos
            printf("Caso 1: Liberando %s..\n", (*raiz)->nome);
            liberarNO(*raiz);
            *raiz = NULL;
        }else if((*raiz)->esq == NULL){
            //Caso 2.1 - Possui apenas uma subarvore direita
            printf("Caso 2.1: Liberando %s..\n", (*raiz)->nome);
            aux = *raiz;
            *raiz = (*raiz)->dir;
            liberarNO(aux);
        }else if((*raiz)->dir == NULL){
            //Caso 2.2 - Possui apenas uma subarvore esquerda
            printf("Caso 2.2: Liberando %s..\n", (*raiz)->nome);
            aux = *raiz;
            *raiz = (*raiz)->esq;
            liberarNO(aux);
        }else{
            //Caso 3 - Possui as duas subarvores (esq e dir)
            //Duas estrategias:
            //3.1 - Substituir pelo NO com o MAIOR valor da subarvore esquerda
            //3.2 - Substituir pelo NO com o MENOR valor da subarvore direita
            printf("Caso 3: Liberando %s..\n", (*raiz)->nome);
            //Estrategia 3.1:
            NO* Filho = (*raiz)->esq;
            while(Filho->dir != NULL)//Localiza o MAIOR valor da subarvore esquerda
                Filho = Filho->dir;
            (*raiz)->matricula = Filho->matricula;
            Filho->matricula = matricula;
            return removeRec(&(*raiz)->esq, matricula, nome);
        }
        return 1;
    }else if(matricula < (*raiz)->matricula)
        return removeRec(&(*raiz)->esq, matricula, nome);
    else 
        return removeRec(&(*raiz)->dir, matricula, nome);
}

int removematricula(ABP* raiz, int matricula, char* nome){
    if(pesquisa(raiz, matricula, nome) == 0){
        printf("Matricula inexistente!\n");
        return 0;
    }
    return removeRec(raiz, matricula, nome);
}

void em_ordem(NO* raiz, int nivel){
    if(raiz != NULL){
        em_ordem(raiz->esq, nivel+1);
        printf("[%s, %d, %.2lf, %d] \n", raiz->nome, raiz->matricula, raiz->nota, nivel);
        em_ordem(raiz->dir, nivel+1);
    }
}

void imprime(ABP* raiz){
    if(raiz == NULL) return;
    if(estaVazia(raiz)){
        printf("Arvore Vazia!\n");
        return;
    }
    em_ordem(*raiz, 0);
    printf("\n");
}

int achaMaior(NO* raiz, int maiorNota, int matricula){
    if(raiz == NULL) return matricula;
    if(raiz->nota > maiorNota){
        maiorNota = raiz->nota;
        matricula = raiz->matricula;
    }
    matricula = achaMaior(raiz->esq, maiorNota, matricula);
    matricula = achaMaior(raiz->dir, maiorNota, matricula);
    return matricula;
}

void imprimeMaior(NO* raiz, int matricula){
    if(raiz == NULL) return;
    if(raiz->matricula == matricula){
        printf("[%s, %d, %.2lf] \n", raiz->nome, raiz->matricula, raiz->nota);
    }
    if(matricula < raiz->matricula)
        return imprimeMaior(raiz->esq, matricula);
    else 
        return imprimeMaior(raiz->dir, matricula);
}

int achaMenor(NO* raiz, int menorNota, int matricula){
    if(raiz == NULL) return matricula;
    if(raiz->nota < menorNota){
        menorNota = raiz->nota;
        matricula = raiz->matricula;
    }
    matricula = achaMenor(raiz->esq, menorNota, matricula);
    matricula = achaMenor(raiz->dir, menorNota, matricula);
    return matricula;
}

void imprimeMenor(NO* raiz, int matricula){
    if(raiz == NULL) return;
    if(raiz->matricula == matricula){
        printf("[%s, %d, %.2lf] \n", raiz->nome, raiz->matricula, raiz->nota);
    }
    if(matricula < raiz->matricula)
        return imprimeMenor(raiz->esq, matricula);
    else 
        return imprimeMenor(raiz->dir, matricula);
}

#endif