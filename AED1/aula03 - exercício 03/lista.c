#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void iniciar(ListaDinamica *l, int capacidade) {
    l->elementos = (int *) malloc(capacidade * sizeof(int));
    l->tamanho = 0;
    l->capacidade = capacidade;
}

int inserir(ListaDinamica *l, int valor) {
    l->elementos[l->tamanho] = valor;
    l->tamanho++;
    
    return 1;
}

void exibir(ListaDinamica *l) {
    for(int i = 0; i < l->tamanho; i++) {
        printf("%d ", l->elementos[i]);
    }
}

int liberar(ListaDinamica *l) {
    free(l->elementos);
    
    l->elementos = NULL;
    l->tamanho = 0;
    l->capacidade = 0;
}