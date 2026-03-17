#include <stdio.h>
#include <stdlib.h>
#include "Produto.h"
#include "Data.h"

int main() {
    int d, m, a;
    printf("Digite a data alvo para consulta (dia mes ano): ");
    if (scanf("%d %d %d", &d, &m, &a) != 3) return 1;

    // 1. Criar a data alvo usando o teu TAD Data
    tData* dataAlvo = dta_cria(d, m, a);

    // 2. Criar um vetor de ponteiros para produtos (Exemplo com 2 produtos)
    tProd* estoque[2];
    
    // Produto 1: Leite, Preço 5.0, 2 unidades, fabricado em 10/03/2024, Lote 100
    estoque[0] = pro_cria("Leite", "789001", 5.0, 2, 10, 3, 2024, 100);
    
    // Produto 2: Iogurte, Preço 4.0, 3 unidades, fabricado na mesma data da consulta
    // (Este deve receber o desconto de 25%)
    estoque[1] = pro_cria("Iogurte", "789002", 4.0, 3, d, m, a, 200);

    printf("\n--- PROCESSAMENTO DE ESTOQUE ---\n");

    for (int i = 0; i < 2; i++) {
        int aplicarDesconto = 0;
        printf("\nProduto: %s\n", pro_getIdenti(estoque[i]));

        // 3. Verificar cada unidade do produto
        for (int j = 0; j < pro_getQuant(estoque[i]); j++) {
            tUni* u = pro_getUnidadePos(estoque[i], j);
            
            // uni_idade retorna a diferença em dias entre a fabricação e o alvo
            int diff = uni_idade(u, dataAlvo);
            
            // O enunciado pede: vencer em 3 dias da data alvo
            // Interpretamos como: diferença entre 0 e 3 dias
            if (diff >= 0 && diff <= 3) {
                aplicarDesconto = 1;
            }
        }

        if (aplicarDesconto) {
            printf(">> Unidade perto do vencimento detectada! Aplicando -25%% de desconto.\n");
            pro_reajuste(estoque[i], -25.0);
        }

        // 4. Mostrar estado final do produto usando o teu pro_getProduto
        char* info = pro_getProduto(estoque[i]);
        printf("Info Atualizada: %s\n", info);
        free(info); // Importante: pro_getProduto faz malloc, precisa de free
    }

    // 5. Limpeza de memória
    for (int i = 0; i < 2; i++) {
        pro_libera(estoque[i]);
    }
    dta_libera(dataAlvo);

    printf("\nProcesso concluido com sucesso.\n");
    return 0;
}