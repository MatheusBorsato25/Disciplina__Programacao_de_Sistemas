/*Faça um algoritmo que leia uma matriz quadrada e informe todos
elementos da sua diagonal principal.
Faça um subprograma que retorne a soma dos elementos da diagonal
principal de uma matriz.
Faça um subprograma que retorne a soma de todos elementos da
diagonal secundária de uma matriz.
Faça um algoritmo que some os elementos da diagonal principal de uma
matriz quadrada, e multiplique o valor pela soma dos elementos da
diagonal secundária*/

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

void elementos_diagonal_principal(int matriz[TAM][TAM], int n_linhas, int vetor_auxiliar[TAM], int *tamanho_logico) {
    for (int i = 0; i < n_linhas; i++) {
        vetor_auxiliar[i] = matriz[i][i];
    }
    *tamanho_logico = n_linhas;
}

void escreve_vetor(int vetor[TAM], int tamanho_vetor) {
    printf("[");
    for (int i = 0; i < tamanho_vetor; i++) {
        printf("%d", vetor[i]);
        if (i < tamanho_vetor - 1) {
            printf(", ");
        }
    }
    printf("]");
}

int soma_diagonal_principal(int vetor[TAM], int tamanho_vetor) {
    int soma = 0;
    
    for (int i = 0; i < tamanho_vetor; i++) {
        soma += vetor[i];
    }
    return soma;
}

int soma_diagonal_secundaria(int matriz[TAM][TAM], int n_linhas) {
    int soma = 0;
    
    for (int i = 0, j = n_linhas - 1; i < n_linhas; i++, j--) {
        soma += matriz[i][j];
    }
    return soma;
}

int produto_diagonais(int diagonal_principal, int diagonal_secundaria) {
    int produto = diagonal_principal * diagonal_secundaria;
    return produto;
}

int main() {
    int matriz[TAM][TAM];
    int n_linhas, n_colunas, tamanho_logico;
    int vetor_auxiliar[TAM];
    
    printf("\nMatriz: \n");
    printf("Número de Linhas: ");
    scanf("%d", &n_linhas);
    printf("Número de Colunas: ");
    scanf("%d", &n_colunas);
    
    if (n_linhas == n_colunas) {
        cria_matriz(matriz, n_linhas, n_colunas);
        printf("\n");
        escreve_matriz(matriz, n_linhas, n_colunas);
        elementos_diagonal_principal(matriz, n_linhas, vetor_auxiliar, &tamanho_logico);
        printf("\nElementos da Diagonal Principal: ");
        escreve_vetor(vetor_auxiliar, tamanho_logico);
        int soma_dp = soma_diagonal_principal(vetor_auxiliar, tamanho_logico);
        int soma_ds = soma_diagonal_secundaria(matriz, n_linhas);
        printf("\nSoma dos Elementos da Diagonal Principal: %d.", soma_dp);
        printf("\nSoma dos Elementos da Diagonal Secundária: %d.", soma_ds);
        printf("\nProduto entre as Somas das Diagonais: %d.", produto_diagonais(soma_dp, soma_ds));
    } else {
        printf("\nA matriz não é quadrada!");
    }
    
    return 0;
}
