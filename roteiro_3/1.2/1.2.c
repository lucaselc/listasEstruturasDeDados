#include <stdio.h>
#include <stdlib.h>
#include "cubo.h"
#include <math.h>

int main(){
    Cubo* cubo = (Cubo*)malloc(sizeof(Cubo));
    double lado;
    scanf("%lf", &lado);
    inicializar(cubo, lado);
    printf("Tamanho de cada lado do cubo: %2.lf\n", lado_cubo(cubo));
    printf("Área do cubo: %2.lf\n", area_cubo(cubo));
    printf("Volume do cubo: %2.lf\n", volume_cubo(cubo));

    return 0;
}
