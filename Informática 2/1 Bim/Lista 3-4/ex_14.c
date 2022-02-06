#include <stdlib.h>


int main(void){

    float peso;
    char gen[1];
    printf("Insira seu Genero: ");

    scanf("%s", &gen);


    printf("Insira seu peso: ");

    scanf("%f", &peso);


        if(gen[0] == 'f' && peso < 47){

            printf("\nCategoria - Feminino abaixo de 47 kg");
        }

        else if(gen[0] == 'f' && peso >= 47 && peso < 54){

            printf("\nCategoria - Feminino entre 47 e 54 kg");
        }

        else if(gen[0] == 'f' && peso >= 54){

            printf("\nCategoria - Feminino acima de 54 kg");
        }



        else if(gen[0] == 'm' && peso < 52){

            printf("\nCategoria - Masculino abaixo de 52 kg");
        }

        else if(gen[0] == 'm' && peso >= 52 && peso < 57){

            printf("\nCategoria - Masculino entre 52 e 57 kg");
        }

        else if(gen[0] == 'm' && peso >= 57 && peso < 63){

            printf("\nCategoria - Masculino entre 57 e 63 kg");
        }

        else if(gen[0] == 'm' && peso >= 63 && peso < 70){

            printf("\nCategoria - Masculino entre 63 e 70 kg");
        }

        else if(gen[0] == 'm' && peso >= 70){

            printf("\nCategoria - Masculino acima de 70 kg");
        }
        else{
            printf("\nValores invalidos");

        }
    printf("\n\nPressione qualquer tecla para continuar. . . ");
    getch();

return 0;
}


