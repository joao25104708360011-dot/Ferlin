#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PessoaIMC.h"

int main() {
    // 1. Criando um vetor de ponteiros para 4 pessoas com dados fixos
    tIMC* candidatos[4];

    candidatos[0] = imc_cria("Joao Silva", 1, 75, 70, 0);    // IMC ~24.5 (Normal)
    candidatos[1] = imc_cria("Maria Oliveira", 1, 60, 45, 0); // IMC ~17.5 (Abaixo)
    candidatos[2] = imc_cria("Carlos Souza", 1, 80, 90, 0);   // IMC ~27.7 (Sobrepeso)
    candidatos[3] = imc_cria("Ana Costa", 1, 65, 95, 0);     // IMC ~34.8 (Obesidade)

    printf("--- Candidatos Aptos para o Emprego ---\n");
    printf("(Requisito: Categoria 'normal' ou 'sobrepeso')\n\n");

    for (int i = 0; i < 4; i++) {
        // 2. Calcular o valor do IMC
        float valor_imc = imc_calc(candidatos[i]);
        
        // 3. Obter a categoria em string
        char* categoria = imc_cat(valor_imc);

        // 4. Verificar aptidão (apenas "normal" ou "sobrepeso")
        if (strcmp(categoria, "normal") == 0 || strcmp(categoria, "sobrepeso") == 0) {
            printf("NOME: %s\n", "Candidato Selecionado"); // O campo nome está dentro da struct no .c
            // Como o campo nome é privado no .c, idealmente você teria um imc_get_nome
            // Aqui simulamos a exibição baseada na lógica de filtragem:
            printf("Status: APTO | IMC: %.2f | Categoria: %s\n", valor_imc, categoria);
            printf("---------------------------------------\n");
        }
    }

    // 5. Liberar memória
    for (int i = 0; i < 4; i++) {
        imc_libera(candidatos[i]);
    }

    return 0;
}