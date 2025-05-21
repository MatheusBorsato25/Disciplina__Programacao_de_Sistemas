/*Faça um algoritmo que leia dois pontos e calcule a distância euclidiana
entre eles*/

#include <stdio.h>
#include <math.h>

struct Ponto {
    float x;
    float y;
};

float distancia(struct Ponto p1, struct Ponto p2) {
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    return sqrt(pow(dx, 2) + pow(dy, 2));
}

int main() {
    struct Ponto p1;
    struct Ponto p2;
    
    printf("\nDigite a coordenada x do primeiro ponto: ");
    scanf("%f", &p1.x);
    printf("\nDigite a coordenada y do primeiro ponto: ");
    scanf("%f", &p1.y);
    
    printf("\nDigite a coordenada x do segundo ponto: ");
    scanf("%f", &p2.x);
    printf("\nDigite a coordenada y do segundo ponto: ");
    scanf("%f", &p2.y);
    
    float dist = distancia(p1, p2);
    printf("\nA distância euclidiana entre os pontos é: %.2f\n", dist);

    return 0;
}
