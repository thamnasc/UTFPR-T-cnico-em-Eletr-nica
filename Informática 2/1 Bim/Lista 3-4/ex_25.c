#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int det = 0, det1 = 0, det2 = 0;
    char tam_mat[1];
    int i, j;

    printf("\t\tDETERMINANTE DE MATRIZ\n\n");
    printf("Determinante matriz 2x2 - 2\nDeterminante matriz 3x3 - 3\n\nEscolha uma: ");
    scanf("%c", &tam_mat[0]);
    system("cls || clear");

    if (tam_mat[0] == '2'){
        int matriz[2][2];
        printf("Insira uma matriz 2x2:\n");
        for (i = 0; i < 2; i++){
            for (j = 0; j < 2; j++){
                scanf("%d", &matriz[i][j]);

            }
        }

        det = (matriz[0][0]*matriz[1][1])-(matriz[0][1] * matriz[1][0]);
        printf("\n\nDeterminante da matriz: %d", det);
        printf("\n\nPressione qualquer tecla para continuar. . . ");
        getch();
    }

    else if (tam_mat[0] == '3'){
        int matriz[3][3];
        printf("Insira uma matriz 3x3:\n");
        for (i = 0; i < 3; i++){
            for (j = 0; j < 3; j++){
                scanf("%d", &matriz[i][j]);

            }
        }

        det1 = ((matriz[0][0]*matriz[1][1]*matriz[2][2])+
              (matriz[0][1]*matriz[1][2]*matriz[2][0])+
              (matriz[0][2]*matriz[1][0]*matriz[2][1]));
        det2 = ((matriz[0][1]*matriz[1][0]*matriz[2][2])+
              (matriz[0][0]*matriz[1][2]*matriz[2][1])+
              (matriz[0][2]*matriz[1][1]*matriz[2][0]));
        printf("\n\nDeterminante da matriz: %d", det1 - det2);
        printf("\n\nPressione qualquer tecla para continuar. . . ");
        getch();

    }
    else {
        printf("Valor invalido!");
        printf("\n\nPressione qualquer tecla para continuar. . . ");
        getch();
        return(0);

    }




    return(0);
}
