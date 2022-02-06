#include <stdio.h>
#include <stdlib.h>
#define COND 4

int main(void)
{
    int matriz[COND][COND];
    int i, j;

    printf("\t\tMATRIZ 4x4\n\n");
    printf("Insira uma Matriz de 4x4: \n\n");
    for (i = 0;i < COND;++i) {
            for(j = 0; j < COND; j++){
                scanf("%d", &matriz[i][j]);
            }
    }

    printf("\n\nDiagonal principal: ");
    for (i = 0; i < COND; i++){
        printf("%d ", matriz[i][j]);
    }

    printf("\n\nPressione qualquer tecla para continuar. . . ");
    getch();
    return(0);
}



