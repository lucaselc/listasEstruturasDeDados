#ifndef CUBO_H
#define CUBO_H

typedef struct Cubo{
    double lado;
}Cubo;

Cubo* criar();
void inicializar(Cubo* cubo, double lado);
double lado_cubo(Cubo* cubo);
double area_cubo(Cubo* cubo);
double volume_cubo(Cubo* cubo);

#endif