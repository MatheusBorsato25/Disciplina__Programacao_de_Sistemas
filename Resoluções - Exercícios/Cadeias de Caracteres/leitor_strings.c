/*Faça um algoritmo que receba strings até que o usuário insira a string
vazia. Em seguida, mostre todas as strings recebidas e seus respectivos
tamanhos*/

#include <stdio.h>
#include <string.h>

#define TAM_MAX 100
#define QTD_MAX 50

int main() {
    char strings[QTD_MAX][TAM_MAX];
    int contador = 0, continua = 1;

    printf("\nDigite as strings (pressione ENTER para encerrar):\n");

    while (continua) {
        printf("String %d: ", contador + 1);
        fgets(strings[contador], TAM_MAX, stdin);

        if (strlen(strings[contador]) < 2) {
            continua = 0;
        } else {
            contador++;
        }
    }

    printf("\nStrings digitadas e seus tamanhos:\n\n");
    for (int i = 0; i < contador; i++) {
        printf("String %d: %s   (Tamanho: %zu)\n", i + 1, strings[i], strlen(strings[i]) - 1);
    }

    return 0;
}
