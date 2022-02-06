
 #include <stdlib.h>
 #include<stdio.h>


int main(){



     float a,b,c;

    printf("Media entre duas notas! \n\n");
     printf("Digite a primeira nota: ");
     scanf("%f", &a);

     printf("Digite a segunda nota: ");
     scanf("%f", &b);

     printf("Digite a terceira nota: ");
     scanf("%f", &c);


    printf("\nMEDIA = %0.1f\n\n", (((a*2)+(b*3)+(c*5))/10));
getchar();
getchar();
    return 0;
}
