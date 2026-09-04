#ifndef _LISTA_H
#define _LISTA_H

typedef struct no No;

No* criaListaVazia();

No* insereInicio (No *l, int elem);

void imprime(No *l);

void verificaListaVazia(No *l);

#endif