#include <stdio.h>
#include <math.h>


int main () {


    float raio,vol,area,compr;

    printf("Informe o valor do raio: \n");
    scanf("%f", &raio);

    vol = (float)4/3*M_PI*pow(raio,3);
    area = M_PI*raio*raio;
    compr = 2*M_PI*raio;

    printf("\t O volume e %.2f\n \t A area e %.2f \n \t e o comprimento e %.2f \n", vol,area,compr);

    return 0;

}
