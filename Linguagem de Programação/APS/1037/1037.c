#include <stdio.h>

int main () {

    float num;

    printf("\t Informe o numero: \n");
    scanf("%f", &num);

    if (num>=0&&num<=25)
        printf("\tIntervalo [0,25]\n");
    else if (num>25&&num<=50)
        printf("\tIntervalo (25,50]\n");
    else if (num>50&&num<=75)
        printf("\tIntervalo (50,75]\n");
    else if (num>75&&num<=100)
        printf("\tIntervalo (75,100]\n");
    else
        printf("\tFora de intervalo\n");

    return 0;
}
