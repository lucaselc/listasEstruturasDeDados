#ifndef BUSCA_H
#define BUSCA_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 200

typedef struct{

    char nome[MAX];
    int matricula;
    double nota1, nota2, nota3;

} Aluno;

//Medidas de Complexidade
int comp; //Num. de comparacoes

int* copiaVetor(int* v, int n){
    int i;
    int *v2;
    v2 = (int*) malloc (n*sizeof(int));
    for(i=0; i<n; i++) v2[i] = v[i];
    return v2;
}

Aluno* copiaVetor_aluno(Aluno* v, int n){
    int i;
    Aluno *v2;
    v2 = (Aluno*) malloc (n*sizeof(Aluno));
    for(i=0; i<n; i++) v2[i] = v[i];
    return v2;
}

void imprimeVetor(int* v, int n){
    int i, prim = 1;
    printf("[");
    for(i=0; i<n; i++)
        if(prim){ printf("%d", v[i]); prim = 0; }
        else printf(", %d", v[i]);
    printf("]\n");
}

void preencheAleatorio(int* v, int n, int ini, int fim){
    int i;
    for(i=0; i<n; i++)
        v[i] = ini + rand() % (fim-ini + 1); 
}

void troca_nome(Aluno* a, Aluno *b){
	Aluno aux = *a;
	*a = *b;
	*b = aux;
} 

int buscaSequencial_nome(Aluno *v, int n, char *elem){
    int i;
    for(i=0; i<n; i++){
        comp++;
        if(strcmp(v[i].nome, elem) == 0) 
            return i; //Elemento encontrado
    }
    return -1; //Elemento nao encontrado
}

int particao_nome(Aluno *v, int ini, int fim){
    int i = ini, j = fim;
    Aluno pivo = v[(ini+fim)/2];
    while (1) {
        while(strcmp(v[i].nome, pivo.nome) < 0){ i++; } //procura algum >= pivo do lado esquerdo
        while(strcmp(v[j].nome, pivo.nome) > 0){ j--; } //procura algum <= pivo do lado direito
        
        if(i<j){
            troca_nome(&v[i], &v[j]); //troca os elementos encontrados
            i++;
            j--;
        }else
            return j; //retorna o local onde foi feita a particao
    }    
}

void QuickSort_nome(Aluno *v, int ini, int fim){
    if(ini < fim ){
        int q = particao_nome(v, ini, fim);
        QuickSort_nome(v, ini, q);
        QuickSort_nome(v, q+1, fim);
    }
}

int rec_buscaBinaria_nome(Aluno *v, int ini, int fim, char *elem){
    if(ini > fim) return -1;
    int meio = (ini + fim)/2;
    comp++;
    if(strcmp(v[meio].nome, elem) == 0) 
        return meio;
    else 
        if(strcmp(v[meio].nome, elem) > 0)
            return rec_buscaBinaria_nome(v, ini, meio-1, elem);
        else
            return rec_buscaBinaria_nome(v, meio+1, fim, elem);
}

int it_buscaBinaria_nome(Aluno *v, int ini, int fim, char *elem){
    int meio;
    while(ini <= fim){
        meio = (ini + fim)/2;
        comp++;
        if(strcmp(v[meio].nome, elem) == 0) return meio;
        else
            if(strcmp(v[meio].nome, elem) > 0)
                fim = meio-1;
            else
                ini = meio+1;
    }
    return -1;
}

void troca_matricula(Aluno* a, Aluno *b){
	Aluno aux = *a;
	*a = *b;
	*b = aux;
} 

int buscaSequencial_matricula(Aluno *v, int n, int elem){
    int i;
    for(i=0; i<n; i++){
        comp++;
        if(v[i].matricula == elem) 
            return i; //Elemento encontrado
    }
    return -1; //Elemento encontrado
}

int particao_matricula(Aluno *v, int ini, int fim){
    int i = ini, j = fim;
    Aluno pivo = v[(ini+fim)/2];
    while (1) {
        while(v[i].matricula < pivo.matricula){ i++; } //procura algum >= pivo do lado esquerdo
        while(v[j].matricula > pivo.matricula){ j--; } //procura algum <= pivo do lado direito
        
        if(i<j){
            troca_matricula(&v[i], &v[j]); //troca os elementos encontrados
            i++;
            j--;
        }else
            return j; //retorna o local onde foi feita a particao
    }    
}

void QuickSort_matricula(Aluno *v, int ini, int fim){
    if(ini < fim ){
        int q = particao_matricula(v, ini, fim);
        QuickSort_matricula(v, ini, q);
        QuickSort_matricula(v, q+1, fim);
    }
}

int rec_buscaBinaria_matricula(Aluno *v, int ini, int fim, int elem){
    if(ini > fim) return -1;
    int meio = (ini + fim)/2;
    comp++;
    if(v[meio].matricula == elem) 
        return meio;
    else 
        if(elem < v[meio].matricula)
            return rec_buscaBinaria_matricula(v, ini, meio-1, elem);
        else
            return rec_buscaBinaria_matricula(v, meio+1, fim, elem);
}

int it_buscaBinaria_matricula(Aluno *v, int ini, int fim, int elem){
    int meio;
    while(ini <= fim){
        meio = (ini + fim)/2;
        comp++;
        if(elem == v[meio].matricula) return meio;
        else
            if(elem < v[meio].matricula)
                fim = meio-1;
            else
                ini = meio+1;
    }
    return -1;
}

// void troca(int* a, int *b){
// 	int aux = *a;
// 	*a = *b;
// 	*b = aux;
// } 

// int buscaSequencial(int *v, int n, int elem){
//     int i;
//     for(i=0; i<n; i++){
//         comp++;
//         if(v[i] == elem) 
//             return i; //Elemento encontrado
//     }
//     return -1; //Elemento encontrado
// }

// int particao(int *v, int ini, int fim){
//     int i = ini, j = fim;
//     int pivo = v[(ini+fim)/2];
//     while (1) {
//         while(v[i] < pivo){ i++; } //procura algum >= pivo do lado esquerdo
//         while(v[j] > pivo){ j--; } //procura algum <= pivo do lado direito
        
//         if(i<j){
//             troca(&v[i], &v[j]); //troca os elementos encontrados
//             i++;
//             j--;
//         }else
//             return j; //retorna o local onde foi feita a particao
//     }    
// }

// void QuickSort(int *v, int ini, int fim){
//     if(ini < fim ){
//         int q = particao(v, ini, fim);
//         QuickSort(v, ini, q);
//         QuickSort(v, q+1, fim);
//     }
// }

// int rec_buscaBinaria(int *v, int ini, int fim, int elem){
//     if(ini > fim) return -1;
//     int meio = (ini + fim)/2;
//     comp++;
//     if(v[meio] == elem) 
//         return meio;
//     else 
//         if(elem < v[meio])
//             return rec_buscaBinaria(v, ini, meio-1, elem);
//         else
//             return rec_buscaBinaria(v, meio+1, fim, elem);
// }

// int it_buscaBinaria(int *v, int ini, int fim, int elem){
//     int meio;
//     while(ini <= fim){
//         meio = (ini + fim)/2;
//         comp++;
//         if(elem == v[meio]) return meio;
//         else
//             if(elem < v[meio])
//                 fim = meio-1;
//             else
//                 ini = meio+1;
//     }
//     return -1;
// }

#endif