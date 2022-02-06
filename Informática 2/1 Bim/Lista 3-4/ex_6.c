 #include <stdlib.h>
 #include<stdio.h>


int main(){


     int a;


    printf("\t\tNumero para Extenso\n\n");
    printf("Digite um valor entre 1 e 9: ");
    scanf("%d", &a);

    if (a == 0){
        printf("\n\t\tZero");
    }
    else if (a == 1){
        printf("\n\t\tUm");
    }
    else if (a == 2){
        printf("\n\t\tDois");
    }
    else if (a == 3){
        printf("\n\t\tTres");
    }
    else if (a == 4){
        printf("\n\t\tQuatro");
    }
    else if (a == 5){
        printf("\n\t\tCinco");
    }
    else if (a == 6){
        printf("\n\t\tSeis");
    }
    else if (a == 7){
        printf("\n\t\tSete");
    }
    else if (a == 8){
        printf("\n\t\tOito");
    }
    else if (a == 9){
        printf("\n\t\tNove");
    }
    printf("\n\nPressione qualquer tecla para continuar. . . ");
    getch();

    return 0;
}



