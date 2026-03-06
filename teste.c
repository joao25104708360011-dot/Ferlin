
#include <stdio.h>
#include <string.h>

struct opiniao {
	 char nome[15];
	 int idade;
	 int vPref[4]; // nota que a pessoa deu
};
typedef struct opiniao tOp;

tOp funcao(tOp * ent1);
tOp printar(const tOp * ent1);

int main() {
    int i;
	tOp vet1[3];
	tOp * p;

	
	
	for(i = 0; i < 3; i++)
	{
	    funcao(&vet1[i]);
	}    
	
	for(i = 0; i < 3; i++)
	{
	    printar(&vet1[i]);
	}  
	

    return 0;
}

tOp funcao(tOp * ent1)
{
    int i;
    
    printf("DADOS?");
    scanf("%[^\n]", (*ent1).nome);
    
    scanf("%d", &(*ent1).idade);
    
    for(i = 0; i < 4; i++)
    {
        scanf("%d", &(*ent1).vPref[i]);
    }
}

tOp printar(const tOp * ent1)
{
    int i;
    
    printf("------------------------------------------");
    printf("Nome: %s\n", ent1->nome);
    printf("Idade: %d\n", ent1->idade);
    
    for(i = 0; i < 4; i++)
    {
        printf("Notas: %d\n", ent1->vPref[i]);
    }
    printf("------------------------------------------");
}
