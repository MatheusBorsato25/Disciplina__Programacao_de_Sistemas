/*Faça um programa em C que receba um ângulo em graus e mostre o
valor do seno e cosseno deste ângulo*/

#include <stdio.h>
#include <math.h>
#define PI 3.14159

int main() {
    float angulo_graus, angulo_radianos, seno, cosseno;
    printf("Digite o ângulo em graus: ");
    scanf("%f", &angulo_graus);
    angulo_radianos = (angulo_graus * PI)/180.0;
    seno = sin(angulo_radianos);
    cosseno = cos(angulo_radianos);
    printf("\nO seno de %.1f° é %.2f", angulo_graus, seno);
    printf("\nO cosseno de %.1f° é %.2f", angulo_graus, cosseno);
    return 0;
}