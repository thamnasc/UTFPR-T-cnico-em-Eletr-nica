#include <stdio.h>

int main ()
{
    float n1,n2,n3,n4,n5,n6,n,valor;

    printf("Informe os numeros 6 numeros:\n");
    scanf("%f%f%f%f%f%f",&n1,&n2,&n3,&n4,&n5,&n6);

    n=0;
    valor=0;

    if (n1>0)
    {
        n++;
        valor=valor+n1;
    }
    if (n2>0)
    {
        n++;
        valor=valor+n2;
    }
    if (n3>0)
    {
        n++;
        valor=valor+n3;
    }
    if (n4>0)
    {
        n++;
        valor=valor+n4;
    }
    if (n5>0)
    {
        n++;
        valor=valor+n5;
    }
    if (n6>0)
    {
        n++;
        valor=valor+n6;
    }

    printf("%.0f valores positivos\n%.1f\n",n,valor/n);

    return 0;
}
