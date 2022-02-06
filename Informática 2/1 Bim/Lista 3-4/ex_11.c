 #include <stdlib.h>
 #include<stdio.h>


int main(){


     int a, i = 0;


    printf("\t\tTABUADA\n\n");
    printf("Digite um valor entre 1 e 9: ");
    scanf("%d", &a);

    for(i=1; i<=10; i++){

        printf("%d x %d = %d\n", a, i, a*i);
    }
    printf("\n\nPressione qualquer tecla para continuar. . . ");
    getch();
    return 0;
}
