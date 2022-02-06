#include <stdio.h>
#include <math.h>


int main () {

    printf(" \n\n\n \t ================================ \n");
    printf("\t ====LINGUAGEM DE PROGRAMACAO==== \n");
    printf("\t =========== AULA 03 ============ \n");
    printf("\t ==================== EdTha \n \n\n\n");

    float real,cot,dolar;

    printf("\t \n\n Informe a cotacao do dolar: \n");
    scanf("%f", &cot);

    printf("\t Informe a quantia de dinheiro em reais: \n");
    scanf("%f", &real);

    dolar = real/cot;

    printf("\t O valor de reais convertido em dolar e: US$ %.2f\n", dolar);

    return 0;

}



