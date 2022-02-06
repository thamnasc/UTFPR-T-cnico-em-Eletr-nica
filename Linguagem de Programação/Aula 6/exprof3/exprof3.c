#include <stdio.h>

int main()
{
    float weight,height,imc;
    while(1){
    printf("\nInforme o seu peso e a altura:\n");
    scanf("%f%f",&weight,&height);

    imc=weight/(height*height);

    if(imc<16)
        printf("Magreza grave\n");
    else if(imc<17)
        printf("Magreza moderada\n");
    else if(imc<18.5)
        printf("Magreza leve\n");
    else if(imc<25)
        printf("Peso normal\n");
    else if(imc<30)
        printf("Sobrepeso\n");
    else if(imc<35)
        printf("Obesidade Grau I\n");
    else if(imc<40)
        printf("Obesidade Grau II (severa)\n");
    else
        printf("Obesidade Grau III (morbida)\n");
    }
    return 0;
}

