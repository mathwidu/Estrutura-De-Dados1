#include <stdio.h>
#include <stdlib.h>
int main()
{
    int matriz[2][5] = { {1,2,3,4,5},
        {6,7,8,9,10}
    };

    int i, j;
    int *p;

    for (j=0; j < 2; j++)
    {
        {
            for (i=0; i < 2; i++)
                printf("%d\t", matriz[j][i]);
        }
        printf("\n\n");
    }

    printf("\n\n\n\n");

    p = &matriz[1][2];
    i = 0;

    while (i<3)
    {
        printf("%d\t", *p);
        p++;
        i++;
    }
    printf("\n\n\n\n\n\n");

    p=&matriz;

    i=0;

    while (i<10)
    {
        printf("%d\t", *(p+i));
        i = i + 2;
    }
    printf("\n\n\n\n\n\n");
}
