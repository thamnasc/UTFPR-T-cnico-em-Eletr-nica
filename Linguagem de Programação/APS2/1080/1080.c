#include <stdio.h>

int main ()
{
    int a,b,i,j=1,k=1;

    scanf("%d",&a);

    for(i=0;i<100;i++)
    {
        scanf("%d",&b);
        j++;

        if (b>a)
        {
            a=b;
            k=j;
        }
    }

    printf("%d\n",a);
    printf("%d\n",k);

    return 0;
}
