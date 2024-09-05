#include <stdio.h>
#include <locale.h>
#define TAM 4

int main(void){
    setlocale(LC_ALL, "portuguese");
    int matriz [TAM][TAM] = {
                                {5, 6, 10, 2},
                                {1, 4, 3, 0},
                                {0, 0, 6, 4},
                                {2, 3, 4, 8},
                            };
    int *p, i;
    int soma = 0;
    p = matriz;
    for (i = 0; i<TAM*TAM; i++){
        soma += *p;
        p++;
    }

    printf("A soma dos valores de toda a matriz é igual a %d.", soma);
    getchar();
    return 0;
}
