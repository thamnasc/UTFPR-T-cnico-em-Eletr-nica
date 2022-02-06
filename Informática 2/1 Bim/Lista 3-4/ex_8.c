#include <stdio.h>
#define COND 50


int main (void) {
    float vl = 0;
    int i = 0;
    float vs[COND] = {0};
        printf("\t\t MEDIA\n\n");


    printf("Digite 50 valores: ");
    for (i = 0; i < COND; i++){
        scanf("%f", &vs[i]);

    }
    for (i = 0; i < COND; i++){

        vl += vs[i];
    }

    printf("\nO Media: %.3f",vl/COND);

    printf("\n\nPressione qualquer tecla para continuar. . . ");
    getch();
    return 0;
}

