#ifndef _LISTA_H
#define _LISTA_H

typedef struct No {
    int capTanque;
    int combustivel;
    struct No* prox;
} No;

typedef struct {
    No* fim;
} ListaCircular;

void inserirFinal(ListaCircular* lista, int capTanque, int combustivel);
void imprimirFrota(ListaCircular* lista);
void abastecerFrota(ListaCircular* lista, int qtdPorCiclo);

#endif