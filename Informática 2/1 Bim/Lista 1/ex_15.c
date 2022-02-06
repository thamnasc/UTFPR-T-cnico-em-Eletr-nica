
 #include <stdlib.h>
 #include<stdio.h>

int main(){



     float x1, y1, x2, y2;


    printf("Distancia entre dois pontos!\n\n");
    printf("X   Y\n");
     scanf("%f %f" , &x1,&y1);
     scanf("%f %f" , &x2, &y2);

     printf("\n\nDISTANCIA: %0.4f \n\n", sqrt((pow(x2-x1, 2)+pow(y2-y1, 2))));

getchar();
getchar();

    return 0;
}


