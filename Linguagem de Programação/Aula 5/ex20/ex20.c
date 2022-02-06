#include <stdio.h>

int main ()
{
    int c1=25000,c2=30000,a=0;

    while (c1<=c2)
    {
        c1=c1+c1*0.005;
        c2=c2+c2*0.001;
        a++;
    }
     printf("Apos %d anos a cidade 1 ultrapassara a 2. \n", a);
    return 0;
}
