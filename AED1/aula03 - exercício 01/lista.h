#ifndef _LISTA_H
#define _LISTA_H

#define MAX 100

typedef struct {
    int elementos[MAX];
    int tamanho;
} Lista;

void iniciar(Lista *l);

int inserir(Lista *l, int valor);

void exibir(Lista *l);

#endif