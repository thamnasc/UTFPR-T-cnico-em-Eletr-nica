#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x, y;

    int i, j;

    printf("\t\tMATRIZ INDENTIDADE\n\n");
    printf("Insira a quantidade de linhas: ");
    scanf("%d", &x);
    printf("Insira a quantidade de colunas: ");
    scanf("%d", &y);

    int matriz [x] [y];
    system("cls || clear");
    printf("\n\nInsira uma Matriz de %dx%d: \n\n", x, y);

    for (i = 0; i < x; ++i) {
            for(j = 0; j < y; ++j){
                scanf("%d", &matriz[i][j]);
            }
    }
    for (i = 0; i < x && i < y; i++){

        if((i != j && matriz[i][j] != 0) || (i==j && matriz[i][j]!=1)){

            printf("\n\nNao e matriz indentidade!");
            printf("\n\nPressione qualquer tecla para continuar. . . ");
            getch();
            return(0);
        }
        else {
            printf("\n\nMatriz indentidade!");
            printf("\n\nPressione qualquer tecla para continuar. . . ");
            getch();
            return(0);
        }
    }


    return(0);
}

