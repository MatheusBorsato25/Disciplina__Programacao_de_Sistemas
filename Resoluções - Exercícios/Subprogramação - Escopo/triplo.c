/*Faça um algoritmo que use um procedimento para a leitura de uma
variável global, e após isso chame uma função que retorne o triplo do
valor lido e escreva o resultado na tela*/

#include <stdio.h>

int valor;

// Função que retorna o triplo
int triplo() {
    return valor * 3;
}

int main() {
    printf("Digite um número: ");
    scanf("%d", &valor);
    int resultado = triplo();
    printf("\nO triplo de %d é %d.\n", valor, resultado);
    return 0;
}
