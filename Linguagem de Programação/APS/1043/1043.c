#include <stdio.h>
#include <stdlib.h>

int main ()
{
    float A,B,C,area;

    printf("Informe o lado A, B e C: \n");
    scanf("%f%f%f",&A,&B,&C);

    area=((A+B)*C)/2;

    if ((abs(B-C))<A&&A<(B+C) && (abs(A-C))<B&&B<(A+C) && (abs(A-B))<C&&C<(A+B))
        printf("Perimetro = %.1f\n",A+B+C);
    else
        printf("Area = %.1f",area);

    return 0;
}

