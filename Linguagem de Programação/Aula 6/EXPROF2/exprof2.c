#include <stdio.h>

int main()
{
    float compra,desc = 0;

    printf("Informe o valor de sua compra:\n");
    scanf("%f",&compra);

    if (compra>=30.0 && compra<=100.0)
    {
        desc=compra*0.1;
    }

    else if (compra>100.0)
    {
        desc=compra*0.15;
    }

    printf("Voce recebeu desconto de R$ %.2f\ne o valor final de sua compra e R$ %.2f\n",desc,compra-desc);

    return 0;
}

