#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct no {
    int ref;
    struct no *proximo;
}No;

No* push(No *topo, int num){
    No novo = (No)malloc(sizeof(No));
    if(novo){
        novo-ref = num;
        novo->proximo = topo;
        return novo;
}
    else{
        printf("***Erro ao alocar memoria***");
    }
    return NULL;
}

int main void (void){
    No *topo = NULL;
    topo = push(topo, 1);
    return 0;
}
