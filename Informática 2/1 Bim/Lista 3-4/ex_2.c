#include <stdlib.h>

int main(){
    char nome[30], a = 160;
    printf("\t\t OLA\n\n");

    printf("Insira seu nome: ");
    scanf("%s", &nome);
    printf("Ol%c, %s", a, nome);
    printf("\n\nPressione qualquer tecla para continuar. . . ");
    getch();

return 0;
}

