/*Faça um programa que apresente um menu com as seguintes opções:

Calcular combinação entre dois números: C
Calcular Arranjo de dois números: A
Calcular Fatorial de um número: F

Seu programa deve receber a opção desejada, após isso, receber os
dados de entrada necessários, e por fim exibir o resultado*/

#include <stdio.h>

int fatorial(int n) {
    int fat = 1;
    for (int i = 1; i <= n; i++) {
        fat *= i;
    }
    return fat;
}

int combinacao(int n, int p) {
    if (n < p) {
        printf("\nErro: n deve ser maior ou igual a p para calcular a combinação.\n");
        return -1;  // Indica erro
    }
    return fatorial(n) / (fatorial(p) * fatorial(n - p));
}

int arranjo(int n, int p) {
    if (n < p) {
        printf("\nErro: n deve ser maior ou igual a p para calcular o arranjo.\n");
        return -1;  // Indica erro
    }
    return fatorial(n) / fatorial(n - p);
}

int main() {
    char controle = 'S';  // Começa com 'S' para entrar no loop
    char opcao;
    int n, p;

    printf("Olá, seja bem-vindo!\n");

    while (controle == 'S') {
        printf("\nEscolha uma opção:");
        printf("\n\nCalcular combinação (C)");
        printf("\nCalcular arranjo (A)");
        printf("\nCalcular fatorial (F)");
        printf("\n\nOpção (C, A ou F): ");
        scanf(" %c", &opcao);  

        if (opcao == 'C') {
            printf("\nDigite n: ");
            scanf("%d", &n);
            printf("\nDigite p: ");
            scanf("%d", &p);
            int resultado = combinacao(n, p);
            if (resultado != -1) {
                printf("\nC(%d, %d) = %d\n", n, p, resultado);
            }
        } else if (opcao == 'A') {
            printf("\nDigite n: ");
            scanf("%d", &n);
            printf("\nDigite p: ");
            scanf("%d", &p);
            int resultado = arranjo(n, p);
            if (resultado != -1) {
                printf("\nA(%d, %d) = %d\n", n, p, resultado);
            }
        } else if (opcao == 'F') {
            printf("\nDigite o número: ");
            scanf("%d", &n);
            int resultado = fatorial(n);
            printf("\n%d! = %d\n", n, resultado);
        } else {
            printf("\nOpção inválida.\n");
        }
        printf("\nDeseja realizar outra operação? (S/N): ");
        scanf(" %c", &controle);
    }

    printf("\nPrograma Encerrado!");
    return 0;
}
