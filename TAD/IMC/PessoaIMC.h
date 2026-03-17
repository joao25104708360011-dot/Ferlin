#include "Peso.h"
#include "Altura.h"

typedef struct imc tIMC;

tIMC* imc_cria(char nome[], int m, int cm, int kilos, int gramas);

tIMC* imc_peso(tIMC *p, int gramas);

tIMC* imc_alt(tIMC *p, int cm);

char* imc_cat(float p);

float imc_calc(tIMC *p);

void imc_libera(tIMC* p);

