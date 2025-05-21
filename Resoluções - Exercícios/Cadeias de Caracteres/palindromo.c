/*Uma palavra é um palíndromo quando lida tanto da direita para a
esquerda quanto da esquerda para direita resulta na mesma palavra.
Faça um algoritmo que receba uma palavra e avalie se ela é ou não um
palíndromo*/

#include <stdio.h>
#include <string.h>

#define TAM_MAX 100

int eh_palindromo(char palavra[TAM_MAX]) {
    int tamanho = strlen(palavra) - 1;
    int palindromo = 1;
    
    for (int i = 0, j = tamanho; i < j; i++, j--) {
        if (palavra[i] != palavra[j]) {
            palindromo = 0;
        }
    }
    
    return palindromo;
}

int main() {
    char palavra[TAM_MAX];

    printf("\nDigite uma palavra: ");
    scanf("%s", palavra);

    if (eh_palindromo(palavra)) {
        printf("\nÉ palíndromo.\n");
    } else {
        printf("\nNão é palíndromo.\n");
    }

    return 0;
}
