#ifndef PESO_H
#define PESO_H

typedef struct peso tPeso;

/* Função cria - Aloca e retorna um peso (kilos e gramas) */
tPeso* peso_cria(int kilos, int gramas);

int converteParag(tPeso *p);

/* Função libera - Libera a memória de um peso previamente criado */
void peso_libera(tPeso* p);

/* Função acessa - Retorna os valores de um peso */
void peso_acessa(tPeso *p, int *kilos, int *gramas);

/* Função atribui - Atribui novos valores às partes de um peso */
void peso_atribui(tPeso *p, int kilos, int gramas);

void peso_exibe(tPeso* p);

/* Função getAltur- Retorna uma string com os valores do peso no formato
kilos, gramas*/
char* peso_getPeso(tPeso *p);

int peso_compara(tPeso *p1, tPeso *p2);

tPeso* peso_soma(tPeso *p, int gramas);

tPeso* peso_copia(tPeso *p);

#endif
