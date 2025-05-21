/*Faça um algoritmo que receba dois pontos p e q e troque o valor de p e q*/

#include <stdio.h>

struct Ponto {
    float x;
    float y;
};

void determina_coordenadas(struct Ponto *p) {
    printf("\nCoordenada x: ");
    scanf("%f", &p->x);
    printf("Coordenada y: ");
    scanf("%f", &p->y);
}

void troca_pontos(struct Ponto *p1, struct Ponto *p2) {
    float auxiliar;
    
    auxiliar = p1->x;
    p1->x = p2->x;
    p2->x = auxiliar;
    
    auxiliar = p1->y;
    p1->y = p2->y;
    p2->y = auxiliar;
}

int main() {
    struct Ponto p1;
    struct Ponto p2;
    
    printf("\nPonto 1: ");
    determina_coordenadas(&p1);
    printf("\nPonto 2: ");
    determina_coordenadas(&p2);
    printf("\nPonto 1: [%.1f, %.1f]", p1.x, p1.y);
    printf("\nPonto 2: [%.1f, %.1f]\n", p2.x, p2.y);
    troca_pontos(&p1, &p2);
    printf("\nDepois da Troca:\n");
    printf("\nPonto 1: [%.1f, %.1f]", p1.x, p1.y);
    printf("\nPonto 2: [%.1f, %.1f]\n", p2.x, p2.y);
    
    return 0;
}
