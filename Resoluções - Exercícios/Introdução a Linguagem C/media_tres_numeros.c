/*Escreva um programa em C que receba 3 números inteiros e informe a média
aritmética entre eles.*/

#include <stdio.h>

int main() {
    int a, b, c;
    printf("Primeiro Número: ");
    scanf("%d", &a);
    printf("Segundo Número: ");
    scanf("%d", &b);
    printf("Terceiro Número: ");
    scanf("%d", &c);
    float media = (a + b + c)/3.0;
    printf("\nA média entre %d, %d e %d é %.2f", a, b, c, media);
    return 0;
}
