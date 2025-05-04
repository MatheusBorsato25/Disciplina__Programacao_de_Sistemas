/*Faça uma função que receba uma base B e um expoente E e calcule B^E
sendo E inteiro. Utilize a função para calcular Xy com x e y informados
pelo usuário*/

#include <stdio.h>

double potencia(double base, int expoente) {
    double resultado = 1;
    
    if (expoente > 0) {
        for (int i = 0; i < expoente; i++) {
            resultado *= base;
        }
    } else if (expoente < 0) {
        for (int i = 0; i > expoente; i--) {
            resultado /= base;
        }
    } else {  // Expoente = 0;
        resultado = 1;
    }
    return resultado;
}

int main() {
    double x, resultado;
    int y;
    printf("Digite a base: ");
    scanf("%lf", &x);
    printf("Digite o expoente inteiro: ");
    scanf("%d", &y);

    resultado = potencia(x, y);

    printf("\n%.2lf elevado a %d = %.4lf\n", x, y, resultado);
    return 0;
}

