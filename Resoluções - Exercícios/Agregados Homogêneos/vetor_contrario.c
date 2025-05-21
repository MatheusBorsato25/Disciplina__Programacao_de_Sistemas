/*Faça um procedimento que receba um vetor e seu tamanho lógico e o
escreva de trás para frente*/

#include <stdio.h>

void cria_vetor(int vetor[], int *tamanho) {
    printf("\nQual o tamanho do vetor? ");
    scanf("%d", &*tamanho);
    
    for(int i = 0; i < *tamanho; i++) {
        printf("Digite o elemento de índice %d: ", i);
        scanf("%d", &vetor[i]);
    }
}

void escreve_vetor_contrario(int vetor[], int tamanho_logico) {
    printf("[");
    for(int i = tamanho_logico - 1; i >= 0; i--) {
        printf("%d", vetor[i]);
        if (i > 0) {
            printf(", ");
        }
    }
    printf("]");
}

int main() {
    int vetor[50];
    int tamanho_logico;
    cria_vetor(vetor, &tamanho_logico);
    
    printf("\nVetor Contrário: ");
    escreve_vetor_contrario(vetor, tamanho_logico);

    return 0;
}
