/*Faça um algoritmo que some todos elementos de uma matriz*/

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

int soma_elementos(int matriz[TAM][TAM], int n_linhas, int n_colunas) {
    int soma = 0;
    
    for (int i = 0; i < n_linhas; i++) {
        for (int j = 0; j < n_colunas; j++) {
            soma += matriz[i][j];
        }
    }
    return soma;
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
    int soma = soma_elementos(matriz, n_linhas, n_colunas);
    printf("\nA soma dos elementos da matriz é %d.", soma);
    
    return 0;
}
