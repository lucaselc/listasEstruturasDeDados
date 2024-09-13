#include "cubo.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void inicializar(Cubo* cubo, double lado){
    cubo->lado = lado;
}

double lado_cubo(Cubo* cubo){
    return cubo->lado;
}

double area_cubo(Cubo* cubo){
    return 6.0*cubo->lado*cubo->lado;
}

double volume_cubo(Cubo* cubo){
    return cubo->lado*cubo->lado*cubo->lado;
}