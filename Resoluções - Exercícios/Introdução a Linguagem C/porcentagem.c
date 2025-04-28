/*Faça um programa em C que obtenha dois números, N e P, e informe P% de N.
Exemplo: se o valor digitado para P for 20 e o valor digitado para N for 70, o
resultado exibido deverá ser 14, pois 20% de 70 é 14.*/

#include <stdio.h>

int main()
{
    int N, P;
    printf("Cálculo de P%% de N: ");
    printf("\nDigite P: ");
    scanf("%d", &P);
    printf("Digite N: ");
    scanf("%d", &N);
    float calculo = (P / 100.0) * N;
    printf("\n%d%% de %d equivale a %.2f", P, N, calculo);

    return 0;
}
