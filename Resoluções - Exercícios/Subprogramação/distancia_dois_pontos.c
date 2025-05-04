/*Faça uma função que receba os valores x1, y1 e x2, y2 pontos cartesianos e
calcule a distância euclidiana entre os pontos. Faça uma chamada da
função que receba como parâmetros os valores informados pelo usuário
e retorne o valor em uma variável*/

#include <stdio.h>
#include <math.h>

double distancia(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    double x1, y1, x2, y2, d;

    printf("Digite o valor de x1: ");
    scanf("%lf", &x1);
    printf("Digite o valor de y1: ");
    scanf("%lf", &y1);
    printf("Digite o valor de x2: ");
    scanf("%lf", &x2);
    printf("Digite o valor de y2: ");
    scanf("%lf", &y2);

    d = distancia(x1, y1, x2, y2);

    printf("\nA distância entre os pontos é: %.4f\n", d);

    return 0;
}
