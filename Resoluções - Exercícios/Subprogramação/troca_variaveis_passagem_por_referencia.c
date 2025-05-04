/*Faça um procedimento que receba duas variáveis e troque o valor das
duas. Ao voltar para o local que foi chamado as variáveis passadas como
parâmetro devem manter seus valores invertidos*/

#include <stdio.h>

void troca(int *a, int *b) {
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

int main() {
    int a, b;
    printf("Digite um valor (a): ");
    scanf("%d", &a);
    printf("Digite outro valor (b): ");
    scanf("%d", &b);   
    troca(&a, &b);
    printf("\nVariáveis invertidas: ");
    printf("a = %d, b = %d.", a, b);
    return 0;
}
