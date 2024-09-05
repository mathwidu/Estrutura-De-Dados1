#include <stdio.h>
#include <locale.h>

int main (void){
    setlocale(LC_ALL, "portuguese");

    int numero;

    printf("Digite um número: \n");
    scanf("%d", &numero);

    printf("Esse número em base octal é: %o\n", numero);

    printf("Esse número em base hexadecimal é: %x", numero);

    return 0;
}
