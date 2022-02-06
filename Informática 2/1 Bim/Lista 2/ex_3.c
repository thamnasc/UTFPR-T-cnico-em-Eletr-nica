 #include <stdlib.h>
 #include<stdio.h>


int main(){



     int a,b,x;

    printf("\t\tCorrida! \n\n");
     printf("Digite a distancia a percorrer: ");
     scanf("%d", &a);

     printf("Digite o comprimento da pista: ");
     scanf("%d", &b);

    x = a % b;
    printf("\nPonto de termino = %d\n\n", x);

printf("Pressione qualquer tecla para continuar. . . ");
getch();

    return 0;
}

