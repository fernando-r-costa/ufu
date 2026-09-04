#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void inicializarLista(Descritor *l) {
    l->inicio = NULL;
    l->fim = NULL;
    l->quantidade = 0;
}

int listaVazia(Descritor *lista) {
    if (lista->quantidade == 0) {
        printf("A lista esta vazia.\n\n");
        return 1;
    }
    return 0;
}

void adicionarNoInicio(Descritor *lista, int valor) {
    
    No* novo;
    novo = (No*) malloc(sizeof(No));
    
    novo->valor = valor;
    novo->prox = lista->inicio;
    
    if (lista->quantidade == 0) {
        lista->fim = novo;
    }
    
    lista->inicio = novo;
    
    lista->quantidade++;
}

void adicionarNoFinal(Descritor *lista, int valor) {
    
    No* novo;
    novo = (No*) malloc(sizeof(No));
    
    novo->valor = valor;
    novo->prox = NULL;
    
    if (lista->quantidade == 0) {
        lista->inicio = novo;
    } else {
        lista->fim->prox = novo;
    }
    
    lista->fim = novo;
    
    lista->quantidade++;   
}


void removerDoInicio(Descritor *lista) {
    
    if (listaVazia(lista)) {
        return;
    }
    
    No* novoInicio = lista->inicio;
    
    lista->inicio = novoInicio->prox;
    
    if (lista->quantidade == 1) {
        lista->fim = NULL;
    }
    
    free(novoInicio);
    
    lista->quantidade--;
}


void removerDoFinal(Descritor *lista) {
    if (listaVazia(lista)) {
        return;
    }
    
    if (lista->quantidade == 1) {
        free(lista->inicio);
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->quantidade = 0;
        return;
    }
    
    No* novoFim = lista->inicio;
    
    while(novoFim->prox != lista->fim) {
        novoFim = novoFim->prox;
    }
    
    free(lista->fim);
    
    novoFim->prox = NULL;
    lista->fim = novoFim;
    lista->quantidade--;
}


void removerElemento(Descritor *lista, int elemento){
    if (listaVazia(lista)) {
        return;
    }
    
    No* busca = lista->inicio;
    No* anterior = NULL;
    
    while(busca != NULL && busca->valor != elemento) {
        anterior = busca;
        busca = busca->prox;
    }
    
    if (busca == NULL) {
        printf("Elemento %d nao encontrado.\n\n", elemento);
        return;
    }
    
    if (anterior == NULL) {
        lista->inicio = busca->prox;
        
        if (lista->quantidade == 1) {
            lista->fim = NULL;
        }
    } else {
        anterior->prox = busca->prox;
        
        if (busca == lista->fim) {
            lista->fim = anterior;
        }
    }
    
    free(busca);
    
    lista->quantidade--;
}

void exibirLista(Descritor *lista) {
    
    if (listaVazia(lista)) {
        return;
    }
    
    No* atual = lista->inicio;
    
    printf("Quantidade: %d\n", lista->quantidade);
    while(atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    
    printf("\n");
}


