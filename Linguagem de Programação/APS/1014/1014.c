#include <stdio.h>

int main () {

    int X;
    float Y;

    printf("\t Informe os quilometros percorridos e \n \t os litros de combutivel gastos: \n");
    scanf("%d %f", &X,&Y);

    printf("\n \t %.3f km/l \n", X/Y);

    return 0;
}
