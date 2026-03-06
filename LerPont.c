#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct opiniao {
	 char nome[15];
	 int idade;
	 int vPref[4]; // nota que a pessoa deu
};
typedef struct opiniao tOp;

void funcao(tOp * ent1);
void printar(const tOp * ent1);

int main() {
    int i;
	tOp vet1[3];
	tOp *vet2;

	vet2 = (tOp*)malloc (3 *sizeof(tOp));
	
    if(vet2 == NULL)
    {
        printf("\n Erro no codigo.");
        exit(0);
    }
    //estático
	for(i = 0; i < 3; i++)
	{
	    funcao(&vet1[i]);
	}    
	
	for(i = 0; i < 3; i++)
	{
	    printar(&vet1[i]);
	}  
	
    //dinamico
    for(i = 0; i < 3; i++)
    {
        funcao(&vet2[i]);
    }
    for(i = 0; i < 3; i++)
    {
        printar(&vet2[i]);
    }
    free(vet2);
    return 0;
}

void funcao(tOp * ent1)
{
    int i;
    
    printf("DADOS?\n");
    scanf(" %[^\n]", (*ent1).nome);
    
    scanf("%d", &(*ent1).idade);
    
    for(i = 0; i < 4; i++)
    {
        scanf("%d", &(*ent1).vPref[i]);
    }
}

void printar(const tOp * ent1)
{
    int i;
    
    printf("------------------------------------------");
    printf("\nNome: %s\n", ent1->nome);
    printf("Idade: %d\n", ent1->idade);
    
    for(i = 0; i < 4; i++)
    {
        printf("Notas: %d\n", ent1->vPref[i]);
    }
    
}
