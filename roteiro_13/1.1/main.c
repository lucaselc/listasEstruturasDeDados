#include "MSE.h"

int main(){
    criaArquivoTeste("dados.txt", 1, 1000);
    system("cp dados.txt dados2.txt");
    MergeSortExterno("dados.txt");
    return 0;
}