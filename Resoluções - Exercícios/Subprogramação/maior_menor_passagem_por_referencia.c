/*Faça um procedimento que receba 3 parâmetros passados por valor e 2
por referência. Seu procedimento deverá armazenar em um dos dois
parâmetros por referência o maior dos 3 parâmetros passados por cópia,
e o menor no outro*/

#include <stdio.h>

void maior_menor(int n1, int n2, int n3, int *maior, int *menor){
    if(n1 > n2){
        *maior = n1;
        *menor = n2;
    } else {
        *maior = n2;
        *menor = n1;
    }
    if(n3 > *maior){
        *maior = n3;
    } else if(n3 < *menor){
        *menor = n3;
    }
}

int main(){
    int n1, n2, n3, max, min;
    printf("Digite o 1º número: ");
    scanf("%d",&n1);
    printf("Digite o 2º número: ");
    scanf("%d",&n2);
    printf("Digite o 3º número: ");
    scanf("%d",&n3);
    
    maior_menor(n1, n2, n3, &max, &min);
    printf("\nMaior: %d, Menor: %d.", max, min);
    return 0;
}
