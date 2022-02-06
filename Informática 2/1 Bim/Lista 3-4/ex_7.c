 #include <stdlib.h>
 #include<stdio.h>


int main(){

    system("cls || clear");
     int a;


    printf("\t\tIndentificador de Sinal\n\n");
    printf("Digite um valor: ");
    scanf("%d", &a);

    if (a < 0){
        printf("\n\t\tNumero invalido");
        printf("\n\nPressione qualquer tecla para continuar. . . ");
        getchar();
        getchar();

        main();
    }
    else{
        printf("\n\t\tNumero Validado");
        printf("\n\nPressione qualquer tecla para continuar. . . ");
        getchar();
        getchar();

        return 0;
    }



}



