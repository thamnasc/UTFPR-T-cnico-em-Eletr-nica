#include <stdio.h>
#include <locale.h>

int main () {

    setlocale(LC_ALL,"portuguese");

    int item,quant;
    float price;

    printf("\t------------------------------------------------");
    printf("\n\n\tCODIGO\t\tESPECIFICAÇÕES\t\tPREÇO\n\n");
    printf("\t------------------------------------------------\n");
    printf("\t1\t\tCachorro Quente\t\tR$ 4.00\n");
    printf("\t2\t\tX-Salada\t\tR$ 4.50\n");
    printf("\t3\t\tX-Bacon\t\t\tR$ 5.00\n");
    printf("\t4\t\tTorrada simples\t\tR$ 2.00\n");
    printf("\t5\t\tRefrigerante\t\tR$ 1.50\n");
    printf("\t------------------------------------------------\n\n");

    printf("\tInforme seu pedido e a quantidade: \n");
    scanf("%d%d", &item,&quant);

    if (item==1)
    {
        price=4*quant;
        printf("\tTotal : R$ %.2f\n", price);
    }
    else if (item==2)
    {
        price=4.5*quant;
        printf("\tTotal : R$ %.2f\n", price);
    }
    else if (item==3)
    {
        price=5*quant;
        printf("\tTotal : R$ %.2f\n", price);
    }
    else if (item==4)
    {
        price=2*quant;
        printf("\tTotal : R$ %.2f\n", price);
    }
    else
    {
        price=1.5*quant;
        printf("\tTotal : R$ %.2f\n", price);
    }

    return 0;
}
