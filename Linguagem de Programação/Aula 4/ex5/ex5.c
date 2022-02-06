#include <stdio.h>

int main (void) {

        int choice;
        float x,y;
        char op;


        printf("\n \t Informe os numeros x e y e o operador: ");
        scanf("%f%f %c", &x,&y, &op);

        printf("\n \t Voce deseja executar por if/else ou switch/case? \n \t (1 para if, 2 para switch)");
        scanf("%i", &choice);

        if (choice==2) {

            switch (op) {

                case '+':
                    printf("\n \t A soma e %.2f.", x+y);
                    break;

                case '-':
                      printf("\n \t A subtracao e %.2f.", x-y);
                    break;

                case '*':
                      printf("\n \t A multiplicacao e %.2f.", x*y);
                    break;

                case '/':
                    if (y!=0)
                        printf("\n \t A divisao e %.2f", x/y);
                    else {
                          printf("\n \t A operacao nao pode ser executada.", x+y);
                    }
                    break;

                default :
                    printf("\n \t A operacao é invalida.");
            }
        }

        else {

            if (op=='+') {
                printf("\n \t A soma e %.2f.", x+y);
            }
            else if (op=='-') {
                printf("\n \t A subtracao e %.2f.", x-y);
            }
             else if (op=='*') {
                printf("\n \t A multiplicacao e %.2f.", x-y);
            }
            else if (op=='/') {
                    if (y!=0) {
                        printf("\n \t A divisao e %.2f", x/y);
                    }
                    else {
                          printf("\n \t A operacao nao pode ser executada.", x+y);
                    }
            }
            else {
                printf("\n \t A operacao é invalida.");
                    printf("\n \t A operacao é invalida.");
            }
        }

    return 0;

}
