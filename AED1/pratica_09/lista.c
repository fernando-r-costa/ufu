#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void inserirFinal(ListaCircular* lista, int capTanque, int combustivel) {
    No* novo = (No*) malloc(sizeof(No));
    if (!novo) return;
    
    novo->capTanque = capTanque;
    novo->combustivel = combustivel;
    
    if(lista->fim == NULL) {
        novo->prox = novo;
        lista->fim = novo;
    } else {
        novo->prox = lista->fim->prox;
        lista->fim->prox = novo;
        lista->fim = novo;
    }
    
}

void imprimirFrota(ListaCircular* lista) {
    if(lista->fim == NULL) {
        printf("Frota vazia\n");
        return;
    }
    
    printf("\n\n");
    
    No* atual = lista->fim->prox;
    do {
        printf("Capacidade: %d | Combustivel Atual: %d\n", atual->capTanque, atual->combustivel);
        atual = atual->prox;
    } while (atual != lista->fim->prox);
}

void abastecerFrota(ListaCircular* lista, int qtdPorCiclo) {
    if (lista->fim == NULL) {
        printf("Frota vazia\n");
        return;
    }

    No* atual;
    int qteAbastecimentos;

    do {
        qteAbastecimentos = 0;
        atual = lista->fim->prox;

        do {
            if (atual->combustivel < atual->capTanque) {
                
                atual->combustivel = atual->combustivel + qtdPorCiclo;
                
                if (atual->combustivel > atual->capTanque) {
                    atual->combustivel = atual->capTanque;
                }
                
                qteAbastecimentos++; 
            }
            
            atual = atual->prox;
            
        } while (atual != lista->fim->prox);

    } while (qteAbastecimentos > 0);
}

