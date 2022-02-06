
 #include <stdlib.h>
 #include<stdio.h>

int main(){


     int a,b,c;


    printf("\t\tVice-Campeao\nDigite as 3 pontuacoes!\n\n");
    printf("A   B   C\n");
     scanf("%d %d %d" , &a, &b, &c);

if ( (a>=0 && a<=100) && (b>=0 && b<=100) && (c>=0 && c<=100)){
     if ( (a>b && b>c) || (c>b && b>a) ){
     printf("\nVice-campeao: B = %d\n\n", b);}

     else if ( (b>c && c>a) || (a>c && c>b) ){
     printf("\nVice-campeao: C = %d\n\n", c);}

     else if ( (c>a && a>b) || (b>a && a>c) ){
     printf("\nVice-campeao: A = %d\n\n", a);}

     else {
        printf("Valores invalidos!");
     }
}
else {
        printf("Valores invalidos!");
     }
printf("Pressione qualquer tecla para continuar. . . ");
getch();
    return 0;



}




