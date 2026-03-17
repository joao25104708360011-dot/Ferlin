#ifndef UNIDADE_H
#define UNIDADE_H
#include "Data.h"
typedef struct unidade tUni;


tUni* uni_cria(int dia, int mes, int ano, int lote);

void uni_libera(tUni* p);

void uni_exibe(tUni* p);

int uni_getLote(tUni* p);

tData* uni_getFabri(tUni* p);

void uni_setLote(tUni* p, int lote);

void uni_setFabri(tUni* p, int d, int m, int a);

int uni_idade(tUni* p, tData* alvo);

char* uni_getUnidade(tUni* p);

int uni_menor(tUni* p1, tUni* p2, tData* data);

#endif