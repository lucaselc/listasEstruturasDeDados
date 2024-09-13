#ifndef conta_h
#define conta_h

typedef struct ContaBancaria
{
   int num_conta;
   double saldo;
   char titular[100];
}ContaBancaria;

void criarConta(ContaBancaria* c, int numero, char *titular);
void depositar(ContaBancaria* c, double valor);
void sacar(ContaBancaria* c, double valor);
double consultarSaldo(ContaBancaria* c);
void imprimirInfo(ContaBancaria* c);


#endif