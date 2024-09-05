#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PontoTuristico {
    char descricao[41];
    float latitude;
    float longitude;
    struct PontoTuristico *proximo;
};
struct PontoTuristico* remover_lista(struct PontoTuristico* cabeca, char *desc);
struct PontoTuristico* criar_lista(void);
struct PontoTuristico* inserir_inicio(struct PontoTuristico* cabeca);
void lePontoTuristico(struct PontoTuristico *aux);
void imprimir(struct PontoTuristico* cabeca);
struct PontoTuristico* buscar_lista(struct PontoTuristico* cabeca, char *desc);
int verificar_lista_vazia(struct PontoTuristico* cabeca);
struct PontoTuristico* liberar_lista(struct PontoTuristico* cabeca);
struct PontoTuristico* inserir_final(struct PontoTuristico* cabeca);

int main() {
    struct PontoTuristico* cabeca;
    cabeca = criar_lista();
    cabeca = inserir_inicio(cabeca);
    cabeca = inserir_inicio(cabeca);
    cabeca = inserir_inicio(cabeca);
    imprimir(cabeca);
    struct PontoTuristico* busca = buscar_lista(cabeca, "poa");
    if (busca)
        printf("Ponto turistico encontrado: %s - Lat: %.2f - Long: %.2f",
        busca->descricao, busca->latitude, busca->longitude);
    remover_lista(cabeca, "poa");
    imprimir(cabeca);
    return 0;
}

struct PontoTuristico* criar_lista(void) {
    return NULL;
}

void lePontoTuristico(struct PontoTuristico *aux) {
    printf("Descricao: ");
    scanf("%[^\n]", aux->descricao);
    fflush(stdin);
    printf("\nLat: ");
    scanf("%f", &aux->latitude);
    fflush(stdin);
    printf("\nLong: ");
    scanf("%f", &aux->longitude);
    fflush(stdin);
}

struct PontoTuristico* inserir_inicio(struct PontoTuristico* cabeca) {
    struct PontoTuristico* novo = (struct PontoTuristico*) malloc(sizeof(struct PontoTuristico));
    lePontoTuristico(novo);
    novo->proximo = cabeca;
    return(novo);
}

void imprimir(struct PontoTuristico* cabeca) {
    struct PontoTuristico* paux;
    for (paux = cabeca; paux != NULL; paux = paux->proximo)
        printf("%s: lat: %.2f, long: %.2f\n", paux->descricao, paux->latitude, paux->longitude);
}
struct PontoTuristico* buscar_lista(struct PontoTuristico* cabeca, char *desc){
    struct PontoTuristico *paux;
    for (paux = cabeca; paux != NULL; paux = paux->proximo){
        if(strcmp(paux->descricao, desc)==0){
            return paux;
        }
    }
    return NULL;
};
struct PontoTuristico* remover_lista(struct PontoTuristico* cabeca, char *desc){
    struct PontoTuristico *paux = cabeca;
    struct PontoTuristico *anterior_aux = NULL;
    while (paux != NULL && strcmp(paux->descricao, desc)!=0){
        anterior_aux = paux;
        paux = paux->proximo;
    }
    if(paux==NULL){
        return cabeca;
    }
    if (anterior_aux == NULL){
        cabeca = paux->proximo;
    }
    else{
        anterior_aux->proximo = paux->proximo;
        free(paux);
        return cabeca;
    }
};

int verificar_lista_vazia(struct PontoTuristico* cabeca){
    if (cabeca == NULL){
        return 0;
    }
    else{
        return 1;
    }
}

struct PontoTuristico* liberar_lista(struct PontoTuristico* cabeca){
    struct PontoTuristico *paux = cabeca;
    struct PontoTuristico *aux = NULL;
    while(paux!=NULL){
        aux = paux->proximo;
        free(paux);
        paux = aux;
    }
    return NULL;
};

struct PontoTuristico* inserir_final(struct PontoTuristico* cabeca){
    struct PontoTuristico *paux;
    struct PontoTuristico* novo = (struct PontoTuristico*) malloc(sizeof(struct PontoTuristico));
    if (cabeca == NULL){
        cabeca = novo;
    }
    else{
        paux = cabeca;
        {
            while(paux->proximo!=NULL){
                paux = paux->proximo;
            }
            paux->proximo = novo;
        }
        return cabeca;
    }

}



