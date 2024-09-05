#include <stdio.h>
#include <locale.h>

void Lista_floats (float *vetor, int tamanho);

int main (void)
{
    setlocale(LC_ALL, "portuguese");
    int QtaFloat;
    printf("Quantos elementos float você gostaria de armazenar? \n");
    scanf("%d", &QtaFloat);

    float *p = malloc(QtaFloat * sizeof(float));

    printf("Digite os valores para o vetor: \n");
    for (int i = 0; i<QtaFloat; i++)
    {
        scanf("%f", &p[i]);
    }

    Lista_floats(p, QtaFloat);
}
void Lista_floats (float *vetor, int tamanho)
{
    printf("Lista dos valores armazenados: ");
    for(int i=0; i<tamanho; i++)
    {
        printf("%2.f  ", vetor[i]);
    }
}
