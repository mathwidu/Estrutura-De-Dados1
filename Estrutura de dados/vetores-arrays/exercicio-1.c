#include <locale.h>
#include <stdio.h>
struct Produto
{
    char nome[50];
    float preco;
};
void lerProdutos(struct Produto produtos[], int numProdutos)
{
    for (int i = 0; i < numProdutos; i++)
    {
        printf("Digite o nome do produto %d: ", i + 1);
        scanf("%s", produtos[i].nome);

        printf("Digite o preço do produto %d: ", i + 1);
        scanf("%f", &produtos[i].preco);
    }
}
void ListaProdutos(struct Produto produtos[], int numProdutos)
{
    printf("Lista de produtos\n");
    for (int i = 0; i < numProdutos; i++){
        printf("%s: R$ %.2f\n", produtos[i].nome, produtos[i].preco);
    }
}
float ProdutoMaisCaro (struct Produto produtos[], int numProdutos)
{
    float maior = produtos[0].preco;
    for (int i = 1; i<numProdutos; i++){
        if (maior < produtos[i].preco){
            maior = produtos[i].preco;
        }
    }
    printf("O preço do maior produto é: %.2fR$\n", maior);
    return maior;
}
float ProdutoMaisBarato (struct Produto produtos[], int numProdutos)
{
    float menor = produtos[0].preco;
    for (int i = 1; i<numProdutos; i++){
        if (menor>produtos[i].preco){
            menor = produtos[i].preco;
        }
    }
    printf("O do produto de menor preço é: %.2fR$\n", menor);
    return menor;
}
float ProdutoTotal (struct Produto produtos[], int numProdutos)
{
    float total = 0;
    for (int i = 0; i<numProdutos; i++){
        total += produtos[i].preco;
    }
    printf("o preço total de todos os produtos é: %.2fR$\n", total);
    return total;
}
float ProdutoMedia (struct Produto produtos[], int numProdutos)
{
    float total = 0;
    float media = 0;
    for (int i = 0; i<numProdutos; i++){
        total += produtos[i].preco;
    }
    media = total/numProdutos;
    printf("a media de todos os produtos é: %.2fR$\n", media);
    return total;
}

int main (void)
{
    setlocale(LC_ALL, "portuguese");

    struct Produto produtos[5];

    lerProdutos(produtos, 5);

    ListaProdutos(produtos, 5);

    ProdutoMaisCaro(produtos, 5);

    ProdutoMaisBarato(produtos, 5);

    ProdutoTotal(produtos, 5);

    ProdutoMedia(produtos, 5);

    return 0;
}
