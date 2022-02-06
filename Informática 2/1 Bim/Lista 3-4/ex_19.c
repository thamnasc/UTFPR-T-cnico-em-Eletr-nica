#include <stdio.h>
#include <stdlib.h>
#define COND 50

int main(void)
{

    float num_max, num_min, num_med;
    float *vetor;
    int i;

    vetor = (float*) malloc(COND*sizeof(float));
    printf("\t\tMaior-Menor-Media\n\n");
    printf("Insira 50 valores: ");
    for (i = 0;i < COND;++i)
    {
        scanf("%f",&vetor[i]);
    }

    num_max = vetor[0];

    for (i = 0;i < COND;++i)
        num_med += vetor[i]/COND;

    for (i = 0;i < COND;++i)
        if (vetor[i] > num_max)
            num_max = vetor[i];
            num_min = vetor[0];

    for (i = 0;i < COND;++i)
        if (vetor[i] < num_min)
            num_min = vetor[i];

    printf("\nO maior valor: %.0f\n",num_max);
    printf("\nO menor valor: %.0f\n",num_min);
    printf("\nMedia: %.1f\n",num_med);

    free(vetor);
    printf("\n\nPressione qualquer tecla para continuar. . . ");
    getch();
    return(0);


}


