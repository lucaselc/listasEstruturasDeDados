#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ContaBancaria
{
   int num_conta;
   double saldo;
   char titular[100];
}ContaBancaria;

void criarConta(ContaBancaria* c, int numero, char *titular){
    strcpy(c->titular, titular);
    c->saldo = 0;
    c->num_conta = numero;
}

void depositar(ContaBancaria* c, double valor){
    c->saldo += valor;
}

void sacar(ContaBancaria* c, double valor){
    if(c->saldo >= valor){
        c->saldo -= valor;
    }else{
        printf("Saldo insuficiente!\n");
    }
}

double consultarSaldo(ContaBancaria* c){
    return c->saldo;
}

void imprimirInfo(ContaBancaria* c){
    printf("Titular = %s - Número da Conta = %d - Saldo = R$%.2lf\n", c->titular , c->num_conta, c->saldo);
}