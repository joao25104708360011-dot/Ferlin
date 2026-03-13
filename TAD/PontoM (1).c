#include "PontoM.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
/* Implementação TAD: Ponto (x,y) */
/*definição do tipo exportado*/ 
struct ponto {
   double x;
   double y;
};

/*definição das funções exportadas*/ 
/* Função cria - Aloca e retorna um ponto com coordenadas (x,y) */
Ponto* pto_cria(float x, float y){
   Ponto* p = (Ponto*) malloc(sizeof(Ponto));
   if (p == NULL) {
      printf("Memória insuficiente!\n");
   }
   else{
    p->x = x;
    p->y = y;
   }
   return p;
}

/* Função libera - Libera a memória de um ponto previamente criado */
void pto_libera(Ponto* p) {
  free(p);
}

/* Função acessa - Retorna os valores das coordenadas de um ponto */
void pto_acessa(Ponto* p, float* x, float* y) {
  *x=p->x;
  *y=p->y;
}

/* Função acessa - Retorna o valor da coordenada x de um ponto */
void pto_acessaX(Ponto* p, float* x) {
    *x=p->x;
}

/* Função acessa - Retorna o valor da coordenada y de um ponto */
void pto_acessaY(Ponto* p, float* y) {
    *y=p->y;
}

/* Função atribui - Atribui novos valores às coordenadas de um ponto */
void pto_atribui(Ponto* p, float x, float y) {
  p->x=x;
  p->y=y;
}

/* Função atribui - Atribui um novo valor a coordenada x de um ponto */
void pto_atribuiX(Ponto* p, float x) {
    p->x=x;
}

/* Função atribui - Atribui um novo valor a coordenada y de um ponto */
void pto_atribuiX(Ponto* p, float y) {
    p->y=y;
}

/* Função distancia - Retorna a distância entre dois pontos */
float pto_distancia(Ponto* p1, Ponto* p2) {
  float dx = p2->x - p1->x;
  float dy = p2->y - p1->y;
  return sqrt(dx*dx + dy*dy);

  
}

/* Função getPonto - Retorna uma string com os valores do ponto formato(x,y)*/
char* pto_getPonto(Ponto* p1) {
  char* pt;
  int tam = sizeof(*p1)+ 8;
  pt = (char*)malloc(tam);
  sprintf(pt,"( %.2f , %.2f )", p1->x, p1->y);
  return pt;

}

/* Função exibe -Escreve na tela o ponto no formato  (xxx.xx,yyy.yy)*/
void pto_exibe(Ponto* p) {
  printf(" (%.2f,%.2f) ",p->x,p->y);
}

/* função compara -1:se o pt1 < pt2, 0 se pt1 == pt2, +1 se o pt1 > pt2  */
/* um ponto é menor do que o outro se estiver mais próximo da origem*/
int pto_compara(Ponto*p1,Ponto*p2){
    if (p1->x ==p2->x  && p1->y ==p2->y)
        return 0;
     Ponto* origem=pto_cria(0,0);
     float dist1=pto_distancia(p1,origem);
     float dist2=pto_distancia(p2,origem);
     pto_libera(origem);
     if (dist1 == dist2)
        if (p1->x < p2->x ||p1->y < p2->y )
            return -1;
        else
            return 1;
     else if (dist1 < dist2)
        return -1;
    else
        return 1;
     
}

/* função para copiar as cordenadas de um ponto em outro ponto */
void pto_copia(Ponto*p) {
    float x,y;
    pto_acessa(p, &x, &y);
    return(pto_cria(x, y));
}








