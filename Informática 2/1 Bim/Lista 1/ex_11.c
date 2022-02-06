
#include "math.h"
#include<stdlib.h>
#include<stdio.h>




int main(){


    float rai, pi;
    pi = 3.14159;
    printf("Digite o raio para saber o volume da esfera!\n\n");
    printf("Raio: ");
    scanf("%f", &rai);



    printf("\nVOLUME: %0.3f\n\n",((4.0/3) * pi * pow(rai, 3)));

getchar();
getchar();
    return 0;

}

