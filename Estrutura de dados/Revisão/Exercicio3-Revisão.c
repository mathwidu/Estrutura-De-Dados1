#include <stdio.h>
#include <locale.h>

int main (void){
    setlocale(LC_ALL, "portuguese");

    int numero;

    printf("Digite um n�mero: \n");
    scanf("%d", &numero);

    printf("Esse n�mero em base octal �: %o\n", numero);

    printf("Esse n�mero em base hexadecimal �: %x", numero);

    return 0;
}
