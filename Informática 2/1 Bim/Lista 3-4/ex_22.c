#include <stdlib.h>
#include <stdlib.h>

int main(void){

char pala[256];
int i = 0, j = 0;
printf("\t\tINVERSO\n\n");
printf("Insira um texto ou palavra: ");
gets(pala);

while (pala[i]) {
    j++;
    i++;
}
printf("\n\nOrdem inversa:\n\n");

for(i = j; i >= 0; i--) {

    if (pala[i]) {
        printf("%c", pala[i]);
    }
}
    printf("\n\nPressione qualquer tecla para continuar. . . ");
    getch();
    return(0);
}

