/*Faça um algoritmo que leia um valor inteiro N. Após isso devem ser lidos
N números e informados o maior e o menor dentre os N números lidos*/

#include <stdio.h>

int main() {
    int n;
    float numero, maior, menor;
    printf("Quantos números devem ser lidos? ");
    scanf("%d", &n);
    if (n == 0) {
        printf("\nNenhum número foi lido.");
    } else {
        printf("\nDigite um número: ");
        scanf("%f", &numero);
        maior = numero;
        menor = numero;
        for (int i = 1; i < n; i++) {
            printf("\nDigite um número: ");
            scanf("%f", &numero);
            if (numero > maior) {
                maior = numero;
            }
            if (numero < menor) {
                menor = numero;
            }
        }
        printf("\nMaior = %.1f, Menor = %.1f", maior, menor);
    }
    return 0;
}
