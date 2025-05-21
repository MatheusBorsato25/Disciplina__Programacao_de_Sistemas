/*Faça um subprograma que receba dois vetores e devolva um terceiro
vetor contendo a intersecção de ambos*/

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

int existe(int vetor[], int tamanho, int valor) {
    int existe = 0;
    
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == valor) {
            existe = 1;
            break;
        }
    }
    return existe;
}

void intersecao(int A[], int tamanho_A, int B[], int tamanho_B, int C[], int *tamanho_C) {
    *tamanho_C = 0;
    for (int i = 0; i < tamanho_A; i++) {
        if (existe(B, tamanho_B, A[i])) {
            C[*tamanho_C] = A[i];
            (*tamanho_C)++;
        }
    }
}

int main() {
    int A[50], B[50], C[50];
    int tamanho_A, tamanho_B, tamanho_C;
    
    printf("Vetor A:\n");
    cria_vetor(A, &tamanho_A);
    escreve_vetor(A, tamanho_A);
    
    printf("\n\nVetor B:\n");
    cria_vetor(B, &tamanho_B);
    escreve_vetor(B, tamanho_B);

    intersecao(A, tamanho_A, B, tamanho_B, C, &tamanho_C);

    printf("\n\nInterseção: ");
    escreve_vetor(C, tamanho_C);

    return 0;
}