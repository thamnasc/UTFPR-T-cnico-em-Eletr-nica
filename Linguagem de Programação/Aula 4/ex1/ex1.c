#include <stdio.h>

int main () {

    int num;

    while(1){

    printf("\n\n\n\n \t Informe o numero: ");
    scanf("%d", &num);

    if ((num%2)==0) {

        printf("\n \t O numero %d e par.", num);
    }

    else {

        printf("\n \t O numero %d e impar.", num);
    }
    }
    return 0;
}
