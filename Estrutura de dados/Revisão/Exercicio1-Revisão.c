#include <stdio.h>
#include <locale.h>
int main() {
    setlocale(LC_ALL, "portuguese");
    int i;

    printf("Caractere\tCódigo ASCII\n");
    for(i = 0; i <= 127; i++) {
        printf("%c\t\t%d\n", i, i);
    }

    return 0;
}
