#include <stdio.h>
#define COND 20


int main (void) {
    float vl = 0, vl2 = 0;
    int i = 0, j = 0;
    int vs[COND] = {0};
        printf("\t\t Soma e Media\n\n");


    printf("Digite 20 valores: ");
    for (i = 0; i < COND; i++){
        scanf("%d", &vs[i]);

    }
    for (i = 0; i < COND; i++){

        if( vs[i]%2 == 0){
            vl += vs[i];

        }
        else if (vs[i]%2 != 0){
            j++;
          vl2 = (vl2 + vs[i]);

        }
    }

    printf("\nO Soma dos pares: %.0f",vl);
    printf("\nO Media dos impares: %.2f",vl2/j);


    printf("\n\nPressione qualquer tecla para continuar. . . ");
    getch();
    return 0;
}


