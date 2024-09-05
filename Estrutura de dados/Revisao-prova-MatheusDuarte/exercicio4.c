#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct colaborador {
    char cpf[12];
    char nome[41];
    float salario;
};

int main(void) {
    struct colaborador *colaborador;
    printf("%d\n", sizeof(struct colaborador));
    colaborador = (struct colaborador *)malloc(5 * sizeof(struct colaborador));

    strcpy(colaborador->cpf, "12345678911");
    strcpy(colaborador->nome, "Ian Anderson");
    colaborador->salario = 3000.99;
    printf("%s\n", colaborador->cpf);
    printf("%s\n", colaborador->nome);
    printf("%.2f\n", colaborador->salario);

    strcpy(colaborador->cpf, "987654321");
    strcpy(colaborador->nome, "Robert Plant");
    colaborador->salario = 5500.99;
    colaborador++;
    printf("%s\n", colaborador->cpf);
    printf("%s\n", colaborador->nome);
    printf("%.2f\n", colaborador->salario);

    free(colaborador);

    return 0;
}
