
 #include <stdlib.h>
 #include<stdio.h>

int main(){


     float a,b,c;


    printf("\t\tAREAS\nDigite A, B, C!\n\n");
    printf("A   B   C\n");
     scanf("%f %f %f" , &a, &b, &c);

    printf("\n\nTRIANGULO: %0.3f\n", (a*c)/2);
    printf("CIRCULO: %0.3f\n", 3.141559 * (c * c));
    printf("TRAPEZIO: %0.3f\n", ((a+b)*c)/2 );
    printf("QUADRADO: %0.3f\n", b*b);
    printf("RETANGULO: %0.3f\n\n", a*b);



getchar();
getchar();

    return 0;
}


