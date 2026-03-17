#include "Peso.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct peso {
    int kilos, gramas;
};

/* Função cria - Aloca e retorna um peso (kilos e gramas) */
tPeso* peso_cria(int kilos, int gramas)
{
    tPeso *p = (tPeso*)malloc(sizeof(tPeso));

    if (p == NULL) {
        printf("Memória insuficiente!\n");
        exit(1);
    }

    p->kilos = kilos;
    p->gramas = gramas;

    return p;
}

int converteParag(tPeso *p) 
{ 
    return p->kilos * 1000 + p->gramas; 
}

/* Função libera - Libera a memória de um peso previamente criado */
void peso_libera(tPeso* p)
{
    free(p);
}

/* Função acessa - Retorna os valores de um peso */
void peso_acessa(tPeso *p, int *kilos, int *gramas)
{
    *kilos = p->kilos;
    *gramas = p->gramas;
}

/* Função atribui - Atribui novos valores às partes de um peso */
void peso_atribui(tPeso *p, int kilos, int gramas)
{
    p->kilos = kilos;
    p->gramas =  gramas;
}

void peso_exibe(tPeso* p)
{
    printf("\nPeso: %d,%02dkg", p->kilos, p->gramas);
}

/* Função getAltur- Retorna uma string com os valores do peso no formato
kilos, gramas*/
char* peso_getPeso(tPeso *p)
{
    char *ps;
    int tam = sizeof(*p) + 5;
    ps = (char*)malloc(tam);
    sprintf(ps, "%d,%02dkg", p->kilos, p->gramas);
    return ps;
}

int peso_compara(tPeso *p1, tPeso *p2)
{
    int a1 = converteParag(p1);
    int a2 = converteParag(p2);
    return a1 - a2;
}

tPeso* peso_soma(tPeso *p, int gramas)
{
    int total_g = converteParag(p) + gramas;
    int novos_kilos = total_g / 1000;
    int novos_gramas = total_g % 1000;
    return peso_cria(novos_kilos, novos_gramas);
}

tPeso* peso_copia(tPeso *p)
{
    if (p == NULL) 
    {
        return NULL;
    }

    return peso_cria(p->kilos, p->gramas);
}
