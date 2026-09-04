#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {
    
    int tamanho = 3;
    
    int *vetor = (int *) malloc(tamanho * sizeof(int));
    
    for (int i = 0; i < tamanho; i++) {
        printf("Digite um número: ");
        scanf("%d", &vetor[i]);
    }
    
    printf("Números digitados:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d\n", vetor[i]);
    }
    
    tamanho = 4;
    
    vetor = (int *) realloc(vetor, tamanho * sizeof(int));
    
    printf("Digite mais um número: ");
    scanf("%d", &vetor[tamanho-1]);
    
    printf("Números 1 realloc:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d\n", vetor[i]);
    }
    
    tamanho = tamanho/2;
    
    vetor = (int *) realloc(vetor, tamanho * sizeof(int));
    
    printf("Números 2 realloc:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d\n", vetor[i]);
    }
    
    free(vetor);
    
    printf("Números free:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d\n", vetor[i]);
    }
    
    vetor = NULL; 
    tamanho = 0; 
    
    printf("Números free:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d\n", vetor[i]);
    }
    
    return 0;
}