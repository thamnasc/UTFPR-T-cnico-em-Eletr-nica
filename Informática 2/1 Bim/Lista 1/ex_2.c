
#include "math.h"
#include<stdlib.h>
#include<stdio.h>




int main(){



    float rai, pi;
    pi = 3.14159;
    printf("Digite o raio para saber a area do circulo!\n\n");
    printf("Raio: ");
    scanf("%f", &rai);



    printf("Area de circulo: %0.4f\n\n", pi * (rai * rai));

getchar();
getchar();


    return 0;

}
