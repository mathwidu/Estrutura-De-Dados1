#include <locale.h>
#include <stdio.h>

int main(void) {
    setlocale(LC_ALL, "portuguese");
    float matriz[3][5];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("Digite o valor que o vendedor %d fez no mês %d: ", j + 1, i + 1);
            scanf("%f", &matriz[i][j]);
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%f\t", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}
