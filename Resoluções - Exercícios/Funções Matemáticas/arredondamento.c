/*Faça um programa em C que receba um número real e um valor inteiro N.
Seu programa deverá arredondar o número real com N casas decimais*/

#include <stdio.h>
#include <math.h>

int main() {
    double numero, arredondado;
    int casas;
    printf("Digite um número real: ");
    scanf("%lf", &numero);
    printf("Número de casas decimais: ");
    scanf("%d", &casas);
    arredondado = round(numero * pow(10, casas)) / pow(10, casas);
    printf("O número %lf arredondado para %d casa(s) decimal(is) é %f", numero, casas, arredondado);
    return 0;
}
