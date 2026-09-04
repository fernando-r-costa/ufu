#ifndef _LISTA_H
#define _LISTA_H

typedef struct no No;

No* criaListaVazia();

void verificaListaVazia(No *l);

No* inserirAluno (No *l, char nome[], int np, int nt);

void buscaAluno(No *l, char nome[]);

void mediaSuperior(No *l);

No* removerAluno(No *l, char nome[]);

void imprimeLista(No *l);

#endif