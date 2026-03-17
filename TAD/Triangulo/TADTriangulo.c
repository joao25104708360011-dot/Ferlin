#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "TADTriangulo.h"

struct triangulo {
    Ponto *v1;
    Ponto *v2;
    Ponto *v3;
};

tTriangulo* tri_cria(float x1, float y1, float x2, float y2, float x3, float y3) {
    tTriangulo* t = (tTriangulo*)malloc(sizeof(tTriangulo));
    if (t == NULL) {
        printf("Memória insuficiente para triângulo!\n");
        exit(1);
    }
    t->v1 = pto_cria(x1, y1);
    t->v2 = pto_cria(x2, y2);
    t->v3 = pto_cria(x3, y3);
    return t;
}

void tri_libera(tTriangulo* t) {
    if (t != NULL) {
        pto_libera(t->v1);
        pto_libera(t->v2);
        pto_libera(t->v3);
        free(t);
    }
}

float tri_perimetro(tTriangulo* t) {
    float a = pto_distancia(t->v1, t->v2);
    float b = pto_distancia(t->v2, t->v3);
    float c = pto_distancia(t->v3, t->v1);
    return a + b + c;
}

float tri_area(tTriangulo* t) {
    float a = pto_distancia(t->v1, t->v2);
    float b = pto_distancia(t->v2, t->v3);
    float c = pto_distancia(t->v3, t->v1);
    
    // Semiperímetro para a Fórmula de Heron
    float s = (a + b + c) / 2.0;
    
    // Área = sqrt(s * (s-a) * (s-b) * (s-c))
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

void tri_exibe(tTriangulo* t) {
    printf("Triangulo: \n");
    printf("  V1: "); pto_exibe(t->v1); printf("\n");
    printf("  V2: "); pto_exibe(t->v2); printf("\n");
    printf("  V3: "); pto_exibe(t->v3); printf("\n");
}