#include <stdio.h>

struct elemento
{
    float nota;
    struct elemento *prox
    };
typedef struct elemento Elemento;

Elemento* cria_lista(void);
Elemento* insere_lista1(Elemento* lista, float nota);
Elemento* insere_lista2(Elemento* lista, float nota);
int verifica_lista_vazia (Elemento* lista);
void imprime_lista(Elemento* lista);
Elemento* operacao (Elemento * listaUm, Elemento* listaDois);
//exercicio letra A:
Elemento* buscar(Elemento *lista, float valor);

int main()
{
    Elemento *listaUm;
    Elemento *listaDois;
    listaUm = cria_lista();
    listaDois = cria_lista();

    listaUm = insere_lista1(listaUm, 8.0);
    listaUm = insere_lista1(listaUm, 9.2);
    listaUm = insere_lista1(listaUm, 7.8);
    listaUm = insere_lista1(listaUm, 8.5);

    listaDois = operacao(listaUm, listaDois);
    //exercicio letra B:
    imprime_lista(listaDois);
    getchar();

    //exercicio letra A:
    buscar(listaUm, 9.2);
    return 0;
}
Elemento* cria_lista(void)
{
    return NULL;
}
Elemento *insere_lista1(Elemento* lista, float nota)
{
    Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
    novo->prox = lista;
    novo->nota = nota;
    return novo;
}

Elemento* insere_lista2(Elemento* lista, float nota)
{
    Elemento *p, *ant = NULL;
    Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
    novo->nota = nota;
    novo->prox = NULL;
    if (verifica_lista_vazia(lista))
    {
        lista = novo;
    }
    else
    {
        p = lista;
        while(p != NULL)
        {
            ant = p;
            p = p->prox;
        }
        ant->prox = novo;
    }
    return lista;
}
void imprime_lista(Elemento* lista){
    if (verifica_lista_vazia(lista)){
        printf("Lista vazia");
    }
    else{
        Elemento* p;
        for(p = lista; p != NULL; p = p->prox){
            printf("nota: %6.2f\n", p->nota);
        }
    }
}
int verifica_lista_vazia(Elemento* lista){
    return (lista == NULL);
}
Elemento* operacao(Elemento *listaUm, Elemento *listaDois){
    Elemento *p;
    p = listaUm;
    while (p != NULL){
        listaDois = insere_lista2(listaDois, p->nota);
        p = p->prox;
    }
    return listaDois;
}
//exercicio letra A:
Elemento* buscar(Elemento *lista, float valor){
    Elemento *aux = lista;
    while(aux != NULL){
        if (aux->nota == valor){
            return aux;
        }
    return NULL;
    }
}

