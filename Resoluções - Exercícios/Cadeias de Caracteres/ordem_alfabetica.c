/*Faça um algoritmo que receba um valor N e os nomes de alunos N
alunos. Após isso, seu algoritmo deve mostrar qual seria a primeira
pessoa na na lista de chamada*/

#include <stdio.h>
#include <string.h>

#define TAM_MAX 100
#define QTD_MAX 50

void recebe_nomes(char strings[QTD_MAX][TAM_MAX], int *quantidade) {
    printf("\nQuantidade de nomes a serem digitados: ");
    scanf("%d", &*quantidade);
    int i = 0;
    getchar();
    
    while (i < *quantidade) {
        printf("Nome %d: ", i + 1);
        fgets(strings[i], TAM_MAX, stdin);
        i++;
    }
}

// Devolve o índice do menor nome:
int ordem_alfabetica(char strings[QTD_MAX][TAM_MAX], int quantidade) {
    int indice = 0;
    
    for (int i = 1; i < quantidade; i++) {
        if (strcmp(strings[indice], strings[i]) > 0) {
            indice = i;
        }
    }
    return indice;
}

int main() {
    char strings[QTD_MAX][TAM_MAX];
    int quantidade;
    recebe_nomes(strings, &quantidade);
    
    if (quantidade < 1) {
        printf("\nNão há nomes recebidos!");
    } else {
        int indice_menor = ordem_alfabetica(strings, quantidade);
        printf("\nPrimeira pessoa na lista de chamada: %s", strings[indice_menor]);
    }
    
    return 0;
}
