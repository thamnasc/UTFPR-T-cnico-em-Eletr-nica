#include <stdio.h>
#define MAX 50

int aux=0;
int eleA ,eleB ,eleU ,eleI,maior ;
int vetorA[MAX],vetorB[MAX],auxiliar[2*MAX],intersec[MAX],sub[MAX],uniao[2*MAX];

int d=0,e=0; //controle para intersecao (d) e diferenca (e)

void ordena(int vetor[],int ele)
{
    for(int i=0;i<ele;i++)//organiza o vetor auxiliar por ordem crescente
    {
        for(int j=i+1;j<ele;j++)
        {
            if(vetor[i]>vetor[j])
            {
                aux=vetor[i];
                vetor[i] = vetor[j];
                vetor[j]= aux;
            }
        }
    }
}


void pegando_valores()
{
    //definicao de numeros de elementos dos vetores
    printf("Informe a quantia de elementos dos vetores A e B: \n");
    scanf("%d%d",&eleA,&eleB);


    //recebimento dos elementos do vetor1 e vetor2
    printf("Informe os numeros do vetor 1: \n");

    for(int j=0;j<eleA;j++)
        scanf("%d",&vetorA[j]);

    printf("Informe os numeros do vetor 2: \n");

    for(int j=0;j<eleB;j++)
        scanf("%d",&vetorB[j]);
}

void fazendo_operacoes()
{

    eleU = eleA+eleB;

    //Fazendo a Uniao

    for(int i=0;i<eleA;i++)//passa o vetorA para o vetor auxiliar
        auxiliar[i]=vetorA[i];

    for(int i=0;i<eleB;i++)//passa o vetorB para o final do vetor auxiliar
        auxiliar[i+eleA]=vetorB[i];


    uniao[0] = auxiliar[0];
    aux=0;
    for(int i=1;i<eleU;i++)//passa o vetor auxiliar para o vetor uniao verificando se ha numeros duplicados
    {
        if(auxiliar[i] != uniao[aux])//verifica se jaa tem o numero no vetor uniao e caso nao tenha passa o valor para o uniao
        {
            uniao[aux+1] = auxiliar[i];
            aux++;
        }
    }



    //Fazendo a intersecao

    if(eleA>eleB)
        eleI=eleB;
    else
        eleI=eleA;

    for(int i=0; i<eleI;i++)
    {

    }



}

void printando()
{

    // mostrando onjunto uniao
    printf("\n\n CONJUNTO UNIAO = { %i",auxiliar[0]);
    for(int i =1; i<=aux;i++)
    {
        printf(", %i",uniao[i]);
    }
    printf(" }\n");







/*
    //mostrando conjunto intersecção
    printf("\n\n CONJUNTO INTERSECCAO = { ");
    for(int i =0; i<eleI;i++)
    {
        printf("%i, ",intersec[i]);
    }
    printf(" }\n");

    //mostrando conjunto sub
    printf("\n\n CONJUNTO Sub = { ");
    for(int i =0; i<e;i++)
    {
        printf("%i, ",sub[i]);
    }
    printf(" }\n");*/

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
