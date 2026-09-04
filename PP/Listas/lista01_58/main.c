#include <stdio.h>
#include <math.h>

int main()
{
	int m[10][3] = {
		{ 4, 12, 7 },
		{ 9, 1, 15 },
		{ 6, 10, 2 },
		{ 14, 3, 8 },
		{ 0, 11, 5 },
		{ 13, 6, 9 },
		{ 2, 14, 1 },
		{ 7, 4, 10 },
		{ 12, 5, 3 },
		{ 8, 0, 11 }
	};

	for(int i=0; i<10; i++) {
	    float soma = 0;
		for(int j=0; j<3; j++) {
			soma = soma + m[i][j];
		}
		float media = soma / 3.0;
		printf("A média do aluno %d foi: %.2f\n", i+1, media);
	}

	return 0;
}