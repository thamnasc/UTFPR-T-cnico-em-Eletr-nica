
 #include <stdlib.h>
 #include<stdio.h>

int main(){


     int c1, c2,q1, q2;
     float v1, v2;


    printf("C = Codigo da peca, V = Valor, Q = Quantidade\n\n");
    printf("C   Q   V\n");
     scanf("%d %d %f" , &c1,&q1, &v1);
     scanf("%d %d %f" , &c2, &q2, &v2);

     printf("\n\nVALOR A PAGAR: R$ %0.2f \n\n", (v1* q1)+ (v2 * q2));

getchar();
getchar();


    return 0;
}

