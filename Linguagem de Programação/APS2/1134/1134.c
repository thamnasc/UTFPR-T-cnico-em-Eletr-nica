#include <stdio.h>

int main ()
{
    int alc=0,gas=0,die=0,x;

    do
    {
        scanf("%d",&x);

        switch(x)
        {
            case 1: alc++; break;
            case 2: gas++; break;
            case 3: die++; break;
        }
    }
    while(x!=4);

    printf("MUITO OBRIGADO\n");
    printf("Alcool: %d\n",alc);
    printf("Gasolina: %d\n",gas);
    printf("Diesel: %d\n",die);

    return 0;
}
