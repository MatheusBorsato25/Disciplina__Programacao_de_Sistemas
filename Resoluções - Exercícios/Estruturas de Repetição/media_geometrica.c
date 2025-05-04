/*Faça um algoritmo que receba N valores e calcule a média geométrica dos
valores. A média geométrica entre N números é dada pela raiz N-ésima
do produto dos N valores*/

#include <stdio.h>
#include <math.h>

int main() {
    float numero_atual, media_geometrica, produto = 1, quantidade = 0;
    char controle;
    printf("Deseja inserir um número (s/n): ");
    scanf("%c", &controle);
    while (controle == 's') {
        printf("\nInsira um número: ");
        scanf("%f", &numero_atual);
        produto *= numero_atual;
        quantidade++;
        printf("\nDeseja inserir outro número (s/n): ");
        scanf(" %c", &controle);
    }
    media_geometrica = pow(produto, 1.0/quantidade);
    printf("\nMédia Geométrica = %.2f", media_geometrica);
    return 0;
}