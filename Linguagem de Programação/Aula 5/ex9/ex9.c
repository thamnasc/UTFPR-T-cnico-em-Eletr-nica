#include <stdio.h>

int main(){

    float S, num, dem, i;
    S = 0;

    for (dem=1,num=1;dem<51;dem++,num=num+2)
    {
        S = S + num/dem;
        printf("\n %.0f / %.0f", num ,dem);
    }

    printf("\n O valor de S e %.2f",S);

    return 0;
}
