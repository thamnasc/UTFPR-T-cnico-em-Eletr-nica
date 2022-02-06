#include <stdio.h>

int main()
{
    int a,b,j=0;

    printf("Informe o valor <a> e <b>:");
    scanf("%d%d",&a,&b);

        for (int i=1;i<b;i++)
        j=j+a;

    /*else
    {
        for (int i=1;i<-b;i++)
        a=a+j;
    }
*/
    printf("O valor da adicao e %d\n",a);

    return 0;
}

