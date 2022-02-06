#include <stdio.h>
#include <stdlib.h>

float media(int n, float *v)
{
    float soma=0;

    for (int i=0;i<n;i++)
    {
        soma+=v[i];
    }

    return soma/n;
}

int main ()
{
    int i,n;
    float *v;
    float med;
    scanf("%d", &n);

    v = (float*) malloc(n*sizeof(float));
        if (v==NULL)
        {
            printf("Memoria insuficiente.\n");

            return 1;
        }

    for (i=0;i<n;i++)
    {
        scanf("%f", &v[i]);
    }

    med = media(n,v);

    printf("Media = %f\n", med);

    free(v);

    return 0;
}
