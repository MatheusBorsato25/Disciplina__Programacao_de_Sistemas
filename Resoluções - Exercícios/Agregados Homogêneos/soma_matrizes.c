/*Faça um algoritmo que some duas matrizes. A soma de matriz é feita da
seguinte forma:
Cij = Aij + Bij*/

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

void escreve_matriz(int matriz[TAM][TAM], int n_linhas, int n_colunas){

    for(int i = 0; i < n_linhas; i++){
        for(int j = 0; j < n_colunas; j++){
            printf("%5d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void soma_matrizes(int A[TAM][TAM], int n_linhasA, int n_colunasA, int B[TAM][TAM], int n_linhasB, int n_colunasB, int C[TAM][TAM], int *n_linhasC, int *n_colunasC) {
    if ((n_linhasA != n_linhasB) || (n_colunasA != n_colunasB)) {
        printf("\nAs dimensões das duas matrizes não são compatíveis!");
    } else {
        for (int i = 0; i < n_linhasA; i++) {
            for (int j = 0; j < n_colunasA; j++) {
                C[i][j] = A[i][j] + B[i][j];
            }
        }
        *n_linhasC = n_linhasA;
        *n_colunasC = n_colunasA;
    }
}

int main() {
    int A[TAM][TAM], B[TAM][TAM], C[TAM][TAM];
    int n_linhasA, n_linhasB, n_linhasC = 0, n_colunasA, n_colunasB, n_colunasC = 0;
    
    printf("\nMatriz A: \n");
    printf("Número de Linhas: ");
    scanf("%d", &n_linhasA);
    printf("Número de Colunas: ");
    scanf("%d", &n_colunasA);
    cria_matriz(A, n_linhasA, n_colunasA);
    printf("\n");
    escreve_matriz(A, n_linhasA, n_colunasA);
    
    //////////////////////////////////////////////////////////////////////////////
    
    printf("\nMatriz B: \n");
    printf("Número de Linhas: ");
    scanf("%d", &n_linhasB);
    printf("Número de Colunas: ");
    scanf("%d", &n_colunasB);
    cria_matriz(B, n_linhasB, n_colunasB);
    printf("\n");
    escreve_matriz(B, n_linhasB, n_colunasB);
    
    //////////////////////////////////////////////////////////////////////////////
    
    soma_matrizes(A, n_linhasA, n_colunasA, B, n_linhasB, n_colunasB, C, &n_linhasC, &n_colunasC);
    
    if (n_linhasC > 0 && n_colunasC > 0) {
        printf("\nMatriz C: \n\n");
        escreve_matriz(C, n_linhasC, n_colunasC);
    }
    
    return 0;
}
