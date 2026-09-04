#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// Função para inserir no final da lista circular
void inserirFinal(ListaCircular* lista, int valor) {
    No* novo = (No*) malloc(sizeof(No));
    if (!novo) return;
    novo->dado = valor;

    if (lista->fim == NULL) {
        novo->prox = novo;
        lista->fim = novo;
    } else {
        No* atual = lista->fim;
        novo->prox = atual->prox;
        lista->fim = novo;
        atual->prox = novo;
    }
}

// Função para imprimir a lista circular de forma iterativa
void imprimirLista(ListaCircular* lista) {
    if (lista->fim == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    No* atual = lista->fim->prox;
    do {
        printf("%d -> ", atual->dado);
        atual = atual->prox;
    } while (atual != lista->fim->prox);
    printf("(volta ao inicio)\n");
}

// Função interna recursiva para impressão
void imprimirListaRec(No* atual, No* inicio) {
    if (atual == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    if (atual->prox == inicio)  
        printf("%d ", atual->dado);
    else {
        printf("%d ", atual->dado); 
        imprimirListaRec(atual->prox, inicio);
    } 
}

// Função principal (wrapper) que inicia a recursão da impressão
void imprimirRecursiva(ListaCircular* lista) {
    if (lista->fim == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    
    No* inicioDaLista = lista->fim->prox;
    imprimirListaRec(inicioDaLista, inicioDaLista);
}

// ALTERADO: Otimização para evitar código duplicado e limpeza na árvore de decisão
int BuscaRec(No* atual, No* inicio, int elem) {
    if (atual == NULL) {
        return 0;
    }
    
    // Checa o valor do nó atual de forma universal (meio ou fim)
    if (atual->dado == elem) { 
        printf("Valor encontrado: %d ", atual->dado);
        return 1;
    }
    
    // Caso base: Chegou ao fim do círculo e o valor não estava lá
    if (atual->prox == inicio) {
        return 0;
    }
       
    // ALTERADO CRÍTICO: Adicionado a palavra 'return' que faltava para propagar o resultado correto
    return BuscaRec(atual->prox, inicio, elem);
}

// ALTERADO: Implementada a função casca da busca para iniciar do primeiro elemento (10) e não do último
int buscarLista(ListaCircular* lista, int elem) {
    if (lista->fim == NULL) return 0;
    No* inicioDaLista = lista->fim->prox;
    return BuscaRec(inicioDaLista, inicioDaLista, elem);
}

// ALTERADO: Reescrita completa da função para funcionar sem o "lista->inicio" que causava erro
int listaCircularOrdenada(ListaCircular* lista) {
    // Se a lista estiver vazia ou tiver apenas 1 elemento, ela está ordenada
    if (lista->fim == NULL || lista->fim->prox == lista->fim)
        return 1;
        
    No* atual = lista->fim->prox; // Começa no primeiro nó da lista
    do {
        // Se o valor atual for maior que o próximo, quebra a ordem crescente
        if (atual->dado > atual->prox->dado) 
            return 0;
        atual = atual->prox;
    } while (atual != lista->fim); // Percorre até alcançar o último nó da lista

    return 1;
}