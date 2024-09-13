#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conta.c"

int main(){
   ContaBancaria *c = (ContaBancaria*)malloc(sizeof(ContaBancaria));
   int numero;
   double saque, deposito;
   char titular[100];

   scanf("%s", &titular);
   scanf("%d", &numero);
   criarConta(c, numero, titular);
   scanf("%lf", &deposito);
   depositar(c, deposito);
   scanf("%lf", &saque);
   sacar(c, saque);
   printf("Seu saldo é: R$%.2lf\n", consultarSaldo(c));
   imprimirInfo(c);
   free(c);
   return 0;
}