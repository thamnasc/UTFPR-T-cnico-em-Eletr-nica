#include <stdio.h>
#define COND 4


int main (void) {
    float vl = 0;
    int i = 0;
    float vs[COND] = {0}, media;

    printf("Digite 4 notas: ");
    for (i = 0; i < COND; i++){
        scanf("%f", &vs[i]);
        if(vs[i] < 0){
            printf("\n Valor invalido!");
            printf("\n\nPressione qualquer tecla para continuar. . . ");
            getch();
            return 0;
        }
    }
    for (i = 0; i < COND; i++){

        vl += vs[i];
    }
    media = vl/COND;

    if (media >= 6.0 && media <= 10.0){

        printf("\n%.1f - Aprovado!",media);
        printf("\n\nPressione qualquer tecla para continuar. . . ");
        getch();
        return 0;
    }
    else if (media < 6.0 && media >= 4.0){

        printf("\n%.1f - Exame Final!",media);
        printf("\n\nPressione qualquer tecla para continuar. . . ");
        getch();
        return 0;
    }
    else if (media < 4.0 && media >= 0.0){

        printf("\n%.1f - Reprovado!",media);
        printf("\n\nPressione qualquer tecla para continuar. . . ");
        getch();
        return 0;
    }
    else {


        printf("\nValores invalidos!",media);
        printf("\n\nPressione qualquer tecla para continuar. . . ");
        getch();
        return 0;
    }
}


