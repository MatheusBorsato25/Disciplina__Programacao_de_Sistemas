/*A Chevrolet abriu uma linha de crédito para compra de carros. O valor
máximo da prestação não poderá ultrapassar 40% do salário bruto do cliente.
Faça um programa que receba o salário bruto do cliente e o valor da
prestação como entrada, e informe se o crédito pode ou não ser concedido*/

#include <stdio.h>

int main() {
    float salario, prestacao;
    printf("Digite o salário bruto: ");
    scanf("%f", &salario);
    printf("Digite o valor da prestação: ");
    scanf("%f", &prestacao);

    if (prestacao > 0.4 * salario) {
        printf("\nCrédito negado.");
    } else {
        printf("\nCrédito concedido.");
    }
    return 0;
}
