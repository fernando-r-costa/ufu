#ifndef _LISTA_H
#define _LISTA_H

typedef struct {
    int *elementos;
    int tamanho;
    int capacidade;
} ListaDinamica;

void iniciar(ListaDinamica *l, int capacidade);

int inserir(ListaDinamica *l, int valor);

void exibir(ListaDinamica *l);

int liberar(ListaDinamica *l);

#endif