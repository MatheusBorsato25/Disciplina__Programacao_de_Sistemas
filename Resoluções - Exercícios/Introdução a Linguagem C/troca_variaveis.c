/*Faça um programa em C que receba duas variáveis, A e B, e troque o valor de
ambas*/

#include <stdio.h>

int main() {
    int A, B, aux;
    printf("Digite o valor de A: ");
    scanf("%d", &A);
    printf("Digite o valor de B: ");
    scanf("%d", &B);
    aux = A;
    A = B;
    B = aux;
    printf("\nA = %d e B = %d", A, B);
    return 0;
}
