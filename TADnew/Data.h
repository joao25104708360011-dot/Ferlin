#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Representação do TAD: TData
//-----------
// Interface
//-----------

typedef struct data tData;

/* Funções exportadas */
/* Funçao cria - Aloca e retorna uma data dia/mês/ano */
tData* dta_cria(int dia, int mes, int ano);

/* Função Libera a memória de uma Data criada */
void dta_libera(tData* p);

/* Função acessa - Retorna os valores de uma Data */
void dta_acessa(tData* p, int* dia, int* mes, int* ano);

/* Função atribui - Atribui novos valores á Data */
void dta_atribui(tData* p, int dia, int mes, int ano);

/* Função Intervalo - Retorna a data após X dias */
tData* dta_intervalo(tData* p1, int X);

/* Função Exibe e Escreve na tela a data  no formato dd/mm/aaaa */
tData* dta_exibe(tData* p1);

/* Função getData - Retorna uma string com os valores da data no formato dd/mm/aaaa*/
char* dta_getData(tData* p);

/* DIFERENÇA EM DIAS ENTRE DUAS DATAS*/
int dta_diferenca(tData* dt1, tData * dt2);