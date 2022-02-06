#include <stdio.h>
#define COND 100


int main (void) {
    int i = 0;
    int vs[COND] = {0};
        printf("\t\t Fizz-Buzz\n\n");



    for (i = 1; i <= COND; i++){

        if( i%3 == 0 && i%5 == 0){
            printf("FizzBuzz\n");

        }

        else if (i%5 == 0 ){
            printf("Buzz\n");
        }
        else if (i%3 == 0 ){
            printf("Fizz\n");
        }

        else {
            printf("%d\n", i);
        }

    }
    printf("\n\nPressione qualquer tecla para continuar. . . ");
    getch();
    return 0;
}



