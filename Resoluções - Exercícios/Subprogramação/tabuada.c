/*Faça um procedimento que receba um número e imprima a tabuada do
número recebido, e faça uma chamada do procedimento para o valor
informado pelo usuário*/

#include <stdio.h>

void imprimeTabuada(int num) {
    printf("\nTabuada do número %d:\n", num);
    for (int i = 0; i <= 10; i++) {
        int resultado = num * i;
        printf("\n%d X %d = %d", num, i, resultado);
    }
}

int main() {
    int num;
    printf("Digite um número: ");
    scanf("%d", &num);

    imprimeTabuada(num); 
    
    return 0;
}
