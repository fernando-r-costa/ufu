#ifndef _LISTA_H
#define _LISTA_H

typedef struct No {
    int dado;
    struct No* prox;
} No;

typedef struct {
    No* fim;
} ListaCircular;

void inserirFinal(ListaCircular* lista, int valor);
void imprimirLista(ListaCircular* lista);
void imprimirRecursiva(ListaCircular* lista);
int BuscaRec(No* atual, No* inicio, int elem);
int listaCircularOrdenada(ListaCircular* lista);
int buscarLista(ListaCircular* lista, int elem); // ALTERADO: Adicionado o wrapper padrão ouro para a busca

#endif