#include <stdio.h>

int main () {

    double A,B,C,med;

    printf("\t \n Informe as tres notas: \n");
    scanf("%lf%lf%lf", &A,&B,&C);

    med=(A*2+B*3+C*5)/10;

    printf("\n \t MEDIA = %.1lf \n", med);

    return 0;
}
