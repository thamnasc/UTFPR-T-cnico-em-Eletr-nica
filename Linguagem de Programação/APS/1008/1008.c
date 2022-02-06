#include <stdio.h>

int main () {

    int num,h;
    float salh;

    printf("\t Informe seu numero, \n \t horas trabalhadas e \n \t quanto recebe por hora: \n");
    scanf("%d%d %f", &num,&h,&salh);

    printf("\n \t NUMBER = %d \n \t SALARY = U$ %.2f \n", num,salh*h);

    return 0 ;
}
