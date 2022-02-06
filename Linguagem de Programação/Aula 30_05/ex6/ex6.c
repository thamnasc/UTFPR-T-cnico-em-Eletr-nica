#include <stdio.h>

struct data
{
    int dia, mes, ano;
};

int main ()
{

    struct data x;
    printf("Infome o dia, mes e ano: \n");
    scanf("%d%d%d",&x.dia,&x.mes,&x.ano);

    printf("%02d/%02d/%04d\n",x.dia,x.mes,x.ano);

    return 0;
}
