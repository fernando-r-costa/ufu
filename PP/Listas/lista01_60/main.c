#include <stdio.h>

int main()
{
	// Matriz Inca (Espiral) 4x4 Fixa
	int m[4][4] = {
		{ 1,  2,  3,  4},
		{12, 13, 14,  5},
		{11, 16, 15,  6},
		{10,  9,  8,  7}
	};

    /*// Exemplo de Matriz Aleatoria 4x4 (Valores de exemplo)
	int m[4][4] = {
		{45, 12, 88,  3},
		{99, 21,  5, 67},
		{32, 76, 10, 54},
		{ 1, 90, 23, 41}
	};*/

	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++) {
			if(i==j) {
				m[i][j]=1;
			} else {
				m[i][j]=0;
			}
		}
	}

	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++) {
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}


	return 0;
}