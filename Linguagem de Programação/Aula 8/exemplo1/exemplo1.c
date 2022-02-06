#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max 100

int main ()
{
    float ale[max],control = 0;

    srand (time(NULL));

    for (int i=0; i<max; i++)
    {
        ale[i]=rand();
        printf("%.2f\n", ale[i]);

        if(ale[i]>control)
            control=ale[i];
    }

    printf("O maior numero e %.2f", control);

    return 0;
}
