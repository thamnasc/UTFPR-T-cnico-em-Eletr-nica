#include <stdlib.h>


int main(){

    int vazao, temp_lig;
        printf("\t\t CONSUMO\n\n");

    printf("Insira a vazao do chuveiro (l/min): ");

    scanf("%d", &vazao);
    printf("Insira o tempo ligado do chuveiro (min): ");
    scanf("%d", &temp_lig);

    printf("\n\nFoi consumido %d litros de agua", temp_lig*vazao);

    printf("\n\nPressione qualquer tecla para continuar. . . ");
    getch();

return 0;
}


