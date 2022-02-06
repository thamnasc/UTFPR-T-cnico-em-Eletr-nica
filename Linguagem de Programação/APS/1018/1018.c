#include <stdio.h>

int main ()
{
    int din,d;
    int em,cinq,vinte,dez,cinco,dois,um;

    scanf("%d", &din);

    d=din;

    em=din/100;  din=din-em*100;

    cinq=din/50;  din=din-cinq*50;

    vinte=din/20;  din=din-vinte*20;

    dez=din/10;  din=din-dez*10;

    cinco=din/5;  din=din-cinco*5;

    dois=din/2;  din=din-dois*2;

    um=din/1;  din=din-um*1;

    printf("%d\n",d);
    printf("%d nota(s) de R$ 100,00\n",em);
    printf("%d nota(s) de R$ 50,00\n",cinq);
    printf("%d nota(s) de R$ 20,00\n",vinte);
    printf("%d nota(s) de R$ 10,00\n",dez);
    printf("%d nota(s) de R$ 5,00\n",cinco);
    printf("%d nota(s) de R$ 2,00\n",dois);
    printf("%d nota(s) de R$ 1,00\n",um);

    return 0;
}
