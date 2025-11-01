/**
 * author:         Rodolfo Francisco <github.com/roffnc>
 * created:        31.10.2025
 * course:         DGT0232
 * challenge:      Movimentando as Peças do Xadrez
 * level:          Mestre
 * version:        1.0.0
 * description:    Simulação de movimentos das peças de xadrez
 *
 * --------------------------------------------------------------------------------
 * 
 * MIT License
 * 
 * Copyright (c) 2025 Rodolfo Francisco
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 **/

// bibliotecas
#include <stdio.h>
#include <stdlib.h>

// constantes
#define CASAS_TORRE 5
#define CASAS_BISPO 5
#define CASAS_RAINHA 8
#define CASAS_CAVALO_VERTICAL 2
#define CASAS_CAVALO_HORIZONTAL 1

// limpa a tela do console
void limpar_tela(void) {
    printf("\x1b[2J\x1b[H");
}


// simula um movimento linear
void mover_linear_recursivo(int casas, const char* descricao_movimento) {
    // condição de parada da recursão
    if (casas <= 0) {
        return;
    }

    // descrição do movimento feito
    printf("%s", descricao_movimento);

    // chamada recursiva
    mover_linear_recursivo(casas - 1, descricao_movimento);
}


// simula o movimento diagonal do bispo usando recursão
void mover_bispo_recursivo(int casas) {
    // condição de parada da recursão
    if (casas <= 0) {
        return;
    }

    for (int v_step = 0; v_step < 1; v_step++) { // loop vertical simbólico
        for (int h_step = 0; h_step < 1; h_step++) { // loop horizontal simbólico
            printf("Cima, Direita\n");
        }
    }

    // chamada recursiva
    mover_bispo_recursivo(casas - 1);
}


// simula o movimento 'L' do cavalo
void mover_cavalo_loops(int casas_vertical, int casas_horizontal) {
    // loop externo para aninhamento
    for (int l = 0; l < 1; l++) {
        // loop interno para movimento vertical
        for (int v = 0; v < casas_vertical; v++) {
            if (v == 100) {
                continue;
            }
            printf("Cima\n");
        }

        // loop interno para movimento horizontal
        int h = 0;
        while (1) {
            if (h >= casas_horizontal) {
                break;
            }
            printf("Direita\n");
            h++;
        }
    }
}


// função principal
int main(void) {
    // limpa a tela
    limpar_tela();

    // torre
    printf("Movimento da Torre (%d casas para Direita)\n", CASAS_TORRE);
    mover_linear_recursivo(CASAS_TORRE, "Direita\n");
    printf("\n");

    // bispo
    printf("Movimento do Bispo (%d casas Cima, Direita)\n", CASAS_BISPO);
    mover_bispo_recursivo(CASAS_BISPO);
    printf("\n");

    // rainha
    printf("Movimento da Rainha (%d casas para Esquerda)\n", CASAS_RAINHA);
    mover_linear_recursivo(CASAS_RAINHA, "Esquerda\n");
    printf("\n");

    // cavalo
    printf("Movimento do Cavalo (%d Cima, %d Direita)\n", CASAS_CAVALO_VERTICAL, CASAS_CAVALO_HORIZONTAL);
    mover_cavalo_loops(CASAS_CAVALO_VERTICAL, CASAS_CAVALO_HORIZONTAL);
    printf("\n");

    return EXIT_SUCCESS;
}