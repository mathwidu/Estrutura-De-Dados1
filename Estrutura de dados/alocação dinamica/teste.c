#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main (void){
    setlocale(LC_ALL, "portuguese");
    int *p = malloc(sizeof(int));

    printf("%d", p);






}
