#include <stdio.h>

int main ()
{
    float rombus,imp,a,b,c;

    printf("Informe o valor de sua renda:\n");
    scanf("%f",&rombus);

    a=rombus-2000;
    b=rombus-3000;
    c=rombus-4500;

    if (rombus<=2000)
        printf("Isento");
    else if (a<1000)
        imp=a*0.08;
    else if (b<1500)
        imp=80+b*0.18; /*1000*0,08=80*/
    else
        imp=350+c*0.28; /*80+1500*0,18=350*/
    if (rombus>2000)
    printf("R$ %.2f",imp);

  return 0;
}
