/*Faça um subprograma que receba um vetor e retorne a quantidade de
números pares que o vetor contém*/

#include <stdio.h>

void cria_vetor(int vetor[], int *tamanho) {
    printf("\nQual o tamanho do vetor? ");
    scanf("%d", &*tamanho);
    
    for(int i = 0; i < *tamanho; i++) {
        printf("Digite o elemento de índice %d: ", i);
        scanf("%d", &vetor[i]);
    }
}

int pares(int vetor[], int tamanho_logico) {
    int n_pares = 0;
    for(int i = 0; i < tamanho_logico; i++) {
        if (vetor[i] % 2 == 0) {
            n_pares++;
        }
    }
    return n_pares;
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

int main() {
    int vetor[50];
    int tamanho_logico;
    cria_vetor(vetor, &tamanho_logico);
    printf("\nO vetor ");
    escreve_vetor(vetor, tamanho_logico);
    printf(" possui %d números pares.", pares(vetor, tamanho_logico));

    return 0;
}
