/*Faça um algoritmo que receba dois números reais e qual operação deve ser
efetuado sobre os dois : soma (+), subtração (-), multiplicação (*), divisão (/),
potenciação (^) e mostre o resultado*/

#include <stdio.h>
#include <math.h>

int main() {
    float num1, num2, resultado;
    char operacao;
    printf("Escolha a operação (+, -, *, /, ^): ");
    scanf("%c", &operacao); 
    printf("Digite o primeiro número: ");
    scanf("%f", &num1);
    printf("Digite o segundo número: ");
    scanf("%f", &num2);
 

    switch (operacao) {
        case '+':
            resultado = num1 + num2;
            printf("\nResultado: %.2f", resultado);
            break;
        case '-':
            resultado = num1 - num2;
            printf("\nResultado: %.2f", resultado);
            break;
        case '*':
            resultado = num1 * num2;
            printf("\nResultado: %.2f", resultado);
            break;
        case '/':
            if (num2 != 0) {
                resultado = num1 / num2;
                printf("\nResultado: %.2f", resultado);
            } else {
                printf("\nErro: Divisão por zero não permitida.");
            }
            break;
        case '^':
            resultado = pow(num1, num2);
            printf("\nResultado: %.2f", resultado);
            break;
        default:
            printf("\nOperação inválida.");
            break;
    }
    return 0;
}