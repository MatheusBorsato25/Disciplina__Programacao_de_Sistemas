/*Escreva um programa em C que receba o valor do raio de uma circunferência e
exiba sua área (considere pi = 3.14)*/

#include <stdio.h>

int main() {
    float pi = 3.14;
    float raio, area;
    printf("Digite o raio da circunferência: ");
    scanf("%f", &raio);
    area = pi * raio * raio;
    printf("A área da circunferência é %.2f.", area);
    
    return 0;
}
