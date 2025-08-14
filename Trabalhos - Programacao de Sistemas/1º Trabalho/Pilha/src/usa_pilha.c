#include "pilha.h"
#include <stdio.h>

int main(){
    struct pilha p;
    int r;
    inicializa_pilha(&p);
    int numeros[]={8,2,3,5,1};
    for(int i=0;i<5;i++){
        empilha(&p, numeros[i]);
        mostra_pilha(&p);
    }
    desempilha(&p,&r);
    desempilha(&p,&r);
    mostra_pilha(&p);
    printf("Topo da Pilha: %d", topo(&p));
    printf("\nO 2 está na pilha?\n");
    busca_pilha(&p, 2);
    printf("\nO 6 está na pilha?\n");
    busca_pilha(&p, 6);
    empilha(&p, 6);
    printf("\n");
    mostra_pilha(&p);
    printf("\nO 6 está na pilha?\n");
    busca_pilha(&p, 6);
}