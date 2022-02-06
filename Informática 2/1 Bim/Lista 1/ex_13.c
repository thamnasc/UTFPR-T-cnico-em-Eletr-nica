
 #include <stdlib.h>
 #include<stdio.h>

int main(){


     int a,b,c;


    printf("\t\tO MAIOR\nDigite 3 valores!\n\n");
    printf("A   B   C\n");
     scanf("%d %d %d" , &a, &b, &c);
if ( a>b && a>c)
     printf("\n%d Eh o maior!\n\n", a);

     if ( b>c && b>a)
     printf("\n%d Eh o maior!\n\n", b);

     if ( c>b && c>a)
     printf("\n%d Eh o maior!\n\n", c);
getchar();
getchar();

    return 0;



}




