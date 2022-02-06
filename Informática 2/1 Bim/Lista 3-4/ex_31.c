#include <stdio.h>
#include <stdlib.h>

    char jv[3][3];
    char O='O', X='X';
    int i =0, j =0, l = 0;
    int saida();
    int main(void) {

        for (i = 0; i < 3; i++)
            for (j = 0; j < 3; j++)
                jv[i][j] = ' ';

    while(l<=9){

        system("cls");
        printf("\t\t   Jogo da Velha \n\n\n");
        for(i=0;i<3;i++){
            printf("\t\t     %c \xBA %c \xBA %c\n",jv[i][0],jv[i][1],jv[i][2]);
            if(i<3-1){
                printf("\t\t    ÍÍÍ\xCEÍÍÍ\xCEÍÍÍ\n");
            }
        }
            if(l%2)printf("Player 2\nLINHA: ");
        else printf("Player 1\nLinha: ");

        scanf("%d",&i);
        printf("Coluna: ");
        scanf("%d",&j);

        if(jv[i-1][j-1]==' '){
            if(l%2)jv[i-1][j-1]=O;
            else jv[i-1][j-1]=X;
            l++;
        }

        if((jv[0][0]==O && jv[0][1]==O && jv[0][2]==O)||
           (jv[1][0]==O && jv[1][1]==O && jv[1][2]==O)||
           (jv[2][0]==O && jv[2][1]==O && jv[2][2]==O)||
           (jv[0][0]==O && jv[1][0]==O && jv[2][0]==O)||
           (jv[0][1]==O && jv[1][1]==O && jv[2][1]==O)||
           (jv[0][2]==O && jv[1][2]==O && jv[2][2]==O)||
           (jv[0][0]==O && jv[1][1]==O && jv[2][2]==O)||
           (jv[0][2]==O && jv[1][1]==O && jv[2][0]==O)){
            system("cls || clear");
               for(i=0;i<3;i++){
            printf("\t\t     %c \xBA %c \xBA %c\n",jv[i][0],jv[i][1],jv[i][2]);
            if(i<3-1){
                printf("\t\t    ÍÍÍ\xCEÍÍÍ\xCEÍÍÍ\n");
            }
        }
            printf("\n\n\n\n\a\t\tPlayer 2 Ganhou!");

            saida();

            break;
        }

        else if((jv[0][0]==X && jv[0][1]==X && jv[0][2]==X)||
           (jv[1][0]==X && jv[1][1]==X && jv[1][2]==X)||
           (jv[2][0]==X && jv[2][1]==X && jv[2][2]==X)||
           (jv[0][0]==X && jv[1][0]==X && jv[2][0]==X)||
           (jv[0][1]==X && jv[1][1]==X && jv[2][1]==X)||
           (jv[0][2]==X && jv[1][2]==X && jv[2][2]==X)||
           (jv[0][0]==X && jv[1][1]==X && jv[2][2]==X)||
           (jv[0][2]==X && jv[1][1]==X && jv[2][0]==X)){
               system("cls || clear");
               for(i=0;i<3;i++){
            printf("\t\t     %c \xBA %c \xBA %c\n",jv[i][0],jv[i][1],jv[i][2]);
            if(i<3-1){
                printf("\t\t    ÍÍÍ\xCEÍÍÍ\xCEÍÍÍ\n");
            }
        }
            printf("\n\n\n\n\a\t\tPlayer 1 Ganhou!");
            saida();
            break;
        }

        else if (l == 9){
                  system("cls || clear");
                for(i=0;i<3;i++){
            printf("\t\t     %c \xBA %c \xBA %c\n",jv[i][0],jv[i][1],jv[i][2]);
            if(i<3-1){
                printf("\t\t    ÍÍÍ\xCEÍÍÍ\xCEÍÍÍ\n");
            }
        }
            printf("\n\n\n\n\a\t\tVelha!");
            saida();

            break;
        }
}
    return(0);

    }
saida(){
    l = 0;
    char sn[4];
    printf("\n\nPressione qualquer tecla para continuar. . . ");
    getchar();
    getchar();
    system("clear || cls");
    printf("\nDeseja reiniciar? S/N: ");
    scanf("%s", sn);
    sn[0] = toupper(sn[0]);
    if (sn[0] == 'S'){
        main();
    }
    else {
        return EXIT_SUCCESS;
    }
}


