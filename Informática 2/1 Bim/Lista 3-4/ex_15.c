#include <stdio.h>
#define COND 50


int main (void) {
    float vl = 0;
    int i = 0;
    int vs[COND] = {0}, media;
        printf("\t\t Media de Idade\n\n");


    printf("Digite a idade de 50 pessoas: ");
    for (i = 0; i < COND; i++){
        scanf("%d", &vs[i]);

    }
    for (i = 0; i < COND; i++){

        vl += vs[i];
    }
    media = vl/COND;
    if (media >= 0 && media <= 12){

        printf("\nO Media: %d - Criancas", media);

    }

    else if (media >= 13 && media <= 19){

        printf("\nO Media: %d - Adolecentes", media);

    }

    else if (media >= 20 && media <= 59){

        printf("\nO Media: %d - Adultos", media);

    }

    else if (media >= 60){

        printf("\nO Media: %d - Idosos", media);

    }
    else{

        printf("\nValores invalidos");
    }
    printf("\n\nPressione qualquer tecla para continuar. . . ");
    getch();
    return 0;
}


