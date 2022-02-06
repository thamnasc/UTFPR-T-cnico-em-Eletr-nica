#include <stdio.h>
#include <math.h>


int main () {

    printf(" \n\n\n \t ================================ \n");
    printf("\t ====LINGUAGEM DE PROGRAMACAO==== \n");
    printf("\t =========== AULA 03 ============ \n");
    printf("\t ==================== EdTha \n \n\n\n");

    float real,cot,dolar;

    printf(" \n\n \t Informe a cotacao do dolar: ");
    scanf("%f", &cot);

    printf("\t Informe a quantia de dinheiro em dolar: ");
    scanf("%f", &dolar);

    real = dolar*cot;

    printf("\t O valor de dolar convertido em reais e: R$ %.2f\n", real);

    return 0;

}




