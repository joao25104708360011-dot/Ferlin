#ifndef TADTRIANGULO_H
#define TADTRIANGULO_H

#include "TADPonto.h"

/* Tipo exportado */
typedef struct triangulo tTriangulo;

/* Funções exportadas */

/* Função cria - Aloca e retorna um triângulo dados os três vértices */
tTriangulo* tri_cria(float x1, float y1, float x2, float y2, float x3, float y3);

/* Função libera - Libera a memória do triângulo e de seus pontos */
void tri_libera(tTriangulo* t);

/* Função Perímetro - Retorna a soma dos comprimentos dos lados */
float tri_perimetro(tTriangulo* t);

/* Função Área - Retorna a área do triângulo (Fórmula de Heron) */
float tri_area(tTriangulo* t);

/* Função exibe - Imprime as coordenadas dos vértices na tela */
void tri_exibe(tTriangulo* t);

#endif