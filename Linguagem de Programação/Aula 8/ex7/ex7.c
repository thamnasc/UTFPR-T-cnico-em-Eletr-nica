#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max 100

int main ()
{
    int n,matriz[10][10],i=0,j=0,S=0;

    scanf("%d",&n);

    srand(time(NULL));

    for (; i<n; i++)
    {
        printf("\n");

        for (; j<n; j++)
        {
            matriz[i][j]=rand();

            if (i==j)
                S=S+matriz[i][j];

            printf("%d ",matriz[i][j]);
        }
    }

    printf("\n%d",S);


    return 0;
}
