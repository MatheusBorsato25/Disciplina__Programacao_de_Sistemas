/*Faça um programa que receba 3 números e os imprima ordenados*/

#include <stdio.h>

int main() {
    int n1, n2, n3, aux;
    printf("Digite três números: ");
    printf("\nPrimeiro: ");
    scanf("%d", &n1);
    printf("Segundo: ");
    scanf("%d", &n2);
    printf("Terceiro: ");
    scanf("%d", &n3);
    
    if (n1 > n2) {
        aux = n1;
        n1 = n2;
        n2 = aux;
    }  
    if (n2 > n3) {
        aux = n2;
        n2 = n3;
        n3 = aux;
    }
    if (n1 > n2) {
        aux = n1;
        n1 = n2;
        n2 = aux;
    }
    printf("\nNúmeros em ordem crescente: %d, %d, %d.", n1, n2, n3);
    return 0;
}
