/*Faça um programa que receba um número e informe se ele é divisível por 10,
por 5 ou por 2. Caso o número seja divisível por mais de um destes valores,
todos devem ser mostrados, e caso nenhum seja divisível não é necessário
exibir nenhuma mensagem*/

#include <stdio.h>

int main() {
    int numero;
    printf("Digite um número: ");
    scanf("%d", &numero);

    if (numero % 10 == 0) {
        printf("\n%d é divisível por 10, 5 e 2.", numero);
    } else {
        if (numero % 5 == 0) {
            printf("\n%d é divisível por 5.", numero);
        }
        if (numero % 2 == 0) {
            printf("\n%d é divisível por 2.", numero);
        }
    }

    return 0;
}
