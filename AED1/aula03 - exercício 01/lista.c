#include <stdio.h>
#include "lista.h"

void iniciar(Lista *l) {
    l->tamanho = 0;
}

int inserir(Lista *l, int valor) {
    l->elementos[l->tamanho] = valor;
    l->tamanho++;
    
    return 1;
}

void exibir(Lista *l) {
    for(int i = 0; i < l->tamanho; i++) {
        printf("%d ", l->elementos[i]);
    }
}