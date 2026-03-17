#include "Unidade.h"
#include <stdlib.h>
#include <stdio.h>

struct unidade 
{
    tData* fabri;
    int lote;
};

tUni* uni_cria(int dia, int mes, int ano, int lote) 
{
    tUni* un = (tUni*)malloc(sizeof(struct unidade));
    
    un->fabri = dta_cria(dia, mes, ano);
    un->lote = lote;
    
    return un;
}

void uni_libera(tUni* p) 
{
    
    dta_libera(p->fabri);
    free(p);
    
}


int uni_getLote(tUni* p) 
{ 
    return p->lote; 
}

tData* uni_getFabri(tUni* p) 
{ 
    return p->fabri; 
}

void uni_setLote(tUni* p, int lote) 
{ 
    p->lote = lote; 
}

void uni_setFabri(tUni* p, int dia, int mes, int ano) 
{
    dta_atribui(p->fabri, dia, mes, ano);
}

void uni_exibe(tUni* p) 
{
        dta_exibe(p->fabri);
        printf(" | Lote: %d\n", p->lote);
}

int uni_idade(tUni* p, tData* alvo) 
{
    return dta_diferenca(p->fabri, alvo);
}

int uni_menor(tUni* p1, tUni* p2, tData* data) 
{
    int idade1 = dta_diferenca(p1->fabri, data);
    int idade2 = dta_diferenca(p2->fabri, data);

    if (idade1 < idade2)
    { 
        return 1;
    }
    if (idade1 > idade2)
    {
        return 0;
    }
        
    return (p1->lote < p2->lote);
}