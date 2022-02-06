#include <stdio.h>
#include <math.h>

int jan = 31,
    fev[2] = {59,60},
    mar[2] = {90,91},
    abr[2] = {120,121},
    maio[2] = {151,152},
    junh[2] = {181,182},
    julh[2] = {212,213},
    agos[2] = {243,244},
    set[2] = {273,274},
    out[2] = {304,305},
    nov[2] = {334,335};

int datax_dias(int datax[])
{
    int bis = 0, dias = 0;
    dias += datax[0];

    if((datax[2]%4==0 && datax[2]%100!= 0) || datax[2]%400 ==0)
        bis = 1;
    else
        bis = 0;

    switch(datax[1])
    {
        case 2:
            dias += jan;
            break;
        case 3:
            dias += fev[bis];
            break;
        case 4:
            dias += mar[bis];
            break;
        case 5:
            dias += abr[bis];
            break;
        case 6:
            dias += maio[bis];
            break;
        case 7:
            dias += junh[bis];
            break;
        case 8:
            dias += julh[bis];
            break;
        case 9:
            dias += agos[bis];
            break;
        case 10:
            dias += set[bis];
            break;
        case 11:
            dias += out[bis];
            break;
        case 12:
            dias += nov[bis];
            break;
    }
    for(int ano=1;ano < datax[2];ano++)
    {
        if((ano%4==0 && ano%100!= 0) || (ano%400 ==0 && ano%100!= 0) )
            dias += 366;
        else
            dias += 365;
    }
    return dias;
}

int main()
{
    int data1[3],data2[3],dias = 0,dias1 = 0,dias2 = 0, mes[12];
    while(1)
    {
        printf("\n\n\nInforme a primeira data: <DD> <MM> <AAAA>");
        scanf("%i%i%i",&data1[0],&data1[1],&data1[2]);

        printf("Informe a segunda data: <DD> <MM> <AAAA>");
        scanf("%i%i%i",&data2[0],&data2[1],&data2[2]);

        dias1 = datax_dias(data1);
        dias2 = datax_dias(data2);

        dias = abs(dias2 - dias1);

        printf("\n\t Data 1 : %02d/%02d/%02d\n",data1[0],data1[1],data1[2]);
        printf("\t Data 2 : %02d/%02d/%02d\n",data2[0],data2[1],data2[2]);
        printf("\n\t Ha %d dias entre a data um e a data dois\n",dias);
        dias=0;
    }

    return 0;
}
