/*Faça um procedimento que receba um vetor e seu tamanho lógico e
escreva o vetor na tela.*/

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
    printf("\n[");
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
    int tamanho_vetor;
    cria_vetor(vetor, &tamanho_vetor);
    escreve_vetor(vetor, tamanho_vetor);
    return 0;   
}
