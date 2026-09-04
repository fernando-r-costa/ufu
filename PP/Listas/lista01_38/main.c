#include <stdio.h>

int main()
{
	int n;
	int qte = 0;
	int soma = 0;

	for(int i=0; i<10; i++) {
		printf("Digite um número: ");
		scanf("%d", &n);

		if(n>=0) {
			qte++;
			soma = soma + n;
		}
	}

	float media = soma/(float)qte;

	printf("A média dos %d números positivos digitados é: %.2f", qte, media);

	return 0;
}