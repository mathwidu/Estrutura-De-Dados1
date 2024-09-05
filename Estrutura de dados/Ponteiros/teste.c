#include <stdio.h>
#include <locale.h>

int main (void)
{
    setlocale(LC_ALL, "portuguese");
    char placar[30] = "Internacional 1 x 0 Grêmio";
    char *p;
    int i;

    printf("%u %u\n", placar, &placar[0]);

    for (i=20; placar[i] != '\0'; i++){
        printf("%c", placar[i]);
    }
    printf("\n");

    for (p = placar; *p != '\0'; p++){
        printf("%c", *p);
    }
    printf("\n");

    for (p = placar; *p != 'e'; p++){
        printf("%u\n", p);
    }
}
