#include <stdio.h>
#include <math.h>
int main()
{
    float Xa ,Xb, Ya, Yb , d;

    scanf("%f%f%f%f", &Xa, &Ya,&Xb, &Yb);

    d =  sqrt((Xb - Xa)*(Xb - Xa) +(Yb - Ya)*(Yb - Ya));

    printf("%.2f",d);
    return 0;
}
