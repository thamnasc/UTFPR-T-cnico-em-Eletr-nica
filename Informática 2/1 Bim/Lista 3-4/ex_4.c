 #include <stdlib.h>
 #include<stdio.h>


int main(){


     int a;
     int b,x;

    printf("\t\tSoma de Tres Valores\n\n");
     printf("Digite um valor: ");
     scanf("%d", &a);

     printf("Digite outro valor: ");
     scanf("%d", &b);

     printf("Digite mais um valor: ");
     scanf("%d", &x);
    printf("\nSoma = %d\n\n", a + b + x);
    printf("\n\nPressione qualquer tecla para continuar. . . ");
    getch();

    return 0;
}


