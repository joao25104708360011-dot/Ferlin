#ifndef PRODUTO_H
#define PRODUTO_H
#include "Unidade.h"


typedef struct produto tProd;

tProd* pro_cria(char identi[], char codBar[], float preco, int quant, int dia, int mes, int ano, int lote);

void pro_libera(tProd* p);

void pro_exibe(tProd* p);

char* pro_getIdenti(tProd* p);

char* pro_getCodBar(tProd* p);

float pro_getPreco(tProd* p);

int pro_getQuant(tProd* p);

tUni* pro_getUnidadePos(tProd* p, int pos);

void pro_setIdenti(tProd* p, char identi[]);

void pro_setCodBar(tProd* p, char codBar[]);

void pro_setPreco(tProd* p, float preco);

void pro_reajuste(tProd* p, float reaj);

char* pro_getProduto(tProd* p);

#endif