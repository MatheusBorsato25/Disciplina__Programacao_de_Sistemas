/*Dado um par de coordenada cartesiana (x,y), faça um algoritmo que
determine em qual quadrante, ou sobre qual eixo, está o par*/

#include <stdio.h>

int main() {
    float x, y;
    printf("Digite a coordenada x: ");
    scanf("%f", &x);
    printf("Digite a coordenada y: ");
    scanf("%f", &y);

    if (x == 0.0 && y == 0.0) {
        printf("\nO ponto está na origem.");
    } else if (x == 0.0) {
        printf("\nO ponto está sobre o eixo y.");
    } else if (y == 0.0) {
        printf("\nO ponto está sobre o eixo x.");
    } else if (x > 0.0 && y > 0.0) {
        printf("\nO ponto está no 1º quadrante.");
    } else if (x < 0.0 && y > 0.0) {
        printf("\nO ponto está no 2º quadrante.");
    } else if (x < 0.0 && y < 0.0) {
        printf("\nO ponto está no 3º quadrante.");
    } else {
        printf("\nO ponto está no 4º quadrante.");
    }
    return 0;
}
