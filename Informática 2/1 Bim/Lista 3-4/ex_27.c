#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int xa = 0, ya = 0, xb = 0, yb = 0, xc = 0, yc = 0;

    int i = 0, j = 0, k = 0;

    printf("\t\tSoma matricial!\n\n");
    printf("Insira a quantidade de linhas da matriz A: ");
    scanf("%d", &xa);
    printf("Insira a quantidade de colunas da matriz A: ");
    scanf("%d", &ya);

    printf("Insira a quantidade de linhas da matriz B: ");
    scanf("%d", &xb);
    printf("Insira a quantidade de colunas da matriz B: ");
    scanf("%d", &yb);
    if ( xa == xb && yb == ya){
        int matriza [xa] [ya];
        int matrizb [xa] [ya];
        int matrizc [xa] [yb];

        matriza [xa] [ya] = 0;
        matrizb [xa] [ya] = 0;
        matrizc [xa] [yb] = 0;
        system("cls || clear");
        printf("\n\nInsira a Matriz A: \n\n");

        for (i = 0; i < xa; ++i) {
            for(j = 0; j < ya; ++j){
                scanf("%d", &matriza[i][j]);
            }
        }

        printf("\n\nInsira a Matriz B: \n\n");
        for (i = 0; i < xb; i++){
            for(j = 0; j < yb; ++j){
                scanf("%d", &matrizb[i][j]);
            }

        }

        for (i = 0; i < xa; i++){
            for (j = 0; j < ya; j++){
                matrizc[i][j] = matriza[i][j] + matrizb[i][j];
            }
        }

        printf("\n\nMatriz A + B = C\n");
        for (i = 0; i < xa; i++){
            printf("\n");
            for (j = 0; j < ya; j++){
                printf("%d ", matrizc[i][j]);
            }
        }

        printf("\n\nPressione qualquer tecla para continuar. . . ");
        getch();
        return(0);

    }
    else {

        printf("\n\nMatrizes invalidas!");
        printf("\n\nPressione qualquer tecla para continuar. . . ");
        getch();
        return(0);


    }

    return(0);
}
