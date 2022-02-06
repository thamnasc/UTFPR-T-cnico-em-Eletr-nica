/*
    APS 4 - Linguagem de Programacao

    Não foi especificado ao fim da questão a quantidade de valores possiveis para atingir um alcance de 500 metros então pegamos apenas 2:
     - velocidade inicial: 75.22m/s     angulo inicial: 30°         g: 9.8
     - velocidade inicial: 120m/s     angulo inicial:  9.947°       g: 9.8
*/
#include <stdio.h>
#include <math.h>

#define pi 3.14159265359 //Define o valor de PI

int main()
{
    float vi, ai, g, altura, distancia, AlturaMax, DistanciaMax,Tf;
    while(1) //loop para voltar o programa do começo sempre que ele acabar
    {
        printf("\n\n Insira a velocidade inicial, o angulo inicial e o valor de g: ");
        scanf("%f %f %f",&vi, &ai,&g); // Pega os valores da velocidade inicial e angulo inicial

        while(vi < 0)
        {
            printf("\nA velocidade inicial precisa ser positiva!!! \n \t favor digite outro valor: ");
            scanf("%f",&vi);
        }
        while(ai< 0 || ai >90)
        {
            printf("\nO angulo inicial precisa estar no intervalo (0,90]!!! \n \t favor digite outro valor: ");
            scanf("%f",&ai);
        }
        printf("\n");// Pular uma linha antes de mostrar os dados de saida

        ai = ai*pi/180; // converte o angulo inicial de graus para rad
        AlturaMax = pow(vi,2)*pow(sin(ai),2)/(2*g); // calculo da altura maxima
        DistanciaMax = pow(vi,2)*sin(2*ai)/g; //Calculo da distancia maxima
        Tf = 2*vi*sin(ai)/g;  //Calculo do tempo maximo

        for(int t= 0; t < Tf; t++ )
        {
            distancia = vi*cos(ai)*t;                   //Calculo da distancia em t sengundos
            altura = (vi*sin(ai)*t) - ((g*t*t)/2);      //Calculo da altura em t segundos

            printf("tempo: %2is   Altura: %6.2f   Distancia: %.2fm \n", t, altura, distancia);
        }

        printf("\n\nFim da simulacao!!\n");
        printf("tempo total: %.2fs   Altura Maxima: %.2fm   Distancia Percorrida: %.2fm \n",Tf, AlturaMax, DistanciaMax);
    }

    return 0;
}
