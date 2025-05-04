/*Use o procedimento do exercício dois para imprimir as tabuadas de 1 a
10*/

#include <stdio.h>

void imprimeTabuada(int num) {
    printf("\n\nTabuada do número %d:\n", num);
    for (int i = 0; i <= 10; i++) {
        int resultado = num * i;
        printf("\n%d X %d = %d", num, i, resultado);
    }
}

int main() {
    for (int i = 0; i <= 10; i++) {
        imprimeTabuada(i);
    }
    return 0;
}
