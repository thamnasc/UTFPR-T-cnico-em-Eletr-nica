#include <stdio.h>
#include <stdlib.h> // necessario para usar a funcao exit
#define N 5 // quantidade de funcionarios


typedef struct{ // criando variavel  tipo funcionario
        int codigo;
        char nome[30];
        float salario;
} funcionario;


void saida()// funcao usada para ver se o usuario deseja sair do programa ou continuar
{
    int fazer;
    printf("\n\n\t (0) Sair");
    printf("\t (1) Voltar ao menu\n");
    scanf("%i",&fazer);
    while(!(fazer == 0 || fazer==1 ))
    {
        printf("\n\t Numero digitado invalido!!!\n\t Favor informar outro numero: ");
        scanf("%i",&fazer);
    }
    printf("\n\n\n\n\n\n\n");
    if(fazer== 0)
        exit(0);
}

void pede_pessoa (funcionario pessoa[]) //funcao utilizada para pegar as informacoes do usuario
{
    for(int i=1; i<= N;i++)
    {
        printf("\n\t Informe o codigo do %i funcionario: ",i);
        scanf("%i", &pessoa[i-1].codigo);
        fflush(stdin);

        printf("\t Informe o nome do %io funcionario: ",i);
        scanf("%[^\n]s", pessoa[i-1].nome);
        fflush(stdin);

        printf("\t Informe o salario do %io funcionario: ",i);
        scanf("%f", &pessoa[i-1].salario);
        fflush(stdin);
    }
    saida();
}

void printando(funcionario pessoa[]) // funcao para mostrar as informacoes do usuario
{
   for(int i=1; i<=N; i++)
   {
       printf("\n\n\t Informacoes do %i funcionario: \n",i);
       printf("\t\t Codigo: %i\n",pessoa[i-1].codigo);
       printf("\t\t Nome: %s\n",pessoa[i-1].nome);
       printf("\t\t Salario: %.2f\n",pessoa[i-1].salario);

   }
   saida();
}
void med_salario(funcionario pessoa[]) // funcao para calcular a media salarial
{
    float media = 0;
    for(int i=1;i <=N;i++)
    {
        printf("\n\t Salario do %s e de R$%.2f\n",pessoa[i-1].nome,pessoa[i-1].salario);
        media += pessoa[i-1].salario;
    }
    media /= 5;
    printf("\n\n\t A media salarial dos cinco funcionarios e de R$%.2f ",media);
    saida();
}
void acrescento_percentual (funcionario pessoa[]) // funcao para acrescentar percentual de aumento no salario
{
    int cod, percentual, qts;
    printf("\n\t Informe o percentual de aumento do funcionario: %");
    scanf("%i",&percentual);

    printf("\n\t Deseja acrescentar o percentual para todos os funcionarios ou apenas um?\n");
    printf("\n\t\t (0) Acrescentar apenas a um funcionario especifico.");
    printf("\n\t\t (1) Acrescentar a todos os funcionarios.");
    scanf("%i",&qts);
    if(qts == 0) // caso deseja acrescentar o salario de um funcionario em especifico ira entrar nesse if
    {
        printf("\n\t Informe o codigo do funcionario: ");
        scanf("%i",&cod);

        // o while ira verificar se o codigo e um codigo valido ou nao
        while(!(cod == pessoa[0].codigo || cod == pessoa[1].codigo || cod == pessoa[2].codigo || cod == pessoa[3].codigo || cod == pessoa[4].codigo))
        {
            printf("\t Codigo invalido!!!");
            printf("\t Informe outro: ");
            scanf("%i",&cod);
        }

        if( cod == pessoa[0].codigo) // verificar de qual funcionario e o codigo e realizar o aumento salarial
            pessoa[0].salario += pessoa[0].salario*(percentual/100.0);
            else if( cod == pessoa[1].codigo)
                pessoa[1].salario += pessoa[1].salario*(percentual/100.0);
                else if(cod == pessoa[2].codigo)
                    pessoa[2].salario += pessoa[2].salario*(percentual/100.0);
                    else if(cod == pessoa[3].codigo)
                        pessoa[3].salario += pessoa[3].salario*(percentual/100.0);
                        else
                            pessoa[4].salario += pessoa[4].salario*(percentual/100);
    }
    else // caso deseja aumentar o salario de todos os funcionarios ira entrar nesse else
        for(int i= 0; i <N;i++)
            pessoa[i].salario += pessoa[i].salario*(percentual/100.0);
    saida();
}
int main()
{
    int opcao;
    funcionario pessoa[N];

    while(1) // while para voltar ao menu principal
    {
        printf("\n\n\n\t =============================\n");
        printf("\t =========APS 3 ex3 ==========\n");
        printf("\t =============================\n");
        printf("\t =====Linguagem de Programacao\n");

        printf("\n\n\n\t Ola usuario, o que deseja fazer?\n");
        printf("\t (1) Atualizar informacoes sobre funcionarios.\n");
        printf("\t (2) Ver informacoes dos funcionarios cadastrados.\n");
        printf("\t (3) Ver media salarial dos funcionarios cadastrados.\n");
        printf("\t (4) Acrescentar porcentual de aumento no salario de um funcionario.\n");
        printf("\n\t Digite o numero da operacao desejada: ");
        scanf("%i",&opcao);


        while(!(opcao == 1 || opcao==2 || opcao==3 || opcao==4)) // verifica se o numero digitado e uma opcao valida ou nao
        {
            printf("\n\t Numero digitado invalido!!!\n\t Favor informar outro numero: ");
            scanf("%i",&opcao);
        }
        switch(opcao) // caso seja valida ira direcionar para a opcao escolhida
        {
            case 1:
                pede_pessoa(pessoa);
                break;
            case 2:
                printando(pessoa);
                break;
            case 3:
                med_salario(pessoa);
                break;
            case 4:
                acrescento_percentual(pessoa);
                break;
        }
    }

    return 0;
}
