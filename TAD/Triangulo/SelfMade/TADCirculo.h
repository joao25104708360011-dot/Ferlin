typedef struct circulo tCirculo;
#include "TADPonto.h"
/* Funções exportadas */

/* Função cria - Aloca e retorna um círculo com centro (x,y) e raio r */
tCirculo* circ_cria(int x,int y, float r); 

/* Função libera - Libera a memória de um círculo previamente criado */
void circ_libera(tCirculo* c);


/* Funções Set e Get - atribui/ acessa raio */
void circ_setRaio(tCirculo* c, float r);
float circ_getRaio(tCirculo * c); 

/* Função Area - Retorna o valor da área do círculo */
float circ_area(tCirculo * c); 
/* Função Comprimento - Retorna o valor da circunferência (perímetro) */
float circ_comprimento(tCirculo *c);

/* Função Compara - determina pelo comprimento dos circulos */
int circ_compara(tCirculo *c1, tCirculo *c2); 

/* Função getCirculo - Retorna uma string lo no formato (c:centro,r:raio)*/
char* circ_getCirculo(tCirculo* p);
/* Função exibe -Escreve na tela o círculo no formato (c:centro,r:raio)*/
void circ_exibe(tCirculo* p);

/* Função clona – cria um novo cículo igual ao recebido*/
//tCirculo* circ_clona(tCirculo* cO);

int circ_quadrante(tCirculo* c);