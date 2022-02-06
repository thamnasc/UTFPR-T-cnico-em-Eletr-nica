 #include <stdlib.h>
 #include<stdio.h>


int main(){


     int a;


    printf("\t\tIndentificador de Sinal\n\n");
    printf("Digite um valor: ");
    scanf("%d", &a);

    if (a == 0){
        printf("\n\t\tZero");
    }
    else if (a > 0){
        printf("\n\t\tPositivo");
    }
    else if (a < 0){
        printf("\n\t\tNegativo");
    }
    printf("\n\nPressione qualquer tecla para continuar. . . ");
    getch();

    return 0;
}


