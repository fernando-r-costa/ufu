#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

typedef struct no { 
    int item;
    struct no* prox;
} No;

No* criaListaVazia() {
    return NULL;
}

No* insereInicio (No *l, int elem) {
    No* novo;
    novo = (No*) malloc (sizeof(No));
    
    if (novo == NULL)
        return novo;
        
    novo->item = elem;
    novo->prox = l;
    return novo;
}

void imprime(No *l) {
    while (l != NULL) {
        printf("%d ", l->item);
        l = l->prox;
    }
    printf("\n");
}

void verificaListaVazia(No *l) {
    if(l == NULL) {
        printf("Lista vazia");
    } else {
        printf("A lista possui elementos\n");
    }
}