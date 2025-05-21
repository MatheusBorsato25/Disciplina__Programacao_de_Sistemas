/*Faça um algoritmo que gere uma matriz com dimensões aleatórias entre
1 e 10 (por exemplo 5x2), a preencha com Mij = 10*(i+1)*(j+1).
Para gerar o número aleatório utilize a função rand() na biblioteca stdlib*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10

void escreve_matriz(int matriz[TAM][TAM], int n_linhas, int n_colunas){

    for(int i = 0; i < n_linhas; i++){
        for(int j = 0; j < n_colunas; j++){
            printf("%5d ", matriz[i][j]);
        }
        printf("\n");
    }
}
int main(){
    srand(time(NULL));
    
    int n_linhas, n_colunas, matriz[TAM][TAM];
    n_linhas = rand() % TAM;
    n_colunas = rand() % TAM;
    for(int i = 0; i < n_linhas; i++){
        for(int j = 0; j < n_colunas; j++){
            matriz[i][j] = 10 * (i + 1) * (j + 1);
        }
    }
    escreve_matriz(matriz, n_linhas, n_colunas);
}
