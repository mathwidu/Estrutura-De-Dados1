#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

struct Produto{
    int codigo;
    char nome[41];
    double preco;
};
struct Produto *p1, p2;

//vou fazer essa função só para mostrar que está tudo funcionando;
void mostrarProduto(struct Produto *produto) {
    printf("Nome: %s\n", produto->nome);
    printf("Código: %d\n", produto->codigo);
    printf("Preço: %.2f\n", produto->preco);
}

int main (void){
    setlocale(LC_ALL, "portuguese");

    p1 = (struct Produto*)malloc(sizeof(struct Produto));
    strcpy(p1->nome, "Leite");
    p1->preco = 1.99;
    p1->codigo = 1001;

    strcpy(p2.nome, "Café");
    p2.preco = 19.80;
    p2.codigo = 1002;

    printf("Dados de p1:\n");
    mostrarProduto(p1);

    printf("\nDados de p2:\n");
    mostrarProduto(&p2);

    free(p1);

    return 0;
}
