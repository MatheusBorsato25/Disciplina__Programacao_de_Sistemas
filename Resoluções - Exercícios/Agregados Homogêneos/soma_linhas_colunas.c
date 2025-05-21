/*Faça um algoritmo que some todos elementos de cada linha e de cada
coluna de uma matriz*/

#include <stdio.h>
#define TAM 10

void cria_matriz(int matriz[TAM][TAM], int n_linhas, int n_colunas) {
    printf("\nDigite os elementos da matriz %dx%d:\n\n", n_linhas, n_colunas);
    for (int i = 0; i < n_linhas; i++) {
        for (int j = 0; j < n_colunas; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void escreve_matriz(int matriz[TAM][TAM], int n_linhas, int n_colunas) {

    for (int i = 0; i < n_linhas; i++){
        for (int j = 0; j < n_colunas; j++){
            printf("%5d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void soma_linhas(int matriz[TAM][TAM], int n_linhas, int n_colunas) {
    printf("\nSoma dos elementos de cada linha: \n\n");
    for (int i = 0; i < n_linhas; i++) {
        int soma = 0;
        for (int j = 0; j < n_colunas; j++) {
            soma += matriz[i][j];
        }
        printf("Linha %d: %d\n", i, soma);
    }
}

void soma_colunas(int matriz[TAM][TAM], int n_linhas, int n_colunas) {
    printf("\nSoma dos elementos de cada coluna: \n\n");
    for (int j = 0; j < n_colunas; j++) {
        int soma = 0;
        for (int i = 0; i < n_linhas; i++) {
            soma += matriz[i][j];
        }
        printf("Coluna %d: %d\n", j, soma);
    }
}

int main() {
    int matriz[TAM][TAM];
    int n_linhas, n_colunas;
    
    printf("\nMatriz: \n");
    printf("Número de Linhas: ");
    scanf("%d", &n_linhas);
    printf("Número de Colunas: ");
    scanf("%d", &n_colunas);
    
    cria_matriz(matriz, n_linhas, n_colunas);
    printf("\n");
    escreve_matriz(matriz, n_linhas, n_colunas);
    soma_linhas(matriz, n_linhas, n_colunas);
    soma_colunas(matriz, n_linhas, n_colunas);
    
    return 0;
}
