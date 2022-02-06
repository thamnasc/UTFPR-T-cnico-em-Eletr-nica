#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int xa = 0, ya = 0, xb = 0, yb = 0;

    int i = 0, j = 0, k = 0;

    printf("\t\tMultiplicacao de matrizes\n\n");
    printf("Insira a quantidade de linhas da matriz A: ");
    scanf("%d", &xa);
    printf("Insira a quantidade de colunas da matriz A: ");
    scanf("%d", &ya);
    printf("Insira a quantidade de linhas da matriz B: ");
    scanf("%d", &xb);
    printf("Insira a quantidade de colunas da matriz B: ");
    scanf("%d", &yb);
    if ( xa == yb){
        int matriza [xa] [ya];
        int matrizb [xb] [yb];
        int matrizc [xa] [yb];
        matriza [xa] [ya] = 0;
        matrizb [xb] [yb] = 0;
        system("cls || clear");
        printf("Insira a Matriz A: \n\n");

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
            for (j = 0; j < xa; j++){
                matrizc[i][j] = 0;
                for (k = 0; k < ya; k++){

                    matrizc[i][j] = matrizc[i][j] + (matriza[i][k] * matrizb[k][j]);
                }
            }
        }
        printf("\n\nMatriz A * B = C\n\n");
        for (i=0; i<xa; i++) {
            for (j=0; j<yb; j++) {
                printf("%d ", matrizc[i][j]);

            }
            printf("\n");
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
