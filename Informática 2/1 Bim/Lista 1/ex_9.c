
 #include <stdlib.h>
 #include<stdio.h>

int main(){


    char nome[25];
     double c,b;

    printf("Salario = Fixo + 15/100 das vendas! \n\n");

     printf("Digite seu nome: ");
     scanf("%s", nome);

     printf("\n\nDigite seu salario fixo: ");
     scanf("%lf", &c);

     printf("Valor em vendas: ");
     scanf("%lf", &b);





    printf("\nTOTAL = R$ %0.2lf\n\n", c + ((b/100)*15));
getchar();
getchar();

    return 0;
}

