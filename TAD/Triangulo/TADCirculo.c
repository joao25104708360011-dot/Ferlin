#include <stdlib.h>
#include <stdio.h>
#include "TADCirculo.h"
#define PI 3.14159


struct circulo {
 Ponto *centro;
 float r;
} ;


void circ_setRaio(tCirculo * c, float r){
    c->r=r;
}

tCirculo * circ_cria(int x,int y, float r){
  tCirculo * c=(tCirculo*)malloc(sizeof(tCirculo));
  c->centro=pto_cria(x,y);
  //pto_atribui(&c->p,x,y);
  circ_setRaio(c,r);
  return c;
}

float circ_getRaio(tCirculo *c){
    return c->r;
}

float circ_area(tCirculo *c){
    return PI*c->r*c->r;
}

float circ_comprimento(tCirculo *c){
    return 2*PI*c->r;
}

int circ_compara(tCirculo *c1, tCirculo *c2){
    float compC1=circ_comprimento(c1);
    float compC2=circ_comprimento(c2);
    if(compC1>compC2){
        printf("Primeiro circulo maior que o segundo");
        return 1;
    }
    else {
        if(compC1==compC2){
            printf("Circulos iguais");
            return -1;
        }
        else {
            printf("Segundo circulo maior que o primeiro");
            return 0;
        }
    }
}

void circ_libera(tCirculo* c){

    pto_libera(c->centro); 
    free(c);

}
char* circ_getCirculo(tCirculo* p){

    char * ponto_Textual = pto_getPonto(p->centro);
    int tam = sizeof(*p) + sizeof(*ponto_Textual);
    char* pt = (char*)malloc(tam + 20);

    sprintf(pt, "(centro:%s , raio:%.2f )", pto_getPonto(p->centro), p->r);

    return pt;

}

void circ_exibe(tCirculo* p){
     printf("Centro: ");
     pto_exibe(p->centro);
     printf("Raio: %.2f",p->r);
    //printf("(centro: %s, raio: % .2f)",pto_getPonto(p->p), p->r);

}


/*

*/
