#include <stdio.h>

int main()
{
	float n1, n2, resultado;
	int opcao;
	int tentativas = 0;
	int max_tentativas =3;

	while(tentativas < max_tentativas) {

		printf("> Escolha a opaoo:\n");
		printf("\t1- Soma de 2 numeros\n");
		printf("\t2- Diferenca entre 2 numeros\n");
		printf("\t3- Produto entre 2 numeros\n");
		printf("\t4- Divisao entre 2 numeros (obs.: o denominador nao pode ser zero)\n");
		scanf("%d", &opcao);

		if(opcao==1 || opcao==2 || opcao==3 || opcao==4) {
			printf("Opcao: %d\n", opcao);
		    break;
		} else {
			printf("Opcao invalida");
			tentativas++;
			if(tentativas == max_tentativas) {
			    return 0;
			}
		}
	}

	printf("Digite o primeiro numero: ");
	scanf("%f", &n1);
	printf("Digite o secundo numero: ");
	scanf("%f", &n2);

	switch(opcao) {
	case 1 :
		resultado = n1+n2;
		break;
	case 2 :
		resultado = n1-n2;
		break;
	case 3 :
		resultado = n1*n2;
		break;
	case 4 :
		resultado = n1/n2;
		break;
	}

	printf("Resultado: %f", resultado);

	return 0;
}
