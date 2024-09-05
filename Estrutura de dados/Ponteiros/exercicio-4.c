#include <locale.h>
#include <stdio.h>
int ZeraNum (int *a, int *b){
    *a=0;
    *b=0;
}
int main (void){
    int a = 10;
    int b = 20;
    printf("a: %d - b: %d\n\n", a, b);

    ZeraNum(&a,&b);

    printf("a: %d - b: %d", a, b);


}
