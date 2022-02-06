/*Edson Vinicius Pereira de Medina
  Thalita Maria do Nascimento
*/

#include <stdio.h>

#define max 1000

int main ()
{
    int i = 0,maxUni,maxInt,maxA, maxB;
    scanf("%d%d",&maxA,&maxB);
    float A[maxA], B[maxB], Uni[maxUni], Int[maxInt], Dif[maxA];
    maxUni=maxA+maxB; //na uniao, o limite do conjunto pode ser no maximo a soma dos elementos

    if (maxA<maxB) //na interseçao, o conjunto que tem menos elementos serve como limite
        maxInt=maxA;
    else
        maxInt=maxB;


    for(;i < max; i++ )
    {
        scanf("%f",&A[i]);

        if( A[i] <= 10)
            printf("A[%d] = %.1f\n",i,A[i]);
    }

    return 0;
}
