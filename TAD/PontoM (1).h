/*Tipo exportado */
/* cria um ponto no pano cartesiano (x,y)*/
typedef struct ponto Ponto;

/* Funções exportadas */
/* Função cria - Aloca e retorna um ponto com coordenadas (x,y) */
Ponto* pto_cria(float x, float y);

/* Função libera - Libera a memória de um ponto previamente criado */
void pto_libera(Ponto* p);

/* Função acessa - Retorna os valores das coordenadas de um ponto */
void pto_acessa(Ponto* p, float* x, float* y);

/* Função acessa - Retorna o valor da coordenada x de um ponto */
void pto_acessaX(Ponto* p, float* x);

/* Função acessa - Retorna o valor da coordenada y de um ponto */
void pto_acessaY(Ponto* p, float* y);

/* Função atribui - Atribui novos valores às coordenadas de um ponto */
void pto_atribui(Ponto* p, float x, float y);

/* Função atribui - Atribui um novo valor a coordenada x de um ponto */
void pto_atribuiX(Ponto* p, float x);

/* Função atribui - Atribui um novo valor a coordenada y de um ponto */
void pto_atribuiY(Ponto* p, float y);

/* Função exibe -Escreve na tela o ponto no formato  (xxx.xx,yyy.yy)*/
void pto_exibe(Ponto* p);

/* Função getPonto - Retorna uma string com os valores do ponto formato(x,y)*/
char* pto_getPonto(Ponto* p);

/* Função distancia - Retorna a distância entre dois pontos */
float pto_distancia(Ponto* p1, Ponto* p2);

/* função compara -1:se o pt1 < pt2, 0 se pt1 == pt2, +1 se o pt1 > pt2  */
/* um ponto é menor do que o outro se estiver mais próximo da origem*/
int pto_compara(Ponto*p1,Ponto*p2);

/* função para copiar as cordenadas de um ponto em outro ponto */
void pto_copia(Ponto*p1,Ponto*p2);
