/*Faça um procedimento que receba um vetor A, um vetor B, seus
tamanhos lógicos, e dois índices, i e j, e armazene em B os valores
existentes em A[i] até A[j]*/

#include <stdio.h>

void cria_vetor(int vetor[], int *tamanho) {
    printf("\nQual o tamanho do vetor? ");
    scanf("%d", &*tamanho);
    
    for(int i = 0; i < *tamanho; i++) {
        printf("Digite o elemento de índice %d: ", i);
        scanf("%d", &vetor[i]);
    }
}

void escreve_vetor(int vetor[], int tamanho_vetor) {
    printf("[");
    for(int i = 0; i < tamanho_vetor; i++) {
        printf("%d", vetor[i]);
        if (i < tamanho_vetor - 1) {
            printf(", ");
        }
    }
    printf("]");
}

void subvetor(int vetor[], int ini, int fim, int novo[], int *tamanho_novo) {
    int i, j;
    for(i = ini, j = 0; i<=fim; i++, j++){
        novo[j] = vetor[i];
    }
    *tamanho_novo = j;
}

int main() {
    int vetor[50], novo[50];
    int tamanho_logico, ini, fim, tamanho_novo;
    cria_vetor(vetor, &tamanho_logico);
    printf("\nVetor: ");
    escreve_vetor(vetor, tamanho_logico); 
    printf("\n\nInício do Subvetor (Valor entre 0 e %d): ", tamanho_logico - 1);
    scanf("%d", &ini);
    printf("\nFim do Subvetor (Valor entre %d e %d): ", ini, tamanho_logico - 1);
    scanf("%d", &fim);
    subvetor(vetor, ini, fim, novo, &tamanho_novo);
    printf("\nSubvetor: ");
    escreve_vetor(novo, tamanho_novo);

    return 0;
}
