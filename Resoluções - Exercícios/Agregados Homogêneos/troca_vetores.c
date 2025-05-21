/*Faça um procedimento que receba dois vetores, seus tamanhos lógicos, e
troque o valor dos dois.*/

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

void troca_vetores(int vetor_a[], int *tamanho_a, int vetor_b[], int *tamanho_b) {
    int vetor_auxiliar[50];
    
    for(int i = 0; i < *tamanho_a; i++) {
        vetor_auxiliar[i] = vetor_a[i];
    }
    for(int j = 0; j < *tamanho_b; j++) {
        vetor_a[j] = vetor_b[j];
    }
    for(int k = 0; k < *tamanho_a; k++) {
        vetor_b[k] = vetor_auxiliar[k];
    }
    
    int aux = *tamanho_a;
    *tamanho_a = *tamanho_b;
    *tamanho_b = aux;
}

int main() {
    
    int vetor_a[50], vetor_b[50];
    int tamanho_a, tamanho_b;
    printf("\nCriação do Vetor A: ");
    cria_vetor(vetor_a, &tamanho_a);
    printf("\nCriação do Vetor B: ");
    cria_vetor(vetor_b, &tamanho_b);
    
    printf("\nVetor A: ");
    escreve_vetor(vetor_a, tamanho_a);
    printf("\nVetor B: ");
    escreve_vetor(vetor_b, tamanho_b);
    
    troca_vetores(vetor_a, &tamanho_a, vetor_b, &tamanho_b);
    
    printf("\n\nDepois da Troca...\n");
    printf("\nVetor A: ");
    escreve_vetor(vetor_a, tamanho_a);
    printf("\nVetor B: ");
    escreve_vetor(vetor_b, tamanho_b);

    return 0;
}
