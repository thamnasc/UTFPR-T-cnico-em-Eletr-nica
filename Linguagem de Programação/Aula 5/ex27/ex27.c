#include <stdio.h>
#include <math.h>

int main ()
{
    float num,raiz;

    for(num=1;num<=50;num++)
        printf("\nA raiz de %.0f e <%.2f>",num,sqrt(num));

    return 0;
}
