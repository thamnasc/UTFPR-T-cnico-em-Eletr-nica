#include <stdio.h>
#define MAX 50

int eleU=0,aux=0;
int eleA=0,eleB=0,eleaux=0,eleI=0,eleD=0;
int vetorA[MAX],vetorB[MAX],auxiliar[2*MAX],intersec[MAX],dif[MAX],uniao[2*MAX];

void pegando_valores()
{
    //definicao de numeros de elementos dos vetores
    printf("Informe a quantia de elementos dos vetores A e B: \n");
    scanf("%d%d",&eleA,&eleB);

    //recebimento dos elementos do vetorA e vetorB
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

void uniao_op ()
{
    eleaux = eleA+eleB;

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

    uniao[0] = auxiliar[0];

    for(int i=1;i<eleaux;i++)//passa o vetor auxiliar para o vetor uniao verificando se ha numeros duplicados
    {
        if(auxiliar[i] != uniao[eleU])//verifica se ja tem o numero no vetor uniao e caso nao tenha passa o valor para o uniao
        {
            uniao[eleU+1] = auxiliar[i];
            eleU++;
        }
    }
}

void intersec_op ()
{
    eleaux=0;

    //zerando vetor auxiliar
    for(int i=0;i<eleaux;i++)
    {
        auxiliar[i]=0;
    }

    //caso o elemento de vetorA seja igual ao do vetorB, o auxiliar recebe o elemento
    for(int i=0;i<eleA;i++)
    {
        for(int j=0;j<eleB;j++)
        {
            if(vetorA[i] == vetorB[j])
            {
                auxiliar[eleaux] = vetorB[j];
                eleaux++;
            }
        }
    }

    //retirando numeros repetidos

    intersec[0]=auxiliar[0];

    //caso o elemento nao seja repetido entre os vetores auxiliar e intersec, e passado para elemento+1 de intersec
    for(int i=1;i<eleaux;i++)
    {
        if(auxiliar[i] != intersec[eleI])
        {
            intersec[eleI+1] = auxiliar[i];
            eleI++;
        }
    }

}

void dif_op ()
{
    aux=0;

    //caso o elemento do vetorA seja diferente de todos do vetor B, vetor dif recebe o elemento do vetorA
    for(int i=0;i<eleA;i++)
    {
        for(int j=0;j<eleB;j++)
        {
            if(vetorA[i] != vetorB[j])
                aux++;
        }

        if(aux==eleB)
        {
            dif[eleD] = vetorA[i];
            //if(i<eleA-1)
                eleD++;
        }

        aux=0;
    }
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

     // mostrando onjunto intersecao
    printf("\n\n CONJUNTO INTERSECAO = { %i",intersec[0]);
    for(int i =1; i<=eleI;i++)
    {
        printf(", %i",intersec[i]);
    }
    printf(" }\n");

    // mostrando onjunto diferenca
    printf("\n\n CONJUNTO DIFERENCA = { %i",dif[0]);
    for(int i =1; i<eleD;i++)
    {
        printf(", %i",dif[i]);
    }
    printf(" }\n");
}
int main ()
{
        pegando_valores();

         //operacoes
        uniao_op();
        intersec_op();
        dif_op();

        //mostrar ao usuario os vetores finais
        printando();

    return 0;
}
