#include <stdio.h>
#include <string.h>

int main ()
{
    char nome[100];

    printf("Informe um nome:\n");
    scanf("%[^\n]",nome);

    nome[100]=' ';

    for (int i=0; nome[i]!=' ';i++)
    {
        printf("%c",nome[i]);
    }

    return 0;
}
