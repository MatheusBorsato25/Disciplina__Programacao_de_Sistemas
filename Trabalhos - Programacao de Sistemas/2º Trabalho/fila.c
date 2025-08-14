#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "tprotulo.h"

/*recebe uma fila e inicializa ela, numa fila vazia*/
void inicializa_fila(struct fila *f){
	f->primeiro = NULL;
	f->ultimo = NULL;
}

/*retorna 1 se a fila está vazia, ou 0 caso contrário*/
int fila_vazia(struct fila *f){
	return f->primeiro == NULL && f->ultimo == NULL;
}

/*Insere M no final da fila. Retorna 1 se foi possível inserir, 0 caso contrário*/
int enfileira(struct fila *f, TPRotulo M){
	struct no_fila *novo;
	novo = (struct no_fila *)malloc(sizeof(struct no_fila));
	if (novo == NULL) {
		return 0;
	}
	novo->dado = M;
	novo->prox = NULL;
	if (fila_vazia(f)) {
		f->primeiro = novo;
		f->ultimo = f->primeiro;
	} else {
		f->ultimo->prox = novo;
		f->ultimo = f->ultimo->prox;
	}
	return 1;
}

/*Remove o primeiro da fila. Retorna 1 se foi possível remover, 0 caso contrário*/
int desenfileira(struct fila *f){
	if (fila_vazia(f)){
		return 0;
	}
	struct no_fila *del = f->primeiro;
	f->primeiro = del->prox;
	free(del);
	if (f->primeiro == NULL) {
		f->ultimo = NULL;
	}
	return 1;
}

/*Obtém os dados do primeiro elemento da fila e armazena em M.
Além disso, a função retorna 1 quando conseguiu obter o primeiro, ou 0 quando não foi
possível obter o primeiro elemento (fila vazia) */
int primeiro(struct fila *f, TPRotulo *M){
	if (fila_vazia(f)) {
		return 0;
	} else {
		*M = f->primeiro->dado;
		return 1; 
	}
}

/*verifica se o valor M está presente no campo dado de algum nó da fila*/
int busca_fila(struct fila *f, TPRotulo M){
    struct no_fila *aux = f->primeiro;
    while(aux != NULL){
        if(aux->dado.L == M.L &&
            aux->dado.C == M.C &&
            aux->dado.rotulo == M.rotulo){
            return 1;
        }
        aux = aux->prox;
    }
    return 0;
}

/*imprime o conteúdo da fila com o valor mais a esquerda sendo o primeiro da fila*/
void escreve_fila(struct fila *f){
    struct no_fila *aux = f->primeiro;
    while(aux != NULL){
        printf("(L=%d, C=%d, Rótulo=%d) ", aux->dado.L, aux->dado.C, aux->dado.rotulo);
    	aux = aux->prox;
    }
    printf("\n");
}
