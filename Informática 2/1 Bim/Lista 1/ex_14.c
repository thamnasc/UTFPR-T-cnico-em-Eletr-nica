
#include "math.h"
#include<stdlib.h>
#include<stdio.h>


int main(){


    float km, l;

    printf("Digite a distancia percorrida (Km):");
    scanf("%f", &km);
    printf("\nConsumo em litros: ");
    scanf("%f", &l);

    printf("\n%0.3f Km/l\n\n",km/l);

getchar();
getchar();

    return 0;

}
