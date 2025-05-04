/*Sabe-se que a série de taylor usada para calcular o valor da função
cosseno é dada pela seguinte somatória...
Faça um algoritmo que calcule a função cosseno de x somando os 10
primeiros termos da somatória*/

#include <stdio.h>
#include <math.h>

double fatorial(int n) {
    double fat = 1;
    for (int i = 1; i <= n; i++) {
        fat *= i;
    }
    return fat;
}

int main() {
    double x, termo, cos_x = 0;
    int termos = 10;
    printf("Digite o valor de x (em radianos): ");
    scanf("%lf", &x);

    for (int n = 0; n < termos; n++) {
        termo = pow(-1, n) * pow(x, 2 * n) / fatorial(2 * n);
        cos_x += termo;
    }

    printf("Aproximação de cos(%.4lf) com %d termos: %.8f\n", x, termos, cos_x);
    printf("Valor real de cos(%.4lf) usando math.h: %.8f\n", x, cos(x));

    return 0;
}