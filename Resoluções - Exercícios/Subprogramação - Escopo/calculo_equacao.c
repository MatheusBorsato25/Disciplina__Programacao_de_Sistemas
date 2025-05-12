/*Faça um algoritmo que use uma função para o cálculo da seguinte
equação: f(x,y) = (3x + 5y) / (y + 15)
Use uma variável global para armazenar se o retorno da função está
certo*/

#include <stdio.h>

// Variável global que indica se o cálculo foi feito corretamente
int resultado_correto;

float calcula_equacao(int x, int y) {
    float denominador = y + 15;
    float numerador = 3 * x + 5 * y;

    if (denominador == 0) {
        resultado_correto = 0; // falso
        return 0;
    }
    
    float calculo = numerador / denominador;
    resultado_correto = 1; // verdadeiro   
    
    return calculo;
}

int main() {
    int x, y;
    printf("Digite o valor de x: ");
    scanf("%d", &x);
    printf("Digite o valor de y: ");
    scanf("%d", &y);

    float resultado = calcula_equacao(x, y);

    if (resultado_correto) {
        printf("\nResultado da equação: %.2f\n", resultado);
    } else {
        printf("\nErro no cálculo!\n");
    }

    return 0;
}
