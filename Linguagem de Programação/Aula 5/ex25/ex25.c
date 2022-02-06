#include <stdio.h>

int main ()
{
    int num,i;

    printf("Informe o numero: ");
    scanf("%d",&num);
    printf("\n\t+++tabuada do %d+++\n",num);
    printf("\t ----------------------");
    for(i=1;i<11;i++)
    {
        printf("\n\t | <%2d> * <%2d> = %4d |",num,i,num*i);
    }
    printf("\n\t ----------------------");
    printf("\n\n\n\n\n");
    return 0;
}
