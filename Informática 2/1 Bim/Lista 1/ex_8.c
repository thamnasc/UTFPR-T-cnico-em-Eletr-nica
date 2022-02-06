
 #include <stdlib.h>
 #include<stdio.h>

int main(){


     int a,d;
     double c,b;

    printf("Salario = Num de horas * Recebido por hora! \n\n");
     printf("Digite seu numero: ");
     scanf("%d", &a);

     printf("Numero de horas trabalhadas: ");
     scanf("%lf", &b);

    printf("Ganho por hora: ");
     scanf("%lf", &c);




    printf("\nNumero = %d", a);
    printf("\nSalario = U$ %0.2lf\n\n", b*c);
getchar();
getchar();
    return 0;
}

