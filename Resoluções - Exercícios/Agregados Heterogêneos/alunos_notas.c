/*Faça um algoritmo que receba os nomes e as notas bimestrais de 5
alunos. Depois de armazenar as informações, o algoritmo deverá buscar
a maior nota do 3 bimestre, e exibir o nome do aluno que a obteve*/

#include <stdio.h>

#define QTD_ALUNOS 5
#define BIMESTRES 4
#define TAM_NOME 100

struct Aluno {
    char nome[TAM_NOME];
    float notas[BIMESTRES];
};

void ler_dados(struct Aluno alunos[], int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("Nome: ");
        scanf("%s", alunos[i].nome);
        for (int j = 0; j < BIMESTRES; j++) {
            printf("Nota do %dº bimestre: ", j + 1);
            scanf("%f", &alunos[i].notas[j]);
        }
    }
}

int indice_maior_nota_3_bimestre(struct Aluno alunos[], int quantidade) {
    int indice = 0;
    float maior = alunos[0].notas[2];

    for (int i = 1; i < quantidade; i++) {
        if (alunos[i].notas[2] > maior) {
            maior = alunos[i].notas[2];
            indice = i;
        }
    }
    return indice;
}

int main() {
    struct Aluno alunos[QTD_ALUNOS];
    ler_dados(alunos, QTD_ALUNOS);

    int indice = indice_maior_nota_3_bimestre(alunos, QTD_ALUNOS);

    printf("\nMaior nota do 3º bimestre: %.2f\n", alunos[indice].notas[2]);
    printf("Aluno que obteve essa nota: %s\n", alunos[indice].nome);

    return 0;
}
