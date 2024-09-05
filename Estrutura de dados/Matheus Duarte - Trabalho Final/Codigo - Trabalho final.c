#include <locale.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define TAMANHO 200000

void monta_vetor(int A[]) {
    int i;
    srand(time(NULL));
    for (i = 0; i < TAMANHO; i++) {
        A[i] = rand() % 100001;
    }
}

void escreve_vetor(int A[], char *msg) {
    int i;
    printf("******* %s *******\n", msg);
    for (i = 0; i < TAMANHO; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Algoritmo que utiliza a estratégia do insertion sort
void insertion_sort(int A[]) {
    int i, j, key;
    for (j = 1; j < TAMANHO; j++) {
        key = A[j];
        i = j - 1;
        while (i >= 0 && A[i] > key) {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = key;
    }
}

// Algoritmo que utiliza a estratégia do bubble sort para ordenar o vetor.
void bubble_sort(int A[]) {
    int flag, i, j, aux;
    for (i = 1; i < TAMANHO; i++) {
        flag = 0;
        for (j = 0; j < TAMANHO - i; j++) {
            if (A[j] > A[j + 1]) {
                aux = A[j];
                A[j] = A[j + 1];
                A[j + 1] = aux;
                flag = 1;
            }
        }
        if (!flag) return;
    }
}

// Algoritmo que utiliza a estratégia do selection sort para ordenar o vetor.
void selection_sort(int A[]) {
    int i, j, menor, aux;
    for (i = 0; i < TAMANHO; i++) {
        menor = i;
        for (j = i + 1; j < TAMANHO; j++) {
            if (A[j] < A[menor]) {
                menor = j;
            }
        }
        aux = A[menor];
        A[menor] = A[i];
        A[i] = aux;
    }
}

// Algoritmo que utiliza a estratégia do merge para ordenar o vetor.
void merge(int A[], int p, int q, int r) {
    int i, j, k, n1, n2;
    n1 = q - p + 1;
    n2 = r - q;

    int L[n1 + 1];
    int R[n2 + 1];

    for (i = 0; i < n1; i++)
        L[i] = A[p + i];

    for (j = 0; j < n2; j++)
        R[j] = A[q + j + 1];

    L[n1] = 999999;
    R[n2] = 999999;

    i = 0;
    j = 0;
    for (k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

// Função que faz as chamadas recursivas para a função merge_sort e aplica a função merge quando necessário
void merge_sort(int A[], int p, int r) {
    int q;
    q = (p + r) / 2;
    if (p < r) {
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}






// implementação do algoritmo escolhido  Quick Sort

//Criação da função troca auxiliar de particao, usada para trocar a posição de dois elementos do vetor.
void troca(int *a, int *b) {
    int temp = *a; // Armazena o valor de *a em temp
    *a = *b; // Coloca o valor de *b em *a
    *b = temp; // Coloca o valor armazenado em temp em *b
}

// Função auxiliar de Merge Sort, para fazer a partição do vetor em dois sub vetores.
int particao(int A[], int primeiro, int ultimo) { // A função recebe da função quick sort um vetor A, a posição do seu primeiro e ultimo elemento da.
    int pivo = A[ultimo]; // coloco o valor do ultimo elemento do vetor A na minha variavel pivo.
    int i = (primeiro - 1); // crio uma variavel auxiliar i e defino ela como o valor da posição do primeiro elemento de A menos um.
    for (int j = primeiro; j < ultimo; j++) {//uso um loop for partindo do primeiro elemento do vetor até o ultimo.
        if (A[j] <= pivo) {// compara todos os elemento do vetor com o valor de pivo, se for menor ou igual fazemos o if.
            i++; // somo um no valor de i.
            troca(&A[i], &A[j]); // trocamos os valorers das posições i e j.
        }
    }
    troca(&A[i + 1], &A[ultimo]); // trocamos os valores das posições i+1 e pivo(ultima valor do vetor), assim coloco o pivo sempre logo após o ultimo elemento menor ou igual a ele.
    return (i + 1); // retorno o índice de onde está o pivo para minha função quick_sort
}

// Função principal Quick Sort, usa a recursividade para dividir o vetor em dois sub vetores usandoa a função partição como auxiliar.
void quick_sort(int A[], int primeiro, int ultimo) { // recebe um vetor A[], a posição do seu primeiro e ultimo elemento
    if (primeiro < ultimo) {//verifica se o vetor recebido tem pelo menos 2 elementos, se tiver entramos no if.
        int pivo = particao(A, primeiro, ultimo); //crio o pivo na minha função quick sort recebendo o retorno da função partição(que ja particiona o vetor a primeira vez).
        quick_sort(A, primeiro, pivo - 1); // faço uma chamada recursiva passando o sub vetor da esquerda, sendo ele os valores menores ou iguais a pivo na minha primeira partição do vetor
        quick_sort(A, pivo + 1, ultimo); // faço uma chamada recursiva passando o sub vetor da direita, sendo ele os valores maiores que pivo na minha primeira partição do vetor.

        /*cada chamada recursiva ira chamar mais duas chamadas recursivas, todas criando sub vetores ordenados, até que o vetor recebido tenha menos de dois elementos. No final de tudo acontece
        o desenpilhamento da final de execução e assim temos nosso vetor totalmente ordenado de forma crescente.*/

    }
}

int main(void) {
    setlocale(LC_ALL, "portuguese");
    clock_t inicio, fim;
    double diferenca;
    int A[TAMANHO];

    // calculando tempo dos algoritmos
    monta_vetor(A);
    //escreve_vetor(A, "VETOR DESORDENADO");

    inicio = clock();
     //bubble_sort(A);
     //selection_sort(A);
    //insertion_sort(A);
    merge_sort(A, 0, TAMANHO -1);
    //quick_sort(A, 0, TAMANHO - 1); // Quick Sort
    fim = clock();

    diferenca = (double)(fim - inicio) / CLOCKS_PER_SEC * 1000;
    printf("Tempo em ms: %10.4f\n", diferenca);
    //escreve_vetor(A, "VETOR ORDENADO");

    return 0;
}



