#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
    //fazer numeros aleatorios de acordo com a hora do computador (evitando repeticoes)
    srand(time(NULL));

    int ale[60];
    FILE *loteria;

    loteria = fopen("loteria.txt", "w");

    if(loteria==NULL)
        printf("Ocorreu um erro na criacao do arquivo. \n");

    else
    {
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<6;j++)
            {
                ale[j]=1+(rand()%60);
                printf("%02d ",ale[j]);
                fprintf(loteria, "%02d ", ale[j]);
            }

            printf("\n");
            fprintf(loteria, "\n");
        }
    }

    fclose(loteria);

    return 0;
}
