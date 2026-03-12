#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//nome em malloc
struct opiniao {
  char *nome;
  int idade;
  int vPref[4]; // nota que a pessoa deu
};
typedef struct opiniao tOp;

void preenche(tOp * p, int i);
void nomesORD(tOp * p[], int n);
void IdadesORD(tOp * p[], int n);
void printar(tOp * p[], int n);

int main() {

  tOp vEnt[30];
  tOp * vNomes[30];
  tOp * vIdades[30];
  tOp * vOriginal[30];
  int resp;
  int n = 10;

  for(int i=0;i<n;i++)
  {
    preenche(&vEnt[i],i);
    vNomes[i] = &vEnt[i];
    vIdades[i] = &vEnt[i];
    vOriginal[i] = &vEnt[i];
  }

  nomesORD(vNomes, n);
  IdadesORD(vIdades, n);
  

  
  printf("--------------------------------------------\n");
  printf("-------Escolha uma opção de listagem--------\n");
  printf("--------------------------------------------\n");
  printf("\n");
  printf("############################################\n");
  printf("Opção 1: Ordenar por nome\n");
  printf("############################################\n");
  printf("Opção 2: Ordenar por idade\n");
  printf("############################################\n");
  printf("Opção 3: Ordenar por ordem de inclusão\n");
  printf("############################################\n");
  //printf("Opção 4: Incluir um novo registro\n");
  //printf("############################################\n");
  printf("\n");

  scanf("%d", &resp);

  switch (resp)
  {
  case 1:
    printar(vNomes, n);
    break;
  
  case 2:
    printar(vIdades, n);
    break;

  case 3:
    printar(vOriginal, n);
    break;

  /*case 4:
    if (n < 30)
    {
      char novo[100];
      printf("Digite um novo nome: ");
      scanf("%s", novo);

      vEnt[n].nome = (char*) malloc();

    }
    break;*/

  default:
    printf("Você escolheu um numero errado.");
    break;
  }

  for(int i = 0 ;i < n; i++)
  {
    free(vEnt[i].nome);
    free(vEnt[i].idade);
  }

  return 0;
}



void preenche(tOp * p, int i)
{
  char vNomes[10][10]={"ze","ana","joca", "sergio", "andre", "thomas", "marcos", "leticia", "marcia", "antedeguemon"};
  int vIdades[10]={10,22,16, 30, 12, 13, 24, 18, 31, 28};

  p->nome = (char *) malloc((strlen(vNomes[i]) + 1) * sizeof(char));
  if(p->nome != NULL)
  {
    strcpy(p->nome, vNomes[i]);
  }

  p->idade=vIdades[i];

  for( int j=0;j<3;j++)
  {
    p->vPref[j]=(j+1)* i+3;
  } 
  return;  
}

void nomesORD(tOp * p[], int n)
{
    int i, j;
    tOp *aux;
    for(i = 1; i < n; i++)
    {
        j = i - 1;
        aux = p[i];

        while (j >= 0 && strcmp(p[j]->nome, aux->nome) > 0)
        {
            p[j + 1] = p[j];
            j--;
        }
        p[j + 1] = aux;
    }
}

void IdadesORD(tOp * p[], int n)
{
  int i, j;
  tOp *aux;

  for(i = 1; i < n; i++)
  {
    j = i - 1;
    aux = p[i];

    while (j >= 0 && p[j]->idade > aux->idade)
    {
        p[j + 1] = p[j];
        j--;
    }
    p[j + 1] = aux;
  }
}

void printar(tOp * p[], int n)
{
  int i;

  for(i = 0; i < n; i++)
  {
    printf("Nome: %s | Idade: %d\n", p[i]->nome, p[i]->idade);
  }  
}