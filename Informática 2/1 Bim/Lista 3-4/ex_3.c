
 #include <stdlib.h>
 #include<stdio.h>


int main(){


     int a;
     float b,x;

    printf("\t\tSOMA\n\n");
     printf("Digite um valor inteiro: ");
     scanf("%d", &a);

     printf("Digite outro valor real: ");
     scanf("%f", &b);

    x = a + b;
    printf("\nSoma = %.3f\n\n", x);
    printf("\n\nPressione qualquer tecla para continuar. . . ");
    getch();

    return 0;
}

