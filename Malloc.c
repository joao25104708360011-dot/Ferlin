#include <stdlib.h>
#include <stdio.h>

#define LIN 6
#define COL 6

int procurarsoma(int mato[], int c, int **mat);

int main(void)
{

    int **mat;
    int mato[6] = {3,4,2,5,6,1};
    int i, j, resul;
    int c = 6;

    mat = malloc(LIN * sizeof(int*));

    for(i = 0; i < LIN; i++)
    {
        mat[i] = malloc(COL * sizeof(int));
    }

    for(i = 0; i < LIN; i++)
    {
        for(j = 0; j < COL; j++)
        {
            mat[i][j] = 1;
        }
    }

    mat[2][3] = 10;  
    mat[3][1] = 150; 
    mat[1][4] = 95;  
    mat[4][5] = 80;  
    mat[5][0] = 190; 

    resul = procurarsoma(mato, c, mat);

    printf("\n\nEssa foi a distancia percorrida: %d\n\n", resul);

    
    for(i=0; i < LIN; i++)
    {
        free(mat[i]);
    }
    free(mat);

    return 0;
}

int procurarsoma(int mato[], int c, int **mat)
{
    int i, j, soma = 0;
    int origem, destino;

    for(i = 0;i < c - 1; i++)
    {
        origem = mato[i] - 1;
        destino = mato[i + 1] - 1;

        soma += mat[origem][destino];
    }

    return soma;
}
