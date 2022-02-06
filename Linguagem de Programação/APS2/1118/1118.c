#include <stdio.h>

int main ()
{
    int again=0;
    float a,b;

    do
    {
        do
        {
            scanf("%f",&a);

            if (a<0||a>10)
                printf("nota invalida\n");
        }
        while(a<0||a>10);

        do
        {
            scanf("%f",&b);

            if (b<0||b>10)
                printf("nota invalida\n");
        }
        while(b<0||b>10);

        printf("media = %.2f\n",(a+b)/2);

        do
        {
           printf("novo calculo (1-sim 2-nao)\n");

           scanf("%d",&again);

           if(again==1||again==2)
            break;
        }
        while(again!=1||again!=2);
    }
    while(again==1);

    return 0;
}
