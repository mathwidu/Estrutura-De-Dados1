#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 20

int pesquisaSequencial(int vetor[TAM], int numero);
int pesquisaBinariaIterativa(int vetor[TAM], int numero);
int pesquisaBinariaRecursiva(int vetor[TAM], int inicio, int fim, int numero);

int main (void)
{
    setlocale(LC_ALL, "Portuguese");
    int numero;
    int opcao;
    int resultado;

    int vetor[TAM] = {1, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95};

    while (1)
    {
        printf("\nEscolha o método de busca:\n");
        printf("1 - Busca Sequencial\n");
        printf("2 - Busca Binária Iterativa\n");
        printf("3 - Busca Binária Recursiva\n");
        printf("4 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        if (opcao == 4)
        {
            break;
        }

        printf("Qual número você quer buscar na sequência? ");
        scanf("%d", &numero);

        switch(opcao)
        {
        case 1:
            resultado = pesquisaSequencial(vetor, numero);
            printf("Resultado da busca sequencial: %d\n", resultado);
            break;
        case 2:
            resultado = pesquisaBinariaIterativa(vetor, numero);
            printf("Resultado da busca binária iterativa: %d\n", resultado);
            break;
        case 3:
            resultado = pesquisaBinariaRecursiva(vetor, 0, TAM - 1, numero);
            printf("Resultado da busca binária recursiva: %d\n", resultado);
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
            break;
        }
    }

    return 0;
}

int pesquisaSequencial(int vetor[TAM], int numero)
{
    for (int i = 0; i < TAM; i++)
    {
        if (vetor[i] == numero)
        {
            return i;
        }
    }
    return -1;
}

int pesquisaBinariaIterativa(int vetor[TAM], int numero)
{
    int inicio = 0;
    int fim = TAM - 1;
    while (inicio <= fim)
    {
        int meio = (inicio + fim) / 2;
        int chute = vetor[meio];
        if (chute == numero)
        {
            return meio;
        }
        else if (chute < numero)
        {
            inicio = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
    }
    return -1;
}

int pesquisaBinariaRecursiva(int vetor[TAM], int inicio, int fim, int numero)
{
    if (inicio > fim)
    {
        return -1;
    }
    int meio = (inicio + fim) / 2;
    if (vetor[meio] == numero)
    {
        return meio;
    }
    else if (vetor[meio] < numero)
    {
        return pesquisaBinariaRecursiva(vetor, meio + 1, fim, numero);
    }
    else
    {
        return pesquisaBinariaRecursiva(vetor, inicio, meio - 1, numero);
    }
}

