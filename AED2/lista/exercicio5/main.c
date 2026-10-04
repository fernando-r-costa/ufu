#include <stdio.h>

int main(void)
{
    int v[10] = {2, 5, 8, 12, 16, 23, 38, 56, 88, 90};
    int n = 10;
    int busca = 88;

    int inicio = 0;
    int fim = n - 1;
    int meio;
    int indBusca = -1;

    while (inicio <= fim) {
        meio = inicio + (fim - inicio) / 2;

        if (v[meio]  == busca) {
            indBusca = meio;
            break;
        } else if (v[meio] < busca) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    if (indBusca != -1) {
        printf("Número %d encontrado no indice %d.\n", busca, indBusca);
    } else {
        printf("Número %d não encontrado.\n", busca);
    }

	return 0;
}
