#include <stdio.h>
#include <locale.h>
int main () {

    setlocale(LC_ALL,"portuguese");

    float n1,n2,n3,n4,med;

    printf("\n \t Informe a <nota1>, <nota2>, <nota3> e <nota4>: ");
    scanf("%f %f %f %f", &n1,&n2,&n3,&n4);

    med=(n1+n2+n3+n4)/4;

    if (med>=6) {
        printf("\n \t Sua nota é %.1f e voce esta aprovado!", med);
    }
    else {
        printf("\n \t Sua nota é %.1f e voce esta reprovado! ):", med);
    }

    return 0;
}
