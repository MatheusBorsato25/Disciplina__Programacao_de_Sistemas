/*Faça uma função que receba um vetor e retorne a média de seus
elementos*/

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

float media_vetor(int vetor[], int tamanho_logico) {
    float soma = 0;
    
    for(int i = 0; i < tamanho_logico; i++) {
        soma += vetor[i];
    }
    
    float media = soma / tamanho_logico;
    return media;
}
int main() {
    int vetor[50];
    int tamanho_logico;
    cria_vetor(vetor, &tamanho_logico);
    printf("\nVetor: ");
    escreve_vetor(vetor, tamanho_logico);
    printf("\nA média dos elementos é: %.2f", media_vetor(vetor, tamanho_logico));
    
    return 0;
}
