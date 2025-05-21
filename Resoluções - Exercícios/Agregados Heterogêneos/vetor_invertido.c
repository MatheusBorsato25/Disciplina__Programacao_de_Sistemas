/*Faça uma função que receba um registro contendo um vetor e seu
tamanho lógico e retorne o vetor invertido*/

#include <stdio.h>
#define TAM 100

struct Vetor {
    int numeros[TAM];
    int tamanho_logico;
};

void cria_vetor(struct Vetor *v) {
    printf("\nQual o tamanho do vetor? ");
    scanf("%d", &v->tamanho_logico);
    
    for(int i = 0; i < v->tamanho_logico; i++) {
        printf("Digite o elemento de índice %d: ", i);
        scanf("%d", &v->numeros[i]);
    }
}

void escreve_vetor(struct Vetor v) {
    printf("[");
    for(int i = 0; i < v.tamanho_logico; i++) {
        printf("%d", v.numeros[i]);
        if (i < v.tamanho_logico - 1) {
            printf(", ");
        }
    }
    printf("]");
}

void inverte_vetor(struct Vetor *v) {
    int inicio = 0;
    int fim = v->tamanho_logico - 1;
    while (inicio < fim) {
        int temp = v->numeros[inicio];
        v->numeros[inicio] = v->numeros[fim];
        v->numeros[fim] = temp;
        inicio++;
        fim--;
    }
}

int main() {
    struct Vetor v;
    cria_vetor(&v);
    printf("\nVetor Original: ");
    escreve_vetor(v);
    inverte_vetor(&v);
    printf("\nVetor Invertido: ");
    escreve_vetor(v);    
    
    return 0;
}
