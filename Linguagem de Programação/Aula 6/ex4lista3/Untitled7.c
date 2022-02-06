#include <stdio.h>

int main()
{
    float x,j;
    int n;

    printf("Informe o valor de <x> e de <n>:\n");
    scanf("%f%d",&x,&n);

    j=x;

    if (n==0)
        printf("x = 1");

    else if (n==1)
        printf("x = %.2f",x);

    else
    {
        for (int i=1;i<n;i++)
        {
            x=x*j;
        }
        printf("x = %.2f",x);
    }

    return 0;
}
