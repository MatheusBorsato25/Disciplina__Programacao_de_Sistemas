/*Faça um programa em C que receba um ângulo em radianos e mostre o
valor do seno e cosseno deste número*/

#include <stdio.h>
#include <math.h>

int main() {
    float angulo, seno, cosseno;
    printf("Digite o ângulo em radianos: ");
    scanf("%f", &angulo);
    seno = sin(angulo);
    cosseno = cos(angulo);
    printf("\nO seno de %frad é %.2f", angulo, seno);
    printf("\nO cosseno de %frad é %.2f", angulo, cosseno);
    return 0;
}