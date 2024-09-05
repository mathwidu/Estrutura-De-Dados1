#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
struct PontoTuristico{
    char descricao[41];
    float latitude;
    float longitude;
    struct PontoTuristico *proximo;
};
struct PontoTuristico* criar_lista(void){
    return NULL;
};
void LePontoTuristico(struct PontoTuristico *aux){
    setlocale(LC_ALL, "portuguese");
    printf("\nDescrição: ");
    scanf("%[^\n]", aux->descricao);
    fflush(stdin);
    printf("\nLatitude: ");
    scanf("%f", &aux->latitude);
    fflush(stdin);
    printf("\nLongitude: ");
    scanf("%f", &aux->longitude);
    fflush(stdin);
}
struct PontoTuristico* inserir_inicio(struct PontoTuristico* cabeca){
    struct PontoTuristico* novo = (struct PontoTuristico*) malloc(sizeof(struct PontoTuristico));
    LePontoTuristico (novo);
    novo->proximo = cabeca;
    return (novo);
};

void imprimir(struct PontoTuristico *cabeca){
    struct PontoTuristico *paux;
    for (paux = cabeca; paux!=NULL; paux = paux->proximo){
        printf("Descrição: %s\tLatitude: %2.f\tLongitude: %2.f\t\n", paux->descricao, paux->latitude; paux->longitude);
    }
}
int main (void){
    struct PontoTuristico *cabeca;
    cabeca = criar_lista();
    cabeca = inserir_inicio(cabeca);
    //cabeca = inserir_final(cabeca);
}
