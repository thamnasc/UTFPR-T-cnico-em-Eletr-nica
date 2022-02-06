#include <stdio.h>
#include <math.h>


int main () {


    float base,altura,area,per,diag;

    printf("Informe o valor dos lados: \n");
    scanf("%f%f", &base,&altura);

    area = base*altura;
    per = 2*base+2*altura;
    diag = sqrt(pow(base,2)+pow(altura,2));

    printf("\t A area e %.2f\n \t o perimetro e %.2f \n \t e a diagonal e %f.2\n", area,per,diag);

    return 0;

}
