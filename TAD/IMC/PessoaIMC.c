#include "PessoaIMC.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct imc {
    char nome[30];
    Altura* alt;
    tPeso* peso; 
};


tIMC* imc_cria(char nome[], int m, int cm, int kilos, int gramas)
{
    tIMC* p = (tIMC*)malloc(sizeof(struct imc));

    if (p == NULL) {
        printf("Memória insuficiente!\n");
        exit(1);
    }

    strcpy(p->nome, nome);

    p->peso = peso_cria(kilos, gramas);
    p->alt = alt_cria(m, cm);

    return p;
}

tIMC* imc_peso(tIMC *p, int gramas)
{
    tPeso* novo = peso_soma(p->peso, gramas);
    peso_libera(p->peso);
    p->peso = novo;
}

tIMC* imc_alt(tIMC *p, int cm)
{
    Altura* nova = alt_soma(p->alt, cm);
    alt_libera(p->alt); 
    p->alt = nova;
}



float imc_calc(tIMC *p)
{
    int k, g, m, cm;
    
    // Usa as funções de acesso que você já criou
    peso_acessa(p->peso, &k, &g);
    alt_acessa(p->alt, &m, &cm);
    
    // Converte para float diretamente na fórmula
    float peso_total = k + (g / 1000.0);
    float altura_total = m + (cm / 100.0);
    
    return peso_total / (altura_total * altura_total);
}

char* imc_cat(float p)
{
    if(p < 18.5)
    {
        return "abaixo do peso";
    } 
    else
    {
        if(p <= 24.9)
        {
            return "normal"; 
        }
        else
        {
            if(p <= 29.9)
            {
                return "sobrepeso";
            }
            else
            {
                return "obesidade";
            }
        }
    }
}

void imc_libera(tIMC* p) {
    if (p != NULL) {
        alt_libera(p->alt);
        peso_libera(p->peso);
        free(p);
    }
}