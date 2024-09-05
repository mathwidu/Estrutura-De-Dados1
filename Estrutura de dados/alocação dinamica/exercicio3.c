//Implementar um algoritmo que armazene um vetor de strings. Este vetor deve ser criado
//dinamicamente atrav�s da fun��o malloc ou calloc. O programador deve questionar o usu�rio
//sobre quantas strings ele deseja armazenar. De posse do n�mero de valores, o espa�o de
//mem�ria adequado deve ser alocado e posteriormente a leitura dos valores deve ser realizada.
//Ap�s a leitura de todos os valores, deve ser chamada uma fun��o lista_strings para mostrar na
//tela todos os valores cadastrados.
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
struct String{
    char caracter[50];
};
typedef struct String string;
void Lista_Strings (string *vetor, int tamanho);
int main(void){
setlocale(LC_ALL, "portuguese");
    int QtaStrings;
    printf("Quantas strings voc� gostaria de armazenar? \n");

    scanf("%d", &QtaStrings);
    fflush(stdin);
    string *p = malloc(QtaStrings * sizeof(string));

    for (int i = 0; i<QtaStrings; i++){
            printf("Digite o conteudo para a string: \n");
            scanf("%50[^\n]", p[i].caracter);
            fflush(stdin);
    }
    Lista_Strings(p, QtaStrings);
}
void Lista_Strings (string *vetor, int tamanho)
{
    printf("Lista de alunos armazenados: \n");
    for(int i=0; i<tamanho; i++)
    {
        printf("Conteudo string %d %s\n", i+1, vetor[i].caracter);
    }
}
