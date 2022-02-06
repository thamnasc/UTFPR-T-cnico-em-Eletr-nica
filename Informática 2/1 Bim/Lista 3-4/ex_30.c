#include <stdlib.h>
#include <stdlib.h>

int main(void){

    char pala[256], x = 'x';
    int tam_tex = 0, i, j, aux = 0;
    printf("\t\Par = X\n\n");
    printf("Insira um texto ou palavra: ");
    gets(pala);
    tam_tex = strlen(pala);

    for (i = 0; i < tam_tex; i++){
        if (i%2 == 0){
            pala[i] = x;
        }
    }
    printf("\n\n");
    for (i = 0; i < tam_tex; i++){
           printf("%c",pala[i]);
    }
    printf("\n\nPressione qualquer tecla para continuar. . . ");
    getch();
    return(0);

}

