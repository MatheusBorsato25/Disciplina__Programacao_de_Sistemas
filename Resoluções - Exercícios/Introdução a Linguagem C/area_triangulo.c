/*Escreva um programa em C que receba a base e a altura de um triângulo e
exiba sua área*/

#include <stdio.h>

int main() {
    float base, altura, area;
    printf("Base do Triângulo: ");
    scanf("%f", &base);
    printf("Altura do Triângulo: ");
    scanf("%f", &altura);
    area = (base * altura)/2.0;
    printf("A área do triângulo é %.2f.", area);

    return 0;
}