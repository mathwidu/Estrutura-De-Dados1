#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
struct Aluno
{
    int matricula;
    char *nome;
    float media;
};
typedef struct Aluno aluno;
void Lista_Alunos (aluno *vetor, int tamanho);

int main (void)
{
    setlocale(LC_ALL, "portuguese");
    int QtaAlunos;
    printf("Quantos alunos você gostaria de armazenar? \n");

    scanf("%d", &QtaAlunos);

    aluno *p = malloc(QtaAlunos * sizeof(aluno));
    if (p==NULL)
    {
        printf("ERRO ao alocar memoria. \n");
    }
    printf("Digite os dados para os alunos: \n\n");
    fflush(stdin);
    for (int i = 0; i<QtaAlunos; i++)
    {
        p[i].nome = malloc(31 * sizeof(char));
        if(p[i].nome == NULL)
        {
            printf("ERRO ao alocar memoria.\n");
        }
        printf("Nome: \n");
        scanf("%30[^\n]", p[i].nome);
        fflush(stdin);

        printf("Matricula: \n");
        scanf("%d", &p[i].matricula);
        fflush(stdin);

        printf("Media: \n");
        scanf("%f", &p[i].media);
        fflush(stdin);
    }
    Lista_Alunos(p, QtaAlunos);
    free(p);
}
void Lista_Alunos (aluno *vetor, int tamanho)
{
    printf("Lista de alunos armazenados: ");
    for(int i=0; i<tamanho; i++)
    {
        printf("Nome: %s\n", vetor[i].nome);
        printf("Matricula: %d\n", vetor[i].matricula);
        printf("Media: %2.f\n", vetor[i].media);
    }
}
