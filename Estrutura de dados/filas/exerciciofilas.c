#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tamanho 10

typedef struct fila {
    int inicio;
    int fim;
    int avioes[tamanho];
} fila;

// fun��o para inicializar a fila
void inicia_fila(fila *f) {
    f->inicio = 0;
    f->fim = 0;
}

// fun��o para verificar se a fila est� cheia
int fila_cheia(fila *f) {
    return f->fim == tamanho;
}

// fun��o para verificar se a fila est� vazia
int fila_vazia(fila *f) {
    return f->inicio == f->fim;
}

// fun��o que adiciona um avi�o ao final da fila
void adc_aviao(fila *f, int aviao) {
    if (!fila_cheia(f)) {
        f->avioes[f->fim] = aviao;
        f->fim++;
    } else {
        printf("ERRO, fila cheia\n");
    }
}

// fun��o que remove um avi�o da fila
int remov_aviao(fila *f) {
    if (!fila_vazia(f)) {
        int aviao = f->avioes[f->inicio];
        for (int i = 0; i < f->fim - 1; i++) {
            f->avioes[i] = f->avioes[i + 1];
        }
        f->fim--;
        return aviao;
    } else {
        printf("Fila vazia! N�o h� avi�es para remover.\n");
        return -1;
    }
}

// Imprime todos os avi�es na fila
void imprimir_fila(fila *f) {
    if (!fila_vazia(f)) {
        printf("Avi�es na pista:\n");
        for (int i = f->inicio; i < f->fim; i++) {
            printf("Avi�o %d\n", f->avioes[i]);
        }
    } else {
        printf("Fila vazia! Nenhum avi�o na pista.\n");
    }
}

int main() {
    setlocale(LC_ALL, "portuguese");
    fila fila;
    inicia_fila(&fila);

    int opcao, aviao;

    do {
        printf("\nControle de Pista de Decolagem\n");
        printf("1. Chegada de um avi�o\n");
        printf("2. Decolagem de um avi�o\n");
        printf("3. Imprimir fila de avi�es\n");
        printf("4. Sair\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("N�mero do avi�o: ");
                scanf("%d", &aviao);
                adc_aviao(&fila, aviao);
                break;
            case 2:
                aviao = remov_aviao(&fila);
                if (aviao != -1) {
                    printf("Avi�o %d decolou.\n", aviao);
                }
                break;
            case 3:
                imprimir_fila(&fila);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Op��o inv�lida!\n");
        }
    } while (opcao != 4);

    return 0;
}

