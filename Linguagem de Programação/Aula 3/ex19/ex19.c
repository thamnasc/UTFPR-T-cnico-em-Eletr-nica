#include <stdio.h>
#include <math.h>


int main () {

    printf(" \n\n\n \t ================================ \n");
    printf("\t ====LINGUAGEM DE PROGRAMACAO==== \n");
    printf("\t =========== AULA 03 ============ \n");
    printf("\t ==================== EdTha \n \n\n\n");


    float graus,rad, mod;

    printf("\t Informe o angulo em graus: ");
    scanf("%f", &graus);

    mod = (int)graus/360;
    graus = graus-mod*360;

    rad = (graus * M_PI)/180;

    printf("\n \t O valor do angulo em radianos e %.4f rad \n", rad);

    return 0;

}



