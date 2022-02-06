#include <stdlib.h>
#include <stdlib.h>

int main(void){

char pala[256];
int tam_tex, i, j;
printf("\t\tPALINDROMO\n\n");
printf("Insira um texto ou palavra: ");
scanf("%s", &pala);
tam_tex = strlen(pala);

for (i = 0, j = tam_tex -1; i < tam_tex/2; i++, j--){

    if (pala[i] != pala[j]){

        printf("\nNao e palindromo\n");
        printf("\n\nPressione qualquer tecla para continuar. . . ");
        getch();
        return(0);
    }


}
printf ("\nPalindromo\n");
    printf("\n\nPressione qualquer tecla para continuar. . . ");
    getch();
    return(0);





}
