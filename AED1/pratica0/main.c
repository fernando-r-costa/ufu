#include <stdio.h>

int pesquisa_binaria(int* vetor, int tamanho, int chave);

int main() {
    int chave, tamanho;

    scanf("%d", &chave);

    scanf("%d", &tamanho);

    int vetor[tamanho];

    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);
    }

    int res = pesquisa_binaria(vetor, tamanho, chave);
    printf("%d\n", res);

    return 0;
}

int pesquisa_binaria(int* vetor, int tamanho, int chave) {
    int comeco = 0;
    int fim = tamanho - 1;

    while (comeco <= fim) {
        int metade = comeco + (fim - comeco) / 2;

        if (vetor[metade] == chave) {
            return metade;
        } 
        
        if (vetor[metade] < chave) {
            comeco = metade + 1;
        } else {
            fim = metade - 1;
        }
    }

    return -1;
}