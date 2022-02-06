#include <stdio.h>

int main()
{
    int decimal, bin[8] = {0,0,0,0,0,0,0,0},j=8;

    scanf("%d", &decimal);

    for(int i =0; i <8; i++)
    {
        j--;
        bin[j] = decimal%2;
        decimal = decimal/2;
    }

    for(int i=0;i<8;i++)
    {
        printf("%d", bin[i]);
    }

    return 0;
}
