#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct no {
    int elem;
    struct no *prox;
} No;

void criaListaVazia(No **l) {
    *l = NULL;
}

int insereLista(No **l, int elem) {
    No* novo;
    novo = (No*) malloc(sizeof(No));
    
    if (novo == NULL) {
        return 0;
    }
    
    novo->elem = elem;
    novo->prox = *l;
    *l = novo;
    
    return 1;
}

void imprimeLista(No **l) {
    No *atual = *l;
    
    while (atual!= NULL) {
        printf("%d\n", atual->elem);
        atual = atual->prox;
    }
}

int removerLista(No **l, int elem) {
    No *lAtual = *l;
    No *lAnterior = NULL;
    
    while (lAtual != NULL && lAtual->elem != elem) {
        lAnterior = lAtual;
        lAtual = lAtual->prox;
    }
    
    if (lAtual == NULL) {
        return 1;
    }
    
    if (lAnterior == NULL) {
        *l = lAtual->prox;
    } else {
        lAnterior->prox = lAtual->prox;
    }
    
    free(lAtual);
    return 1;
}

void buscaLista(No **l, int elem) {
    No *atual = *l;
    
    while (atual != NULL && atual->elem != elem) {
        atual = atual->prox;
    }
    
    if (atual == NULL) {
        return;
    }
    
    printf("Elemento encontrado\n\n");
}