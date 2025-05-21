/*Faça um subprograma que receba uma matriz M e um escalar E e
devolva a matriz M multiplicada pelo escalar E*/

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

void multiplicacao_por_escalar(int matriz[TAM][TAM], int n_linhas, int n_colunas, int escalar) {
    
    for (int i = 0; i < n_linhas; i++) {
        for (int j = 0; j < n_colunas; j++) {
            matriz[i][j] *= escalar;
        }
    }
}

int main() {
    int matriz[TAM][TAM];
    int n_linhas, n_colunas, escalar;
    
    printf("\nMatriz: \n");
    printf("Número de Linhas: ");
    scanf("%d", &n_linhas);
    printf("Número de Colunas: ");
    scanf("%d", &n_colunas);
    
    cria_matriz(matriz, n_linhas, n_colunas);
    printf("\n");
    escreve_matriz(matriz, n_linhas, n_colunas);
    printf("\nEscalar que deve multiplicar a matriz: ");
    scanf("%d", &escalar);
    multiplicacao_por_escalar(matriz, n_linhas, n_colunas, escalar);
    printf("\nNova matriz: \n\n");
    escreve_matriz(matriz, n_linhas, n_colunas);
    
    return 0;
}
