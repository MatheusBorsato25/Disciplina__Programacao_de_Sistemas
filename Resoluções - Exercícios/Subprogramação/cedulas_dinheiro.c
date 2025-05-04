/*Faça um algoritmo que receba um valor em dinheiro e informe quais as
notas devem ser usadas para que tal valor seja alcançado com o menor
número de notas possíveis. Assuma notas de 100, 50, 20, 10, 5, 2, e 1.
Dica: Use um procedimento com dois argumentos, um por referência e
outro por cópia*/

#include <stdio.h>

void retira_cedulas(int *valor_restante, int cedula) {
    while (*valor_restante >= cedula) {
        printf("%d ", cedula);
        *valor_restante -= cedula;
    }
}

int main() {
    int valor;
    printf("Digite um valor inteiro: ");
    scanf("%d", &valor);

    printf("\nNotas: ");
    retira_cedulas(&valor, 100);
    retira_cedulas(&valor, 50);
    retira_cedulas(&valor, 20);
    retira_cedulas(&valor, 10);
    retira_cedulas(&valor, 5);
    retira_cedulas(&valor, 2);
    retira_cedulas(&valor, 1);
    return 0;
}
