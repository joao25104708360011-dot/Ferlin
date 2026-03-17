typedef struct triangulo tTri;
#include "TADPonto.h"
/* Funções exportadas */

/* Função cria - Aloca e retorna um triangulo com centro (x,y) e raio r */
tTri* tri_cria(float x1,float y1, float x2, float y2, float x3, float y3); 

/* Função libera - Libera a memória de um triangulo previamente criado */
void tri_libera(tTri* t);


/* Funções Set e Get - atribui/ acessa os vertices */
void tri_setVert(tTri* t, float x1, float y1, float x2, float y2, float x3, float y3);
Ponto* tri_getVert1(tTri* t);
Ponto* tri_getVert2(tTri* t); 
Ponto* tri_getVert3(tTri* t); 

/* Função Area - Retorna o valor da área do triangulo */
float tri_area(tTri* t); 
float tri_perimetro(tTri* t);
/* Função Compara - determina pelo comprimento dos circulos */
int tri_compara(tTri *c1, tTri *c2); 

/* Função getCirculo - Retorna uma string lo no formato (c:centro,r:raio)*/
char* tri_getTriangulo(tTri* t);
/* Função exibe -Escreve na tela o círculo no formato (c:centro,r:raio)*/
void tri_exibe(tTri* t);

/* Função clona – cria um novo cículo igual ao recebido*/
//tCirculo* circ_clona(tCirculo* cO);

int tri_quadrante(tTri* t);

