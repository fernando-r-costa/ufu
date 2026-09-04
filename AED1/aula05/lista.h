#ifndef _LISTA_H
#define _LISTA_H

typedef struct no No;

void criaListaVazia(No **l);

int insereLista(No **l, int elem);

void imprimeLista(No **l);

int removerLista(No **l, int elem);

void buscaLista(No **l, int elem);

#endif