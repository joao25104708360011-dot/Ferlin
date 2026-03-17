#include "Produto.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct produto {
    char identi[30];
    char codBar[30];
    float preco;
    int quant;
    tUni** unidades; 
};

tProd* pro_cria(char identi[], char codBar[], float preco, int quant, int dia, int mes, int ano, int lote) 
{
    tProd* p = (tProd*)malloc(sizeof(struct produto));

    if (identi != NULL && strlen(identi) > 0) 
    {
        strcpy(p->identi, identi);
    } 
    else 
    {
        strcpy(p->identi, "Produto");
    }

    if (codBar != NULL && strlen(codBar) > 0) {
        strcpy(p->codBar, codBar);
    }
    else 
    {
        strcpy(p->codBar, "");
    }

    p->preco = preco;
    p->quant = quant;

    p->unidades = (tUni*)malloc(p->quant * sizeof(tUni*));

    for (int i = 0; i < p->quant; i++)
    {
        p->unidades[i] = uni_cria(dia, mes, ano, lote);
    }
    
    return p;
}

char* pro_getIdenti(tProd* p) 
{ 
    return p->identi; 
}

char* pro_getCodBar(tProd* p) 
{ 
    return p->codBar; 
}

float pro_getPreco(tProd* p) 
{ 
    return p->preco; 
}

int pro_getQuant(tProd* p) 
{
    return p->quant; 
}

tUni* pro_getUnidadePos(tProd* p, int pos) 
{
    if (pos >= 0 && pos < p->quant)
    {
        return p->unidades[pos];
    }
    return NULL;
}

void pro_setIdenti(tProd* p, char identi[]) 
{ 
    strcpy(p->identi, identi); 
}

void pro_setCodBar(tProd* p, char codBar[]) 
{ 
    strcpy(p->codBar, codBar); 
}

void pro_setPreco(tProd* p, float preco) 
{ 
    p->preco = preco; 
}

void pro_libera(tProd* p) 
{
        for (int i = 0; i < p->quant; i++)
        { 
            uni_libera(p->unidades[i]);
        }

        free(p->unidades);
        free(p);
    
}

void pro_exibe(tProd* p) 
{
    printf("Prod: %s | Preco: %.2f\n", p->identi, p->preco);
    
    for (int i = 0; i < p->quant; i++)
    { 
        uni_exibe(p->unidades[i]);
    }
}

void pro_reajuste(tProd* p, float reaj) 
{
    p->preco += p->preco * (reaj / 100);
}

char* pro_getProduto(tProd* p) 
{
    char* res = (char*)malloc(100);
    sprintf(res, "ID: %s | Preco: %.2f | Qtd: %d", p->identi, p->preco, p->quant);
    return res;
}