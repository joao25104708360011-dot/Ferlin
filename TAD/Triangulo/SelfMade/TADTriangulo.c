#include <stdlib.h>
#include <stdio.h>
#include "TADTriangulo.h"

struct triangulo {
 Ponto* ver1;
 Ponto* ver2;
 Ponto* ver3;
};


tTri* tri_cria(float x1, float y1, float x2, float y2, float x3, float y3)
{
  tTri* t = (tTri*)malloc(sizeof(tTri));
  t->ver1 = pto_cria(x1, y1);
  t->ver2 = pto_cria(x2, y2);
  t->ver3 = pto_cria(x3, y3);

  return t;
}

void tri_libera(tTri* t)
{
    pto_libera(t->ver1);
    pto_libera(t->ver2);
    pto_libera(t->ver3); 
    free(t);
}

void tri_setVert(tTri* t, float x1, float y1, float x2, float y2, float x3, float y3)
{
    pto_atribui(t->ver1, x1, y1);
    pto_atribui(t->ver2, x2, y2);
    pto_atribui(t->ver3, x3, y3);

}

Ponto* tri_getVert1(tTri* t){
    return t->ver1;
}

Ponto* tri_getVert2(tTri* t){
    return t->ver2;
}

Ponto* tri_getVert3(tTri* t){
    return t->ver3;
}

float tri_perimetro(tTri* t)
{
    float a = pto_distancia(t->ver1, t->ver2);
    float b = pto_distancia(t->ver2, t->ver3);
    float c = pto_distancia(t->ver3, t->ver1);

    return a + b + c;
}

float tri_area(tTri* t) 
{
    float a = pto_distancia(t->ver1, t->ver2);
    float b = pto_distancia(t->ver2, t->ver3);
    float c = pto_distancia(t->ver3, t->ver1);


    float semi = (a + b + c) / 2.0;
    
    float area = sqrt(semi *(semi - a) * (semi - b) * (semi - c));
    return area;
}

int tri_compara(tTri *c1, tTri *c2) {
    float compT1= tri_area(c1);
    float compT2= tri_area(c2);

    if(compT1>compT2){
        printf("Primeiro triangulo maior que o segundo");
        return 1;
    }
    else {
        if(compT1==compT2){
            printf("Triangulos iguais");
            return -1;
        }
        else {
            printf("Segundo triangulo maior que o primeiro");
            return 0;
        }
    }
}

char* tri_getTriangulo(tTri* t){

    char* ponto_Textual1 = pto_getPonto(t->ver1);
    char* ponto_Textual2 = pto_getPonto(t->ver2);
    char* ponto_Textual3 = pto_getPonto(t->ver3);
    /*
    int tam = sizeof(*p) + sizeof(*ponto_Textual);
    char* pt = (char*)malloc(tam + 20);
    sprintf(pt, "(centro:%s , raio:%.2f )", pto_getPonto(p->centro), p->r);
*/
    char* str_triangulo = (char*)malloc(128 * sizeof(char)); 
    
    if (str_triangulo == NULL) 
    {
        return NULL;
    }    
    
    sprintf(str_triangulo, "Vertice 1: %s\nVertice 2: %s\nVertice 3: %s", ponto_Textual1, ponto_Textual2, ponto_Textual3);
    free(ponto_Textual1); 
    free(ponto_Textual2); 
    free(ponto_Textual3); 

    return str_triangulo;
    //return pt;

}

void tri_exibe(tTri* t){
    printf("Vertice 1: ");
    pto_exibe(t->ver1);
    printf("Vertice 2: ");
    pto_exibe(t->ver2);
    printf("Vertice 3: ");
    pto_exibe(t->ver3);
    //printf("(centro: %s, raio: % .2f)",pto_getPonto(p->p), p->r);

}

int tri_quadrante(tTri* t)
{
    int qua1 = pto_quadrante(t->ver1);
    int qua2 = pto_quadrante(t->ver2);
    int qua3 = pto_quadrante(t->ver3);

    if(qua1 == qua2 && qua2 == qua3)
    {
        return  qua1;
    }
    return 0;
}


/*

*/
