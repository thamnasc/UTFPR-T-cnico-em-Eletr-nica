/*Edson Vinicius Pereira de Medina
  Thalita Maria do Nascimento
*/

#include <stdio.h>

#define max 100

int main ()
{
    int i = 0;
    float A[max] ;

    for(;i < max; i++ )
    {
        scanf("%f",&A[i]);

        if( A[i] <= 10)
            printf("A[%d] = %.1f\n",i,A[i]);
    }

    return 0;
}
