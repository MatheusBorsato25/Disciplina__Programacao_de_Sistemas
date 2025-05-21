/*Faça um algoritmo que leia uma matriz de dimensões 5x5 e a escreva na
tela*/

#include <stdio.h>

#define LINHAS 5
#define COLUNAS 5

void le_matriz(int matriz[LINHAS][COLUNAS]) {
    printf("\nDigite os elementos da matriz 5x5:\n\n");
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void escreve_matriz(int matriz[LINHAS][COLUNAS]) {
    printf("\nMatriz 5x5:\n");
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%5d ", matriz[i][j]);  // espaçamento para alinhamento
        }
        printf("\n");
    }
}

int main() {
    int matriz[LINHAS][COLUNAS];
    
    le_matriz(matriz);
    escreve_matriz(matriz);
    
    return 0;
}
