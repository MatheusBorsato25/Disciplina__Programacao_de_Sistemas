/*Faça um procedimento que receba um valor a e um valor b e escreva
todos números no intervalo [a,b], e faça uma chamada do procedimento
para valores informados pelo usuário*/

#include <stdio.h>

void imprimeIntervalo(int a, int b) {
    printf("Números no intervalo [%d, %d]: \n", a, b);
    for (int i = a; i <= b; i++) {
        printf("%d ", i);
    }
}

int main() {
    int a, b;

    printf("Digite o valor de a: ");
    scanf("%d", &a);

    printf("Digite o valor de b: ");
    scanf("%d", &b);

    imprimeIntervalo(a, b); 
    
    return 0;
}
