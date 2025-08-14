
#ifndef __FILA_H__
#define __FILA_H__

struct no_fila{
	int dado;
	struct no_fila *prox;
};

/*
	Estrutura para armazenar os ponteiros de primeiro e ultimo da lista
*/
struct fila{
	struct no_fila *primeiro, *ultimo;
};


/*recebe uma fila e inicializa ela, numa fila vazia*/
void inicializa_fila(struct fila *f);

/*retorna 1 se a fila está vazia, ou 0 caso contrário*/
int fila_vazia(struct fila *f);

/*Insere d no final da fila. Retorna 1 se foi possível inserir, 0 caso contrário
Não se esqueça de alterar o tipo de dado a ser inserido na fila*/
int enfileira(struct fila *f, int d);

/*Remove o primeiro da fila. Retorna 1 se foi possível remover, 0 caso contrário*/
int desenfileira(struct fila *f);

/*Obtém os dados do primeiro elemento da fila e amazena em ret.
Além disso, a função retorna 1 quando conseguiu obter o primeiro, ou 0 quando não foi
possível obter o primeiro elemento (fila vazia) */
int primeiro(struct fila *f, int *ret);

/*verifica se o valor v está presente no campo dado de algum nó da fila*/
int busca_fila(struct fila *f, int v);

/*imprime o conteúdo da fila com o valor mais a esquerda sendo o primeiro da fila*/
void escreve_fila(struct fila *f);

#endif
