#include <stdio.h>
#include <math.h>


int main () {

    printf(" \n\n\n \t ================================ \n");
    printf("\t ====LINGUAGEM DE PROGRAMACAO==== \n");
    printf("\t =========== AULA 03 ============ \n");
    printf("\t ==================== EdTha \n \n\n\n");


    float x,fx;

    printf("\t Informe o valor do x: ");
    scanf("%f", &x);

    fx = cos(2*x) + 1;

    printf("\n \t O valor da equacao e %.4f \n", fx);

    return 0;

}


