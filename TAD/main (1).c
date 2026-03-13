/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include "PontoM.h"

int main()
{
    Ponto * pt1;
    pt1=pto_cria(3,2);
    pto_exibe(pt1);
    char * s = pto_getPonto(pt1);
    printf("vc criou este ponto----> %s", s);

    return 0;
}
