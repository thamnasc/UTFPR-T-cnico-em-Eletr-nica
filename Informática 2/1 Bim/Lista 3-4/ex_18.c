#include <stdio.h>
#define COND 100


int main (void) {
    int vl = 0;
    int i = 0;
    int vs[COND] = {0};
        printf("\t\t Multiplo de 3\n\n");
        printf("\t\t 0...100\n\n");


    for (i = 0; i <= COND; i++){

        if( i%3 == 0){
            vl += i;

        }

    }

    printf("\nO Soma dos multiplos de 3: %d",vl);


    printf("\n\nPressione qualquer tecla para continuar. . . ");
    getch();
    return 0;
}

