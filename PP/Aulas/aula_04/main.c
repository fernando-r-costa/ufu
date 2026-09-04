#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*//Exerc�cio lista 1 - 41 e 42
    int tamanho = 5;
    int vet[tamanho];
    int maior, menor;
    int index_maior, index_menor;

    for (int i = 0; i < tamanho; i++) {
        printf("Digite o %do valor: ", i+1);
        scanf("%d", &vet[i]);
    }

    printf("O vetor eh: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vet[i]);
        if (i == 0) {
            maior = menor = vet[i];
            index_maior = index_menor = i+1;
        } else {
            if(vet[i] > maior) {
                maior = vet[i];
                index_maior = i+1;
            } else if (vet[i] < menor) {
                menor = vet[i];
                index_menor = i+1;
            }
        }
    }

    printf("\nO maior elemento eh: %d, na posicao: %d", maior, index_maior);
    printf("\nO menor elemento eh: %d, na posicao: %d", menor, index_menor);

    printf("\nO vetor invertido eh: ");
    for (int i = tamanho-1; i >= 0; i--) {
        printf("%d ", vet[i]);
    }*/

    /*//Exerc�cio 50
    int linhas = 4;
    int colunas = 4;
    int matriz[linhas][colunas];

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; i < colunas; j++) {
            if (i==j) {
                matriz[i][j] = 1;
            } else {
                    matriz[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; i < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }*/

    int linhas = 2, colunas = 3;
    int m[linhas][colunas];
    
    int i, j;
    
    int maior;
    int linha_maior, coluna_maior;
    
    for (i=0; i<linhas; i++) {
        for (j=0; j<colunas; j++) {
            scanf("%d", &m[i][j]);
            if (i == 0 && j == 0) {
                maior = m[i][j];
                linha_maior = i+1;
                coluna_maior = j+1;
            } else {
                if (m[i][j] > maior) {
                    maior = m[i][j];
                    linha_maior = i+1;
                    coluna_maior = j+1;
                }
            }
        }
    }
    
    printf("Impressão da matriz:\n");
    for (i=0; i<linhas; i++) {
        for (j=0; j<colunas; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    
    printf("\nO maior elemento é %d e ele está na linha %d, coluna %d",maior, linha_maior, coluna_maior);

    return 0;
}
