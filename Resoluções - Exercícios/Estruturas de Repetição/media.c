/*Faça um algoritmo para calcular a média de um conjunto de números
informado pelo usuário. A cada novo número informado deve-se
perguntar ao usuário se ele deseja inserir mais um número*/

#include <stdio.h>

int main() {
    float numero_atual, media, soma = 0, quantidade = 0;
    char controle;
    printf("Deseja inserir um número (s/n): ");
    scanf("%c", &controle);
    while (controle == 's') {
        printf("\nInsira um número: ");
        scanf("%f", &numero_atual);
        soma += numero_atual;
        quantidade++;
        printf("\nDeseja inserir outro número (s/n): ");
        scanf(" %c", &controle);
    }
    media = soma / quantidade;
    printf("\nMédia = %.2f", media);
    return 0;
}