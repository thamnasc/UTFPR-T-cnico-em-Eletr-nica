
 #include <stdlib.h>
 #include<stdio.h>

int main(){


     float a,b,x;

    printf("Media entre duas notas! \n\n");
     printf("Digite a primeira nota: ");
     scanf("%f", &a);

     printf("Digite a segunda nota: ");
     scanf("%f", &b);


    printf("\nMEDIA = %0.5f\n\n", (((a*3.5)+(b*7.5))/11));

    getchar();
getchar();
    return 0;
}



