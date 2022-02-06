#include <stdlib.h>
#include <stdlib.h>

int main(void){

char pala[256], vog[10] = {"AaEeIiOoUu"};
int tam_tex = 0, i, j, aux = 0;
printf("\t\VOGAIS\n\n");
printf("Insira um texto ou palavra: ");
gets(pala);
tam_tex = strlen(pala);

for (i = 0; i < tam_tex; i++){
    for (j = 0; j < 10; j++)
        if (pala[i] == vog[j]){
            aux++;
        }


}
    printf("\n\n%d Vogais", aux);
    printf("\n\nPressione qualquer tecla para continuar. . . ");
    getch();
    return(0);
}

