#include <stdio.h>
#include <stdlib.h>

void torre_hanoi(int discos, char origem, char destino , char trabalho){
    if(discos>0){
        torre_hanoi(discos-1, origem, trabalho, destino);
        printf("Disco %d movido do pino %c para o pino %c\n",discos,origem, destino);
        torre_hanoi(discos-1, trabalho, destino, origem);
    }
}






int main(){
    int discos;
    scanf("%d", &discos);
    torre_hanoi(discos,'A', 'C', 'B');
    return 0;
}