/*Dado um número inteiro faça um algoritmo que calcule a soma de seus
dígitos*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int numero, digito, soma = 0;
    printf("Digite um número inteiro: ");
    scanf("%d", &numero);

    while (numero != 0) {
        digito = numero % 10;   
        soma += digito;          
        numero /= 10;    // truncamento      
    }

    printf("\nSoma dos dígitos = %d.", abs(soma));

    return 0;
}
