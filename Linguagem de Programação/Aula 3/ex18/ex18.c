#include <stdio.h>
#include <math.h>


int main () {

    printf(" \n\n\n \t ================================ \n");
    printf("\t ====LINGUAGEM DE PROGRAMACAO==== \n");
    printf("\t =========== AULA 03 ============ \n");
    printf("\t ==================== EdTha \n \n\n\n");


    float V,R1,R2,I,Req;

    printf("\t Informe os valores dos resistores: ");
    scanf("%f%f", &R1,&R2);

    printf("\n \t Informe o valor da tensao: ");
    scanf("%f", &V);

    Req = (R1*R2)/(R1+R2);

    I = V/Req;

    printf("\n \t A corrente I e igual a %.2f \n", I);

    return 0;

}


