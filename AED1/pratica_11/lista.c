#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

typedef struct No {
    int id;
    struct No* ant;
    struct No* prox;
} No;

void inserirInicio(No** cabeca, int id) {
    No* novo = (No*) malloc(sizeof(No));
    
    if (novo == NULL) {
        printf("Falha no inicio da lista");
        return;
    }
    
    novo->id = id;
    
    if (*cabeca == NULL) {
        novo->ant = novo;
        novo->prox = novo;
        *cabeca = novo;
    } else {
        No* ultimo = (*cabeca)->ant;
        
        novo->prox = *cabeca;
        novo->ant = ultimo;
        
        (*cabeca)->ant = novo;
        ultimo->prox = novo;
        *cabeca = novo;
    }
}

void removerNo(No** cabeca, No* alvo) {
    if (alvo->prox == alvo) {
        *cabeca = NULL;
    } else {
        if(*cabeca == alvo) {
            *cabeca = alvo->prox;
        }
        
        alvo->ant->prox = alvo->prox;
        alvo->prox->ant = alvo->ant;
    }

    free(alvo);
}

void imprimirFrente(No* cabeca) {
    if(cabeca == NULL) {
        printf("Lista vazia");
        return;
    }
    
    No* atual = cabeca;
    
    do {
        printf("%d ", atual->id);
        atual = atual->prox;
    } while (atual != cabeca);
    
}

void imprimirTras(No* cabeca) {
    if(cabeca == NULL) {
        printf("Lista vazia");
        return;
    }
    
    No* atual = cabeca;
    
    do {
        printf("%d ", atual->id);
        atual = atual->ant;
    } while (atual != cabeca);
    
}

int escolherLider(No** cabeca, int k) {
    No* caixa = *cabeca;
    No* ficaCaixa = NULL;
    
    int gira = 0;
    
    while (caixa->prox != caixa) {
        
        if(gira == 0) {
            for(int i = 0; i < (k-1); i++) {
                caixa = caixa->prox;
            }
            
            ficaCaixa = caixa->ant;
            
            removerNo(cabeca, caixa);
            gira = !gira;
            caixa =  ficaCaixa;
        } else if(gira == 1) {
            for(int i = 0; i < (k-1); i++) {
                caixa = caixa->ant;
            }
            
            ficaCaixa = caixa->prox;
            removerNo(cabeca, caixa);
            gira = !gira;
            caixa = ficaCaixa;
        }
        
    }
    
    printf("O lider é: %d", caixa->id);
    return caixa->id;
}