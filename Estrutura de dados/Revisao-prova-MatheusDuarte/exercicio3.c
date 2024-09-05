#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

int main(void){
    int valor = 7, *p, *q;
    p = &valor;
    q = p;
    printf("%u\n", p+1);
    printf("%u\n", *p);
    printf("%u\n", (*p+1));
    printf("%u\n", *q+1);
    printf("%u\n" (*p)%(*q));
    return 0;
}
