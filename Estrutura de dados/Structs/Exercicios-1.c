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

    printf("Digite a descri��o para o produto: \n");
    scanf("%[^\n]s", produto.descricao);

    printf("Digite um pre�o para o produto: \n");
    scanf("%f", &produto.preco);

    printf("O produto tem uma promo��o ativa? s/n\n");
    scanf(" %c", &produto.promocao);

    printf("Valores cadastrados: \n");
    printf("C�digo: %d\n", produto.codigo);
    printf("Descri��o: %s\n", produto.descricao);
    printf("Pre�o: %.2f\n", produto.preco);
    printf("Promo��o ativa: %c\n", produto.promocao);








return 0;
}
