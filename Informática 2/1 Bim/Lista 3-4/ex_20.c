#include <stdio.h>
#include <stdlib.h>
#define COND 50

int main(void)
{

    int aux;
    int *vetor;
    int i, j;

    vetor = (float*) malloc(COND*sizeof(float));
    printf("\t\tORDEM CRESCENTE\n\n");
    printf("Insira 50 valores: ");
    for (i = 0;i < COND;++i)
    {
        scanf("%d",&vetor[i]);
    }


    for (i = 0;i < COND;++i)
    for (j = 0;j < COND;++j){
        if (vetor[i] < vetor[j]){

            aux = vetor[j];
            vetor[j] = vetor[i];
            vetor[i] = aux;
        }
    }
    printf("Em ordem crescente: ");
    for(i = 0; i < COND; i++){
        printf("%d ", vetor[i]);

    }


    free(vetor);
    printf("\n\nPressione qualquer tecla para continuar. . . ");
    getch();
    return(0);


}


