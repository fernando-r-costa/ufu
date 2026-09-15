#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* proximo;
} No;

int encontraMaior(No* vetor[], int tamanho_vetor) {
    int maior = 0; 
    int primeiro = 0;

    for (int i = 0; i < tamanho_vetor; i++) {
        No* atual = vetor[i];
        
        while (atual != NULL) {
            if (primeiro == 0) {
                maior = atual->valor;
                primeiro = 1;
            } 
            else if (atual->valor > maior) {
                maior = atual->valor;
            }
            
            atual = atual->proximo;
        }
    }
    return maior;
}

int main() {
    No* vetor[10] = {NULL};
    int valor, index;

    printf("Digite 5 valores inteiros:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &valor);
        
        index = abs(valor) % 10;
        
        No* novoNo = (No*)malloc(sizeof(No));
        if (novoNo == NULL) {
            printf("Erro ao alocar memoria!\n");
            return 1;
        }

        novoNo->valor = valor;
        
        novoNo->proximo = vetor[index];
        vetor[index] = novoNo;
    }

    int maiorValor = encontraMaior(vetor, 10);
    
    printf("O maior elemento armazenado e: %d\n", maiorValor);

    for (int i = 0; i < 10; i++) {
        No* atual = vetor[i];
        while (atual != NULL) {
            No* temp = atual;
            atual = atual->proximo;
            free(temp);
        }
    }

    return 0;
}