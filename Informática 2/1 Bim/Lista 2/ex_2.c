  #include <stdlib.h>
  #include<stdio.h>


  int main() {

  	int n,acm=1,melhor=0, i = 0;
  	printf("Digite quantos numeros serao sorteados: ");
  	scanf("%d", &n);
  	int a,b;
  	printf("Digite os numeros sorteados: ");

    scanf("%d", &a);
  	n--;
  	for(i = 0;i < n;i++){
  		    scanf("%d", &b);

  		if(a==b){
			acm++;}

		else{
			melhor = (acm > melhor)? acm : melhor;
			acm = 1;
			a = b;}
	}
	melhor = (acm > melhor)? acm : melhor;
	printf("Maior sequencia: %d numeros!\n\n", melhor);

printf("Pressione qualquer tecla para continuar. . . ");
getch();
	return 0;
  }


