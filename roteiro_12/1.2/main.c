#include "busca.h"


int main(){

    //Atribuicoes iniciais
    srand(time(NULL));
    comp = 0;
    clock_t t;

    /*
    //Template de Calculo do Tempo de Execucao
    t = clock();
    //Chamada do Algoritmo aqui...
    t = clock() - t;
    printf ("It took me %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
    */

    int *v;
    int n, x;
    printf("Digite o tamanho do vetor:\n");
    scanf("%d", &n);
    v = (int*) malloc (n*sizeof(int));

    
    preencheAleatorio(v, n, 1, n);
    //imprimeVetor(v, n);
    QuickSort(v, 0, n-1);
    
    printf("Digite um elemento para busca:\n");
    scanf("%d", &x);

    int ind;

    t = clock();
    ind = buscaSequencial(v, n, x);
    t = clock() - t;
    printf("-----Informacoes Busca Sequencial:\n");
    printf("Tempo Execucao:  %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", comp);

    //imprimeVetor(v, n);

    if(ind != -1)
        printf("O elemento %d foi encontrado na pos %d.\n", x, ind);
    else
        printf("O elemento %d NAO foi encontrado!\n", x);
    

    
    //imprimeVetor(v, n);

    comp = 0;
    t = clock();
    ind = rec_buscaBinaria(v, 0, n-1, x);
    t = clock() - t;
    printf("-----Informacoes Busca Binaria Recursiva:\n");
    printf("Tempo Execucao:  %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", comp);

    if(ind != -1)
        printf("O elemento %d foi encontrado na pos %d.\n", x, ind);
    else
        printf("O elemento %d NAO foi encontrado!\n", x);
    

    comp = 0;
    t = clock();
    ind = it_buscaBinaria(v, 0, n-1, x);
    t = clock() - t;
    printf("-----Informacoes Busca Binaria Iterativa:\n");
    printf("Tempo Execucao:  %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", comp);

    if(ind != -1)
        printf("O elemento %d foi encontrado na pos %d.\n", x, ind);
    else
        printf("O elemento %d NAO foi encontrado!\n", x);
    

    free(v);
    return 0;
}