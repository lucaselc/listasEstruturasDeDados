#ifndef AVL_H
#define AVL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAIOR(a, b) ((a > b) ? (a) : (b))

typedef struct NO{
    int fb, alt;
    struct NO* esq;
    struct NO* dir;
    char nome[90];
    double salario;
    int contratacao;
}NO;

typedef struct NO* AVL;

NO* alocarNO(){
    return (NO*) malloc (sizeof(NO));
}

void liberarNO(NO* q){
    free(q);
}

AVL* criaAVL(){
    AVL* raiz = (AVL*) malloc (sizeof(AVL));
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

int destroiAVL(AVL* raiz){
    if(raiz != NULL){
        destroiRec(*raiz);
        free(raiz);
        return 1;
    }
}

int estaVazia(AVL* raiz){
    if(raiz == NULL) return 0;
    return (*raiz == NULL);
}

//Calcula FB
int altura(NO* raiz){
    if(raiz == NULL) return 0;
    if(raiz->alt > 0)
        return raiz->alt;
    else{ 
        //printf("Calculando altura do (%d)..\n", raiz->info);
        return MAIOR(altura(raiz->esq), altura(raiz->dir)) + 1;
    }
}

int FB(NO* raiz){
    if(raiz == NULL) return 0;
    printf("Calculando FB de (%s)..\n", raiz->nome);
    return altura(raiz->esq) - altura(raiz->dir);
}

//Funcoes de Rotacao Simples
void avl_RotDir(NO** raiz){
   printf("Rotacao Simples a DIREITA!\n");
   NO *aux;
   aux = (*raiz)->esq;
   (*raiz)->esq = aux->dir;
   aux->dir = *raiz;
   
   //Acertando alturas e FB
   //dos NOs afetados
    (*raiz)->alt = aux->alt = -1;
    aux->alt = altura(aux); 
    (*raiz)->alt = altura(*raiz); 
    aux->fb = FB(aux); 
    (*raiz)->fb = FB(*raiz);

   *raiz = aux;
}

void avl_RotEsq(NO** raiz){
   printf("Rotacao Simples a ESQUERDA!\n");
   NO *aux;
   aux = (*raiz)->dir;
   (*raiz)->dir = aux->esq;
   aux->esq = *raiz;
   
   //Acertando alturas e Fatores de Balanceamento dos NOs afetados
    (*raiz)->alt = aux->alt = -1;
    aux->alt = altura(aux); 
    (*raiz)->alt = altura(*raiz); 
    aux->fb = FB(aux); 
    (*raiz)->fb = FB(*raiz);
   
   *raiz = aux;
}


//Funcoes de Rotacao Dupla
void avl_RotEsqDir(NO** raiz){
    printf("Rotacao Dupla ESQUERDA-DIREITA!\n");
    NO *fe; //filho esquerdo
    NO *ffd; //filho filho direito
    
    fe = (*raiz)->esq;
    ffd = fe->dir;
    
    fe->dir = ffd->esq;
    ffd->esq = fe;
    
    (*raiz)->esq = ffd->dir;
    ffd->dir = *raiz;

    //Acertando alturas e Fatores de Balanceamento dos NOs afetados
    (*raiz)->alt = fe->alt = ffd->alt = -1;
    fe->alt = altura(fe); 
    ffd->alt = altura(ffd);
    (*raiz)->alt = altura(*raiz); 
    fe->fb = FB(fe); 
    ffd->fb = FB(ffd);
    (*raiz)->fb = FB(*raiz);

    *raiz = ffd;
}


void avl_RotDirEsq(NO** raiz){
    printf("Rotacao Dupla DIREITA-ESQUERDA!\n");
    NO* fd; //filho direito
    NO* ffe; //filho filho esquerdo

    fd = (*raiz)->dir;
    ffe = fd->esq;
    
    fd->esq = ffe->dir;
    ffe->dir = fd;
    
    (*raiz)->dir = ffe->esq;
    ffe->esq = *raiz;

    //Acertando alturas e Fatores de Balanceamento dos NOs afetados
    (*raiz)->alt = fd->alt = ffe->alt = -1;
    fd->alt = altura(fd); 
    ffe->alt = altura(ffe);
    (*raiz)->alt = altura(*raiz); 
    fd->fb = FB(fd);
    ffe->fb = FB(ffe);
    (*raiz)->fb = FB(*raiz);

    *raiz = ffe;
}

void avl_RotEsqDir2(NO** raiz){
    printf("Rotacao Dupla 2 ESQUERDA-DIREITA!\n");
    avl_RotEsq(&(*raiz)->esq);
    avl_RotDir(raiz);
}

void avl_RotDirEsq2(NO** raiz){
    printf("Rotacao Dupla 2 DIREITA-ESQUERDA!\n");
    avl_RotDir(&(*raiz)->dir);
    avl_RotEsq(raiz);
}


//Funcoes Auxiliares referentes a cada filho
void avl_AuxFE(NO **raiz){
   NO* fe;
   fe = (*raiz)->esq;
   if(fe->fb == +1) /* Sinais iguais e positivo*/
     avl_RotDir(raiz);
   else /* Sinais diferentes*/
     avl_RotEsqDir(raiz);
}

void avl_AuxFD(NO **raiz){
   NO* fd;
   fd = (*raiz)->dir;
   if(fd->fb == -1) /* Sinais iguais e negativos*/
     avl_RotEsq(raiz);
   else /* Sinais diferentes*/
     avl_RotDirEsq(raiz);
}

int insereRec(NO** raiz, char nome[], double salario, int contratacao){
    int ok; //Controle para as chamadas recursivas
    if(*raiz == NULL){
        NO* novo = alocarNO();
        if(novo == NULL) return 0;
        strcpy(novo->nome, nome);
        novo->salario = salario;
        novo->contratacao = contratacao;
        novo->fb = 0, novo->alt = 1;
        novo->esq = NULL; novo->dir = NULL;
        *raiz = novo; return 1;
    }else{
        if(!strcmp((*raiz)->nome, nome)){
            printf("Elemento Existente!\n"); ok = 0;
        }
        if(salario < (*raiz)->salario){
            ok = insereRec(&(*raiz)->esq, nome, salario, contratacao);
            if(ok){
                switch((*raiz)->fb){
                    case -1:
                        (*raiz)->fb = 0; ok = 0; break;
                    case 0:
                        (*raiz)->fb = +1; 
                        (*raiz)->alt++; 
                        break;
                    case +1:
                        avl_AuxFE(raiz); ok = 0; break;
                }
            }
        }
        else if(salario > (*raiz)->salario){
            ok = insereRec(&(*raiz)->dir, nome, salario, contratacao);
            if(ok){
                switch((*raiz)->fb){
                    case +1:
                        (*raiz)->fb = 0; ok = 0; break;
                    case 0:
                        (*raiz)->fb = -1; (*raiz)->alt++; break;
                    case -1:
                        avl_AuxFD(raiz); ok = 0; break;
                }
            }
        }
    }
    return ok;
}

int insereElem(AVL* raiz, char nome[], double salario, int contratacao){
    if(raiz == NULL) return 0;
    return insereRec(raiz, nome, salario, contratacao);
}

int pesquisaRec(NO** raiz, double salario){
    if(*raiz == NULL) return 0;
    if((*raiz)->salario == salario) return 1;
    if(salario < (*raiz)->salario)
        return pesquisaRec(&(*raiz)->esq, salario);
    else 
        return pesquisaRec(&(*raiz)->dir, salario);
}

int pesquisa(AVL* raiz, double salario){
    if(raiz == NULL) return 0;
    if(estaVazia(raiz)) return 0;
    return pesquisaRec(raiz, salario);
}

int pesquisaRecN(NO** raiz, char nome[]){
    int i = 0;
    if(*raiz == NULL) return 0;
    if(!strcmp((*raiz)->nome, nome)) return 1;
    i = pesquisaRecN(&(*raiz)->esq, nome);
    i = pesquisaRecN(&(*raiz)->dir, nome);
    return i;
}

int pesquisaN(AVL* raiz, char nome[]){
    if(raiz == NULL) return 0;
    if(estaVazia(raiz)) return 0;
    return pesquisaRecN(raiz, nome);
}

double encontraSalario(AVL* raiz, char nome[]){
    double salario = 0;
    if((*raiz) == NULL) return salario;
    if(!strcmp((*raiz)->nome, nome)){
        salario = (*raiz)->salario;
    }
    salario = encontraSalario(&(*raiz)->esq, nome);
    salario = encontraSalario(&(*raiz)->dir, nome);
    return salario;
}

int removeRec(NO** raiz, char nome[]){
    if(*raiz == NULL) return 0;
    int ok;
    double salario = encontraSalario(raiz, nome);
    if(!strcmp((*raiz)->nome, nome)){
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
            NO* aux = (*raiz);
            while(Filho->dir != NULL)//Localiza o MAIOR valor da subarvore esquerda
                Filho = Filho->dir;
            strcpy((*raiz)->nome, Filho->nome);
            (*raiz)->salario = Filho->salario;
            (*raiz)->contratacao = Filho->contratacao;
            strcpy(Filho->nome, aux->nome);
            Filho->salario = aux->salario;
            Filho->contratacao = aux->contratacao;
            return removeRec(&(*raiz)->esq, nome);
        }
        return 1;
    }else if(salario < (*raiz)->salario){
        ok = removeRec(&(*raiz)->esq, nome); 
        if(ok){
            switch((*raiz)->fb){
                case +1:
                case 0:
                    //Acertando alturas e Fatores de Balanceamento dos NOs afetados
                    (*raiz)->alt = -1;
                    (*raiz)->alt = altura(*raiz); 
                    (*raiz)->fb = FB(*raiz);
                    break;
                case -1:
                    avl_AuxFD(raiz); break;
            }
        }
    }
    else{ 
        ok = removeRec(&(*raiz)->dir, nome);
        if(ok){
            switch((*raiz)->fb){
                case -1:
                case 0:
                    //Acertando alturas e Fatores de Balanceamento dos NOs afetados
                    (*raiz)->alt = -1;
                    (*raiz)->alt = altura(*raiz); 
                    (*raiz)->fb = FB(*raiz);
                    break;
                case +1:
                    avl_AuxFE(raiz); break;
            }
        }
    }
    return ok;
}

int removeElem(AVL* raiz, char nome[]){
    if(!pesquisaN(raiz, nome)){
        printf("Funcionário inexistente!\n");
        return 0;
    }
    return removeRec(raiz, nome);
}

void em_ordem(NO* raiz, int nivel){
    if(raiz != NULL){
        em_ordem(raiz->esq, nivel+1);
        //printf("[%d, %d, %d] ", raiz->info, raiz->fb, nivel);
        printf("[%s, R$%.2lf, %d, %d, %d, %d] ", raiz->nome, raiz->salario, raiz->contratacao, raiz->fb, nivel, raiz->alt);
        em_ordem(raiz->dir, nivel+1);
    }
}

/*
void pre_ordem(NO* raiz, int nivel){
    if(raiz != NULL){
        printf("[%d, %d, %d] ", raiz->info, raiz->fb, nivel);
        pre_ordem(raiz->esq, nivel+1);
        pre_ordem(raiz->dir, nivel+1);
    }
}
*/

/*
void pos_ordem(NO* raiz, int nivel){
    if(raiz != NULL){
        pos_ordem(raiz->esq, nivel+1);
        pos_ordem(raiz->dir, nivel+1);
        printf("[%d, %d, %d] ", raiz->info, raiz->fb, nivel);
    }
}
*/

void imprime(AVL* raiz){
    if(raiz == NULL) return;
    if(estaVazia(raiz)){
        printf("Arvore Vazia!\n");
        return;
    }
    //printf("\nEm Ordem: [INFO, FB, NIVEL]\n"); 
    printf("Em Ordem: [NOME, SALÁRIO, ANO DE CONTRATAÇÃO, FB, NIVEL, ALTURA]\n"); 
    em_ordem(*raiz, 0);
    //printf("\nPre Ordem: "); pre_ordem(*raiz, 0);
    //printf("\nPos Ordem: "); pos_ordem(*raiz, 0);
    printf("\n");
}

void numero_de_nos(NO** raiz, int* contador){
	if(*raiz == NULL){
        return;	
    }
    numero_de_nos(&(*raiz)->esq, contador);
    numero_de_nos(&(*raiz)->dir, contador);
    (*contador)++;
}

void imprimeMaiorSalario(AVL* raiz){
    if((*raiz)->dir == NULL){
        printf("FUNCIONÀRIO COM MAIOR SALÁRIO:\n");
        printf("NOME: %s\n", (*raiz)->nome);
        printf("SALÁRIO: $%.2lf\n", (*raiz)->salario);
        printf("ANO DE CONTRATAÇÃO: %d\n", (*raiz)->contratacao);
        return;
    }
    imprimeMaiorSalario(&(*raiz)->dir);
}

void imprimeMenorSalario(AVL* raiz){
    if((*raiz)->esq == NULL){
        printf("FUNCIONÀRIO COM MENOR SALÁRIO:\n");
        printf("NOME: %s\n", (*raiz)->nome);
        printf("SALÁRIO: $%.2lf\n", (*raiz)->salario);
        printf("ANO DE CONTRATAÇÃO: %d\n", (*raiz)->contratacao);
        return;
    }
    imprimeMenorSalario(&(*raiz)->esq);
}

NO* pesquisaFuncionarioRec(AVL *raiz, double salario) {
    if (*raiz == NULL) return NULL;
    if ((*raiz)->salario == salario) return *raiz;
    if (salario < (*raiz)->salario)
        return pesquisaFuncionarioRec(&(*raiz)->esq, salario);
    else
        return pesquisaFuncionarioRec(&(*raiz)->dir, salario);
}

NO* pesquisaFuncionario(AVL *raiz, double salario) {
    if (raiz == NULL) return NULL;
    if (estaVazia(raiz)) return NULL;
    return pesquisaFuncionarioRec(raiz, salario);
}



void imprimeFuncionario(NO* no) {
    printf("Nome: %s, Salario: %.2lf, Ano de Contratacao: %d\n",
           no->nome, no->salario, no->contratacao);
}


#endif