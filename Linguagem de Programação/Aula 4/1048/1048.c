#include <stdio.h>

int main () {

    float sal,aum,rea,perc;

    printf("Informe o valor de seu salario: ");
    scanf("%f",&sal);

    if (sal<=400.00){
        perc=15;
        aum=sal+(perc/100)*sal;
        rea=aum-sal;
        printf("\n Novo salario: %.2f", aum);
        printf("\n Reajuste ganho: %.2f", rea);
        printf("\n Em percentual: %.0f %%", perc);
    }
     else if (sal<=800.00){
        perc=12;
        aum=sal+(perc/100)*sal;
        rea=aum-sal;
        printf("\n Novo salario: %.2f", aum);
        printf("\n Reajuste ganho: %.2f", rea);
        printf("\n Em percentual: %.0f %%", perc);
    }
    else if (sal<=1200.00){
        perc=10;
        aum=sal+(perc/100)*sal;
        rea=aum-sal;
        printf("\n Novo salario: %.2f", aum);
        printf("\n Reajuste ganho: %.2f", rea);
        printf("\n Em percentual: %.0f %%", perc);
    }
    else if (sal<=2000.00){
        perc=7;
        aum=sal+(perc/100)*sal;
        rea=aum-sal;
        printf("\n Novo salario: %.2f", aum);
        printf("\n Reajuste ganho: %.2f", rea);
        printf("\n Em percentual: %.0f %%", perc);
    }
     else {
        perc=4;
        aum=sal+(perc/100)*sal;
        rea=aum-sal;
        printf("\n Novo salario: %.2f", aum);
        printf("\n Reajuste ganho: %.2f", rea);
        printf("\n Em percentual: %.0f %%", perc);
    }

    return 0 ;
}
