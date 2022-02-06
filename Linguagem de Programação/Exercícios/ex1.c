#include <stdio.h>
#define MAX 50

int eleU=0,aux;
int eleA ,eleB ,eleaux ,eleI,maior ;
int vetorA[MAX],vetorB[MAX],auxiliar[2*MAX],intersec[MAX],sub[MAX],uniao[2*MAX];

void pegando_valores()
{
    //definicao de numeros de elementos dos vetores
    printf("Informe a quantia de elementos dos vetores A e B: \n");
    scanf("%d%d",&eleA,&eleB);


    //recebimento dos elementos do vetor1 e vetor2
    printf("Informe os numeros do vetor A: \n");

    for(int j=0;j<eleA;j++)
        scanf("%d",&vetorA[j]);

    printf("Informe os numeros do vetor B: \n");

    for(int j=0;j<eleB;j++)
        scanf("%d",&vetorB[j]);

    // ordenando o vetorA em ordem crescente
    for(int i=0;i<eleA;i++)
    {
        for(int j=i+1;j<eleA;j++)
        {
            if(vetorA[i]>vetorA[j])
            {
                aux=vetorA[i];
                vetorA[i] = vetorA[j];
                vetorA[j]= aux;
            }
        }
    }
    // ordenando o vetorB em ordem crescente
    for(int i=0;i<eleB;i++)
    {
        for(int j=i+1;j<eleB;j++)
        {
            if(vetorB[i]>vetorB[j])
            {
                aux=vetorB[i];
                vetorB[i] = vetorB[j];
                vetorB[j]= aux;
            }
        }
    }
}

void fazendo_operacoes()
{

    eleaux = eleA+eleB;

    //Fazendo a Uniao

    for(int i=0;i<eleA;i++)//passa o vetorA para o vetor auxiliar
        auxiliar[i]=vetorA[i];

    for(int i=0;i<eleB;i++)//passa o vetorB para o final do vetor auxiliar
        auxiliar[i+eleA]=vetorB[i];

    for(int i=0;i<eleaux;i++)//organiza o vetor auxiliar por ordem crescente
    {
        for(int j=i+1;j<eleaux;j++)
        {
            if(auxiliar[i]>auxiliar[j])
            {
                aux=auxiliar[i];
                auxiliar[i] = auxiliar[j];
                auxiliar[j]= aux;
            }
        }
    }
    uniao[0] = auxiliar[0];eleU=0;
    for(int i=1;i<eleaux;i++)//passa o vetor auxiliar para o vetor uniao verificando se ha numeros duplicados
    {
        if(auxiliar[i] != uniao[eleU])//verifica se jaa tem o numero no vetor uniao e caso nao tenha passa o valor para o uniao
        {
            uniao[eleU+1] = auxiliar[i];
            eleU++;
        }
    }



    //Fazendo a intersecao

}

void printando()
{
    // mostrando vetorA
    printf("\n\n VetorA = { %i",vetorA[0]);
    for(int i =1; i<eleA;i++)
    {
        printf(", %i",vetorA[i]);
    }
    printf(" }\n");

    // mostrando vetorB
    printf(" vetorB = { %i",vetorB[0]);
    for(int i =1; i<eleB;i++)
    {
        printf(", %i",vetorB[i]);
    }
    printf(" }\n");

    // mostrando onjunto uniao
    printf("\n\n CONJUNTO UNIAO = { %i",uniao[0]);
    for(int i =1; i<=eleU;i++)
    {
        printf(", %i",uniao[i]);
    }
    printf(" }\n");

}
int main ()
{
    while(1)
    {
        pegando_valores();


         //operacoes
        fazendo_operacoes();

        //mostrar ao usuario os vetores finais
        printando();
    }


    return 0;
}
