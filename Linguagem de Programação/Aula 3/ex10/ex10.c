#include <stdio.h>
#include <math.h>


int main () {


    float a,b,c,d,e,f,x,y,etapa1,etapa2;

    printf("Informe os coeficientes de a, b, d e e: \n");
    scanf("%f%f%f%f", &a,&b,&d,&e);

    printf("Informe os resultados c e f: \n");
    scanf("%f%f", &c,&f);

    y = (c*d - f*a)/(-e*a +b*d); //x=x,

    x = (c-b*y)/a; //substitui y em x, acha x


    printf("\t X = %.2f e \n \t Y = %.2f \n", x,y);

    return 0;

}

