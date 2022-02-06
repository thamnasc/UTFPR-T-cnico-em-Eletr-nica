#include <stdio.h>

int main ()
{
    int num,x;

    printf("Informe o numero: \n");
    scanf("%d", &num);

    x = num -1;
    if(num==2){
        printf("\n \t O numero %d e primo. \n ", num);
    }
    else if(num ==1){
        printf("\n \t O numero %d nao e primo. \n ", num);
    }
    else{
        for (;x>1;x--)
        {
            if ((num%x)==0){
                printf("\n \t O numero %d nao e primo. \n ", num);
                break;
            }
            if (x==2)
            {
                printf("\n \t O numero %d e primo. \n ", num);
            }
        }
    }
    return 0;
}


