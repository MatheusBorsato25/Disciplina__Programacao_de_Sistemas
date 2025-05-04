/*Faça um procedimento para o cálculo do fatorial de um número. Seu
procedimento deve ter 2 parâmetros, um para receber o valor N, e outro
deverá ser usado para retornar N!*/

#include <stdio.h>

void fatorial(int n, double *resultado) {
    *resultado = 1;
    for (int i = 1; i <= n; i++) {
        *resultado *= i;
    }
}

int main() {
    int numero;
    double fat;
    printf("Digite um número inteiro não-negativo: ");
    scanf("%d", &numero);
    
    fatorial(numero, &fat);
    printf("\nFatorial de %d é: %.0lf.", numero, fat);
    return 0;
}
