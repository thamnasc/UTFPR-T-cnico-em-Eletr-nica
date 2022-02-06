#include <stdio.h>
#define COND 1000

int vs[COND] = {0};

int main (void) {
    int qv = 0, i = 0, vl = 0, pa = 0, j = 0;
    printf("Quantidade de digitos: ");
    scanf("%d", &qv);
    printf("\nDigite os valores menos um: ");
    for(j = qv; j > 0; j--){

        pa += j;
    }
    for(i = 0; i < qv - 1; i++){

        scanf("%d", &vs[i]);
    }
    for(i = 0; i < qv -1; i++){
        vl = vl + vs[i];
    }

    printf("\nO valor faltante e: %d",pa-vl);

    printf("\n\nPressione qualquer tecla para continuar. . . ");
    getch();
    return 0;
}
