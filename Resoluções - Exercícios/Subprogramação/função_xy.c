/*Faça uma função que receba x e y inteiros e calcule:
F(x,y) = x^y + y^x*/

#include <stdio.h>

int potencia(int base, int expoente) {
    int resultado = 1;
    
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
    int x, y, resultado;
    printf("Vamos calcular x^y + y^x: \n");
    printf("\nDigite x: ");
    scanf("%d", &x);
    printf("Digite y: ");
    scanf("%d", &y);
    resultado = potencia(x, y) + potencia(y, x);
    printf("\nO resultado é %d.", resultado);
    return 0;
}
