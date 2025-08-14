#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main() {
    struct fila f;
    inicializa_fila(&f);

    printf("Fila inicializada.\n");
    escreve_fila(&f);

    // Teste enfileirar
    printf("\nEnfileirando 10, 20, 30, 40...\n");
    enfileira(&f, 10);
    enfileira(&f, 20);
    enfileira(&f, 30);
    enfileira(&f, 40);
    escreve_fila(&f);

    // Teste busca
    printf("\nBuscando 20: %s\n", busca_fila(&f, 20) ? "Encontrado" : "Não encontrado");
    printf("Buscando 99: %s\n", busca_fila(&f, 99) ? "Encontrado" : "Não encontrado");

    // Teste primeiro
    int primeiro_valor;
    if (primeiro(&f, &primeiro_valor)) {
        printf("\nPrimeiro elemento da fila: %d\n", primeiro_valor);
    } else {
        printf("\nFila vazia, não há primeiro elemento.\n");
    }

    // Teste desenfileirar
    printf("\nDesenfileirando tudo...\n");
    while (!fila_vazia(&f)) {
        if (primeiro(&f, &primeiro_valor)) {
            printf("Removendo: %d\n", primeiro_valor);
        }
        desenfileira(&f);
        escreve_fila(&f);
    }

    // Teste após fila esvaziar
    printf("\nTentando desenfileirar em fila vazia...\n");
    if (!desenfileira(&f)) {
        printf("Fila já está vazia, não há o que remover.\n");
    }

    printf("\nTentando obter primeiro em fila vazia...\n");
    if (!primeiro(&f, &primeiro_valor)) {
        printf("Fila vazia, sem primeiro elemento.\n");
    }

    printf("\nTentando buscar em fila vazia...\n");
    printf("Buscando 10: %s\n", busca_fila(&f, 10) ? "Encontrado" : "Não encontrado");

    return 0;
}
