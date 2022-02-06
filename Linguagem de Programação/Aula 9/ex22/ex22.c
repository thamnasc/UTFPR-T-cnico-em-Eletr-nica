#include <stdio.h>
#include <string.h>
int main ()
{
    char nome[100];
    int vog=0;

    printf("Informe uma palavra:\n");
    scanf("%[^\n]s",nome);
    //strupr(s); ou dar o upper antes
    for(int i=0;i<strlen(nome);i++)
    {
        if(toupper(nome[i])=='A'||toupper(nome[i])=='E'||toupper(nome[i])=='I'||toupper(nome[i])=='O'||toupper(nome[i])=='U')
        {
            vog++;
            printf("%c\t",nome[i]);
        }
    }

    printf("\nA quantidade de vogais e %d.\n",vog);

    return 0;
}
