#include <stdio.h>

int main () {

    float x,fx;

    printf("Informe o <x>: ");
    scanf("%f", &x);

    if (x<0) {
        fx=2*x+4;
        printf("<fx> = %.2f.", fx);
    }

    else {
        fx=x+1;
        printf("<fx> = %.2f", fx);
    }

    return 0;
}
