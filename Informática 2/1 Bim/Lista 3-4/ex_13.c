#include <stdlib.h>


int main(){

    float vp;
    printf("\t\t PROMOCAO\n\n");

    printf("Insira o valor do produto: ");

    scanf("%f", &vp);

    printf("\n\nCom a promocao ele custa %.1f R$", vp - (vp*47)/100);

    printf("\n\nPressione qualquer tecla para continuar. . . ");
    getch();

return 0;
}



