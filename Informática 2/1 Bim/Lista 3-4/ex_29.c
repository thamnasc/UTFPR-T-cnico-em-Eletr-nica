#include <stdlib.h>
#include <stdlib.h>

int main(){

    char stg[2][60], aux[60];
    int i, j;
    printf("\t\tORDEM ALFABETICA\n\n");
    printf("Insira duas palavras: ");
    for (i = 0; i < 2; i++){
        scanf("%s", &stg[i]);
    }
    for (i = 0; i < 2; i++){
        for (j = 0; j < 2; j++){

            if (strcmp(stg[i], stg[j]) < 0){

                strcpy(aux, stg[i]);
                strcpy(stg[i], stg[j]);
                strcpy(stg[j], aux);
            }
        }
    }
    printf("\n\nEm ordem alfabetica: ");
    for (i = 0; i < 2; i++){

        printf("%s ", stg[i]);
    }
    printf("\n\n\nPressione qualquer tecla para continuar. . . ");
    getch();
    return (0);
}
