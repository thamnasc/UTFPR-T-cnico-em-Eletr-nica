#include <stdio.h>

int main ()
{
    float SB, SL, HT, VH, PD, TD;

    printf("Informe as horas trabalhadas,\no valor da hora-aula e\no percentual do INSS\n");
    scanf("%f%f%f",&HT,&VH,&PD);

    SB=(HT*VH);
    TD=SB*(PD/100);
    SL=SB-TD;(HT*VH);

    printf("O salario bruto e R$ %.2f e o salario liquido e R$ %.2f",SB,SL);

    return 0;
}
