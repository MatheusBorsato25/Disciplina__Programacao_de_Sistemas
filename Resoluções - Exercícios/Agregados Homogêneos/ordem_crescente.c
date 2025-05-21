/*Faça um subprograma que receba um vetor e verifique se ele está
ordenado de maneira crescente*/

#include <stdio.h>

void cria_vetor(int vetor[], int *tamanho) {
    printf("\nQual o tamanho do vetor? ");
    scanf("%d", &*tamanho);
    
    for(int i = 0; i < *tamanho; i++) {
        printf("Digite o elemento de índice %d: ", i);
        scanf("%d", &vetor[i]);
    }
}

void verifica_ordem(int vetor[], int tamanho_logico) {
    int i = 0, ordem = 1;
    
    while (i < tamanho_logico - 1) {
        int j = i + 1;
        if (vetor[j] <= vetor[i]) {
            ordem = 0;
            break;
        }
        i++;
    }
    
    if (ordem == 0) {
        printf("\nO vetor não está ordenado!");
    } else {
        printf("\nO vetor está ordenado!");
    }
}

int main()
{
    int vetor[50];
    int tamanho_logico;
    cria_vetor(vetor, &tamanho_logico);
    verifica_ordem(vetor, tamanho_logico);

    return 0;
}
