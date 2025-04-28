/*Faça um programa em C que receba as coordenadas x e y de dois pontos
no plano cartesiano e mostre a distância entre eles*/

#include <stdio.h>
#include <math.h>

int main() {
    int x1,x2,y1,y2;
    printf("1º Ponto:");
    printf("\nx1 = ");
    scanf("%d", &x1);
    printf("y1 = ");
    scanf("%d", &y1);
    printf("\n2º Ponto:");
    printf("\nx2 = ");
    scanf("%d", &x2);
    printf("y2 = ");
    scanf("%d", &y2);
    float distancia = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    printf("A distância entre (%d,%d) e (%d,%d) é %.2f", x1, y1, x2, y2, distancia);
    return 0;
}
