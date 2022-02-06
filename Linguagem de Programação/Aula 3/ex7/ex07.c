#include <stdio.h>
#include <math.h>


int main () {


    float catA,catB,area;

    printf("Informe o valor dos catetos A e B:/n");
    scanf("%f%f", &catA,&catB);

    area = (catA*catB)/2;

    printf("A area e %.2f", area);

}
