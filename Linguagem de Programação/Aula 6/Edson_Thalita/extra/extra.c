//Alunos Edson Vinicius, Thalita Nascimento

#include <stdio.h>

int main()
{
    int a,b,c,i,j,k,mdc=0;

    printf("Informe <a> e <b>:");
    scanf("%d%d",&a,&b);

    if (a>b)
        c=b;
    else
        c=a;

    for (i = 1; i <= c; i++)
    {
        j=a%i;
        k=b%i;

        if(j==0 && k==0)
           mdc=i;
    }

    printf("MDC = %d",mdc);

    return 0;
}

