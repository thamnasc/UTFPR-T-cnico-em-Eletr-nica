#include <stdio.h>

int main()
{
    int n,h,m,s;

    scanf("%d", &n);

    h = n/3600; n = n - h*3600;

    m = n/60; n = n - m*60;

    s = n;

    printf("\t%d:%d:%d\n", h,m,s);

    return 0;
}
