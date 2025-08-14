#include "tprotulo.h"

#ifndef __FILA_H__
#define __FILA_H__

struct no_fila{
	TPRotulo dado;
	struct no_fila *prox;
};


struct fila{
	struct no_fila *primeiro, *ultimo;
};

struct fila_hierarquica {
    struct fila *filas;
};

/*recebe uma fila e inicializa ela, numa fila vazia*/
void inicializa_fila(struct fila *f);

/*retorna 1 se a fila está vazia, ou 0 caso contrário*/
int fila_vazia(struct fila *f);

/*Insere M no final da fila. Retorna 1 se foi possível inserir, 0 caso contrário*/
int enfileira(struct fila *f, TPRotulo M);

/*Remove o primeiro da fila. Retorna 1 se foi possível remover, 0 caso contrário*/
int desenfileira(struct fila *f);

/*Obtém os dados do primeiro elemento da fila e armazena em M.
Além disso, a função retorna 1 quando conseguiu obter o primeiro, ou 0 quando não foi
possível obter o primeiro elemento (fila vazia)*/
int primeiro(struct fila *f, TPRotulo *M);

/*verifica se o valor M está presente no campo dado de algum nó da fila*/
int busca_fila(struct fila *f, TPRotulo M);

/*imprime o conteúdo da fila com o valor mais a esquerda sendo o primeiro da fila*/
void escreve_fila(struct fila *f);

#endif
