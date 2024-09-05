#include <locale.h>
#include <stdio.h>

struct TipoProduto{
    int codigo;
    char descricao [100];
    float preco;
    char promocao;
};
int main (void){
    setlocale(LC_ALL, "portuguese");
    struct TipoProduto produto;

    printf("Digite o codigo do produto: \n");
    scanf("%d", &produto.codigo);

    getchar();

    printf("Digite a descrição para o produto: \n");
    scanf("%[^\n]s", produto.descricao);

    printf("Digite um preço para o produto: \n");
    scanf("%f", &produto.preco);

    printf("O produto tem uma promoção ativa? s/n\n");
    scanf(" %c", &produto.promocao);

    printf("Valores cadastrados: \n");
    printf("Código: %d\n", produto.codigo);
    printf("Descrição: %s\n", produto.descricao);
    printf("Preço: %.2f\n", produto.preco);
    printf("Promoção ativa: %c\n", produto.promocao);








return 0;
}
