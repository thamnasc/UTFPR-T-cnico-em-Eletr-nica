 #include <stdlib.h>
 #include <stdio.h>


int main(){



     int x0,x1,x2,x3,y0,y1,y2,y3;
     printf(":::Detectando Colisoes!:::\n\n");
     printf("Digite as cordenadas X e Y de dois retangulos:\n\n");
     printf("X0 Y0 X1 Y1\n");

     scanf("%i %i %i %i", &x0,&y0,&x1,&y1);
     scanf("%i %i %i %i", &x2,&y2,&x3,&y3);

     if (x0 > x3 || x1 < x2 || y0 > y3 || y1 < y2){

        printf("\n0 = Nao tem colisao!\n\n");

          }
    else{

        printf("\n1 = Tem colisao!\n\n");

    }

printf("Pressione qualquer tecla para continuar%e. . . ", 1.54e10);
getch();
    return 0;
}


