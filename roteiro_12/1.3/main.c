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

    Aluno *v;
    int n, matricula;
    char nome[MAX];
    char buffer[MAX];
    printf("Digite o tamanho do vetor:\n");
    scanf("%d", &n);
    v = (Aluno*) malloc (n*sizeof(Aluno));

    for(int i = 0; i < n; i++){
        printf("Digite a matricula do Aluno:\n");
        scanf("%d", &v[i].matricula);
        printf("Digite o nome do Aluno:\n");
        fgets(buffer, sizeof(buffer), stdin);
        scanf("%200[^\n]", v[i].nome);
        v[i].nota1 = 10;
        v[i].nota2 = 10;
        v[i].nota3 = 10;
    }
    //preencheAleatorio(v, n, 1, n);
    //imprimeVetor(v, n);

    //por nome
    QuickSort_nome(v, 0, n-1);
    
    printf("Digite um nome para busca:\n");
    fgets(buffer, sizeof(buffer), stdin);
    scanf("%200[^\n]", nome);

    int ind;

    t = clock();
    ind = buscaSequencial_nome(v, n, nome);
    t = clock() - t;
    printf("-----Informacoes Busca Sequencial:\n");
    printf("Tempo Execucao:  %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", comp);

    //imprimeVetor(v, n);

    if(ind != -1)
        printf("O elemento %s foi encontrado na pos %d.\n", nome, ind);
    else
        printf("O elemento %s NAO foi encontrado!\n", nome);
    

    
    //imprimeVetor(v, n);

    comp = 0;
    t = clock();
    ind = rec_buscaBinaria_nome(v, 0, n-1, nome);
    t = clock() - t;
    printf("-----Informacoes Busca Binaria Recursiva:\n");
    printf("Tempo Execucao:  %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", comp);

    if(ind != -1)
        printf("O elemento %s foi encontrado na pos %d.\n", nome, ind);
    else
        printf("O elemento %s NAO foi encontrado!\n", nome);
    

    comp = 0;
    t = clock();
    ind = it_buscaBinaria_nome(v, 0, n-1, nome);
    t = clock() - t;
    printf("-----Informacoes Busca Binaria Iterativa:\n");
    printf("Tempo Execucao:  %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", comp);

    if(ind != -1)
        printf("O elemento %s foi encontrado na pos %d.\n", nome, ind);
    else
        printf("O elemento %s NAO foi encontrado!\n", nome);
    
    //por matricula
    QuickSort_matricula(v, 0, n-1);
    
    printf("Digite uma matricula para busca:\n");
    scanf("%d", &matricula);
    

    t = clock();
    ind = buscaSequencial_matricula(v, n, matricula);
    t = clock() - t;
    printf("-----Informacoes Busca Sequencial:\n");
    printf("Tempo Execucao:  %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", comp);

    //imprimeVetor(v, n);

    if(ind != -1)
        printf("O elemento %d foi encontrado na pos %d.\n", matricula, ind);
    else
        printf("O elemento %d NAO foi encontrado!\n", matricula);
    

    
    //imprimeVetor(v, n);

    comp = 0;
    t = clock();
    ind = rec_buscaBinaria_matricula(v, 0, n-1, matricula);
    t = clock() - t;
    printf("-----Informacoes Busca Binaria Recursiva:\n");
    printf("Tempo Execucao:  %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", comp);

    if(ind != -1)
        printf("O elemento %d foi encontrado na pos %d.\n", matricula, ind);
    else
        printf("O elemento %d NAO foi encontrado!\n", matricula);
    

    comp = 0;
    t = clock();
    ind = it_buscaBinaria_matricula(v, 0, n-1, matricula);
    t = clock() - t;
    printf("-----Informacoes Busca Binaria Iterativa:\n");
    printf("Tempo Execucao:  %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", comp);

    if(ind != -1)
        printf("O elemento %d foi encontrado na pos %d.\n", matricula, ind);
    else
        printf("O elemento %d NAO foi encontrado!\n", matricula);

    free(v);
    return 0;
}