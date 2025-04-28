/*Faça um programa que receba um número e imprima na tela se tal número é
par ou ímpar*/

#include <stdio.h>

int main() {
    int numero; 
    printf("Digite um número: ");
    scanf("%d", &numero);
    
    if (numero % 2 == 0){
        printf("%d é par.", numero);
    } else {
        printf("%d é ímpar.", numero);
    }
    return 0;
}
