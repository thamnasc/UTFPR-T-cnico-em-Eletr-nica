#include <stdio.h>

int main ()
{
    int i,n,a=0,b=1,j;

    do
    {
        scanf("%d",&n);
    }
    while(n<=0||n>45);

    if (n==1)
        printf("%d",a);

    if (n>1)
    {
        printf("%d",a);
        printf(" %d",b);
    }

    if (n>2)
    {
        for(i=1;i<=(n-2);i++)
        {
            j=a;
            a=b;
            b=j+b;
            printf(" %d",b);
        }
    }

    printf("\n");

    return 0;
}
